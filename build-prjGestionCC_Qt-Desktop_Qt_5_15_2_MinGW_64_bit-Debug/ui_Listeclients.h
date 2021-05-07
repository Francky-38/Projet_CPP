/********************************************************************************
** Form generated from reading UI file 'Listeclients.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTECLIENTS_H
#define UI_LISTECLIENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListeClients
{
public:

    void setupUi(QWidget *ListeClients)
    {
        if (ListeClients->objectName().isEmpty())
            ListeClients->setObjectName(QString::fromUtf8("ListeClients"));
        ListeClients->resize(400, 300);

        retranslateUi(ListeClients);

        QMetaObject::connectSlotsByName(ListeClients);
    } // setupUi

    void retranslateUi(QWidget *ListeClients)
    {
        ListeClients->setWindowTitle(QCoreApplication::translate("ListeClients", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListeClients: public Ui_ListeClients {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTECLIENTS_H
