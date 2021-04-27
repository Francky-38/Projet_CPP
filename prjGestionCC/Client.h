#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include "Adresse.h"
#include "GccExeption.h"

using namespace std;

class Client
{
    public:
        Client();
        Client(unsigned int,string,Adresse*,string);
        virtual ~Client();

        unsigned int GetID() { return ID; }
        void SetID(unsigned int val) { ID = val; }
        string Getnom() { return nom; }
        void Setnom(string val) ;
        Adresse* GetadresseP() { return adresseP; }
        void SetadresseP(Adresse* val) { adresseP = val; }
        string Getmail() { return mail; }
        void Setmail(string val) ;

        string toString();
    protected:

    private:
        unsigned int ID;
        string nom;
        Adresse* adresseP;
        string mail;
};

#endif // CLIENT_H
