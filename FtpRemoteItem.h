// ftpremoteitem.h
#pragma once
#include <QString>
#include <QDateTime>
#include <QList>
#include <QFileInfo>

struct FtpRemoteItem {
    QString name;
    QString fullName;
    bool isDirectory = false;
    qint64 size = 0;
    QDateTime modifiedDate;
    QList<FtpRemoteItem> children;
};

struct UploadItem {
    QString fullPath;
    bool isFolder;
    QString displayName() const {
        return QFileInfo(fullPath).fileName();
    }
};