// telnetclient.h
#ifndef TELNETCLIENT_H
#define TELNETCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

class TelnetClient : public QObject
{
    Q_OBJECT

public:
    // 同步方法（阻塞直到成功/失败/超时）
    bool syncConnectToHost(const QString& host, quint16 port, int timeoutMs = 5000);
    bool syncLogin(const QString& username, const QString& password, int timeoutMs = 5000);
    bool syncSendCommand(const QString& command, int timeoutMs = 3000);

public:
    explicit TelnetClient(QObject *parent = nullptr);
    void connectToHost(const QString &host, quint16 port = 23);
    void login(const QString &username, const QString &password);
    void sendCommand(const QString &command);

signals:
    void connected();
    void loginSuccess();
    void loginFailed();
    void commandSent();
    void error(const QString &msg);
    void disconnected();
    void dataReceived(const QString &data); // emit received data

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

private:
    // TelnetClient.h
    enum State {
        Idle,
        Connecting,
        AwaitingLogin,
        AwaitingPassword,
        AwaitingPrompt,  // 👈 新增：等待 shell 提示符
        LoggedIn
    };
    State m_state = Idle;

    QString m_username, m_password;
    QTcpSocket* m_socket;
    QTimer* m_timeoutTimer;
    int m_loginTimeoutMs = 5000;

    // 新增：用于同步等待的事件循环
    QEventLoop* m_eventLoop = nullptr;
    bool m_syncResult = false;
};

#endif // TELNETCLIENT_H