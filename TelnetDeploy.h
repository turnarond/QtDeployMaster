// TelnetDeploy.h
#pragma once

#include <QWidget>
#include <QDateTime>
#include <QMap>
#include <QTextEdit>
#include <QStringList>
#include <atomic>

class QTreeWidgetItem; // forward declaration

namespace Ui {
    class TabTelnetDeploy;
}

class DeployMaster; // 前向声明主窗口

class TelnetDeploy : public QWidget
{
    Q_OBJECT

public:
    explicit TelnetDeploy(DeployMaster* parentWindow, QWidget* parent = nullptr);
    ~TelnetDeploy();

    

private:

private slots:
    void on_ExecuteTelnetCmdClicked();
    void on_StopTelnetClicked();

    void appendLog(const QString& log); // 供主窗口调用，追加日志
    void onTreeItemDoubleClicked(QTreeWidgetItem* item, int column);

    void onTelnetDataReceived(const QString& ip, const QString& data);
    void updateItemStatus(const QString& ip, const QString& status, const QString& elapsedMs, const QString& note);
    void onTaskFinished();

private:
    QStringList getTargetIPs();
    QString formatFileSize(qint64 bytes);

private:
    Ui::TabTelnetDeploy* ui;
    DeployMaster* m_mainWindow;

    QTextEdit* txt_globalLog = nullptr;

    // runtime control
    std::atomic<bool> m_stopRequested{false};
    std::atomic<bool> m_running{false};
    std::atomic<int> m_pendingTasks{0};

    QMap<QString, QString> m_outputs; // cache output per IP
};
