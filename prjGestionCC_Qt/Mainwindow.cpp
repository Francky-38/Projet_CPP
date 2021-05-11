#include "Mainwindow.h"
#include "ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myModel =  new QStandardItemModel(0, 0, this); // an empty model
    ui->tblClients->setModel(myModel);
    ui->tblClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblClients->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->rbPar, SIGNAL(clicked()), this, SLOT(rempliTblClients()));
    connect(ui->rbPro, SIGNAL(clicked()), this, SLOT(rempliTblClients()));
    connect(ui->rbTt, SIGNAL(clicked()), this, SLOT(rempliTblClients()));

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("GestionCC.db");

    lfNom="";

    initMainWindow();
    //test();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete myModel;
    if(dlgRapImport!= nullptr) delete dlgRapImport;
}

void MainWindow::initMainWindow()
{
    // -------------PRO
    Adresse *a2 = new Adresse("125, rue LaFayette","Digicode 1432",94120,"FONTENAY SOUS BOIS");
    Adresse *a4 = new Adresse("36, quai des Orfèvres","",93500,"ROISSY EN France");
    Adresse *a6 = new Adresse("32, rue E. Renan","Bat. C",75002,"PARIS");
    Adresse *a8 = new Adresse("23, av P. Valery","",92100,"LA DEFENSE");
    Adresse *a10= new Adresse("15, Place de la Bastille","Fond de Cour",75003,"PARIS");

    Adresse *as2 = new Adresse("125, rue LaFayette","Digicode 1432",94120,"FONTENAY SOUS BOIS");
    Adresse *as4 = new Adresse("10, esplanade de la Défense","",92060,"LA DEFENSE");
    Adresse *as6 = new Adresse("32, rue E. Renan","Bat. C",75002,"PARIS");
    Adresse *as8 = new Adresse("24, esplanade de la Défense","Tour Franklin",92060,"LA DEFENSE");
    Adresse *as10= new Adresse("10, rue de la Paix","",75008,"PARIS");

    Professionnel *p2 = new Professionnel(2,"AXA",a2,"info@axa.fr", "12548795641122",Status::SARL,as2);
    Professionnel *p4 = new Professionnel(4,"PAUL",a4,"info@paul.fr", "87459564455444",Status::EURL,as4);
    Professionnel *p6 = new Professionnel(6,"PRIMARK",a6,"contact@primark.fr", "08755897458455",Status::SARL,as6);
    Professionnel *p8 = new Professionnel(8,"ZARA",a8,"info@zara.fr","65895874587854",Status::SA,as8);
    Professionnel *p10= new Professionnel(10,"LEONIDAS",a10,"contact@leonidas.fr", "91235987456832",Status::SAS,as10);

    //--------------PARTICULIER
    Adresse *a1 = new Adresse("12, rue des Oliviers","",94000,"CRETEIL");
    Adresse *a3 = new Adresse("10, rue des Olivies","Etage 2",94300,"VINCENNES");
    Adresse *a5 = new Adresse("15, rue de la République","",94120,"FONTENAY SOUS BOIS");
    Adresse *a7 = new Adresse("25, rue de la Paix","",92100,"LA DEFENSE");
    Adresse *a9 = new Adresse("3, avenue des Parcs","",93500,"ROISSY EN France");
    Adresse *a11= new Adresse("3, rue Lecourbe","",93200,"BAGNOLET");
    Date *d1 = new Date(12,11,1985);
    Date *d3 = new Date(05,05,1965);
    Date *d5 = new Date(06,06,1977);
    Date *d7 = new Date(12,04,1977);
    Date *d9 = new Date(16,04,1976);
    Date *d11= new Date(10,10,1970);
    Particulier *p1 = new Particulier(1,"BETY",a1,"bety@gmail.com", d1,"Daniel",Sexe::M);
    Particulier *p3 = new Particulier(3,"BODIN",a3,"bodin@gmail.com", d3,"Justin",Sexe::M);
    Particulier *p5 = new Particulier(5,"BERRIS",a5,"berris@gmail.com", d5,"Karine",Sexe::F);
    Particulier *p7 = new Particulier(7,"ABENIR",a7,"abenir@gmail.com", d7,"Alexandra",Sexe::F);
    Particulier *p9 = new Particulier(9,"BENSAID",a9,"bensaid@gmail.com", d9,"Georgia",Sexe::F);
    Particulier *p11= new Particulier(11,"ABABOU",a11,"ababou@gmail.com", d11,"Teddy",Sexe::M);

    mesClients.insert(1, p1);
    mesClients.insert(2, p2);
    mesClients.insert(3, p3);
    mesClients.insert(4, p4);
    mesClients.insert(5, p5);
    mesClients.insert(6, p6);
    mesClients.insert(7, p7);
    mesClients.insert(8, p8);
    mesClients.insert(9, p9);
    mesClients.insert(10, p10);
    mesClients.insert(11, p11);

    rempliTblClients();
}

