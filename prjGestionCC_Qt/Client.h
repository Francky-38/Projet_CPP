#ifndef CLIENT_H
#define CLIENT_H

#include <cstring>
#include <algorithm>
#include <QString>
#include "Adresse.h"
#include "GccExeption.h"

class Client
{
public:
    Client();
    Client(unsigned int,string,Adresse*,string);
    virtual ~Client();

    QString GetID()
    {
        ostringstream oss;
        oss.width(5);
        oss.fill('0');
        oss << ID;
        return QString::fromStdString(oss.str());
    }
    void SetID(unsigned int val)
    {
        ID = val;
    }
    QString Getnom()
    {
        string str = nom;
        for (char &c: str) c = toupper(c);
        return QString::fromStdString(str);
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
    QString Getmail()
    {
        return QString::fromStdString(mail);
    }
    void Setmail(string val) ;

    QString virtual toString();
protected:

private:
    unsigned int ID;
    string nom;
    Adresse* adresseP;
    string mail;
};

#endif // CLIENT_H
