#pragma once

#include <QWidget>
#include <QMap>
#include <QTimer>
#include <QTextEdit>
#include <QStringList>

namespace Ui { class TabOpcUaClient; }
class DeployMaster;

class OpcUaClientTab : public QWidget {
    Q_OBJECT
public:
    explicit OpcUaClientTab(DeployMaster* parentWindow, QWidget* parent = nullptr);
    ~OpcUaClientTab();

    void setEndpointList(const QStringList& endpoints);

private slots:
    void on_btn_connect_clicked();
    void on_btn_browse_clicked();
    void on_btn_readValue_clicked();
    void on_btn_writeValue_clicked();
    void on_btn_subscribe_clicked();

    void appendLog(const QString& log);

private:
    Ui::TabOpcUaClient* ui;
    DeployMaster* m_mainWindow;
    QTextEdit* m_globalLog = nullptr;

    QStringList m_endpoints;

    // Note: actual OPC UA implementation omitted; design uses placeholders and signals
    bool m_connected = false;
};