void MainWindow::split(const string &chaine, char delimiteur, vector<string>& elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}

void MainWindow::transac(S_Transac tr, QString *rapImport)
{
    *rapImport += "---------------\n";
    *rapImport += "--- Compte : " + tr.noCompte + "\n";
    *rapImport += "     - retrait : " + QString::number(tr.retrait) + "\n";
    *rapImport += "     - depot   : " + QString::number(tr.depot) + "\n";
    *rapImport += "     - CB      : " + QString::number(tr.cb) + "\n";
    *rapImport += "     ==> transaction : " + QString::number(tr.depot - tr.retrait - tr.cb) + "\n";

    // Recherche du compte en base
    if (db.open())
    {
        QString reqSQL = "select solde, decouvert "
                         "from comptes "
                         "where numcompte=" + tr.noCompte;
        QSqlQuery query(reqSQL, db);
        while(query.next())
        {
            float solde = query.value("solde").toString().replace(",",".").toFloat();
            float decouv = query.value("decouvert").toFloat();
            *rapImport += "     ==> découvert max : " + QString::number(decouv) + "\n";
            float newSolde = solde + tr.depot - tr.retrait - tr.cb;
            if (newSolde < decouv)
            {
                *rapImport += "   Transaction impossible !!!\n";
                *rapImport += "     ==> ancien solde : " + QString::number(solde) + "\n";
                *rapImport += "     ==> nouveau solde : " + QString::number(solde) + "\n";

            }else{
                // Requete mise à jour de la base
                *rapImport += "   Transaction OK !!! \n";
                *rapImport += "     ==> ancien solde : " + QString::number(solde) + "\n";
                *rapImport += "     ==> nouveau solde : " + QString::number(newSolde) + "\n";
                QString reqSQL = "UPDATE comptes SET solde = " + QString::number(newSolde) + " WHERE numcompte = " + tr.noCompte + ";";
                QSqlQuery query(reqSQL, db);
            }
        }
        db.close();
    }else {
        *rapImport += "Erreur Connexion Base de Données !\n";
    }

    //*rapImport += "---------------\n";
}

void MainWindow::rempliTblClients()
{
    int li=0;
    QString cas="tt";
    if (ui->rbPar->isChecked()) cas = "par";
    if (ui->rbPro->isChecked()) cas = "pro";
    myModel->clear();
    Particulier *parTransType;
    Professionnel *proTransType;
    for(auto monClient:mesClients)
    {
        //if (lfNom=="" || lfNom==monClient->Getnom())
        if (lfNom=="" || monClient->Getnom().contains(lfNom))
        {
            parTransType = dynamic_cast<Particulier*>(monClient);
            proTransType = dynamic_cast<Professionnel*>(monClient);
            if (cas=="par")
            {
                //Particulier
                if (parTransType!=nullptr)
                {
                    myModel->setItem(li,0,new QStandardItem(parTransType->GetID()));
                    myModel->setItem(li,1,new QStandardItem(parTransType->Getsexe()));
                    myModel->setItem(li,2,new QStandardItem(parTransType->Getnom()));
                    myModel->setItem(li,3,new QStandardItem(parTransType->Getprenom()));
                    myModel->setItem(li,4,new QStandardItem(parTransType->Getmail()));
                    li++;
                }
            }else if (cas=="pro")
            {
                //Pro
                if (proTransType!=nullptr)
                {
                    myModel->setItem(li,0,new QStandardItem(proTransType->GetID()));
                    myModel->setItem(li,1,new QStandardItem(proTransType->Getstatus()));
                    myModel->setItem(li,2,new QStandardItem(proTransType->Getnom()));
                    myModel->setItem(li,3,new QStandardItem(proTransType->Getsiret()));
                    myModel->setItem(li,4,new QStandardItem(proTransType->Getmail()));
                    li++;
                }
            }else
            {
                // Autres cas ("tt")
                myModel->setItem(li,0,new QStandardItem(monClient->GetID()));
                myModel->setItem(li,2,new QStandardItem(monClient->Getnom()));
                myModel->setItem(li,6,new QStandardItem(monClient->Getmail()));
                if (parTransType!=nullptr)
                {
                    myModel->setItem(li,1,new QStandardItem(parTransType->Getsexe()));
                    myModel->setItem(li,3,new QStandardItem(parTransType->Getprenom()));
                }else
                {
                    myModel->setItem(li,4,new QStandardItem(proTransType->Getstatus()));
                    myModel->setItem(li,5,new QStandardItem(proTransType->Getsiret()));
                }
                li++;
            }
        }
    }
    // Entetes
    if (cas=="par")
    {
        myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        myModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
        myModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        myModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
        myModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Mail"));
    }else if (cas=="pro")
    {
        myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        myModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Status"));
        myModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        myModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Siret"));
        myModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Mail"));
    }else
    {
        myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        myModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
        myModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        myModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
        myModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Status"));
        myModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Siret"));
        myModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Mail"));
    }
}

