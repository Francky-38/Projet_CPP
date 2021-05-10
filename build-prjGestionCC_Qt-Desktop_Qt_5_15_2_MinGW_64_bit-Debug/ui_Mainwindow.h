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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Import_Op_rations;
    QWidget *centralwidget;
    QTableView *tblClients;
    QRadioButton *rbPar;
    QRadioButton *rbPro;
    QRadioButton *rbTt;
    QLabel *labDetail;
    QLabel *labCpt;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 600);
        action_Import_Op_rations = new QAction(MainWindow);
        action_Import_Op_rations->setObjectName(QString::fromUtf8("action_Import_Op_rations"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tblClients = new QTableView(centralwidget);
        tblClients->setObjectName(QString::fromUtf8("tblClients"));
        tblClients->setGeometry(QRect(10, 50, 421, 501));
        rbPar = new QRadioButton(centralwidget);
        rbPar->setObjectName(QString::fromUtf8("rbPar"));
        rbPar->setGeometry(QRect(30, 30, 82, 17));
        rbPar->setChecked(false);
        rbPro = new QRadioButton(centralwidget);
        rbPro->setObjectName(QString::fromUtf8("rbPro"));
        rbPro->setGeometry(QRect(130, 30, 82, 17));
        rbPro->setChecked(true);
        rbTt = new QRadioButton(centralwidget);
        rbTt->setObjectName(QString::fromUtf8("rbTt"));
        rbTt->setGeometry(QRect(270, 30, 82, 17));
        rbTt->setChecked(false);
        labDetail = new QLabel(centralwidget);
        labDetail->setObjectName(QString::fromUtf8("labDetail"));
        labDetail->setGeometry(QRect(450, 50, 241, 171));
        labCpt = new QLabel(centralwidget);
        labCpt->setObjectName(QString::fromUtf8("labCpt"));
        labCpt->setGeometry(QRect(450, 260, 551, 111));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(action_Import_Op_rations);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion compte (Menu principal)", nullptr));
        action_Import_Op_rations->setText(QCoreApplication::translate("MainWindow", "&Import_Op\303\251rations", nullptr));
        rbPar->setText(QCoreApplication::translate("MainWindow", "Particuliers", nullptr));
        rbPro->setText(QCoreApplication::translate("MainWindow", "Professionnels", nullptr));
        rbTt->setText(QCoreApplication::translate("MainWindow", "Tous", nullptr));
        labDetail->setText(QString());
        labCpt->setText(QString());
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
