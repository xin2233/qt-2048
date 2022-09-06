/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
//Qt6上对此类已做了优化，变成
//#include <QtWidgets/QAction>
#include <QtWidgets>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew_game;
    QWidget *centralwidget;
    QPushButton *upPushButton;
    QPushButton *leftPushButton;
    QPushButton *rightPushButton;
    QPushButton *downPushButton;
    QLabel *pointLabel;
    QLabel *pointDataLabel;
    QMenuBar *menubar;
    QMenu *menufile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        actionnew_game = new QAction(MainWindow);
        actionnew_game->setObjectName(QString::fromUtf8("actionnew_game"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        upPushButton = new QPushButton(centralwidget);
        upPushButton->setObjectName(QString::fromUtf8("upPushButton"));
        upPushButton->setGeometry(QRect(270, 460, 50, 40));
        leftPushButton = new QPushButton(centralwidget);
        leftPushButton->setObjectName(QString::fromUtf8("leftPushButton"));
        leftPushButton->setGeometry(QRect(220, 500, 50, 40));
        rightPushButton = new QPushButton(centralwidget);
        rightPushButton->setObjectName(QString::fromUtf8("rightPushButton"));
        rightPushButton->setGeometry(QRect(320, 500, 50, 40));
        downPushButton = new QPushButton(centralwidget);
        downPushButton->setObjectName(QString::fromUtf8("downPushButton"));
        downPushButton->setGeometry(QRect(270, 500, 50, 40));
        pointLabel = new QLabel(centralwidget);
        pointLabel->setObjectName(QString::fromUtf8("pointLabel"));
        pointLabel->setGeometry(QRect(110, 410, 50, 20));
        QFont font;
        font.setPointSize(12);
        pointLabel->setFont(font);
        pointDataLabel = new QLabel(centralwidget);
        pointDataLabel->setObjectName(QString::fromUtf8("pointDataLabel"));
        pointDataLabel->setGeometry(QRect(160, 410, 70, 20));
        QFont font1;
        font1.setPointSize(10);
        pointDataLabel->setFont(font1);
        pointDataLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 23));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menufile->menuAction());
        menufile->addAction(actionnew_game);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionnew_game->setText(QCoreApplication::translate("MainWindow", "new game", nullptr));
        upPushButton->setText(QCoreApplication::translate("MainWindow", "up", nullptr));
        leftPushButton->setText(QCoreApplication::translate("MainWindow", "left", nullptr));
        rightPushButton->setText(QCoreApplication::translate("MainWindow", "right", nullptr));
        downPushButton->setText(QCoreApplication::translate("MainWindow", "down", nullptr));
        pointLabel->setText(QCoreApplication::translate("MainWindow", "point:", nullptr));
        pointDataLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        menufile->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
