/********************************************************************************
** Form generated from reading UI file 'tab_opcua_client.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_OPCUA_CLIENT_H
#define UI_TAB_OPCUA_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabOpcUaClient
{
public:
    QHBoxLayout *mainLayout;
    QTableWidget *table_nodes;
    QVBoxLayout *rightPanelLayout;
    QGroupBox *groupBox_config;
    QGridLayout *gridLayout_config;
    QLabel *label_endpoint;
    QLineEdit *lineEdit_endpoint;
    QLabel *label_timeout;
    QSpinBox *spin_timeout;
    QGroupBox *groupBox_control;
    QVBoxLayout *verticalLayout_control;
    QPushButton *btn_connect;
    QPushButton *btn_browse;
    QPushButton *btn_readValue;
    QPushButton *btn_writeValue;
    QPushButton *btn_subscribe;
    QListWidget *list_endpoints;
    QTextEdit *txt_localLog;

    void setupUi(QWidget *TabOpcUaClient)
    {
        if (TabOpcUaClient->objectName().isEmpty())
            TabOpcUaClient->setObjectName("TabOpcUaClient");
        TabOpcUaClient->resize(960, 620);
        mainLayout = new QHBoxLayout(TabOpcUaClient);
        mainLayout->setObjectName("mainLayout");
        table_nodes = new QTableWidget(TabOpcUaClient);
        if (table_nodes->columnCount() < 3)
            table_nodes->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_nodes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_nodes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_nodes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table_nodes->setObjectName("table_nodes");
        table_nodes->setColumnCount(3);

        mainLayout->addWidget(table_nodes);

        rightPanelLayout = new QVBoxLayout();
        rightPanelLayout->setObjectName("rightPanelLayout");
        groupBox_config = new QGroupBox(TabOpcUaClient);
        groupBox_config->setObjectName("groupBox_config");
        gridLayout_config = new QGridLayout(groupBox_config);
        gridLayout_config->setObjectName("gridLayout_config");
        label_endpoint = new QLabel(groupBox_config);
        label_endpoint->setObjectName("label_endpoint");

        gridLayout_config->addWidget(label_endpoint, 0, 0, 1, 1);

        lineEdit_endpoint = new QLineEdit(groupBox_config);
        lineEdit_endpoint->setObjectName("lineEdit_endpoint");

        gridLayout_config->addWidget(lineEdit_endpoint, 0, 1, 1, 1);

        label_timeout = new QLabel(groupBox_config);
        label_timeout->setObjectName("label_timeout");

        gridLayout_config->addWidget(label_timeout, 1, 0, 1, 1);

        spin_timeout = new QSpinBox(groupBox_config);
        spin_timeout->setObjectName("spin_timeout");
        spin_timeout->setMinimum(100);
        spin_timeout->setMaximum(60000);
        spin_timeout->setValue(5000);

        gridLayout_config->addWidget(spin_timeout, 1, 1, 1, 1);


        rightPanelLayout->addWidget(groupBox_config);

        groupBox_control = new QGroupBox(TabOpcUaClient);
        groupBox_control->setObjectName("groupBox_control");
        verticalLayout_control = new QVBoxLayout(groupBox_control);
        verticalLayout_control->setObjectName("verticalLayout_control");
        btn_connect = new QPushButton(groupBox_control);
        btn_connect->setObjectName("btn_connect");

        verticalLayout_control->addWidget(btn_connect);

        btn_browse = new QPushButton(groupBox_control);
        btn_browse->setObjectName("btn_browse");

        verticalLayout_control->addWidget(btn_browse);

        btn_readValue = new QPushButton(groupBox_control);
        btn_readValue->setObjectName("btn_readValue");

        verticalLayout_control->addWidget(btn_readValue);

        btn_writeValue = new QPushButton(groupBox_control);
        btn_writeValue->setObjectName("btn_writeValue");

        verticalLayout_control->addWidget(btn_writeValue);

        btn_subscribe = new QPushButton(groupBox_control);
        btn_subscribe->setObjectName("btn_subscribe");

        verticalLayout_control->addWidget(btn_subscribe);


        rightPanelLayout->addWidget(groupBox_control);

        list_endpoints = new QListWidget(TabOpcUaClient);
        list_endpoints->setObjectName("list_endpoints");
        list_endpoints->setMinimumHeight(80);

        rightPanelLayout->addWidget(list_endpoints);

        txt_localLog = new QTextEdit(TabOpcUaClient);
        txt_localLog->setObjectName("txt_localLog");
        txt_localLog->setReadOnly(true);
        txt_localLog->setMinimumHeight(160);

        rightPanelLayout->addWidget(txt_localLog);


        mainLayout->addLayout(rightPanelLayout);


        retranslateUi(TabOpcUaClient);

        QMetaObject::connectSlotsByName(TabOpcUaClient);
    } // setupUi

    void retranslateUi(QWidget *TabOpcUaClient)
    {
        QTableWidgetItem *___qtablewidgetitem = table_nodes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TabOpcUaClient", "NodeId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_nodes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TabOpcUaClient", "BrowseName", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_nodes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TabOpcUaClient", "Value", nullptr));
        groupBox_config->setTitle(QCoreApplication::translate("TabOpcUaClient", "Configuration", nullptr));
        label_endpoint->setText(QCoreApplication::translate("TabOpcUaClient", "Endpoint:", nullptr));
        lineEdit_endpoint->setText(QCoreApplication::translate("TabOpcUaClient", "opc.tcp://localhost:4840", nullptr));
        label_timeout->setText(QCoreApplication::translate("TabOpcUaClient", "Timeout(ms):", nullptr));
        groupBox_control->setTitle(QCoreApplication::translate("TabOpcUaClient", "Actions", nullptr));
        btn_connect->setText(QCoreApplication::translate("TabOpcUaClient", "Connect/Disconnect", nullptr));
        btn_browse->setText(QCoreApplication::translate("TabOpcUaClient", "Browse Nodes", nullptr));
        btn_readValue->setText(QCoreApplication::translate("TabOpcUaClient", "Read Value", nullptr));
        btn_writeValue->setText(QCoreApplication::translate("TabOpcUaClient", "Write Value", nullptr));
        btn_subscribe->setText(QCoreApplication::translate("TabOpcUaClient", "Subscribe/Unsubscribe", nullptr));
        (void)TabOpcUaClient;
    } // retranslateUi

};

namespace Ui {
    class TabOpcUaClient: public Ui_TabOpcUaClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_OPCUA_CLIENT_H
