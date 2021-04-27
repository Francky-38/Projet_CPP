#include "Professionnel.h"

Professionnel::Professionnel()
    :Client()
{
    Setsiret("00000000000000");
    Setstatus(Status::NC);
    SetadresseS(new Adresse());
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
    oss << " | ++ Données Pro : Siret " << Getsiret() <<
           " | Statut " << Getstatus() <<
           " | "  << GetadresseS()->toString();

    return oss.str();
}
