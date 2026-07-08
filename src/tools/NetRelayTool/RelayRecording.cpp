/* RelayRecording.cpp */
#include "RelayRecording.h"
#include <QFile>
#include <QDataStream>

bool RelayRecording::load(const QString& path, NrecFile& out, QString& error)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) { error = "无法打开文件: " + file.errorString(); return false; }
    if (file.size() < nrec::kHeaderSize) { error = "文件过小，非法 .nrec"; return false; }

    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);

    char magic[4];
    if (in.readRawData(magic, 4) != 4 ||
        magic[0]!='N'||magic[1]!='R'||magic[2]!='E'||magic[3]!='C') {
        error = "magic 校验失败，非 .nrec 文件"; return false;
    }
    quint16 version; quint8 proto, r0;
    in >> version >> proto >> r0;
    if (version != nrec::kVersion) { error = QString("不支持的版本: %1").arg(version); return false; }
    qint64 startEpoch; in >> startEpoch;
    for (int i = 0; i < 16; ++i) { quint8 x; in >> x; }  // reserved[16]

    out.protocol = (proto == 0) ? RelayProtocol::Tcp : RelayProtocol::Udp;
    out.startEpochMs = startEpoch;
    out.records.clear();

    while (!in.atEnd()) {
        quint8 dir, rr; quint32 sid; qint64 ts; quint32 len;
        in >> dir >> rr >> sid >> ts >> len;
        if (in.status() != QDataStream::Ok) { error = "记录头截断"; return false; }
        QByteArray payload;
        if (len > 0) {
            payload.resize(int(len));
            if (in.readRawData(payload.data(), int(len)) != int(len)) {
                error = "payload 截断"; return false;
            }
        }
        NrecRecord rec;
        rec.dir = (dir == 0) ? RelayDirection::Upstream : RelayDirection::Downstream;
        rec.sessionId = int(sid);
        rec.tsOffsetMs = ts;
        rec.payload = payload;
        out.records.append(rec);
    }
    return true;
}
