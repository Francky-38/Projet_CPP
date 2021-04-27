#include "Adresse.h"

Adresse::Adresse()
{
    Setlib("");
    Setcomplement("");
    SetCP(0);
    Setville("");
}
Adresse::Adresse(string l, string c, unsigned long cp, string v)
{
    Setlib(l);
    Setcomplement(c);
    SetCP(cp);
    Setville(v);
}

Adresse::~Adresse()
{
    //dtor
    cout << endl << "Destruction de l'adresse : " << Getlib() << endl;
}
string Adresse::toString()
{
    ostringstream oss;
    oss << "Adresse : " << Getlib() << " " <<
                           Getcomplement() << " " <<
                           GetCP() << " " <<
                           Getville();
    return oss.str();
}
