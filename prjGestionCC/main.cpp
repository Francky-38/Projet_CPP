#include "entete.h"

//#include <algorithm>
//#include <string>

#include <vector>

typedef struct
{
    string noCompte;
    float retrait;
    float depot;
    float cb;

    void init(string no)
    {
        noCompte = no;
        retrait = depot = cb = 0;
    }

} S_Transac;

void split(const string&, char, vector<string>&);
void transac(S_Transac);

int main()
{
    /*
    Adresse a("12, rue des Oliviers","",94000,"CReteil");
    cout << a.toString() << endl;

    Client c(1,"Bety",&a,"bety@gmail.com");
    cout << c.toString() << endl;

    try
    {
        Client c2(111,"01234567890123456789012345678901234567890123456789AA",&a,"bety@gmail.com");
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

    Particulier par(2,"AXA",&a2,"info@axa.fr", &d,"Daniel",Sexe::M);
    cout << endl << "Particulier par : " << par.toString();

    Particulier par2(2,"AXA",&a2,"info@axa.fr", &d,"012345678901234",Sexe::M);
    cout << endl << "Particulier par : " << par2.toString();

    Professionnel p2(2,"AXA",&a2,"info@axa.fr", "01234567891234",Status::SARL,&a2);
    cout << endl << p2.toString();
    */

    ifstream fichier("Operations.txt");

    S_Transac tCompte;
    tCompte.init("NC");

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
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
            }

            cout << ligne << endl;
        }
        transac(tCompte);
    }
    else
    {
        throw GccExeption(GccErreurs::ERR_OPEN_FILE);
    }

//    struct tm tm;
//	char *str="2009-11-19 13:33:47.51";
//
//	strptime(str,"%Y-%m-%d %H:%M:%S", &tm);
//	printf("%d/%d/%d %d:%d:%d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
//                                  tm.tm_hour, tm.tm_min, tm.tm_sec);

    return 0;
}

void split(const string &chaine, char delimiteur, vector<string>& elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}
void transac(S_Transac tr)
{
    cout << "---------------" << endl;
    cout << "--- Compte : " << tr.noCompte << endl;
    cout << "     - retrait : " << tr.retrait << endl;
    cout << "     - depot   : " << tr.depot << endl;
    cout << "     - CB      : " << tr.cb << endl;
    cout << "     ==> transaction : " << tr.depot - tr.retrait - tr.cb << endl;
    cout << "---------------" << endl;
}
