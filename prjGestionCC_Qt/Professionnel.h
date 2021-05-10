#ifndef PROFESSIONNEL_H
#define PROFESSIONNEL_H

#include <exception>
#include "Client.h"

enum class Status{SARL, SA, SAS, EURL, NC};

class Professionnel : public Client
{
public:
    Professionnel();
    Professionnel(unsigned int,string,Adresse*,string,string,Status,Adresse*);
    virtual ~Professionnel();

    QString Getsiret()
    {
        return QString::fromStdString(siret);
    }
    void Setsiret(string val);
    QString Getstatus()
    {
        switch  (status)
        {
        case Status::SARL:
            return "SARL";
            break;
        case Status::SA:
            return "SA";
            break;
        case Status::SAS:
            return "SAS";
            break;
        case Status::EURL:
            return "EURL";
            break;
        default:
            return "NC";
            break;
        }
    }
    void Setstatus(Status val)
    {
        status = val;
    }
    Adresse* GetadresseS()
    {
        return adresseS;
    }
    void SetadresseS(Adresse* val)
    {
        adresseS = val;
    }

    /*virtual*/ QString toString() override;

protected:

private:
    string siret;
    Status status;
    Adresse* adresseS;
};

#endif // PROFESSIONNEL_H
