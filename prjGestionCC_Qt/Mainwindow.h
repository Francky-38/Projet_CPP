#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Date.h"
#include "Client.h"
#include "Professionnel.h"
#include "Particulier.h"
#include "dialog.h"

#include <QMainWindow>
#include <QMap>
#include <QtDebug>
#include <QStandardItemModel>
#include <fstream>

#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

typedef struct
{
    QString noCompte;
    float retrait;
    float depot;
    float cb;
    void init(QString no)
    {
        noCompte = no;
        retrait = depot = cb = 0;
    }
} S_Transac;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void rempliTblClients(void);
    void test(void);
    void on_tblClients_doubleClicked(const QModelIndex &index);
    void on_action_Import_Op_rations_triggered();
    void on_pushButton_clicked();
    void on_bpTri_clicked();

    void on_txtNom_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *myModel;
    QMap<int, Client*> mesClients;
    void initMainWindow();
    int a;
    void split(const string&, char, vector<string>&);
    void transac(S_Transac, QString *);
    QSqlDatabase db;
    Dialog *dlgRapImport;
    QString lfNom;
};
#endif // MAINWINDOW_H
