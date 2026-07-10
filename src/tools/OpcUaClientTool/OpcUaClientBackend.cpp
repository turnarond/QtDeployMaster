/*
 * Copyright (c) 2024-2026 turnarond.
 * All rights reserved.
 *
 * File: OpcUaClientBackend.cpp
 *
 * Date: 2026-07-10
 *
 * Author: turnarond
 *
 * Description: OPC UA 客户端 Tool 后端实现 — 通过 OpcUaAdapter 连接 OPC UA 服务器，
 *              提供节点的读/写/浏览功能。订阅（DataChange）为 Task 6 预留桩。
 *
 * 线程模型：open62541 client 在 UA_MULTITHREADING=0 下非线程安全。
 * 当前简化方案中，readNodes/writeNodes 同步调用 adapter，
 * svc() 为简单保活循环（100ms sleep），不做 runIterate 轮询。
 * 真实订阅的 runIterate 驱动将在 Task 6 中实现。
 */

#include "OpcUaClientBackend.h"
#include <QUrl>
#include <QDateTime>
#include <thread>
#include <chrono>

// ============================================================
// 构造 / 析构
// ============================================================

OpcUaClientBackend::OpcUaClientBackend()
    : m_adapter(std::make_shared<OpcUaAdapter>())
{
}

OpcUaClientBackend::~OpcUaClientBackend()
{
    m_running = false;
    if (m_adapter && m_adapter->isConnected()) {
        m_adapter->disconnect();
    }
}

// ============================================================
// ServiceTask — svc() 后台线程
// ============================================================

int OpcUaClientBackend::svc()
{
    m_running = true;
    while (m_running && ServiceTask::isRunning()) {
        // 当前简化方案：仅做保活循环，不做 UA_Client_runIterate 轮询。
        // readNodes/writeNodes 同步调用 adapter，内部处理网络 I/O。
        // 真实订阅的 runIterate 驱动将在 Task 6 中实现。
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    m_running = false;
    return 0;
}

// ============================================================
// ToolBackend — 设备/凭证绑定
// ============================================================

void OpcUaClientBackend::bindDevices(const std::vector<DeviceInfo>& /*devices*/)
{
    // OPC UA 为点对点连接，设备由 connectToServer 的 endpoint 参数指定，
    // bindDevices 在此保留为接口兼容，不做实际操作。
}

void OpcUaClientBackend::bindCredentials(const AuthInfo& /*auth*/)
{
    // 首期仅支持匿名认证，bindCredentials 保留为接口兼容。
}

// ============================================================
// 对外 API
// ============================================================

void OpcUaClientBackend::connectToServer(const QString& endpoint)
{
    if (m_logCb) {
        m_logCb(std::string("正在连接 OPC UA 服务器: ") + endpoint.toStdString());
    }

    // 解析 endpoint URL 提取端口号（默认 4840）
    int port = 4840;
    QUrl parsedUrl(endpoint);
    if (parsedUrl.port() > 0) {
        port = parsedUrl.port();
    }

    // 将完整 endpoint URL 存入 DeviceInfo.ip（适配器自动检测 opc.tcp:// 前缀）
    DeviceInfo device;
    device.ip   = endpoint.toStdString();
    device.port = port;
    device.protocol = "opcua";

    // 首期使用匿名认证
    AuthInfo auth;

    bool ok = m_adapter->connect(device, auth);
    if (ok) {
        if (m_logCb) m_logCb("OPC UA 服务器连接成功");
    } else {
        std::string err = m_adapter->lastError();
        if (!err.empty()) {
            if (m_logCb) m_logCb("OPC UA 服务器连接失败: " + err);
        } else {
            if (m_logCb) m_logCb("OPC UA 服务器连接失败");
        }
    }

    if (m_connCb) m_connCb(ok);
}

void OpcUaClientBackend::disconnectFromServer()
{
    if (m_logCb) m_logCb("正在断开 OPC UA 服务器连接...");
    m_adapter->disconnect();
    if (m_logCb) m_logCb("OPC UA 服务器已断开");
    if (m_connCb) m_connCb(false);
}

void OpcUaClientBackend::readNodes(const QStringList& nodeIds)
{
    if (!m_adapter->isConnected()) {
        if (m_logCb) m_logCb("OPC UA 未连接，无法读取节点");
        return;
    }

    QVariantMap results = m_adapter->readNodes(nodeIds);
    if (m_logCb) {
        m_logCb(std::string("批量读取 ") + std::to_string(nodeIds.size())
                + " 个节点完成");
    }

    // 通过 DataChangeCallback 将结果推送给 Widget（模拟订阅式数据推送）
    if (m_dataCb) {
        quint64 ts = QDateTime::currentMSecsSinceEpoch();
        for (const auto& nid : nodeIds) {
            QVariant val = results.value(nid);
            QString quality = val.isValid() ? QStringLiteral("Good")
                                            : QStringLiteral("Bad");
            m_dataCb(nid, val, ts, quality);
        }
    }
}

void OpcUaClientBackend::writeNodes(const QStringList& nodeIds, const QVariantList& values)
{
    if (!m_adapter->isConnected()) {
        if (m_logCb) m_logCb("OPC UA 未连接，无法写入节点");
        return;
    }

    QMap<QString, QString> statuses = m_adapter->writeNodes(nodeIds, values);

    if (m_logCb) {
        m_logCb(std::string("批量写入 ") + std::to_string(nodeIds.size())
                + " 个节点完成");
    }

    // 将写入结果推送至日志
    if (m_logCb) {
        for (const auto& nid : nodeIds) {
            QString st = statuses.value(nid, QStringLiteral("未知"));
            m_logCb(std::string("写入 ") + nid.toStdString()
                    + " → " + st.toStdString());
        }
    }
}

void OpcUaClientBackend::subscribeNodes(const QStringList& nodeIds)
{
    // 订阅功能的真实实现依赖 open62541 Subscription + MonitoredItem，
    // 需在 svc() 中驱动 UA_Client_runIterate 回调派发。
    // 当前为一期骨架桩，将在 Task 6 中实现。
    if (m_logCb) {
        m_logCb("订阅功能将在后续版本(Task 6)中实现");
        m_logCb(std::string("待订阅节点数: ") + std::to_string(nodeIds.size()));
    }
    m_subscribed = false;
}

void OpcUaClientBackend::unsubscribeAll()
{
    // 订阅功能桩，将于 Task 6 实现真正的 UA_Client_deleteSubscriptions。
    m_adapter->unsubscribe();
    m_subscribed = false;
    if (m_logCb) m_logCb("已取消所有订阅");
}

QString OpcUaClientBackend::browseAddressSpace()
{
    if (!m_adapter->isConnected()) {
        if (m_logCb) m_logCb("OPC UA 未连接，无法浏览地址空间");
        return QString();
    }

    QString json = m_adapter->browseRoot();
    if (m_logCb) m_logCb("地址空间浏览完成");
    return json;
}
