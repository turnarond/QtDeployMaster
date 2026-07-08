#include <QtTest/QtTest>
#include <QDir>
#include <QTemporaryFile>

#include "RelayRecorder.h"
#include "RelayRecording.h"

class TstNrec : public QObject {
    Q_OBJECT
private slots:
    void sanity() { QVERIFY(true); }

    void recorderRoundTrip() {
        QString path = QDir::temp().filePath("tst_roundtrip.nrec");
        RelayRecorder rec;
        QVERIFY(rec.open(path, RelayProtocol::Tcp, 1000));
        rec.append(RelayDirection::Upstream,   1, 0,   QByteArray("hello"));
        rec.append(RelayDirection::Downstream, 1, 15,  QByteArray("\x00\x01\x02", 3));
        rec.append(RelayDirection::Upstream,   1, 40,  QByteArray("world"));
        rec.close();

        NrecFile f; QString err;
        QVERIFY2(RelayRecording::load(path, f, err), qPrintable(err));
        QCOMPARE(f.protocol, RelayProtocol::Tcp);
        QCOMPARE(f.startEpochMs, qint64(1000));
        QCOMPARE(f.records.size(), 3);
        QCOMPARE(f.records[0].dir, RelayDirection::Upstream);
        QCOMPARE(f.records[0].tsOffsetMs, qint64(0));
        QCOMPARE(f.records[0].payload, QByteArray("hello"));
        QCOMPARE(f.records[1].payload, QByteArray("\x00\x01\x02", 3));
        QCOMPARE(f.records[2].tsOffsetMs, qint64(40));
        QFile::remove(path);
    }

    void loadRejectsBadMagic() {
        QString path = QDir::temp().filePath("tst_bad.nrec");
        QFile bad(path); QVERIFY(bad.open(QIODevice::WriteOnly));
        bad.write("XXXX garbage"); bad.close();
        NrecFile f; QString err;
        QVERIFY(!RelayRecording::load(path, f, err));   // 坏 magic 必须被拒
        QVERIFY(!err.isEmpty());
        QFile::remove(path);
    }
};

QTEST_MAIN(TstNrec)
#include "tst_nrec.moc"
