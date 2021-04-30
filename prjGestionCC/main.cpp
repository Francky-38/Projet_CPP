#include "entete.h"

int main()
{
    /*
        int j=15,m=11,a=1971;
        cout << "15,11,1971 =>" << Date::fct_ValidDate(j,m,a) << endl;
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

        Date d(12,11,1985);
        cout << endl << "Date d : " << d.toString();

        Particulier par(2,"AXA_par",&a2,"info@axa.fr", &d,"daNiel",Sexe::M);
        cout << endl << par.toString();

        Particulier par2(2,"AXA_par2",&a2,"info@axa.fr", &d,"012345678901234",Sexe::M);
        cout << endl << "Particulier par : " << par2.toString();

        Professionnel p2(2,"AXA_P2",&a2,"info@axa.fr", "01234567891234",Status::SARL,&a2);
        cout << endl << p2.toString();

    */
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
        while(getline(ficOpe, ligne))
        {
            vector<string> infoLigne;
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

    return 0;
}



