#ifndef PARTICULIER_H
#define PARTICULIER_H

#include <exception>
#include <cstring>
#include "Client.h"
#include "Date.h"


enum class Sexe {F=0,M=1,I=2}; // I= inderermin�

class Particulier : public Client
{
public:
    Particulier();
    Particulier(unsigned int,string,Adresse*,string,Date*,string,Sexe);
    virtual ~Particulier();

    Date* Getnaissance()
    {
        return naissance;
    }
    void Setnaissance(Date* val)
    {
        naissance = val;
    }
    string Getprenom();

    void Setprenom(string val);

    char Getsexe()
    {
        switch  (sexe)
        {
        case Sexe::M:
            return 'M';
            break;
        case Sexe::F:
            return 'F';
            break;
        default:
            return 'I';
            break;
        }
    }
    void Setsexe(Sexe val)
    {
        sexe = val;
    }

    string toString() override; //virtual

protected:

private:
    Date* naissance;
    string prenom;
    Sexe sexe;
};

#endif // PARTICULIER_H

