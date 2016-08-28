/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "console.h"
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *openButton;
    QToolButton *printButton;
    QToolButton *exportButton;
    QToolButton *settingButton;
    QToolButton *startButton;
    QToolButton *stopButton;
    QToolButton *closeButton;
    QSpinBox *intervalBox;
    QFrame *line;
    Plot *d_plot;
    Console *console;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(886, 693);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        openButton = new QToolButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setMouseTracking(false);
        openButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QToolButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/1465992334_folder_open_GPL.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon);
        openButton->setIconSize(QSize(50, 40));
        openButton->setCheckable(false);

        horizontalLayout_8->addWidget(openButton);

        printButton = new QToolButton(centralWidget);
        printButton->setObjectName(QStringLiteral("printButton"));
        printButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QToolButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/1465989469_print_printer_LGPL.png"), QSize(), QIcon::Normal, QIcon::Off);
        printButton->setIcon(icon1);
        printButton->setIconSize(QSize(50, 40));

        horizontalLayout_8->addWidget(printButton);

        exportButton = new QToolButton(centralWidget);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QToolButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/1465995014_pdf_LGPL.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportButton->setIcon(icon2);
        exportButton->setIconSize(QSize(50, 40));

        horizontalLayout_8->addWidget(exportButton);

        settingButton = new QToolButton(centralWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QToolButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/1467123158_settings01_free.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingButton->setIcon(icon3);
        settingButton->setIconSize(QSize(50, 40));

        horizontalLayout_8->addWidget(settingButton);

        startButton = new QToolButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QToolButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/1465993344_run_free.png"), QSize(), QIcon::Normal, QIcon::Off);
        startButton->setIcon(icon4);
        startButton->setIconSize(QSize(50, 40));

        horizontalLayout_8->addWidget(startButton);

        stopButton = new QToolButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QToolButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/1465993547_Pause_Icon_free.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon5);
        stopButton->setIconSize(QSize(50, 40));

        horizontalLayout_8->addWidget(stopButton);

        closeButton = new QToolButton(centralWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setStyleSheet(QLatin1String("QToolButton {\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QToolButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/1465992876_Vector-icons_free.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon6);
        closeButton->setIconSize(QSize(50, 40));

        horizontalLayout_8->addWidget(closeButton);

        intervalBox = new QSpinBox(centralWidget);
        intervalBox->setObjectName(QStringLiteral("intervalBox"));
        intervalBox->setMinimumSize(QSize(60, 0));
        intervalBox->setMaximumSize(QSize(60, 16777215));
        intervalBox->setMinimum(100);
        intervalBox->setMaximum(2000);

        horizontalLayout_8->addWidget(intervalBox);


        verticalLayout->addLayout(horizontalLayout_8);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        d_plot = new Plot(centralWidget);
        d_plot->setObjectName(QStringLiteral("d_plot"));

        verticalLayout->addWidget(d_plot);

        console = new Console(centralWidget);
        console->setObjectName(QStringLiteral("console"));

        verticalLayout->addWidget(console);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openButton->setText(QApplication::translate("MainWindow", "Open", 0));
#ifndef QT_NO_TOOLTIP
        printButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Print the Report</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        printButton->setText(QApplication::translate("MainWindow", "Print", 0));
#ifndef QT_NO_TOOLTIP
        exportButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Export a PDF report to...</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        exportButton->setText(QApplication::translate("MainWindow", "Export", 0));
        settingButton->setText(QApplication::translate("MainWindow", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        startButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Start sampling.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
#ifndef QT_NO_TOOLTIP
        stopButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Start sampling.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Close</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QApplication::translate("MainWindow", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
