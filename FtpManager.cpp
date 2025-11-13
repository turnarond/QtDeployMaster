// FtpManager.cpp
#include "FtpManager.h"

#include <QDirIterator>
#include <QFileInfo>
#include <QDebug>
#include <QUrl>

struct FtpContext {
    QFile* file = nullptr;
    qint64 total = 0;
    FtpManager::ProgressCallback progress;
};

size_t readCallback(void* ptr, size_t size, size_t nmemb, void* userdata) 
{
    FtpContext* ctx = static_cast<FtpContext*>(userdata);
    size_t toRead = size * nmemb;
    qint64 read = ctx->file->read(static_cast<char*>(ptr), toRead);
    return static_cast<size_t>(read);
}

size_t writeCallbackString(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realSize = size * nmemb;
    QString* output = static_cast<QString*>(userp);
    output->append(QString::fromUtf8(static_cast<char*>(contents), static_cast<int>(realSize)));
    return realSize;
}

int progressCallback(void* clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    Q_UNUSED(dltotal); Q_UNUSED(dlnow);
    FtpContext* ctx = static_cast<FtpContext*>(clientp);
    if (ctx->progress) {
        ctx->progress(ulnow, ultotal > 0 ? ultotal : ctx->total);
    }
    return 0;
}

FtpManager::FtpManager(const QString& host, quint16 port, const QString& user, const QString& pass)
    : host_(host), port_(port), user_(user), pass_(pass) 
{
    curl_ = curl_easy_init();
    if (!curl_) {
        throw std::runtime_error("curl_easy_init() 失败");
    }
    curl_easy_setopt(curl_, CURLOPT_TCP_KEEPALIVE, 1L);		// 设置长连接
    curl_easy_setopt(curl_, CURLOPT_USERPWD, (user + ":" + pass).toStdString().c_str());
}

void FtpManager::uploadFile(const QString& localPath, const QString& remoteDirectory,
    const ProgressCallback& progress) 
{
    QFile file(localPath);
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("无法打开本地文件: " + localPath.toStdString());
    }

    QString remoteFilePath = buildRemoteFilePath(remoteDirectory, localPath);

    // 使用 QUrl 安全构建 URL（自动处理编码）
    QUrl url;
    url.setScheme("ftp");
    url.setHost(host_);
    url.setPort(port_);
    url.setPath("/" + remoteFilePath); // 必须以 / 开头

    QString urlStr = url.toString(QUrl::FullyEncoded);
    QByteArray urlBytes = urlStr.toUtf8(); // 保持生命周期

    FtpContext ctx;
    ctx.file = &file;
    ctx.total = file.size();
    ctx.progress = progress;

    curl_easy_setopt(curl_, CURLOPT_URL, urlBytes.constData());
    curl_easy_setopt(curl_, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl_, CURLOPT_READFUNCTION, readCallback);
    curl_easy_setopt(curl_, CURLOPT_READDATA, &ctx);
    curl_easy_setopt(curl_, CURLOPT_INFILESIZE_LARGE, static_cast<curl_off_t>(file.size()));
    curl_easy_setopt(curl_, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);
    curl_easy_setopt(curl_, CURLOPT_XFERINFOFUNCTION, progressCallback);
    curl_easy_setopt(curl_, CURLOPT_XFERINFODATA, &ctx);
    curl_easy_setopt(curl_, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl_, CURLOPT_TIMEOUT, 300L);

    CURLcode res = curl_easy_perform(curl_);
    file.close();

    if (res != CURLE_OK) {
        std::string errorMsg = "libcurl 上传失败 (";
        errorMsg += std::to_string(res);
        errorMsg += "): ";
        errorMsg += curl_easy_strerror(res);
        errorMsg += " | URL: ";
        errorMsg += urlStr.toStdString();
        throw std::runtime_error(errorMsg);
    }
}

void FtpManager::uploadFolder(const QString& localPath, const QString& remoteBasePath) {
    QDir localDir(localPath);
    if (!localDir.exists()) {
        std::string errorMsg = "本地文件夹不存在: " + localPath.toStdString();
        throw std::runtime_error(errorMsg);
    }

    QDirIterator it(localPath, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot,
        QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        QFileInfo fi = it.fileInfo();
        if (fi.isFile()) {
            QString filePath = fi.absolutePath();
            QString relPath = localDir.relativeFilePath(filePath);
            QString remoteFile = remoteBasePath + "/"  + localDir.dirName() + "/" + relPath;
            uploadFile(fi.absoluteFilePath(), remoteFile);
        }
    }
}
void FtpManager::clearRemoteDirectory(const QString& remoteDir)
{
    // 规范化路径：去掉首尾斜杠，避免 /app/ -> //app//
    QString cleanDir = remoteDir;
    if (cleanDir.startsWith('/')) cleanDir = cleanDir.mid(1);
    if (cleanDir.endsWith('/')) cleanDir.chop(1);
    if (cleanDir.isEmpty()) {
        throw std::runtime_error("不能清空根目录 '/'");
    }

    // 第一步：列出当前目录内容
    QStringList entries;
    try {
        entries = listFtpDirectory(cleanDir);
    }
    catch (const std::exception& ex) {
        // 如果目录不存在，视为已“清空”
        if (std::string(ex.what()).find("550") != std::string::npos) {
            return; // 550 = File unavailable (e.g., file not found)
        }
        throw; // 其他错误继续抛出
    }

    // 第二步：先删除所有文件
    for (const QString& entry : entries) {
        if (entry.isEmpty()) continue;

        // 构造完整路径用于判断（但 libcurl 的 DELE 不需要完整路径，只需相对名）
        QString fullPath = cleanDir + "/" + entry;

        // 尝试删除文件（如果失败，可能是目录）
        bool isFile = deleteFtpFile(cleanDir, entry);
        if (!isFile) {
            // 如果不是文件，就当作目录处理（递归清空）
            clearRemoteDirectory(fullPath); // 递归清空子目录
            // 然后删除空目录
            deleteFtpDirectory(cleanDir, entry);
        }
    }
}

