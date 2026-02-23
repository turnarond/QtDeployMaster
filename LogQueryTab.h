// LogQueryTab.h
#pragma once

#include <QWidget>
#include <QDateTime>
#include <QMap>
#include <QTextEdit>
#include <QStringList>
#include "FtpManager.h" // 包含 FtpFileInfo 结构体定义

namespace Ui {
    class TabLogQuery;
}

class DeployMaster; // 前向声明主窗口

class LogQueryTab : public QWidget
{
    Q_OBJECT

public:
    explicit LogQueryTab( DeployMaster* parentWindow, QWidget* parent = nullptr);
    ~LogQueryTab();

    // 获取当前查询参数（供主窗口调用）
    QString logPath() const;
    QDateTime startTime() const;
    QDateTime endTime() const;

    void appendLogResult(const QString& ip, const QList<FtpFileInfo>& files);
    void clearResults();

    void setGlobalLogWidget(QTextEdit* logWidget) {
        txt_globalLog = logWidget;
    }

private:
    void downloadALogForIP(const QString& ip, const QString& remoteFile, const QString& saveDir);
    void startDownloadTask(const QString& ip, const QString& remotePath, const QString& localPath, const QString& filename);

private slots:
    void onTreeItemDoubleClicked();
    void on_btn_queryRequested();      // 用户点击“查询日志”
    void on_btn_downloadSelected();    // 下载选中
    void on_btn_downloadAll();         // 下载全部
    void updateDownloadProgress(const QString& ip, const QString& filename,
        qint64 bytesReceived, qint64 totalBytes);

private slots:
    void onLogQueryResultReady(const QString& ip, const QList<FtpFileInfo>& files);
    void appendLog(const QString& log); // 供主窗口调用，追加日志

private:
    QStringList getTargetIPs();
    QString formatFileSize(qint64 bytes);

private:
    Ui::TabLogQuery* ui;
    DeployMaster* m_mainWindow;

    QMap<QString, QStringList> m_logFilesCache; // 缓存每个 IP 的日志文件列表
    QTextEdit* txt_globalLog = nullptr;
};
