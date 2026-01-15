// FtpManager.h
#pragma once
#include <QString>
#include <QFile>
#include <QList>
#include <QDateTime>
#include <functional>
#include <curl/curl.h>

struct FtpFileInfo {
    QString remotePath;
    QString name;
    QDateTime lastModified;
    qint64 size = -1; // 文件大小（字节）
};


class FtpManager {
public:
    using ProgressCallback = std::function<void(qint64 bytesSent, qint64 total)>;

    FtpManager(const QString& host, quint16 port, const QString& user, const QString& pass);
    ~FtpManager();
    void uploadFile(const QString& localPath, const QString& remotePath,
        const ProgressCallback& progress = {});
    void uploadFolder(const QString& localPath, const QString& remoteBasePath);

    void clearRemoteDirectory(const QString& remotePath);
    bool deleteFtpFile(const QString& parentDir, const QString& filename);
    bool deleteFtpDirectory(const QString& parentDir, const QString& dirname);
    QStringList listFtpDirectory(const QString& remoteDir);
    QList<FtpFileInfo> listFtpDirectoryDetailed(const QString& remoteDir);

    // 带进度回调的下载（可选）
    void downloadFile(const QString& remotePath, const QString& localPath,
        const ProgressCallback& progress = {});
    static size_t progressCallback(void* clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow);


private:
    QString buildRemoteFilePath(const QString& remoteDir, const QString& localFilePath);

private:
    QString host_;
    quint16 port_;
    QString user_;
    QString pass_;

    CURL* curl_ = nullptr;
};