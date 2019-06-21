/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tbW_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pbOk;
    QPushButton *pbLast;
    QPushButton *pbCheck_all;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(683, 524);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tbW_7 = new QTableWidget(centralWidget);
        if (tbW_7->columnCount() < 9)
            tbW_7->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tbW_7->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tbW_7->rowCount() < 9)
            tbW_7->setRowCount(9);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setForeground(brush);
        __qtablewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled);
        tbW_7->setItem(0, 0, __qtablewidgetitem9);
        QFont font;
        font.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        tbW_7->setItem(0, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tbW_7->setItem(2, 1, __qtablewidgetitem11);
        tbW_7->setObjectName(QStringLiteral("tbW_7"));
        tbW_7->setGeometry(QRect(50, 30, 421, 421));
        tbW_7->setAlternatingRowColors(false);
        tbW_7->setTextElideMode(Qt::ElideLeft);
        tbW_7->setGridStyle(Qt::CustomDashLine);
        tbW_7->setRowCount(9);
        tbW_7->setColumnCount(9);
        tbW_7->horizontalHeader()->setVisible(false);
        tbW_7->horizontalHeader()->setDefaultSectionSize(45);
        tbW_7->verticalHeader()->setVisible(false);
        tbW_7->verticalHeader()->setDefaultSectionSize(45);
        tbW_7->verticalHeader()->setMinimumSectionSize(15);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(510, 160, 125, 95));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pbOk = new QPushButton(widget);
        pbOk->setObjectName(QStringLiteral("pbOk"));

        verticalLayout->addWidget(pbOk);

        pbLast = new QPushButton(widget);
        pbLast->setObjectName(QStringLiteral("pbLast"));

        verticalLayout->addWidget(pbLast);

        pbCheck_all = new QPushButton(widget);
        pbCheck_all->setObjectName(QStringLiteral("pbCheck_all"));

        verticalLayout->addWidget(pbCheck_all);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\241\321\203\320\264\320\276\320\272\321\203", 0));
        QTableWidgetItem *___qtablewidgetitem = tbW_7->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\220", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tbW_7->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\221", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tbW_7->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\222", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tbW_7->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\223", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tbW_7->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\224", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tbW_7->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\225", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tbW_7->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\226", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tbW_7->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\230", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tbW_7->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\232", 0));

        const bool __sortingEnabled = tbW_7->isSortingEnabled();
        tbW_7->setSortingEnabled(false);
        tbW_7->setSortingEnabled(__sortingEnabled);

        pbOk->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", 0));
        pbLast->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260", 0));
        pbCheck_all->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\262\321\201\321\221", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
