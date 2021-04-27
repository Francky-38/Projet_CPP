#include "Client.h"

Client::Client()
{
    //ctor
    SetID(0);
    Setnom("NC");
    SetadresseP(new Adresse());
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
    cout << endl << "Destruction du client : " << Getnom() << endl;
    delete GetadresseP();
}
string Client::toString()
{
ostringstream oss;
    oss << "Client : id " << GetID() <<
           " | nom " << Getnom() <<
           " | "  << GetadresseP()->toString() <<
           " | mail " << Getmail() ;

    return oss.str();
}
void Client::Setnom(string n)
{
    if (strlen(n.c_str())<=50)
        nom=n;
    else
        throw GccExeption(10);
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
