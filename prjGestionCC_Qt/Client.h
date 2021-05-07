#ifndef CLIENT_H
#define CLIENT_H

#include <cstring>
#include <algorithm>
#include "Adresse.h"
#include "GccExeption.h"

class Client
{
public:
    Client();
    Client(unsigned int,string,Adresse*,string);
    virtual ~Client();

    string GetID()
    {
        ostringstream oss;
        oss.width(5);
        oss.fill('0');
        oss << ID;
        return oss.str();
    }
    void SetID(unsigned int val)
    {
        ID = val;
    }
    string Getnom()
    {
        string str = nom;
        for (char &c: str) c = toupper(c);
        return str;
    }
    void Setnom(string val) ;
    Adresse* GetadresseP()
    {
        return adresseP;
    }
    void SetadresseP(Adresse* val)
    {
        adresseP = val;
    }
    string Getmail()
    {
        return mail;
    }
    void Setmail(string val) ;

    string virtual toString();
protected:

private:
    unsigned int ID;
    string nom;
    Adresse* adresseP;
    string mail;
};

#endif // CLIENT_H
