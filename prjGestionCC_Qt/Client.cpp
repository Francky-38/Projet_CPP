#include "Client.h"

Client::Client()
{
    //ctor
    SetID(0);
    Setnom("NC");
    SetadresseP(nullptr);
    Setmail("NC");
}
Client::Client(unsigned int id, string n, Adresse* a, string m)
{
    SetID(id);
    Setnom(n);
    SetadresseP(a);
    Setmail(m);
}
Client::~Client()
{
    //dtor
    //cout << endl << "Destruction du client : ";// << Getnom() << endl;
}
void Client::Setnom(string n)
{
    if (strlen(n.c_str())<=50)
        nom=n;
    else
        throw GccExeption(GccErreurs::ERR_NOM);
}

void Client::Setmail(string m)
{
    int qtAro = std::count_if(
                    m.begin(),
                    m.end(),
                    std::bind1st(std::equal_to<char>(),'@')
                );
    if (qtAro == 1)
        mail = m;
    else
        throw GccExeption(30);
}
QString Client::toString()
{
    QString oss;
    oss = "Client : id " + GetID() +
        " | nom " + Getnom() +
        " | "  + GetadresseP()->toString() +
        " | mail " + Getmail() ;

    return oss;
}
