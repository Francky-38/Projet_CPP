#include "GccExeption.h"

GccExeption::GccExeption(string msg) throw()
{
    message=msg;
}

GccExeption::GccExeption(int codeErr) throw()
{
    switch (codeErr)
    {
        case 10:
            message = "Nom Invalide ! le nom ne doit pas contenir plus de 50 caracteres.";
            break;
        case 20:
            message = "Prenom Invalide ! le prenom ne doit pas contenir plus de 50 caracteres.";
            break;
        case 30:
            message = "Mail Invalide ! le mail doit contenir un et un seul @";
            break;
        case 40:
            message = "Siret Invalide ! le siret doit avoir 14 chiffres";
            break;
        default:
            message = "Autre Erreur Non g�r�e !!!";
            break;
    }
}
GccExeption::GccExeption(GccErreurs codeErr) throw()
{
    switch (codeErr)
    {
        case GccErreurs::ERR_NOM:
            message = "Nom Invalide ! le nom ne doit pas contenir plus de 50 caracteres.";
            break;
        case GccErreurs::ERR_PRENOM:
            message = "Prenom Invalide ! le prenom ne doit pas contenir plus de 50 caracteres.";
            break;
        case GccErreurs::ERR_MAIL:
            message = "Mail Invalide ! le mail doit contenir un et un seul @";
            break;
        case GccErreurs::ERR_SIRET:
            message = "Siret Invalide ! le siret doit avoir 14 chiffres";
            break;
        default:
            message = "Autre Erreur Non g�r�e !!!";
            break;
    }
}

GccExeption::~GccExeption()throw()
{
     cout << endl << "Destruction GccException";
}

const char* GccExeption::what() const throw()
{
    return message.c_str();
}
