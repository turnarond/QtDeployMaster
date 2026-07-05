/********************************************************************************
** Form generated from reading UI file 'tab_websocket.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_WEBSOCKET_H
#define UI_TAB_WEBSOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabWebSocket
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_mode;
    QHBoxLayout *horizontalLayout_mode;
    QRadioButton *radio_server;
    QRadioButton *radio_client;
    QGroupBox *groupBox_server;
    QFormLayout *formLayout_server;
    QLabel *label_serverPort;
    QSpinBox *spin_serverPort;
    QLabel *label_maxConnections;
    QSpinBox *spin_maxConnections;
    QLabel *label_secureMode;
    QCheckBox *chk_secureMode;
    QGroupBox *groupBox_client;
    QFormLayout *formLayout_client;
    QLabel *label_serverUrl;
    QLineEdit *lineEdit_serverUrl;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QPushButton *btn_send;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_pubsub;
    QGridLayout *gridLayout_pubsub;
    QLabel *label_topic;
    QLineEdit *lineEdit_topic;
    QLabel *label_pubMessage;
    QLineEdit *lineEdit_pubMessage;
    QPushButton *btn_subscribe;
    QPushButton *btn_publish;
    QGroupBox *groupBox_messages;
    QVBoxLayout *verticalLayout_messages;
    QTextEdit *txt_messages;
    QHBoxLayout *horizontalLayout_log;
    QSpacerItem *horizontalSpacer_log;
    QPushButton *btn_clearLog;

    void setupUi(QWidget *TabWebSocket)
    {
        if (TabWebSocket->objectName().isEmpty())
            TabWebSocket->setObjectName("TabWebSocket");
        TabWebSocket->resize(960, 500);
        verticalLayout = new QVBoxLayout(TabWebSocket);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_mode = new QGroupBox(TabWebSocket);
        groupBox_mode->setObjectName("groupBox_mode");
        horizontalLayout_mode = new QHBoxLayout(groupBox_mode);
        horizontalLayout_mode->setObjectName("horizontalLayout_mode");
        radio_server = new QRadioButton(groupBox_mode);
        radio_server->setObjectName("radio_server");
        radio_server->setChecked(true);

        horizontalLayout_mode->addWidget(radio_server);

        radio_client = new QRadioButton(groupBox_mode);
        radio_client->setObjectName("radio_client");

        horizontalLayout_mode->addWidget(radio_client);


        verticalLayout->addWidget(groupBox_mode);

        groupBox_server = new QGroupBox(TabWebSocket);
        groupBox_server->setObjectName("groupBox_server");
        formLayout_server = new QFormLayout(groupBox_server);
        formLayout_server->setObjectName("formLayout_server");
        label_serverPort = new QLabel(groupBox_server);
        label_serverPort->setObjectName("label_serverPort");

        formLayout_server->setWidget(0, QFormLayout::ItemRole::LabelRole, label_serverPort);

        spin_serverPort = new QSpinBox(groupBox_server);
        spin_serverPort->setObjectName("spin_serverPort");
        spin_serverPort->setMinimum(1);
        spin_serverPort->setMaximum(65535);
        spin_serverPort->setValue(8080);

        formLayout_server->setWidget(0, QFormLayout::ItemRole::FieldRole, spin_serverPort);

        label_maxConnections = new QLabel(groupBox_server);
        label_maxConnections->setObjectName("label_maxConnections");

        formLayout_server->setWidget(1, QFormLayout::ItemRole::LabelRole, label_maxConnections);

        spin_maxConnections = new QSpinBox(groupBox_server);
        spin_maxConnections->setObjectName("spin_maxConnections");
        spin_maxConnections->setMinimum(1);
        spin_maxConnections->setMaximum(100);
        spin_maxConnections->setValue(10);

        formLayout_server->setWidget(1, QFormLayout::ItemRole::FieldRole, spin_maxConnections);

        label_secureMode = new QLabel(groupBox_server);
        label_secureMode->setObjectName("label_secureMode");

        formLayout_server->setWidget(2, QFormLayout::ItemRole::LabelRole, label_secureMode);

        chk_secureMode = new QCheckBox(groupBox_server);
        chk_secureMode->setObjectName("chk_secureMode");

        formLayout_server->setWidget(2, QFormLayout::ItemRole::FieldRole, chk_secureMode);


        verticalLayout->addWidget(groupBox_server);

        groupBox_client = new QGroupBox(TabWebSocket);
        groupBox_client->setObjectName("groupBox_client");
        formLayout_client = new QFormLayout(groupBox_client);
        formLayout_client->setObjectName("formLayout_client");
        label_serverUrl = new QLabel(groupBox_client);
        label_serverUrl->setObjectName("label_serverUrl");

        formLayout_client->setWidget(0, QFormLayout::ItemRole::LabelRole, label_serverUrl);

        lineEdit_serverUrl = new QLineEdit(groupBox_client);
        lineEdit_serverUrl->setObjectName("lineEdit_serverUrl");

        formLayout_client->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_serverUrl);


        verticalLayout->addWidget(groupBox_client);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        btn_start = new QPushButton(TabWebSocket);
        btn_start->setObjectName("btn_start");

        horizontalLayout_buttons->addWidget(btn_start);

        btn_stop = new QPushButton(TabWebSocket);
        btn_stop->setObjectName("btn_stop");

        horizontalLayout_buttons->addWidget(btn_stop);

        btn_send = new QPushButton(TabWebSocket);
        btn_send->setObjectName("btn_send");

        horizontalLayout_buttons->addWidget(btn_send);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_buttons->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_buttons);

        groupBox_pubsub = new QGroupBox(TabWebSocket);
        groupBox_pubsub->setObjectName("groupBox_pubsub");
        gridLayout_pubsub = new QGridLayout(groupBox_pubsub);
        gridLayout_pubsub->setObjectName("gridLayout_pubsub");
        label_topic = new QLabel(groupBox_pubsub);
        label_topic->setObjectName("label_topic");

        gridLayout_pubsub->addWidget(label_topic, 0, 0, 1, 1);

        lineEdit_topic = new QLineEdit(groupBox_pubsub);
        lineEdit_topic->setObjectName("lineEdit_topic");

        gridLayout_pubsub->addWidget(lineEdit_topic, 0, 1, 1, 1);

        label_pubMessage = new QLabel(groupBox_pubsub);
        label_pubMessage->setObjectName("label_pubMessage");

        gridLayout_pubsub->addWidget(label_pubMessage, 1, 0, 1, 1);

        lineEdit_pubMessage = new QLineEdit(groupBox_pubsub);
        lineEdit_pubMessage->setObjectName("lineEdit_pubMessage");

        gridLayout_pubsub->addWidget(lineEdit_pubMessage, 1, 1, 1, 1);

        btn_subscribe = new QPushButton(groupBox_pubsub);
        btn_subscribe->setObjectName("btn_subscribe");

        gridLayout_pubsub->addWidget(btn_subscribe, 0, 2, 1, 1);

        btn_publish = new QPushButton(groupBox_pubsub);
        btn_publish->setObjectName("btn_publish");

        gridLayout_pubsub->addWidget(btn_publish, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_pubsub);

        groupBox_messages = new QGroupBox(TabWebSocket);
        groupBox_messages->setObjectName("groupBox_messages");
        verticalLayout_messages = new QVBoxLayout(groupBox_messages);
        verticalLayout_messages->setObjectName("verticalLayout_messages");
        txt_messages = new QTextEdit(groupBox_messages);
        txt_messages->setObjectName("txt_messages");
        txt_messages->setReadOnly(true);

        verticalLayout_messages->addWidget(txt_messages);

        horizontalLayout_log = new QHBoxLayout();
        horizontalLayout_log->setObjectName("horizontalLayout_log");
        horizontalSpacer_log = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_log->addItem(horizontalSpacer_log);

        btn_clearLog = new QPushButton(groupBox_messages);
        btn_clearLog->setObjectName("btn_clearLog");

        horizontalLayout_log->addWidget(btn_clearLog);


        verticalLayout_messages->addLayout(horizontalLayout_log);


        verticalLayout->addWidget(groupBox_messages);


        retranslateUi(TabWebSocket);

        QMetaObject::connectSlotsByName(TabWebSocket);
    } // setupUi

    void retranslateUi(QWidget *TabWebSocket)
    {
        groupBox_mode->setTitle(QCoreApplication::translate("TabWebSocket", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        radio_server->setText(QCoreApplication::translate("TabWebSocket", "Server \346\250\241\345\274\217", nullptr));
        radio_client->setText(QCoreApplication::translate("TabWebSocket", "Client \346\250\241\345\274\217", nullptr));
        groupBox_server->setTitle(QCoreApplication::translate("TabWebSocket", "Server \350\256\276\347\275\256", nullptr));
        label_serverPort->setText(QCoreApplication::translate("TabWebSocket", "\347\253\257\345\217\243\357\274\232", nullptr));
        label_maxConnections->setText(QCoreApplication::translate("TabWebSocket", "\346\234\200\345\244\247\350\277\236\346\216\245\346\225\260\357\274\232", nullptr));
        label_secureMode->setText(QCoreApplication::translate("TabWebSocket", "\345\256\211\345\205\250\346\250\241\345\274\217\357\274\232", nullptr));
        chk_secureMode->setText(QCoreApplication::translate("TabWebSocket", "\344\275\277\347\224\250 WSS", nullptr));
        groupBox_client->setTitle(QCoreApplication::translate("TabWebSocket", "Client \350\256\276\347\275\256", nullptr));
        label_serverUrl->setText(QCoreApplication::translate("TabWebSocket", "\346\234\215\345\212\241\345\231\250 URL\357\274\232", nullptr));
        lineEdit_serverUrl->setText(QCoreApplication::translate("TabWebSocket", "ws://localhost:8080", nullptr));
        btn_start->setText(QCoreApplication::translate("TabWebSocket", "\345\220\257\345\212\250", nullptr));
        btn_stop->setText(QCoreApplication::translate("TabWebSocket", "\345\201\234\346\255\242", nullptr));
        btn_send->setText(QCoreApplication::translate("TabWebSocket", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        groupBox_pubsub->setTitle(QCoreApplication::translate("TabWebSocket", "\345\217\221\345\270\203/\350\256\242\351\230\205", nullptr));
        label_topic->setText(QCoreApplication::translate("TabWebSocket", "\344\270\273\351\242\230 URL\357\274\232", nullptr));
        lineEdit_topic->setText(QCoreApplication::translate("TabWebSocket", "/topic/example", nullptr));
        label_pubMessage->setText(QCoreApplication::translate("TabWebSocket", "\345\217\221\345\270\203\346\266\210\346\201\257\357\274\232", nullptr));
        lineEdit_pubMessage->setPlaceholderText(QCoreApplication::translate("TabWebSocket", "\350\276\223\345\205\245\350\246\201\345\217\221\345\270\203\347\232\204\346\266\210\346\201\257...", nullptr));
        btn_subscribe->setText(QCoreApplication::translate("TabWebSocket", "\350\256\242\351\230\205", nullptr));
        btn_publish->setText(QCoreApplication::translate("TabWebSocket", "\345\217\221\345\270\203", nullptr));
        groupBox_messages->setTitle(QCoreApplication::translate("TabWebSocket", "\346\266\210\346\201\257\346\227\245\345\277\227", nullptr));
        btn_clearLog->setText(QCoreApplication::translate("TabWebSocket", "\346\270\205\347\220\206\346\227\245\345\277\227", nullptr));
        (void)TabWebSocket;
    } // retranslateUi

};

namespace Ui {
    class TabWebSocket: public Ui_TabWebSocket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_WEBSOCKET_H
