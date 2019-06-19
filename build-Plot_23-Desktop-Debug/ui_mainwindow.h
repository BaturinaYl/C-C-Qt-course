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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_5;
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *rbSqr;
    QSpacerItem *verticalSpacer_4;
    QRadioButton *radioButton_3;
    QSpacerItem *verticalSpacer_5;
    QRadioButton *rbFile;
    QVBoxLayout *verticalLayout_5;
    QSlider *slNum;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *lbNum;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *sbYfrom;
    QLabel *label_3;
    QDoubleSpinBox *sbYto;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *sbXfrom;
    QLabel *label;
    QDoubleSpinBox *sbXto;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(833, 529);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 10, 541, 451));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 539, 449));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget = new QCustomPlot(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout_5->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(570, 0, 253, 461));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        rbSqr = new QRadioButton(groupBox);
        rbSqr->setObjectName(QStringLiteral("rbSqr"));

        verticalLayout_6->addWidget(rbSqr);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_6->addWidget(radioButton_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        rbFile = new QRadioButton(groupBox);
        rbFile->setObjectName(QStringLiteral("rbFile"));

        verticalLayout_6->addWidget(rbFile);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_7->addWidget(groupBox);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        slNum = new QSlider(layoutWidget);
        slNum->setObjectName(QStringLiteral("slNum"));
        slNum->setEnabled(true);
        slNum->setMinimum(100);
        slNum->setMaximum(1000);
        slNum->setSingleStep(10);
        slNum->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(slNum);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setWordWrap(true);

        horizontalLayout_3->addWidget(label_2);

        lbNum = new QLabel(layoutWidget);
        lbNum->setObjectName(QStringLiteral("lbNum"));

        horizontalLayout_3->addWidget(lbNum);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sbYfrom = new QDoubleSpinBox(groupBox_2);
        sbYfrom->setObjectName(QStringLiteral("sbYfrom"));
        sbYfrom->setReadOnly(true);
        sbYfrom->setMinimum(-1000);
        sbYfrom->setMaximum(1000);

        horizontalLayout->addWidget(sbYfrom);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        sbYto = new QDoubleSpinBox(groupBox_2);
        sbYto->setObjectName(QStringLiteral("sbYto"));
        sbYto->setReadOnly(true);
        sbYto->setMinimum(-1000);
        sbYto->setMaximum(1000);

        horizontalLayout->addWidget(sbYto);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sbXfrom = new QDoubleSpinBox(groupBox_2);
        sbXfrom->setObjectName(QStringLiteral("sbXfrom"));
        sbXfrom->setMaximum(1000);
        sbXfrom->setSingleStep(1);

        horizontalLayout_2->addWidget(sbXfrom);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        sbXto = new QDoubleSpinBox(groupBox_2);
        sbXto->setObjectName(QStringLiteral("sbXto"));
        sbXto->setMaximum(1000);

        horizontalLayout_2->addWidget(sbXto);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 833, 25));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\270\320\272\320\276\320\262", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\321\216:", 0));
        rbSqr->setText(QApplication::translate("MainWindow", "y = x^2", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "y = sin(x)", 0));
        rbFile->setText(QApplication::translate("MainWindow", "\320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0));
        label_2->setText(QApplication::translate("MainWindow", "       \320\232\320\276\320\273. \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271:", 0));
        lbNum->setText(QApplication::translate("MainWindow", "100", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 :", 0));
        label_3->setText(QApplication::translate("MainWindow", "  Y  ", 0));
        label->setText(QApplication::translate("MainWindow", "  X ", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
