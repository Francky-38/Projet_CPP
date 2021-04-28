#include "Professionnel.h"

Professionnel::Professionnel()
    :Client()
{
    Setsiret("00000000000000");
    Setstatus(Status::NC);
    SetadresseS(nullptr);
}

Professionnel::Professionnel(unsigned int id, string n, Adresse* adrP, string m,
                             string sir, Status sta,Adresse* adrS)
    :Client(id, n, adrP, m)
{
    Setsiret(sir);
    Setstatus(sta);
    SetadresseS(adrS);
}

Professionnel::~Professionnel()
{
    cout << endl << "Destruction du professionnel : " << Getnom() << endl;
    delete GetadresseS();
}

string Professionnel::toString()
{
    ostringstream oss;
    oss << Client::toString();
    oss << " | ++ Donnees Pro : Siret " << Getsiret() <<
        " | Statut " << Getstatus() <<
        " | "  << GetadresseS()->toString();

    return oss.str();
}
void Professionnel::Setsiret(string val)
{
    int qtNumeric = 0;
    for(int i = 0; i < val.length(); ++i)
    {
        if (val[i]>='0' && val[i]<='9') qtNumeric++;
    }
    if (qtNumeric == 14 && val.length() == 14)
        siret = val;
    else
        throw GccExeption(GccErreurs::ERR_SIRET);
}
