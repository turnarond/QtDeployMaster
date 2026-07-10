/*
 * OpcUaAdapter.h — OPC UA 协议适配器（基于 open62541 v1.5.5）
 *
 * 实现 IProtocolAdapter 统一接口，protocolId() → "opcua"。
 * 首期能力：None 安全策略 + 匿名认证的同步客户端；
 *   - 批量读节点   readNodes()
 *   - 批量写节点   writeNodes()
 *   - 浏览根节点树 browseRoot()（返回 JSON 字符串）
 *   - request()    读单个节点（请求-响应模式）
 *
 * open62541 client 在 UA_MULTITHREADING=0 下非线程安全，
 * 调用方需保证同一实例的方法串行调用（放入单一后台线程）。
 */
#pragma once
#include "IProtocolAdapter.h"
#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include <QStringList>
#include <QMap>
#include <atomic>

// 前向声明 open62541 类型，避免在头文件暴露 open62541.h（庞大且为 C 头）
// 注意：UA_Client 是具名结构体（typedef struct UA_Client UA_Client），可前向声明；
//       UA_Variant 是匿名结构体 typedef，无法前向声明，故仅在 .cpp 中经 open62541.h 使用。
struct UA_Client;

class OpcUaAdapter : public IProtocolAdapter {
public:
    OpcUaAdapter();
    ~OpcUaAdapter() override;

    // --- IProtocolAdapter 实现 ---
    std::string protocolId() const override { return "opcua"; }
    bool connect(const DeviceInfo& device, const AuthInfo& auth) override;
    void disconnect() override;
    bool isConnected() const override;
    std::string lastError() const override;
    std::future<Response> request(const Request& req) override;
    void subscribe(const Request& req, StreamCallback onData) override;
    void unsubscribe() override;
    ProtocolCapability capability() const override;

    // --- OPC UA 扩展接口 ---
    // 批量读节点：key = nodeId 字符串（如 "ns=2;i=2255"），value = 读到的值（失败为无效 QVariant）
    QVariantMap readNodes(const QStringList& nodeIds);
    // 批量写节点：nodeIds 与 values 一一对应，返回 key=nodeId，value=状态字符串（"Good" 或错误名）
    QMap<QString, QString> writeNodes(const QStringList& nodeIds, const QVariantList& values);
    // 浏览根节点（Objects Folder）的直接子节点，返回 JSON 数组字符串
    QString browseRoot();

private:
    UA_Client*        m_client = nullptr;
    std::atomic<bool> m_connected{false};
    QString           m_lastError;
    StreamCallback    m_streamCb;

    void setError(const QString& err);
    static QString uaStatusToString(quint32 statusCode);
};
