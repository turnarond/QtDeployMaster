/********************************************************************************
** Form generated from reading UI file 'tab_modbus_cluster_test.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_MODBUS_CLUSTER_TEST_H
#define UI_TAB_MODBUS_CLUSTER_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabModbusCluster
{
public:
    QHBoxLayout *mainLayout;
    QTableWidget *table_registerMatrix;
    QVBoxLayout *rightPanelLayout;
    QGroupBox *groupBox_config;
    QGridLayout *gridLayout_config;
    QLabel *label_port;
    QLineEdit *lineEdit_port;
    QLabel *label_slaveId;
    QLineEdit *lineEdit_slaveId;
    QLabel *label_startAddr;
    QSpinBox *spin_startAddr;
    QLabel *label_length;
    QSpinBox *spin_length;
    QHBoxLayout *hLayout_regType;
    QLabel *label_regType;
    QComboBox *cmb_regType;
    QGroupBox *groupBox_control;
    QVBoxLayout *verticalLayout_control;
    QPushButton *btn_readAll;
    QHBoxLayout *hLayout_refreshRow;
    QPushButton *btn_startAutoRefresh;
    QSpinBox *spin_refreshInterval;
    QSpacerItem *horizontalSpacer_refresh;
    QPushButton *btn_writeSelected;
    QSpacerItem *verticalSpacer_control;
    QLabel *label_duration;
    QGroupBox *groupBox_writeOptions;
    QVBoxLayout *verticalLayout_writeOptions;
    QRadioButton *radio_writeSingleValue;
    QSpinBox *spin_singleValue;
    QRadioButton *radio_writeRandomValues;
    QRadioButton *radio_writeSpecificValues;
    QLabel *label_selectDevices;
    QPushButton *btn_updateDeviceList;
    QSpacerItem *verticalSpacer_rightBottom;
    QListWidget *list_selectedDevices;

    void setupUi(QWidget *TabModbusCluster)
    {
        if (TabModbusCluster->objectName().isEmpty())
            TabModbusCluster->setObjectName("TabModbusCluster");
        TabModbusCluster->resize(960, 620);
        mainLayout = new QHBoxLayout(TabModbusCluster);
        mainLayout->setSpacing(6);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(6, 6, 6, 6);
        table_registerMatrix = new QTableWidget(TabModbusCluster);
        if (table_registerMatrix->columnCount() < 4)
            table_registerMatrix->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_registerMatrix->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_registerMatrix->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_registerMatrix->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_registerMatrix->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (table_registerMatrix->rowCount() < 10)
            table_registerMatrix->setRowCount(10);
        table_registerMatrix->setObjectName("table_registerMatrix");
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        font.setPointSize(10);
        table_registerMatrix->setFont(font);
        table_registerMatrix->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::SelectedClicked);
        table_registerMatrix->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
        table_registerMatrix->setRowCount(10);
        table_registerMatrix->setColumnCount(4);

        mainLayout->addWidget(table_registerMatrix);

        rightPanelLayout = new QVBoxLayout();
        rightPanelLayout->setSpacing(6);
        rightPanelLayout->setObjectName("rightPanelLayout");
        groupBox_config = new QGroupBox(TabModbusCluster);
        groupBox_config->setObjectName("groupBox_config");
        gridLayout_config = new QGridLayout(groupBox_config);
        gridLayout_config->setObjectName("gridLayout_config");
        label_port = new QLabel(groupBox_config);
        label_port->setObjectName("label_port");

        gridLayout_config->addWidget(label_port, 0, 0, 1, 1);

        lineEdit_port = new QLineEdit(groupBox_config);
        lineEdit_port->setObjectName("lineEdit_port");
        lineEdit_port->setMaxLength(5);

        gridLayout_config->addWidget(lineEdit_port, 0, 1, 1, 1);

        label_slaveId = new QLabel(groupBox_config);
        label_slaveId->setObjectName("label_slaveId");

        gridLayout_config->addWidget(label_slaveId, 0, 2, 1, 1);

        lineEdit_slaveId = new QLineEdit(groupBox_config);
        lineEdit_slaveId->setObjectName("lineEdit_slaveId");
        lineEdit_slaveId->setMaxLength(3);

        gridLayout_config->addWidget(lineEdit_slaveId, 0, 3, 1, 1);

        label_startAddr = new QLabel(groupBox_config);
        label_startAddr->setObjectName("label_startAddr");

        gridLayout_config->addWidget(label_startAddr, 1, 0, 1, 1);

        spin_startAddr = new QSpinBox(groupBox_config);
        spin_startAddr->setObjectName("spin_startAddr");
        spin_startAddr->setMinimum(0);
        spin_startAddr->setMaximum(65535);
        spin_startAddr->setValue(1000);

        gridLayout_config->addWidget(spin_startAddr, 1, 1, 1, 1);

        label_length = new QLabel(groupBox_config);
        label_length->setObjectName("label_length");

        gridLayout_config->addWidget(label_length, 1, 2, 1, 1);

        spin_length = new QSpinBox(groupBox_config);
        spin_length->setObjectName("spin_length");
        spin_length->setMinimum(1);
        spin_length->setMaximum(125);
        spin_length->setValue(10);

        gridLayout_config->addWidget(spin_length, 1, 3, 1, 1);

        hLayout_regType = new QHBoxLayout();
        hLayout_regType->setObjectName("hLayout_regType");
        label_regType = new QLabel(groupBox_config);
        label_regType->setObjectName("label_regType");

        hLayout_regType->addWidget(label_regType);

        cmb_regType = new QComboBox(groupBox_config);
        cmb_regType->addItem(QString());
        cmb_regType->addItem(QString());
        cmb_regType->setObjectName("cmb_regType");

        hLayout_regType->addWidget(cmb_regType);


        gridLayout_config->addLayout(hLayout_regType, 2, 0, 1, 4);


        rightPanelLayout->addWidget(groupBox_config);

        groupBox_control = new QGroupBox(TabModbusCluster);
        groupBox_control->setObjectName("groupBox_control");
        verticalLayout_control = new QVBoxLayout(groupBox_control);
        verticalLayout_control->setObjectName("verticalLayout_control");
        btn_readAll = new QPushButton(groupBox_control);
        btn_readAll->setObjectName("btn_readAll");
        btn_readAll->setStyleSheet(QString::fromUtf8("background-color: #2196F3; color: white;"));

        verticalLayout_control->addWidget(btn_readAll);

        hLayout_refreshRow = new QHBoxLayout();
        hLayout_refreshRow->setObjectName("hLayout_refreshRow");
        btn_startAutoRefresh = new QPushButton(groupBox_control);
        btn_startAutoRefresh->setObjectName("btn_startAutoRefresh");
        btn_startAutoRefresh->setCheckable(true);

        hLayout_refreshRow->addWidget(btn_startAutoRefresh);

        spin_refreshInterval = new QSpinBox(groupBox_control);
        spin_refreshInterval->setObjectName("spin_refreshInterval");
        spin_refreshInterval->setMinimum(1);
        spin_refreshInterval->setMaximum(60);
        spin_refreshInterval->setValue(5);

        hLayout_refreshRow->addWidget(spin_refreshInterval);

        horizontalSpacer_refresh = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayout_refreshRow->addItem(horizontalSpacer_refresh);


        verticalLayout_control->addLayout(hLayout_refreshRow);

        btn_writeSelected = new QPushButton(groupBox_control);
        btn_writeSelected->setObjectName("btn_writeSelected");
        btn_writeSelected->setStyleSheet(QString::fromUtf8("background-color: #FF9800; color: white;"));

        verticalLayout_control->addWidget(btn_writeSelected);

        verticalSpacer_control = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_control->addItem(verticalSpacer_control);

        label_duration = new QLabel(groupBox_control);
        label_duration->setObjectName("label_duration");
        label_duration->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_duration->setWordWrap(true);

        verticalLayout_control->addWidget(label_duration);


        rightPanelLayout->addWidget(groupBox_control);

        groupBox_writeOptions = new QGroupBox(TabModbusCluster);
        groupBox_writeOptions->setObjectName("groupBox_writeOptions");
        verticalLayout_writeOptions = new QVBoxLayout(groupBox_writeOptions);
        verticalLayout_writeOptions->setObjectName("verticalLayout_writeOptions");
        radio_writeSingleValue = new QRadioButton(groupBox_writeOptions);
        radio_writeSingleValue->setObjectName("radio_writeSingleValue");

        verticalLayout_writeOptions->addWidget(radio_writeSingleValue);

        spin_singleValue = new QSpinBox(groupBox_writeOptions);
        spin_singleValue->setObjectName("spin_singleValue");
        spin_singleValue->setMinimum(0);
        spin_singleValue->setMaximum(65535);
        spin_singleValue->setValue(100);

        verticalLayout_writeOptions->addWidget(spin_singleValue);

        radio_writeRandomValues = new QRadioButton(groupBox_writeOptions);
        radio_writeRandomValues->setObjectName("radio_writeRandomValues");

        verticalLayout_writeOptions->addWidget(radio_writeRandomValues);

        radio_writeSpecificValues = new QRadioButton(groupBox_writeOptions);
        radio_writeSpecificValues->setObjectName("radio_writeSpecificValues");

        verticalLayout_writeOptions->addWidget(radio_writeSpecificValues);

        label_selectDevices = new QLabel(groupBox_writeOptions);
        label_selectDevices->setObjectName("label_selectDevices");

        verticalLayout_writeOptions->addWidget(label_selectDevices);

        btn_updateDeviceList = new QPushButton(groupBox_writeOptions);
        btn_updateDeviceList->setObjectName("btn_updateDeviceList");

        verticalLayout_writeOptions->addWidget(btn_updateDeviceList);


        rightPanelLayout->addWidget(groupBox_writeOptions);

        verticalSpacer_rightBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        rightPanelLayout->addItem(verticalSpacer_rightBottom);

        list_selectedDevices = new QListWidget(TabModbusCluster);
        list_selectedDevices->setObjectName("list_selectedDevices");
        list_selectedDevices->setMinimumSize(QSize(0, 80));
        list_selectedDevices->setMaximumSize(QSize(16777215, 16777215));
        list_selectedDevices->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);

        rightPanelLayout->addWidget(list_selectedDevices);


        mainLayout->addLayout(rightPanelLayout);

        mainLayout->setStretch(0, 3);
        mainLayout->setStretch(1, 1);

        retranslateUi(TabModbusCluster);

        QMetaObject::connectSlotsByName(TabModbusCluster);
    } // setupUi

    void retranslateUi(QWidget *TabModbusCluster)
    {
        TabModbusCluster->setWindowTitle(QCoreApplication::translate("TabModbusCluster", "Modbus \346\211\271\351\207\217\345\220\214\346\255\245\346\265\213\350\257\225\345\267\245\345\205\267", nullptr));
        mainLayout->setProperty("layoutStretch", QVariant(QCoreApplication::translate("TabModbusCluster", "2,1", nullptr)));
        QTableWidgetItem *___qtablewidgetitem = table_registerMatrix->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TabModbusCluster", "\350\257\273\345\217\226\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_registerMatrix->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TabModbusCluster", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_registerMatrix->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TabModbusCluster", "\345\276\205\345\206\231\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_registerMatrix->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TabModbusCluster", "\350\256\276\345\244\207A", nullptr));
        groupBox_config->setTitle(QCoreApplication::translate("TabModbusCluster", "\351\205\215\347\275\256", nullptr));
        label_port->setText(QCoreApplication::translate("TabModbusCluster", "Modbus \347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_port->setText(QCoreApplication::translate("TabModbusCluster", "502", nullptr));
        lineEdit_port->setPlaceholderText(QCoreApplication::translate("TabModbusCluster", "502", nullptr));
        label_slaveId->setText(QCoreApplication::translate("TabModbusCluster", "\344\273\216\347\253\231 ID\357\274\232", nullptr));
        lineEdit_slaveId->setText(QCoreApplication::translate("TabModbusCluster", "1", nullptr));
        lineEdit_slaveId->setPlaceholderText(QCoreApplication::translate("TabModbusCluster", "1~247", nullptr));
        label_startAddr->setText(QCoreApplication::translate("TabModbusCluster", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_length->setText(QCoreApplication::translate("TabModbusCluster", "\351\225\277\345\272\246\357\274\210\346\225\260\351\207\217\357\274\211\357\274\232", nullptr));
        label_regType->setText(QCoreApplication::translate("TabModbusCluster", "\345\257\204\345\255\230\345\231\250\347\261\273\345\236\213\357\274\232", nullptr));
        cmb_regType->setItemText(0, QCoreApplication::translate("TabModbusCluster", "\344\277\235\346\214\201\345\257\204\345\255\230\345\231\250 (Holding Registers, 4x)", nullptr));
        cmb_regType->setItemText(1, QCoreApplication::translate("TabModbusCluster", "\347\272\277\345\234\210 (Coils, 0x)", nullptr));

        groupBox_control->setTitle(QCoreApplication::translate("TabModbusCluster", "\346\223\215\344\275\234", nullptr));
        btn_readAll->setText(QCoreApplication::translate("TabModbusCluster", "\342\226\266 \350\257\273\345\217\226\345\271\266\345\257\271\346\257\224", nullptr));
        btn_startAutoRefresh->setText(QCoreApplication::translate("TabModbusCluster", "\360\237\224\201 \345\256\232\346\227\266\345\210\267\346\226\260\357\274\210\345\205\263\351\227\255\357\274\211", nullptr));
        spin_refreshInterval->setSuffix(QCoreApplication::translate("TabModbusCluster", " \347\247\222", nullptr));
        btn_writeSelected->setText(QCoreApplication::translate("TabModbusCluster", "\360\237\224\245 \345\206\231\345\205\245\351\200\211\345\256\232\350\256\276\345\244\207", nullptr));
        label_duration->setText(QCoreApplication::translate("TabModbusCluster", "\342\217\261\357\270\217 \350\256\276\345\244\207\346\223\215\344\275\234\350\200\227\346\227\266:", nullptr));
        groupBox_writeOptions->setTitle(QCoreApplication::translate("TabModbusCluster", "\345\206\231\345\205\245\351\200\211\351\241\271", nullptr));
        radio_writeSingleValue->setText(QCoreApplication::translate("TabModbusCluster", "\345\220\221\351\200\211\345\256\232\350\256\276\345\244\207\347\232\204\346\211\200\346\234\211\345\257\204\345\255\230\345\231\250\345\206\231\345\205\245\347\233\270\345\220\214\345\200\274", nullptr));
        radio_writeRandomValues->setText(QCoreApplication::translate("TabModbusCluster", "\345\220\221\351\200\211\345\256\232\350\256\276\345\244\207\347\232\204\346\211\200\346\234\211\345\257\204\345\255\230\345\231\250\345\206\231\345\205\245\351\232\217\346\234\272\345\200\274", nullptr));
        radio_writeSpecificValues->setText(QCoreApplication::translate("TabModbusCluster", "\346\214\211\350\241\250\346\240\274\344\270\255\347\232\204\345\276\205\345\206\231\345\200\274\345\206\231\345\205\245", nullptr));
        label_selectDevices->setText(QCoreApplication::translate("TabModbusCluster", "\351\200\211\346\213\251\350\246\201\345\206\231\345\205\245\347\232\204\350\256\276\345\244\207\357\274\232", nullptr));
        btn_updateDeviceList->setText(QCoreApplication::translate("TabModbusCluster", "\346\233\264\346\226\260\350\256\276\345\244\207\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TabModbusCluster: public Ui_TabModbusCluster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_MODBUS_CLUSTER_TEST_H
