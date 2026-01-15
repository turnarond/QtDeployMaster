#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DeployMaster.h"
#include "ui_tab_logquery.h"
#include "FtpRemoteItem.h"
#include "FtpManager.h"
#include "LogQueryTab.h"

class DeployMaster : public QMainWindow
{
    Q_OBJECT

public:
    DeployMaster(QWidget* parent = nullptr);
    ~DeployMaster();

public:
    QStringList getTargetIPList() const;

private:
    QString lastUsedDirectory; // 记录上次使用的目录
    QList<UploadItem> uploadItems;

private:
    void addFileToList(const QString& filePath); // 添加文件到列表的函数
    void addFolderToList(const QString& folderPath); // 添加文件夹到列表的函数    
    QStringList getTargetIPs();

public slots:
    void appendFtpLog(const QString& log);
    void ftpUserFinished(QString str);
    void ftpPassFinished(QString str);

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
    void setupLogQueryTab();
private:
    Ui::DeployMaster ui;
    LogQueryTab* m_logQueryTab = nullptr;
};

