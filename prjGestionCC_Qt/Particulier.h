#ifndef PARTICULIER_H
#define PARTICULIER_H

#include <exception>
#include <cstring>
#include "Client.h"
#include "Date.h"
#include <ctime>

enum class Sexe {F=0,M=1,I=2}; // I= indererminé

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
    QString Getprenom();

    void Setprenom(string val);

    QString Getsexe()
    {
        switch  (sexe)
        {
        case Sexe::M:
            return "M";
            break;
        case Sexe::F:
            return "F";
            break;
        default:
            return "I";
            break;
        }
    }
    void Setsexe(Sexe val)
    {
        sexe = val;
    }

    /*virtual*/QString toString() override; //virtual

protected:

private:
    Date* naissance;
    string prenom;
    Sexe sexe;
};

#endif // PARTICULIER_H