bool FtpManager::deleteFtpFile(const QString& parentDir, const QString& filename)
{
    QUrl url;
    url.setScheme("ftp");
    url.setHost(host_);
    url.setPort(port_);
    url.setPath("/" + parentDir.trimmed() + "/" + filename);

    QString urlStr = url.toString(QUrl::FullyEncoded);
    QByteArray urlBytes = urlStr.toUtf8();

    // 使用 QUOTE 发送 DELE 命令（更可靠）
    struct curl_slist* quote = nullptr;
    quote = curl_slist_append(quote, ("DELE " + filename).toUtf8().constData());

    curl_easy_setopt(curl_, CURLOPT_URL, urlBytes.constData());
    curl_easy_setopt(curl_, CURLOPT_QUOTE, quote);
    curl_easy_setopt(curl_, CURLOPT_NOBODY, 1L); // 不下载内容
    curl_easy_setopt(curl_, CURLOPT_TIMEOUT, 30L);

    CURLcode res = curl_easy_perform(curl_);
    curl_slist_free_all(quote);

    return (res == CURLE_OK);
}

bool FtpManager::deleteFtpDirectory(const QString& parentDir, const QString& dirname)
{
    struct curl_slist* quote = nullptr;
    quote = curl_slist_append(quote, ("RMD " + dirname).toUtf8().constData());

    // 构造父目录 URL
    QString parentPath = parentDir;
    if (parentPath.startsWith('/')) parentPath = parentPath.mid(1);
    QUrl url;
    url.setScheme("ftp");
    url.setHost(host_);
    url.setPort(port_);
    url.setPath("/" + parentPath);

    QString urlStr = url.toString(QUrl::FullyEncoded);
    QByteArray urlBytes = urlStr.toUtf8();

    curl_easy_setopt(curl_, CURLOPT_URL, urlBytes.constData());
    curl_easy_setopt(curl_, CURLOPT_QUOTE, quote);
    curl_easy_setopt(curl_, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl_, CURLOPT_TIMEOUT, 30L);

    CURLcode res = curl_easy_perform(curl_);
    curl_slist_free_all(quote);

    return (res == CURLE_OK);
}

QStringList FtpManager::listFtpDirectory(const QString& remoteDir)
{
    QUrl url;
    url.setScheme("ftp");
    url.setHost(host_);
    url.setPort(port_);
    url.setPath("/" + remoteDir.trimmed()); // 确保路径格式正确

    // 如果 remoteDir 为空或 "/"，则列出根目录
    if (url.path().isEmpty() || url.path() == "/") {
        url.setPath("/");
    }

    QString urlStr = url.toString(QUrl::FullyEncoded);
    QByteArray urlBytes = urlStr.toUtf8();

    QString listOutput;
    curl_easy_setopt(curl_, CURLOPT_URL, urlBytes.constData());
    curl_easy_setopt(curl_, CURLOPT_DIRLISTONLY, 1L); // 只返回文件名列表
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, writeCallbackString);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &listOutput);
    curl_easy_setopt(curl_, CURLOPT_TIMEOUT, 30L);

    CURLcode res = curl_easy_perform(curl_);
    if (res != CURLE_OK) {
        throw std::runtime_error("无法列出远程目录: " + std::string(curl_easy_strerror(res)));
    }

    // 按行分割，过滤空行
    QStringList entries = listOutput.split('\n', Qt::SkipEmptyParts);
    for (QString& entry : entries) {
        entry = entry.trimmed();
    }
    return entries;
}

QString FtpManager::buildRemoteFilePath(const QString& remoteDir, const QString& localFilePath) 
{
    QFileInfo fi(localFilePath);
    QString fileName = fi.fileName();

    QString cleanDir = remoteDir;
    if (cleanDir.startsWith('/')) cleanDir = cleanDir.mid(1);
    if (cleanDir.endsWith('/')) cleanDir.chop(1);

    return cleanDir.isEmpty() ? fileName : cleanDir + "/" + fileName;
}

FtpManager::~FtpManager() {
    if (curl_) {
        curl_easy_cleanup(curl_);
        curl_ = nullptr;
    }
}
