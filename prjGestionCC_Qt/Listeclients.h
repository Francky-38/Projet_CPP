#ifndef LISTECLIENTS_H
#define LISTECLIENTS_H

#include <QDialog>

namespace Ui {
class ListeClients;
}

class ListeClients : public QDialog
{
    Q_OBJECT

public:
    explicit ListeClients(QWidget *parent = nullptr);
    ~ListeClients();

private:
    Ui::ListeClients *ui;
};

#endif // LISTECLIENTS_H
