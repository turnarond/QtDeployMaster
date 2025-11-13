#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DeployMaster.h"
#include "FtpRemoteItem.h"
#include "FtpManager.h"

class DeployMaster : public QMainWindow
{
    Q_OBJECT

public:
    DeployMaster(QWidget* parent = nullptr);
    ~DeployMaster();

private:
    QString lastUsedDirectory; // 记录上次使用的目录
    QList<UploadItem> uploadItems;

private:
    void addFileToList(const QString& filePath); // 添加文件到列表的函数
    void addFolderToList(const QString& folderPath); // 添加文件夹到列表的函数    
    QStringList getTargetIPs();

public slots:
    void appendFtpLog(const QString& log);

private slots:
    // Add your custom slots here
    void onAddFilesClicked();
    void onAddFolderClicked();
    void onFilesDropped(const QStringList& filePaths);
    void onFileItemCleanClicked();
    void onDeployClicked();
    void onClearLogClicked();

    void onFtpUploadFinished(const QStringList& deploySuccesses,
        const QStringList& deployFailures,
        bool shouldReboot,
        const QString& user,
        const QString& pass);
private:
    Ui::DeployMaster ui;
};

