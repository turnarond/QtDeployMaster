/********************************************************************************
** Form generated from reading UI file 'tab_telnet.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_TELNET_H
#define UI_TAB_TELNET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabTelnetDeploy
{
public:
    QVBoxLayout *verticalLayout_telnet;
    QSplitter *splitter_telnetMain;
    QFrame *frame_telnetCmd;
    QVBoxLayout *verticalLayout_left;
    QGroupBox *groupBox_cmdTemplate;
    QHBoxLayout *horizontalLayout_template;
    QComboBox *cmb_cmdTemplates;
    QPushButton *btn_saveAsTemplate;
    QGroupBox *groupBox_commands;
    QVBoxLayout *verticalLayout_cmdEdit;
    QTextEdit *txt_telnetCommands;
    QGroupBox *groupBox_telnetOptions;
    QGridLayout *gridLayout_options;
    QLabel *label_timeout;
    QSpinBox *spin_timeout;
    QCheckBox *chk_skipOnFailure;
    QCheckBox *chk_showRawOutput;
    QFrame *frame_telnetResults;
    QVBoxLayout *verticalLayout_right;
    QGroupBox *groupBox_deviceStatus;
    QVBoxLayout *verticalLayout_tree;
    QTreeWidget *tree_telnetResults;
    QGroupBox *groupBox_outputDetail;
    QVBoxLayout *verticalLayout_detail;
    QTextEdit *txt_outputDetail;
    QHBoxLayout *horizontalLayout_detailBtns;
    QPushButton *btn_copyOutput;
    QPushButton *btn_saveOutput;
    QSpacerItem *horizontalSpacer_detail;
    QHBoxLayout *horizontalLayout_telnetActions;
    QPushButton *btn_executeTelnet;
    QPushButton *btn_stopTelnet;
    QPushButton *btn_exportAllResults;
    QSpacerItem *horizontalSpacer_telnet;

    void setupUi(QWidget *TabTelnetDeploy)
    {
        if (TabTelnetDeploy->objectName().isEmpty())
            TabTelnetDeploy->setObjectName("TabTelnetDeploy");
        TabTelnetDeploy->resize(784, 631);
        verticalLayout_telnet = new QVBoxLayout(TabTelnetDeploy);
        verticalLayout_telnet->setObjectName("verticalLayout_telnet");
        splitter_telnetMain = new QSplitter(TabTelnetDeploy);
        splitter_telnetMain->setObjectName("splitter_telnetMain");
        splitter_telnetMain->setOrientation(Qt::Orientation::Horizontal);
        frame_telnetCmd = new QFrame(splitter_telnetMain);
        frame_telnetCmd->setObjectName("frame_telnetCmd");
        verticalLayout_left = new QVBoxLayout(frame_telnetCmd);
        verticalLayout_left->setObjectName("verticalLayout_left");
        groupBox_cmdTemplate = new QGroupBox(frame_telnetCmd);
        groupBox_cmdTemplate->setObjectName("groupBox_cmdTemplate");
        horizontalLayout_template = new QHBoxLayout(groupBox_cmdTemplate);
        horizontalLayout_template->setObjectName("horizontalLayout_template");
        cmb_cmdTemplates = new QComboBox(groupBox_cmdTemplate);
        cmb_cmdTemplates->addItem(QString());
        cmb_cmdTemplates->addItem(QString());
        cmb_cmdTemplates->addItem(QString());
        cmb_cmdTemplates->setObjectName("cmb_cmdTemplates");
        cmb_cmdTemplates->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmb_cmdTemplates->sizePolicy().hasHeightForWidth());
        cmb_cmdTemplates->setSizePolicy(sizePolicy);

        horizontalLayout_template->addWidget(cmb_cmdTemplates);

        btn_saveAsTemplate = new QPushButton(groupBox_cmdTemplate);
        btn_saveAsTemplate->setObjectName("btn_saveAsTemplate");
        btn_saveAsTemplate->setEnabled(false);

        horizontalLayout_template->addWidget(btn_saveAsTemplate);


        verticalLayout_left->addWidget(groupBox_cmdTemplate);

        groupBox_commands = new QGroupBox(frame_telnetCmd);
        groupBox_commands->setObjectName("groupBox_commands");
        verticalLayout_cmdEdit = new QVBoxLayout(groupBox_commands);
        verticalLayout_cmdEdit->setObjectName("verticalLayout_cmdEdit");
        txt_telnetCommands = new QTextEdit(groupBox_commands);
        txt_telnetCommands->setObjectName("txt_telnetCommands");
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(10);
        txt_telnetCommands->setFont(font);

        verticalLayout_cmdEdit->addWidget(txt_telnetCommands);


        verticalLayout_left->addWidget(groupBox_commands);

        groupBox_telnetOptions = new QGroupBox(frame_telnetCmd);
        groupBox_telnetOptions->setObjectName("groupBox_telnetOptions");
        gridLayout_options = new QGridLayout(groupBox_telnetOptions);
        gridLayout_options->setObjectName("gridLayout_options");
        label_timeout = new QLabel(groupBox_telnetOptions);
        label_timeout->setObjectName("label_timeout");

        gridLayout_options->addWidget(label_timeout, 0, 0, 1, 1);

        spin_timeout = new QSpinBox(groupBox_telnetOptions);
        spin_timeout->setObjectName("spin_timeout");
        spin_timeout->setMinimum(5);
        spin_timeout->setMaximum(300);
        spin_timeout->setValue(30);

        gridLayout_options->addWidget(spin_timeout, 0, 1, 1, 1);

        chk_skipOnFailure = new QCheckBox(groupBox_telnetOptions);
        chk_skipOnFailure->setObjectName("chk_skipOnFailure");

        gridLayout_options->addWidget(chk_skipOnFailure, 1, 0, 1, 2);

        chk_showRawOutput = new QCheckBox(groupBox_telnetOptions);
        chk_showRawOutput->setObjectName("chk_showRawOutput");

        gridLayout_options->addWidget(chk_showRawOutput, 1, 2, 1, 2);


        verticalLayout_left->addWidget(groupBox_telnetOptions);

        splitter_telnetMain->addWidget(frame_telnetCmd);
        frame_telnetResults = new QFrame(splitter_telnetMain);
        frame_telnetResults->setObjectName("frame_telnetResults");
        verticalLayout_right = new QVBoxLayout(frame_telnetResults);
        verticalLayout_right->setObjectName("verticalLayout_right");
        groupBox_deviceStatus = new QGroupBox(frame_telnetResults);
        groupBox_deviceStatus->setObjectName("groupBox_deviceStatus");
        verticalLayout_tree = new QVBoxLayout(groupBox_deviceStatus);
        verticalLayout_tree->setObjectName("verticalLayout_tree");
        tree_telnetResults = new QTreeWidget(groupBox_deviceStatus);
        tree_telnetResults->setObjectName("tree_telnetResults");
        tree_telnetResults->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tree_telnetResults->setHeaderHidden(false);

        verticalLayout_tree->addWidget(tree_telnetResults);


        verticalLayout_right->addWidget(groupBox_deviceStatus);

        splitter_telnetMain->addWidget(frame_telnetResults);

        verticalLayout_telnet->addWidget(splitter_telnetMain);

        groupBox_outputDetail = new QGroupBox(TabTelnetDeploy);
        groupBox_outputDetail->setObjectName("groupBox_outputDetail");
        groupBox_outputDetail->setMaximumSize(QSize(16777215, 150));
        verticalLayout_detail = new QVBoxLayout(groupBox_outputDetail);
        verticalLayout_detail->setObjectName("verticalLayout_detail");
        txt_outputDetail = new QTextEdit(groupBox_outputDetail);
        txt_outputDetail->setObjectName("txt_outputDetail");
        txt_outputDetail->setFont(font);
        txt_outputDetail->setLineWrapMode(QTextEdit::LineWrapMode::NoWrap);
        txt_outputDetail->setReadOnly(true);

        verticalLayout_detail->addWidget(txt_outputDetail);

        horizontalLayout_detailBtns = new QHBoxLayout();
        horizontalLayout_detailBtns->setObjectName("horizontalLayout_detailBtns");
        btn_copyOutput = new QPushButton(groupBox_outputDetail);
        btn_copyOutput->setObjectName("btn_copyOutput");

        horizontalLayout_detailBtns->addWidget(btn_copyOutput);

        btn_saveOutput = new QPushButton(groupBox_outputDetail);
        btn_saveOutput->setObjectName("btn_saveOutput");

        horizontalLayout_detailBtns->addWidget(btn_saveOutput);

        horizontalSpacer_detail = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_detailBtns->addItem(horizontalSpacer_detail);


        verticalLayout_detail->addLayout(horizontalLayout_detailBtns);


        verticalLayout_telnet->addWidget(groupBox_outputDetail);

        horizontalLayout_telnetActions = new QHBoxLayout();
        horizontalLayout_telnetActions->setObjectName("horizontalLayout_telnetActions");
        btn_executeTelnet = new QPushButton(TabTelnetDeploy);
        btn_executeTelnet->setObjectName("btn_executeTelnet");
        btn_executeTelnet->setMinimumSize(QSize(100, 30));
        btn_executeTelnet->setStyleSheet(QString::fromUtf8("background-color: #2196F3; color: white; font-weight: bold;"));

        horizontalLayout_telnetActions->addWidget(btn_executeTelnet);

        btn_stopTelnet = new QPushButton(TabTelnetDeploy);
        btn_stopTelnet->setObjectName("btn_stopTelnet");
        btn_stopTelnet->setEnabled(false);

        horizontalLayout_telnetActions->addWidget(btn_stopTelnet);

        btn_exportAllResults = new QPushButton(TabTelnetDeploy);
        btn_exportAllResults->setObjectName("btn_exportAllResults");

        horizontalLayout_telnetActions->addWidget(btn_exportAllResults);

        horizontalSpacer_telnet = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_telnetActions->addItem(horizontalSpacer_telnet);


        verticalLayout_telnet->addLayout(horizontalLayout_telnetActions);


        retranslateUi(TabTelnetDeploy);

        QMetaObject::connectSlotsByName(TabTelnetDeploy);
    } // setupUi

    void retranslateUi(QWidget *TabTelnetDeploy)
    {
        groupBox_cmdTemplate->setTitle(QCoreApplication::translate("TabTelnetDeploy", "\345\221\275\344\273\244\346\250\241\346\235\277\357\274\210\345\217\257\351\200\211\357\274\211", nullptr));
        cmb_cmdTemplates->setItemText(0, QCoreApplication::translate("TabTelnetDeploy", "\350\207\252\345\256\232\344\271\211", nullptr));
        cmb_cmdTemplates->setItemText(1, QCoreApplication::translate("TabTelnetDeploy", "\346\237\245\347\234\213\347\263\273\347\273\237\344\277\241\346\201\257 (uname -a; df -h)", nullptr));
        cmb_cmdTemplates->setItemText(2, QCoreApplication::translate("TabTelnetDeploy", "\346\243\200\346\237\245\350\277\233\347\250\213 (ps aux | grep m580)", nullptr));

        btn_saveAsTemplate->setText(QCoreApplication::translate("TabTelnetDeploy", "\344\277\235\345\255\230\344\270\272\346\250\241\346\235\277", nullptr));
        groupBox_commands->setTitle(QCoreApplication::translate("TabTelnetDeploy", "\350\246\201\346\211\247\350\241\214\347\232\204\345\221\275\344\273\244\357\274\210\346\257\217\350\241\214\344\270\200\346\235\241\357\274\211", nullptr));
        txt_telnetCommands->setPlainText(QCoreApplication::translate("TabTelnetDeploy", "echo \"=== \345\274\200\345\247\213\346\211\247\350\241\214\344\272\216 {ip} ===\"\n"
"cd /apps/m580cn/bin/\n"
"./status.sh\n"
"free -m", nullptr));
        groupBox_telnetOptions->setTitle(QCoreApplication::translate("TabTelnetDeploy", "\346\211\247\350\241\214\351\200\211\351\241\271", nullptr));
        label_timeout->setText(QCoreApplication::translate("TabTelnetDeploy", "\345\221\275\344\273\244\350\266\205\346\227\266\357\274\210\347\247\222\357\274\211\357\274\232", nullptr));
        chk_skipOnFailure->setText(QCoreApplication::translate("TabTelnetDeploy", "\346\237\220\350\256\276\345\244\207\345\244\261\350\264\245\346\227\266\347\273\247\347\273\255\346\211\247\350\241\214\345\205\266\344\273\226\350\256\276\345\244\207", nullptr));
        chk_showRawOutput->setText(QCoreApplication::translate("TabTelnetDeploy", "\346\230\276\347\244\272\345\216\237\345\247\213 Telnet \344\272\244\344\272\222\357\274\210\345\220\253\347\231\273\345\275\225\350\277\207\347\250\213\357\274\211", nullptr));
        groupBox_deviceStatus->setTitle(QCoreApplication::translate("TabTelnetDeploy", "\350\256\276\345\244\207\346\211\247\350\241\214\347\212\266\346\200\201\357\274\210\345\217\214\345\207\273\346\237\245\347\234\213\350\257\246\346\203\205\357\274\211", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree_telnetResults->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("TabTelnetDeploy", "\350\277\224\345\233\236\347\240\201/\351\224\231\350\257\257", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("TabTelnetDeploy", "\350\200\227\346\227\266 (ms)", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("TabTelnetDeploy", "\347\212\266\346\200\201", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("TabTelnetDeploy", "IP \345\234\260\345\235\200", nullptr));
        groupBox_outputDetail->setTitle(QCoreApplication::translate("TabTelnetDeploy", "\345\221\275\344\273\244\350\276\223\345\207\272\350\257\246\346\203\205\357\274\210\346\235\245\350\207\252\357\274\232192.168.2.124\357\274\211", nullptr));
        btn_copyOutput->setText(QCoreApplication::translate("TabTelnetDeploy", "\345\244\215\345\210\266\350\276\223\345\207\272", nullptr));
        btn_saveOutput->setText(QCoreApplication::translate("TabTelnetDeploy", "\344\277\235\345\255\230\345\210\260\346\226\207\344\273\266", nullptr));
        btn_executeTelnet->setText(QCoreApplication::translate("TabTelnetDeploy", "\342\226\266 \346\211\247\350\241\214\345\221\275\344\273\244", nullptr));
        btn_stopTelnet->setText(QCoreApplication::translate("TabTelnetDeploy", "\342\226\240 \345\201\234\346\255\242", nullptr));
        btn_exportAllResults->setText(QCoreApplication::translate("TabTelnetDeploy", "\345\257\274\345\207\272\345\205\250\351\203\250\347\273\223\346\236\234", nullptr));
        (void)TabTelnetDeploy;
    } // retranslateUi

};

namespace Ui {
    class TabTelnetDeploy: public Ui_TabTelnetDeploy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_TELNET_H
