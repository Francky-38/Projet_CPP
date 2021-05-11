#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QString txt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    if (!txt.isEmpty())
    {
         ui->txtSort->setText(txt);
    }
}

Dialog::~Dialog()
{
    delete ui;
}
