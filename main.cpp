#include "DeployMaster.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DeployMaster window;
    window.show();
    return app.exec();
}
