#include "Particulier.h"

Particulier::Particulier()
{
    Setnaissance(new Date({0,0,0}));
    Setprenom("");
    Setsexe(Sexe::I);
}

Particulier::Particulier(unsigned int id, string nom, Adresse* adrP, string m,
                         Date* n, string p, Sexe s)
    :Client(id, nom, adrP, m)
{
    //Setnaissance(new Date(n->Getjour(),n->Getmois(),n->Getannee()));
    Setnaissance(new Date(*n));
    Setprenom(p);
    Setsexe(s);
}

Particulier::~Particulier()
{
    //cout << endl << "Destruction du particulier ";// << Getprenom() << endl;
    delete Getnaissance();
}

QString Particulier::Getprenom()
{
    string str = prenom;
    for (auto & c: str) c = tolower(c);
    str[0]=toupper(str[0]);
    //transform(str.begin(), str.begin()+1,str.begin(), ::toupper);
    return QString::fromStdString(str);
}

void Particulier::Setprenom(string n)
{
    if (strlen(n.c_str())<=50)
        prenom=n;
    else
        throw GccExeption(GccErreurs::ERR_PRENOM);
}
QString Particulier::toString()
{
    QString oss;
    oss = "\nParticulier : " + Client::GetID() + "\n\n";//Client::toString();
    if (Getsexe()=='M')
        oss += "    M. ";
    else
        oss += "    Mme. ";
    oss += Client::Getnom() + " " + Getprenom() + "\n    " + Client::GetadresseP()->Getlib() + "\n";
    if (Client::GetadresseP()->Getcomplement()!="")
        oss += "    " + Client::GetadresseP()->Getcomplement() + "\n";
    oss += "    " + QString::number(Client::GetadresseP()->GetCP()) + " " + Client::GetadresseP()->Getville() + "\n";

    int age = 0;
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);
    int aEc = 1900 + ltm->tm_year;
    unsigned int mEc = 1 + ltm->tm_mon;
    unsigned int jEc = ltm->tm_mday;

    age = aEc - Getnaissance()->Getannee()-1;
    if ((mEc > Getnaissance()->Getmois()) ||
            ((mEc == Getnaissance()->Getmois()) && (jEc >= Getnaissance()->Getjour()))) age++;
    oss += "    Age : " + QString::number(age);
    if ((mEc == Getnaissance()->Getmois()) && (jEc == Getnaissance()->Getjour()))
        oss += " et Bon Anniversaire !";
    oss += "\n";
    return oss;
}
