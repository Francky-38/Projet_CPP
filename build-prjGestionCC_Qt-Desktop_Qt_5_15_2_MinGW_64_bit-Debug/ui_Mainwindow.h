/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *bpLstClient;
    QPushButton *bpLstClient_2;
    QPushButton *bpLstClient_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bpLstClient = new QPushButton(centralwidget);
        bpLstClient->setObjectName(QString::fromUtf8("bpLstClient"));
        bpLstClient->setGeometry(QRect(190, 110, 411, 71));
        QFont font;
        font.setPointSize(21);
        bpLstClient->setFont(font);
        bpLstClient_2 = new QPushButton(centralwidget);
        bpLstClient_2->setObjectName(QString::fromUtf8("bpLstClient_2"));
        bpLstClient_2->setGeometry(QRect(190, 200, 411, 71));
        bpLstClient_2->setFont(font);
        bpLstClient_3 = new QPushButton(centralwidget);
        bpLstClient_3->setObjectName(QString::fromUtf8("bpLstClient_3"));
        bpLstClient_3->setGeometry(QRect(190, 290, 411, 71));
        bpLstClient_3->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion compte (Menu principal)", nullptr));
        bpLstClient->setText(QCoreApplication::translate("MainWindow", "Liste des clients", nullptr));
        bpLstClient_2->setText(QCoreApplication::translate("MainWindow", "Consulter les comptes", nullptr));
        bpLstClient_3->setText(QCoreApplication::translate("MainWindow", "Importation des op\303\251rations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
