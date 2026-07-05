/********************************************************************************
** Form generated from reading UI file 'DeployMaster.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPLOYMASTER_H
#define UI_DEPLOYMASTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "droplistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_DeployMaster
{
public:
    QAction *action_new;
    QAction *action_open;
    QAction *action_save;
    QAction *action_exit;
    QAction *action_start_deploy;
    QAction *action_stop_deploy;
    QAction *action_pause_deploy;
    QAction *action_about;
    QAction *action_clear_log;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_log;
    QSplitter *splitter_main;
    QTabWidget *tabWidget;
    QWidget *tab_deploy;
    QVBoxLayout *verticalLayout_deploy;
    QGroupBox *groupBox_upload;
    QVBoxLayout *verticalLayout_upload;
    QLabel *label_dragHint;
    DropListWidget *list_uploadedItems;
    QHBoxLayout *horizontalLayout_uploadBtns;
    QSpacerItem *horizontalSpacer_upload;
    QPushButton *btn_addFiles;
    QPushButton *btn_addFolders;
    QPushButton *btn_clearUploadList;
    QGroupBox *groupBox_ftp;
    QGridLayout *gridLayout_ftp;
    QLineEdit *txt_remotePath;
    QCheckBox *chk_rebootAfterDeploy;
    QLabel *label_remotePath;
    QCheckBox *chk_clearRemoteBeforeUpload;
    QHBoxLayout *horizontalLayout_deployBtns;
    QPushButton *btn_deploy;
    QPushButton *btn_clearLog;
    QSpacerItem *horizontalSpacer_deploy;
    QWidget *widget_rightPanel;
    QVBoxLayout *verticalLayout_rightPanel;
    QGroupBox *groupBox_remotePreview;
    QVBoxLayout *verticalLayout_remote;
    QComboBox *cmb_targetIPs;
    QPushButton *btn_refreshRemote;
    QGroupBox *groupBox_remoteFiles;
    QVBoxLayout *verticalLayout_tree;
    QTreeView *tree_remoteFiles;
    QGroupBox *groupBox_log;
    QVBoxLayout *verticalLayout_log;
    QTextEdit *txt_globalLog;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_deploy;
    QMenu *menu_help;

    void setupUi(QMainWindow *DeployMaster)
    {
        if (DeployMaster->objectName().isEmpty())
            DeployMaster->setObjectName("DeployMaster");
        DeployMaster->resize(1024, 600);
        action_new = new QAction(DeployMaster);
        action_new->setObjectName("action_new");
        action_open = new QAction(DeployMaster);
        action_open->setObjectName("action_open");
        action_save = new QAction(DeployMaster);
        action_save->setObjectName("action_save");
        action_exit = new QAction(DeployMaster);
        action_exit->setObjectName("action_exit");
        action_start_deploy = new QAction(DeployMaster);
        action_start_deploy->setObjectName("action_start_deploy");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-playback-start")));
        action_start_deploy->setIcon(icon);
        action_stop_deploy = new QAction(DeployMaster);
        action_stop_deploy->setObjectName("action_stop_deploy");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("media-playback-stop")));
        action_stop_deploy->setIcon(icon1);
        action_pause_deploy = new QAction(DeployMaster);
        action_pause_deploy->setObjectName("action_pause_deploy");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("media-playback-pause")));
        action_pause_deploy->setIcon(icon2);
        action_about = new QAction(DeployMaster);
        action_about->setObjectName("action_about");
        action_clear_log = new QAction(DeployMaster);
        action_clear_log->setObjectName("action_clear_log");
        centralwidget = new QWidget(DeployMaster);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(8, 4, 8, 8);
        splitter_log = new QSplitter(centralwidget);
        splitter_log->setObjectName("splitter_log");
        splitter_log->setOrientation(Qt::Orientation::Vertical);
        splitter_log->setHandleWidth(5);
        splitter_main = new QSplitter(splitter_log);
        splitter_main->setObjectName("splitter_main");
        splitter_main->setOrientation(Qt::Orientation::Horizontal);
        splitter_main->setHandleWidth(5);
        tabWidget = new QTabWidget(splitter_main);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tab_deploy = new QWidget();
        tab_deploy->setObjectName("tab_deploy");
        verticalLayout_deploy = new QVBoxLayout(tab_deploy);
        verticalLayout_deploy->setSpacing(6);
        verticalLayout_deploy->setObjectName("verticalLayout_deploy");
        verticalLayout_deploy->setContentsMargins(6, 6, 6, 6);
        groupBox_upload = new QGroupBox(tab_deploy);
        groupBox_upload->setObjectName("groupBox_upload");
        groupBox_upload->setAcceptDrops(true);
        groupBox_upload->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        verticalLayout_upload = new QVBoxLayout(groupBox_upload);
        verticalLayout_upload->setObjectName("verticalLayout_upload");
        label_dragHint = new QLabel(groupBox_upload);
        label_dragHint->setObjectName("label_dragHint");

        verticalLayout_upload->addWidget(label_dragHint);

        list_uploadedItems = new DropListWidget(groupBox_upload);
        list_uploadedItems->setObjectName("list_uploadedItems");
        list_uploadedItems->setMinimumSize(QSize(0, 60));
        list_uploadedItems->setAcceptDrops(true);
        list_uploadedItems->setDragDropMode(QAbstractItemView::DragDropMode::DropOnly);
        list_uploadedItems->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

        verticalLayout_upload->addWidget(list_uploadedItems);

        horizontalLayout_uploadBtns = new QHBoxLayout();
        horizontalLayout_uploadBtns->setObjectName("horizontalLayout_uploadBtns");
        horizontalSpacer_upload = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_uploadBtns->addItem(horizontalSpacer_upload);

        btn_addFiles = new QPushButton(groupBox_upload);
        btn_addFiles->setObjectName("btn_addFiles");
        btn_addFiles->setMinimumSize(QSize(90, 22));

        horizontalLayout_uploadBtns->addWidget(btn_addFiles);

        btn_addFolders = new QPushButton(groupBox_upload);
        btn_addFolders->setObjectName("btn_addFolders");
        btn_addFolders->setMinimumSize(QSize(90, 22));

        horizontalLayout_uploadBtns->addWidget(btn_addFolders);

        btn_clearUploadList = new QPushButton(groupBox_upload);
        btn_clearUploadList->setObjectName("btn_clearUploadList");
        btn_clearUploadList->setMinimumSize(QSize(60, 22));

        horizontalLayout_uploadBtns->addWidget(btn_clearUploadList);


        verticalLayout_upload->addLayout(horizontalLayout_uploadBtns);


        verticalLayout_deploy->addWidget(groupBox_upload);

        groupBox_ftp = new QGroupBox(tab_deploy);
        groupBox_ftp->setObjectName("groupBox_ftp");
        gridLayout_ftp = new QGridLayout(groupBox_ftp);
        gridLayout_ftp->setObjectName("gridLayout_ftp");
        txt_remotePath = new QLineEdit(groupBox_ftp);
        txt_remotePath->setObjectName("txt_remotePath");

        gridLayout_ftp->addWidget(txt_remotePath, 0, 1, 1, 2);

        chk_rebootAfterDeploy = new QCheckBox(groupBox_ftp);
        chk_rebootAfterDeploy->setObjectName("chk_rebootAfterDeploy");
        chk_rebootAfterDeploy->setChecked(false);

        gridLayout_ftp->addWidget(chk_rebootAfterDeploy, 0, 3, 1, 1);

        label_remotePath = new QLabel(groupBox_ftp);
        label_remotePath->setObjectName("label_remotePath");

        gridLayout_ftp->addWidget(label_remotePath, 0, 0, 1, 1);

        chk_clearRemoteBeforeUpload = new QCheckBox(groupBox_ftp);
        chk_clearRemoteBeforeUpload->setObjectName("chk_clearRemoteBeforeUpload");
        chk_clearRemoteBeforeUpload->setChecked(false);

        gridLayout_ftp->addWidget(chk_clearRemoteBeforeUpload, 0, 4, 1, 1);


        verticalLayout_deploy->addWidget(groupBox_ftp);

        horizontalLayout_deployBtns = new QHBoxLayout();
        horizontalLayout_deployBtns->setObjectName("horizontalLayout_deployBtns");
        btn_deploy = new QPushButton(tab_deploy);
        btn_deploy->setObjectName("btn_deploy");
        btn_deploy->setMinimumSize(QSize(100, 30));

        horizontalLayout_deployBtns->addWidget(btn_deploy);

        btn_clearLog = new QPushButton(tab_deploy);
        btn_clearLog->setObjectName("btn_clearLog");
        btn_clearLog->setMinimumSize(QSize(100, 30));

        horizontalLayout_deployBtns->addWidget(btn_clearLog);

        horizontalSpacer_deploy = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_deployBtns->addItem(horizontalSpacer_deploy);


        verticalLayout_deploy->addLayout(horizontalLayout_deployBtns);

        tabWidget->addTab(tab_deploy, QString());
        splitter_main->addWidget(tabWidget);
        widget_rightPanel = new QWidget(splitter_main);
        widget_rightPanel->setObjectName("widget_rightPanel");
        verticalLayout_rightPanel = new QVBoxLayout(widget_rightPanel);
        verticalLayout_rightPanel->setSpacing(6);
        verticalLayout_rightPanel->setObjectName("verticalLayout_rightPanel");
        verticalLayout_rightPanel->setContentsMargins(6, 6, 6, 6);
        groupBox_remotePreview = new QGroupBox(widget_rightPanel);
        groupBox_remotePreview->setObjectName("groupBox_remotePreview");
        verticalLayout_remote = new QVBoxLayout(groupBox_remotePreview);
        verticalLayout_remote->setObjectName("verticalLayout_remote");
        cmb_targetIPs = new QComboBox(groupBox_remotePreview);
        cmb_targetIPs->setObjectName("cmb_targetIPs");
        cmb_targetIPs->setMinimumSize(QSize(200, 0));

        verticalLayout_remote->addWidget(cmb_targetIPs);

        btn_refreshRemote = new QPushButton(groupBox_remotePreview);
        btn_refreshRemote->setObjectName("btn_refreshRemote");

        verticalLayout_remote->addWidget(btn_refreshRemote);

        groupBox_remoteFiles = new QGroupBox(groupBox_remotePreview);
        groupBox_remoteFiles->setObjectName("groupBox_remoteFiles");
        verticalLayout_tree = new QVBoxLayout(groupBox_remoteFiles);
        verticalLayout_tree->setObjectName("verticalLayout_tree");
        tree_remoteFiles = new QTreeView(groupBox_remoteFiles);
        tree_remoteFiles->setObjectName("tree_remoteFiles");
        tree_remoteFiles->setHeaderHidden(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tree_remoteFiles->sizePolicy().hasHeightForWidth());
        tree_remoteFiles->setSizePolicy(sizePolicy);

        verticalLayout_tree->addWidget(tree_remoteFiles);

        verticalLayout_tree->setStretch(0, 1);

        verticalLayout_remote->addWidget(groupBox_remoteFiles);

        verticalLayout_remote->setStretch(2, 1);

        verticalLayout_rightPanel->addWidget(groupBox_remotePreview);

        splitter_main->addWidget(widget_rightPanel);
        splitter_log->addWidget(splitter_main);
        groupBox_log = new QGroupBox(splitter_log);
        groupBox_log->setObjectName("groupBox_log");
        groupBox_log->setMinimumSize(QSize(0, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_log->sizePolicy().hasHeightForWidth());
        groupBox_log->setSizePolicy(sizePolicy1);
        verticalLayout_log = new QVBoxLayout(groupBox_log);
        verticalLayout_log->setObjectName("verticalLayout_log");
        txt_globalLog = new QTextEdit(groupBox_log);
        txt_globalLog->setObjectName("txt_globalLog");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(9);
        txt_globalLog->setFont(font);
        txt_globalLog->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
        txt_globalLog->setReadOnly(true);

        verticalLayout_log->addWidget(txt_globalLog);

        splitter_log->addWidget(groupBox_log);

        verticalLayout->addWidget(splitter_log);

        DeployMaster->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DeployMaster);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 916, 21));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName("menu_file");
        menu_deploy = new QMenu(menubar);
        menu_deploy->setObjectName("menu_deploy");
        menu_help = new QMenu(menubar);
        menu_help->setObjectName("menu_help");
        DeployMaster->setMenuBar(menubar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_deploy->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(action_new);
        menu_file->addAction(action_open);
        menu_file->addAction(action_save);
        menu_file->addSeparator();
        menu_file->addAction(action_exit);
        menu_deploy->addAction(action_start_deploy);
        menu_deploy->addAction(action_stop_deploy);
        menu_deploy->addAction(action_pause_deploy);
        menu_help->addAction(action_about);

        retranslateUi(DeployMaster);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DeployMaster);
    } // setupUi

    void retranslateUi(QMainWindow *DeployMaster)
    {
        DeployMaster->setWindowTitle(QCoreApplication::translate("DeployMaster", "DeployMaster - FTP & Telnet \346\211\271\351\207\217\350\277\220\347\273\264\345\267\245\345\205\267", nullptr));
        action_new->setText(QCoreApplication::translate("DeployMaster", "\346\226\260\345\273\272", nullptr));
        action_open->setText(QCoreApplication::translate("DeployMaster", "\346\211\223\345\274\200", nullptr));
        action_save->setText(QCoreApplication::translate("DeployMaster", "\344\277\235\345\255\230", nullptr));
        action_exit->setText(QCoreApplication::translate("DeployMaster", "\351\200\200\345\207\272", nullptr));
        action_start_deploy->setText(QCoreApplication::translate("DeployMaster", "\345\274\200\345\247\213\351\203\250\347\275\262", nullptr));
        action_stop_deploy->setText(QCoreApplication::translate("DeployMaster", "\345\201\234\346\255\242\351\203\250\347\275\262", nullptr));
        action_pause_deploy->setText(QCoreApplication::translate("DeployMaster", "\346\232\202\345\201\234\351\203\250\347\275\262", nullptr));
        action_about->setText(QCoreApplication::translate("DeployMaster", "\345\205\263\344\272\216", nullptr));
        action_clear_log->setText(QCoreApplication::translate("DeployMaster", "\346\270\205\351\231\244\346\227\245\345\277\227", nullptr));
        groupBox_upload->setTitle(QCoreApplication::translate("DeployMaster", "\344\270\212\344\274\240\345\206\205\345\256\271\357\274\210\346\224\257\346\214\201\346\213\226\346\213\275\357\274\211", nullptr));
        label_dragHint->setText(QCoreApplication::translate("DeployMaster", "\347\202\271\345\207\273\342\200\234\346\267\273\345\212\240\342\200\235\346\210\226\346\213\226\346\213\275\346\226\207\344\273\266/\346\226\207\344\273\266\345\244\271\345\210\260\350\277\231\351\207\214", nullptr));
        btn_addFiles->setText(QCoreApplication::translate("DeployMaster", "\346\267\273\345\212\240\346\226\207\344\273\266...", nullptr));
        btn_addFolders->setText(QCoreApplication::translate("DeployMaster", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271...", nullptr));
        btn_clearUploadList->setText(QCoreApplication::translate("DeployMaster", "\346\270\205\347\251\272", nullptr));
        groupBox_ftp->setTitle(QCoreApplication::translate("DeployMaster", "FTP \350\256\276\347\275\256", nullptr));
        txt_remotePath->setText(QCoreApplication::translate("DeployMaster", "/apps/m580cn/bin/", nullptr));
        chk_rebootAfterDeploy->setText(QCoreApplication::translate("DeployMaster", "\351\203\250\347\275\262\345\220\216\351\207\215\345\220\257\350\256\276\345\244\207", nullptr));
        label_remotePath->setText(QCoreApplication::translate("DeployMaster", "\350\277\234\347\250\213\350\267\257\345\276\204\357\274\232", nullptr));
        chk_clearRemoteBeforeUpload->setText(QCoreApplication::translate("DeployMaster", "\351\203\250\347\275\262\345\211\215\346\270\205\347\251\272\350\277\234\347\250\213\350\267\257\345\276\204", nullptr));
        btn_deploy->setText(QCoreApplication::translate("DeployMaster", "\345\274\200\345\247\213\351\203\250\347\275\262", nullptr));
        btn_clearLog->setText(QCoreApplication::translate("DeployMaster", "\346\270\205\351\231\244\346\227\245\345\277\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_deploy), QCoreApplication::translate("DeployMaster", "\346\211\271\351\207\217\351\203\250\347\275\262", nullptr));
        groupBox_remotePreview->setTitle(QCoreApplication::translate("DeployMaster", "\350\277\234\347\253\257\351\242\204\350\247\210", nullptr));
        btn_refreshRemote->setText(QCoreApplication::translate("DeployMaster", "\345\210\267\346\226\260", nullptr));
        groupBox_remoteFiles->setTitle(QCoreApplication::translate("DeployMaster", "\350\277\234\347\250\213\346\226\207\344\273\266", nullptr));
        groupBox_log->setTitle(QCoreApplication::translate("DeployMaster", "\347\273\274\345\220\210\346\227\245\345\277\227\350\276\223\345\207\272", nullptr));
        txt_globalLog->setPlainText(QCoreApplication::translate("DeployMaster", "[\346\227\245\345\277\227] \347\263\273\347\273\237\345\220\257\345\212\250\345\256\214\346\210\220\357\274\214\347\255\211\345\276\205\346\223\215\344\275\234...", nullptr));
        menu_file->setTitle(QCoreApplication::translate("DeployMaster", "\346\226\207\344\273\266", nullptr));
        menu_deploy->setTitle(QCoreApplication::translate("DeployMaster", "\351\203\250\347\275\262", nullptr));
        menu_help->setTitle(QCoreApplication::translate("DeployMaster", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeployMaster: public Ui_DeployMaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPLOYMASTER_H
