/********************************************************************************
** Form generated from reading UI file 'tab_logquery.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_LOGQUERY_H
#define UI_TAB_LOGQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabLogQuery
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_filters;
    QFormLayout *formLayout_filters;
    QLabel *label_logPath;
    QLineEdit *txt_logPath;
    QLabel *label_keyword;
    QLineEdit *txt_keyword;
    QLabel *label_timeRange;
    QHBoxLayout *horizontalLayout_time;
    QDateTimeEdit *dt_start;
    QLabel *label_to;
    QDateTimeEdit *dt_end;
    QGroupBox *groupBox_preview;
    QVBoxLayout *verticalLayout_preview;
    QTreeWidget *tree_logResults;
    QHBoxLayout *horizontalLayout_actions;
    QPushButton *btn_queryLogs;
    QPushButton *btn_downloadSelected;
    QPushButton *btn_downloadAll;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *TabLogQuery)
    {
        if (TabLogQuery->objectName().isEmpty())
            TabLogQuery->setObjectName("TabLogQuery");
        TabLogQuery->resize(880, 600);
        gridLayout = new QGridLayout(TabLogQuery);
        gridLayout->setObjectName("gridLayout");
        groupBox_filters = new QGroupBox(TabLogQuery);
        groupBox_filters->setObjectName("groupBox_filters");
        formLayout_filters = new QFormLayout(groupBox_filters);
        formLayout_filters->setObjectName("formLayout_filters");
        label_logPath = new QLabel(groupBox_filters);
        label_logPath->setObjectName("label_logPath");

        formLayout_filters->setWidget(0, QFormLayout::ItemRole::LabelRole, label_logPath);

        txt_logPath = new QLineEdit(groupBox_filters);
        txt_logPath->setObjectName("txt_logPath");

        formLayout_filters->setWidget(0, QFormLayout::ItemRole::FieldRole, txt_logPath);

        label_keyword = new QLabel(groupBox_filters);
        label_keyword->setObjectName("label_keyword");

        formLayout_filters->setWidget(1, QFormLayout::ItemRole::LabelRole, label_keyword);

        txt_keyword = new QLineEdit(groupBox_filters);
        txt_keyword->setObjectName("txt_keyword");
        txt_keyword->setReadOnly(true);

        formLayout_filters->setWidget(1, QFormLayout::ItemRole::FieldRole, txt_keyword);

        label_timeRange = new QLabel(groupBox_filters);
        label_timeRange->setObjectName("label_timeRange");

        formLayout_filters->setWidget(2, QFormLayout::ItemRole::LabelRole, label_timeRange);

        horizontalLayout_time = new QHBoxLayout();
        horizontalLayout_time->setObjectName("horizontalLayout_time");
        dt_start = new QDateTimeEdit(groupBox_filters);
        dt_start->setObjectName("dt_start");
        dt_start->setCalendarPopup(true);

        horizontalLayout_time->addWidget(dt_start);

        label_to = new QLabel(groupBox_filters);
        label_to->setObjectName("label_to");

        horizontalLayout_time->addWidget(label_to);

        dt_end = new QDateTimeEdit(groupBox_filters);
        dt_end->setObjectName("dt_end");
        dt_end->setCalendarPopup(true);

        horizontalLayout_time->addWidget(dt_end);


        formLayout_filters->setLayout(2, QFormLayout::ItemRole::FieldRole, horizontalLayout_time);


        gridLayout->addWidget(groupBox_filters, 0, 1, 1, 1);

        groupBox_preview = new QGroupBox(TabLogQuery);
        groupBox_preview->setObjectName("groupBox_preview");
        verticalLayout_preview = new QVBoxLayout(groupBox_preview);
        verticalLayout_preview->setObjectName("verticalLayout_preview");
        tree_logResults = new QTreeWidget(groupBox_preview);
        tree_logResults->setObjectName("tree_logResults");
        tree_logResults->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        tree_logResults->setHeaderHidden(false);

        verticalLayout_preview->addWidget(tree_logResults);


        gridLayout->addWidget(groupBox_preview, 1, 0, 1, 2);

        horizontalLayout_actions = new QHBoxLayout();
        horizontalLayout_actions->setObjectName("horizontalLayout_actions");
        btn_queryLogs = new QPushButton(TabLogQuery);
        btn_queryLogs->setObjectName("btn_queryLogs");
        btn_queryLogs->setMinimumSize(QSize(100, 30));
        btn_queryLogs->setStyleSheet(QString::fromUtf8("background-color: #FF9800; color: white; font-weight: bold;"));

        horizontalLayout_actions->addWidget(btn_queryLogs);

        btn_downloadSelected = new QPushButton(TabLogQuery);
        btn_downloadSelected->setObjectName("btn_downloadSelected");
        btn_downloadSelected->setMinimumSize(QSize(120, 30));

        horizontalLayout_actions->addWidget(btn_downloadSelected);

        btn_downloadAll = new QPushButton(TabLogQuery);
        btn_downloadAll->setObjectName("btn_downloadAll");
        btn_downloadAll->setMinimumSize(QSize(120, 30));

        horizontalLayout_actions->addWidget(btn_downloadAll);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_actions->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_actions, 3, 0, 1, 2);


        retranslateUi(TabLogQuery);

        QMetaObject::connectSlotsByName(TabLogQuery);
    } // setupUi

    void retranslateUi(QWidget *TabLogQuery)
    {
        groupBox_filters->setTitle(QCoreApplication::translate("TabLogQuery", "\346\237\245\350\257\242\346\235\241\344\273\266", nullptr));
        label_logPath->setText(QCoreApplication::translate("TabLogQuery", "\346\227\245\345\277\227\350\267\257\345\276\204\357\274\232", nullptr));
        txt_logPath->setText(QCoreApplication::translate("TabLogQuery", "/apps/m580cn/log", nullptr));
        label_keyword->setText(QCoreApplication::translate("TabLogQuery", "\345\205\263\351\224\256\345\255\227\357\274\210\345\217\257\351\200\211\357\274\211\357\274\232", nullptr));
        label_timeRange->setText(QCoreApplication::translate("TabLogQuery", "\346\227\266\351\227\264\350\214\203\345\233\264\357\274\210\345\217\257\351\200\211\357\274\211\357\274\232", nullptr));
        dt_start->setDisplayFormat(QCoreApplication::translate("TabLogQuery", "yyyy-MM-dd HH:mm", nullptr));
        label_to->setText(QCoreApplication::translate("TabLogQuery", "\350\207\263", nullptr));
        dt_end->setDisplayFormat(QCoreApplication::translate("TabLogQuery", "yyyy-MM-dd HH:mm", nullptr));
        groupBox_preview->setTitle(QCoreApplication::translate("TabLogQuery", "\346\227\245\345\277\227\351\242\204\350\247\210\357\274\210\345\217\214\345\207\273\350\256\276\345\244\207\345\217\257\345\215\225\347\213\254\346\237\245\347\234\213\357\274\211", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree_logResults->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("TabLogQuery", "\344\270\213\350\275\275\350\277\233\345\272\246", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("TabLogQuery", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("TabLogQuery", "\346\226\207\344\273\266\345\244\247\345\260\217", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("TabLogQuery", "\346\226\207\344\273\266\345\220\215", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("TabLogQuery", "\350\256\276\345\244\207 IP", nullptr));
        btn_queryLogs->setText(QCoreApplication::translate("TabLogQuery", "\346\237\245\350\257\242\346\227\245\345\277\227", nullptr));
        btn_downloadSelected->setText(QCoreApplication::translate("TabLogQuery", "\344\270\213\350\275\275\351\200\211\344\270\255\346\227\245\345\277\227", nullptr));
        btn_downloadAll->setText(QCoreApplication::translate("TabLogQuery", "\344\270\213\350\275\275\345\205\250\351\203\250\346\227\245\345\277\227", nullptr));
        (void)TabLogQuery;
    } // retranslateUi

};

namespace Ui {
    class TabLogQuery: public Ui_TabLogQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_LOGQUERY_H
