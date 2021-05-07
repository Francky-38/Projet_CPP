#include "entete.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    int j=15,m=11,aa=1971;
    cout << "15,11,1971 =>" << Date::fct_ValidDate(j,m,aa) << endl;
    cout << "45,11,1971 =>" << Date::fct_ValidDate(45,11,1971) << endl;
    cout << "15,22,1971 =>" << Date::fct_ValidDate(15,22,1971) << endl;


    Date dd(22,2,2021);
    cout << endl << "Date dd : " << dd.toString();

    try
    {
        cout << endl << "jour 10";
        dd.Setjour(10);
    }
    catch (GccExeption& e)
    {
        cout << endl << e.what() << endl;
    }
    catch(exception& e)
    {
        cout<< endl << "exception " << e.what();
    }
    catch(...)
    {
        cout<< endl << "Autre Erreur !";
    }
    cout << endl << "Date d : " << dd.toString();



    Adresse ad("12, rue des Oliviers","",94000,"CReteil");
    cout << ad.toString() << endl;

    Client c(1,"Bety",&ad,"bety@gmail.com");
    cout << c.toString() << endl;

    try
    {
        Client c2(111,"01234567890123456789012345678901234567890123456789AA",&ad,"bety@gmail.com");
        cout << c2.toString() << endl;
    }
    catch (GccExeption& e)
    {
        cout << endl << e.what() << endl;
    }
    catch(exception& e)
    {
        cout<< endl << "exception " << e.what();
    }
    catch(...)
    {
        cout<< endl << "Autre Erreur !";
    }
    Adresse a2("125, rue LaFayette","Digicode 1432",94120,"FONTENAY SOUS BOIS");
    Professionnel p(2,"AXA",&a2,"info@axa.fr", "12548795641122",Status::SARL,&a2);
    cout << endl << p.toString();

    Date d(01,05,1971);
    cout << endl << "Date d : " << d.toString();

    Particulier par(2,"AXA_par",&a2,"info@axa.fr", &d,"daNiel",Sexe::M);
    cout << endl << par.toString();

    Particulier par2(2,"AXA_par2",&a2,"info@axa.fr", &d,"012345678901234",Sexe::M);
    cout << endl << par2.toString();

    Professionnel p2(2,"AXA_P2",&a2,"info@axa.fr", "01234567891234",Status::SARL,&a2);
    cout << endl << p2.toString();

    ifstream ficOpe("Operations.txt");
    ofstream ficAno("Anomalies.log");
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
            if (tCompte.noCompte == "NC") tCompte.noCompte = infoLigne.at(0);
            if (tCompte.noCompte != infoLigne.at(0))
            {
                transac(tCompte);
                tCompte.init(infoLigne.at(0));
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
            cout << ligne << endl;
        }
        transac(tCompte);
    }
    else
    {
        throw GccExeption(GccErreurs::ERR_OPEN_FILE);
    }


    ficAno.close();
    */

    QSettings maConfig("parametres.ini", QSettings::IniFormat);
    QString pathOperations=maConfig.value("pathOperations").toString();

    qDebug() << "Le papath des opé :" + pathOperations;

    QMap<int, Client> mesClients;
    // -------------PRO
    Adresse a2("125, rue LaFayette","Digicode 1432",94120,"FONTENAY SOUS BOIS");
    Adresse a4("36, quai des Orfèvres","",93500,"ROISSY EN France");
    Adresse a6("32, rue E. Renan","Bat. C",75002,"PARIS");
    Adresse a8("23, av P. Valery","",92100,"LA DEFENSE");
    Adresse a10("15, Place de la Bastille","Fond de Cour",75003,"PARIS");

    Adresse as2("125, rue LaFayette","Digicode 1432",94120,"FONTENAY SOUS BOIS");
    Adresse as4("10, esplanade de la Défense","",92060,"LA DEFENSE");
    Adresse as6("32, rue E. Renan","Bat. C",75002,"PARIS");
    Adresse as8("24, esplanade de la Défense","Tour Franklin",92060,"LA DEFENSE");
    Adresse as10("10, rue de la Paix","",75008,"PARIS");

    Professionnel p2(2,"AXA",&a2,"info@axa.fr", "12548795641122",Status::SARL,&a2);
    Professionnel p4(4,"PAUL",&a4,"info@paul.fr", "87459564455444",Status::EURL,&a4);
    Professionnel p6(6,"PRIMARK",&a6,"contact@primark.fr", "08755897458455",Status::SARL,&a6);
    Professionnel p8(8,"ZARA",&a8,"info@zara.fr","65895874587854",Status::SA,&a8);
    Professionnel p10(10,"LEONIDAS",&a10,"contact@leonidas.fr", "91235987456832",Status::SAS,&a10);

    //--------------PARTICULIER
    Adresse a1("12, rue des Oliviers","",94000,"CRETEIL");
    Adresse a3("10, rue des Olivies","Etage 2",94300,"VINCENNES");
    Adresse a5("15, rue de la République","",94120,"FONTENAY SOUS BOIS");
    Adresse a7("25, rue de la Paix","",92100,"LA DEFENSE");
    Adresse a9("3, avenue des Parcs","",93500,"ROISSY EN France");
    Adresse a11("3, rue Lecourbe","",93200,"BAGNOLET");
    Date d1(12,11,1985);
    Date d3(05,05,1965);
    Date d5(06,06,1977);
    Date d7(12,04,1977);
    Date d9(16,04,1976);
    Date d11(10,10,1970);
    Particulier p1(1,"BETY",&a1,"bety@gmail.com", &d1,"Daniel",Sexe::M);
    Particulier p3(3,"BODIN",&a3,"bodin@gmail.com", &d3,"Justin",Sexe::M);
    Particulier p5(5,"BERRIS",&a5,"berris@gmail.com", &d5,"Karine",Sexe::F);
    Particulier p7(7,"ABENIR",&a7,"abenir@gmail.com", &d7,"Alexandra",Sexe::F);
    Particulier p9(9,"BENSAID",&a9,"bensaid@gmail.com", &d9,"Georgia",Sexe::F);
    Particulier p11(11,"ABABOU",&a11,"ababou@gmail.com", &d11,"Teddy",Sexe::M);

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



    MainWindow w;
    w.show();
    return a.exec();

}