void MainWindow::on_tblClients_doubleClicked(const QModelIndex &index)
    {
    int no =index.siblingAtColumn(0).data().toInt();

    // Met à jour le détail des données du client
    ui->labDetail->setText(mesClients[no]->toString());

    // Met à jour le détail des données des comptes
    if (db.open())
    {
        QString reqSQL = "select numcompte, datecreation, solde, decouvert, numcli "
                         "from comptes "
                         "where numcli=" + QString::number(no);
        QSqlQuery query(reqSQL, db);
        QString txtCpt="";
        while(query.next())
        {
            QString noCpt = query.value("numcompte").toString();
            QDateTime dateCrea = query.value("datecreation").toDateTime();
            float solde = query.value("solde").toString().replace(",",".").toFloat();
            float decouv = query.value("decouvert").toFloat();
            int id = query.value("numcli").toInt();

            QString ch = QString("Cpt %1 (%2) Solde ==> %3 (%4)")
                    .arg(noCpt)
                    .arg(dateCrea.toString("dd/MM/yyyy"))
                    .arg(solde)
                    .arg(decouv);
                    //.arg(id);
            txtCpt += ch + "\n";
        }
        ui->labCpt->setText(txtCpt);
        db.close();
    }else {
        ui->labCpt->setText("Erreur Connexion Base de Données !");
    }
}

void MainWindow::on_action_Import_Op_rations_triggered()
{
    ifstream ficOpe("Operations.txt");
    ofstream ficAno("Anomalies.log");

    QString *rapImport = new QString("");

    if (!ficAno)
    {
        throw GccExeption(GccErreurs::ERR_OPEN_FILE);
    }

    S_Transac tCompte;
    tCompte.init("NC");

    if(ficOpe)
    {
        string ligne;
        vector<string> infoLigne;
        while(getline(ficOpe, ligne))
        {
            infoLigne.clear();
            split(ligne,';',infoLigne);
            if (tCompte.noCompte == "NC") tCompte.noCompte = QString::fromStdString(infoLigne.at(0));
            if (tCompte.noCompte != QString::fromStdString(infoLigne.at(0)))
            {
                transac(tCompte, rapImport);
                tCompte.init(QString::fromStdString(infoLigne.at(0)));
            }
            switch  (stoi(infoLigne.at(2)))
            {
            case 1:
                tCompte.retrait+=stof(infoLigne.at(3));
                break;
            case 2:
                tCompte.cb+=stof(infoLigne.at(3));
                break;
            case 3:
                tCompte.depot+=stof(infoLigne.at(3));
                break;
            default:
                ficAno << ligne << "\n";
                break;
            }
            //cout << ligne << endl;
        }
        transac(tCompte, rapImport);
    }
    else
    {
        throw GccExeption(GccErreurs::ERR_OPEN_FILE);
    }

    ficAno.close();

    dlgRapImport = new Dialog(*rapImport, this);

    dlgRapImport->show();
}

void MainWindow::test()
{
    qDebug() << "Test";
}

void MainWindow::on_pushButton_clicked()
{
    on_action_Import_Op_rations_triggered();
}

void MainWindow::on_bpTri_clicked()
{
    lfNom = ui->txtNom->text();
    rempliTblClients();
    lfNom ="";
}

void MainWindow::on_txtNom_textChanged(const QString &arg1)
{
    lfNom = ui->txtNom->text();
    rempliTblClients();
    lfNom ="";
}
