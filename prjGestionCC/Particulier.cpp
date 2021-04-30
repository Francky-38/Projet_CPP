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
    cout << endl << "Destruction du particulier : " << Getprenom() << endl;
    delete Getnaissance();
}

string Particulier::Getprenom()
{
    string str = prenom;
    for (auto & c: str) c = tolower(c);
    str[0]=toupper(str[0]);
    //transform(str.begin(), str.begin()+1,str.begin(), ::toupper);
    return str;
}
string Particulier::toString()
{
    ostringstream oss;
    oss << "\nParticulier : " << Client::GetID() << "\n\n";//Client::toString();
    if (Getsexe()=='M')
        oss << "    M. ";
    else
        oss << "    Mme. ";
    oss << Client::Getnom() << " " << Getprenom() << "\n    " << Client::GetadresseP()->Getlib()<<"\n";
    if (Client::GetadresseP()->Getcomplement()!="")
        oss << "    " << Client::GetadresseP()->Getcomplement()<<"\n";
    oss << "    " << Client::GetadresseP()->GetCP()<<" " << Client::GetadresseP()->Getville()<< "\n";
    oss << "    " << "Ne le : " << Getnaissance()->toString()<< "\n";

        //" | sexe "  << Getsexe() " | ++ Donnees Particulier : Naissance " << Getnaissance()->toString();

    return oss.str();
}

void Particulier::Setprenom(string n)
{
    if (strlen(n.c_str())<=50)
        prenom=n;
    else
        throw GccExeption(GccErreurs::ERR_PRENOM);
}
