#include "Date.h"

Date::Date()
{
    Setjour(1);
    Setmois(1);
    Setannee(1900);
}
Date::Date(unsigned int j, unsigned int m, unsigned int a)
{
    if (Date::fct_ValidDate(j,m,a) == 0)
        throw GccExeption(GccErreurs::ERR_DATE);
    jour = j;
    mois = m;
    annee = a;
}
Date::Date(const Date& cpDate)
{
    jour = cpDate.jour;
    mois = cpDate.mois;
    annee = cpDate.annee;
}

Date::~Date()
{
    cout << endl << "Destruction de la date : " << toString() << endl;
}
string Date::toString()
{
    ostringstream oss;
    oss << Getjour() << "/" << Getmois() << "/" << Getannee();

    return oss.str();
}


int Date::fct_ValidDate(int jour, int mois, int annee)
{
    int jours[]= {31,28,31,30,31,30,31,31,30,31,30,31}; //jour dans mois=jour[];
    char ret=1;//reception 0 ou 1 selon nonValide, Valide
    int nbrJmois=0;

    if ((annee<1583)||(annee>9999)||(mois<1)||(mois>12))
    {
        ret=0;
    }
    else
    {
        nbrJmois = jours[mois-1];// Nombre de jours du mois saisie
        // Si l'année est bissextile et le mois est février on ajoute un jour
        if((mois == 2) &&
           (((annee%4 == 0)&&(annee%100 != 0)) ||
            ((annee%4 == 0)&&(annee%100 == 0)&&(annee%400 == 0)))) nbrJmois++ ;
        // Si le jour saisie n'est pas situé entre 1 et le nombre de jour dans le mois
        if((jour < 1) || (jour > nbrJmois)) ret=0;
    }
    return ret;
}
