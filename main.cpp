#include "DeployMaster.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QTextStream>
#include "src/utils/DeployEvent.h"
// #include "src/presenter/FtpPresenter.h" — 临时禁用，待 Task 13

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 注册元类型
    qRegisterMetaType<DeployEvent>("DeployEvent");
    qRegisterMetaType<DeployEvent::Type>("DeployEvent::Type");

    // 加载深色主题样式表
    QFile styleFile(":/styles/darkstyle.qss");
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&styleFile);
        QString styleSheet = stream.readAll();
        app.setStyleSheet(styleSheet);
        styleFile.close();
    }

    DeployMaster window;

    // 创建 FtpPresenter 实例（订阅 EventBus 事件，连接部署管道）
    // 临时禁用: FtpPresenter.cpp 存在 QPointer 类型兼容性问题，待 Task 13 重构
    // auto* ftpPresenter = new FtpPresenter(&window);
    // Q_UNUSED(ftpPresenter); // 生命周期由 parent 管理

    window.show();
    return app.exec();
}
