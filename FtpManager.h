// FtpManager.h
#pragma once
#include <QString>
#include <QFile>
#include <functional>
#include <curl/curl.h>

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

private:
    QString buildRemoteFilePath(const QString& remoteDir, const QString& localFilePath);
private:
    QString host_;
    quint16 port_;
    QString user_;
    QString pass_;

    CURL* curl_ = nullptr;
};