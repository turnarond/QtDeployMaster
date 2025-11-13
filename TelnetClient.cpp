// telnetclient.cpp
#include "TelnetClient.h"
#include <QTextStream>
#include <QDebug>
#include <QOverload>
#include <QNetworkProxy>

TelnetClient::TelnetClient(QObject* parent)
    : QObject(parent), m_socket(new QTcpSocket(this)), m_state(Idle)
{
    connect(m_socket, &QTcpSocket::connected, this, &TelnetClient::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &TelnetClient::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &TelnetClient::onDisconnected);
    connect(m_socket, &QAbstractSocket::errorOccurred,
        this, &TelnetClient::onError);

    m_timeoutTimer = new QTimer(this);
    m_timeoutTimer->setSingleShot(true);
    connect(m_timeoutTimer, &QTimer::timeout, this, [this]() {
        emit error("Login timeout");
        m_socket->disconnectFromHost();
        });
}

bool TelnetClient::syncConnectToHost(const QString& host, quint16 port, int timeoutMs)
{
    m_state = Connecting;
    m_socket->setProxy(QNetworkProxy::NoProxy);
    m_socket->connectToHost(host, port);

    QEventLoop loop;
    m_eventLoop = &loop;

    // 连接信号到 quit
    QObject::connect(m_socket, &QTcpSocket::connected, &loop, &QEventLoop::quit);
    QObject::connect(m_socket, &QAbstractSocket::errorOccurred, &loop, &QEventLoop::quit);
    QObject::connect(m_timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

    m_timeoutTimer->start(timeoutMs);
    loop.exec(); // 阻塞直到 quit()
    m_timeoutTimer->stop();

    m_eventLoop = nullptr;

    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        return true;
    }
    else {
        emit error("Connection failed: " + m_socket->errorString());
        return false;
    }
}

bool TelnetClient::syncLogin(const QString& username, const QString& password, int timeoutMs)
{
    if (m_socket->state() != QAbstractSocket::ConnectedState) {
        emit error("Not connected");
        return false;
    }

    m_username = username;
    m_password = password;
    m_state = AwaitingLogin;

    QEventLoop loop;
    m_eventLoop = &loop;

    // 登录成功或失败都会 quit
    QObject::connect(this, &TelnetClient::loginSuccess, &loop, &QEventLoop::quit);
    QObject::connect(this, &TelnetClient::error, &loop, &QEventLoop::quit);
    QObject::connect(m_timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

    m_timeoutTimer->start(timeoutMs);
    loop.exec();
    m_timeoutTimer->stop();

    m_eventLoop = nullptr;

    return m_state == LoggedIn;
}

bool TelnetClient::syncSendCommand(const QString& command, int timeoutMs)
{
    if (m_state != LoggedIn) {
        emit error("Not logged in");
        return false;
    }

    m_socket->write(command.toUtf8() + "\n");
    m_socket->flush();

    // 可选：等待回显或提示符（简化版：只等数据到达）
    // 如果不需要确认，可直接 return true;
    QEventLoop loop;
    m_eventLoop = &loop;

    // 等待有数据返回（或超时）
    QObject::connect(m_socket, &QTcpSocket::readyRead, &loop, &QEventLoop::quit);
    QObject::connect(m_timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

    m_timeoutTimer->start(timeoutMs);
    loop.exec();
    m_timeoutTimer->stop();

    m_eventLoop = nullptr;

    // 即使没数据，也认为命令已发送（嵌入式设备通常无回显）
    return true;
}

void TelnetClient::connectToHost(const QString& host, quint16 port)
{
    // 禁用代理
    m_socket->setProxy(QNetworkProxy::NoProxy);
    m_socket->connectToHost(host, port);
}

void TelnetClient::login(const QString& username, const QString& password)
{
    m_username = username;
    m_password = password;
    m_state = AwaitingLogin;
    m_timeoutTimer->start(m_loginTimeoutMs);
}

void TelnetClient::sendCommand(const QString& command)
{
    if (m_state != LoggedIn) {
        emit error("Not logged in");
        return;
    }
    m_socket->write(command.toUtf8() + "\n");
    m_socket->flush();
    emit commandSent();
}

void TelnetClient::onConnected()
{
    emit connected();
}

void TelnetClient::onDisconnected()
{
    m_timeoutTimer->stop();
    emit disconnected();
}

void TelnetClient::onError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    m_timeoutTimer->stop();
    emit error(m_socket->errorString());
}

void TelnetClient::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    QByteArray cleanData;
    for (int i = 0; i < data.size(); ++i) {
        if (static_cast<unsigned char>(data[i]) == 0xFF) {
            i += 2;
            continue;
        }
        cleanData.append(data[i]);
    }

    QString response = QString::fromUtf8(cleanData).trimmed();
    qDebug() << "Telnet RX:" << response;

    switch (m_state) {
    case AwaitingLogin:
        if (response.contains("login:", Qt::CaseInsensitive) ||
            response.contains("username", Qt::CaseInsensitive)) {
            m_socket->write(m_username.toUtf8() + "\n");
            m_socket->flush();
            m_state = AwaitingPassword;
        }
        break;

    case AwaitingPassword:
        if (response.contains("password", Qt::CaseInsensitive)) {
            m_socket->write(m_password.toUtf8() + "\n");
            m_socket->flush();
            m_state = AwaitingPrompt; // 👈 登录后不是 LoggedIn，而是等提示符！
            // 不 stop timer，继续等
        }
        break;

    case AwaitingPrompt:
        // 检查是否出现 shell 提示符（根据你的设备调整！）
        if (response.contains("#") || response.contains(">") || response.contains("$")) {
            m_state = LoggedIn;
            m_timeoutTimer->stop();
            emit loginSuccess(); // ✅ 现在才真正登录成功
        }
        // 注意：有些设备提示符在新行，可能 response 为空，需累积缓冲
        break;

    case LoggedIn:
        // 可用于后续命令回显处理
        break;

    default:
        break;
    }
}