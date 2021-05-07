#include "Listeclients.h"
#include "ui_Listeclients.h"

ListeClients::ListeClients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListeClients)
{
    ui->setupUi(this);
}

ListeClients::~ListeClients()
{
    delete ui;
}
