#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
#include "GccExeption.h"

using namespace std;

class Date
{
public:
    Date();
    Date(const Date&);
    Date(unsigned int,unsigned int,unsigned int);
    virtual ~Date();

    unsigned int Getjour()
    {
        return jour;
    }
    void Setjour(unsigned int j)
    {
        if (Date::fct_ValidDate(j,mois,annee) == 0)
            throw GccExeption(GccErreurs::ERR_DATE);
        jour = j;
    }
    unsigned int Getmois()
    {
        return mois;
    }
    void Setmois(unsigned int m)
    {
        if (Date::fct_ValidDate(jour,m,annee) == 0)
            throw GccExeption(GccErreurs::ERR_DATE);
        mois = m;
    }
    unsigned int Getannee()
    {
        return annee;
    }
    void Setannee(unsigned int a)
    {
        if (Date::fct_ValidDate(jour,mois,a) == 0)
            throw GccExeption(GccErreurs::ERR_DATE);
        annee = a;
    }

    string toString();

    static int fct_ValidDate(int pjour,int pmois,int pannee);

protected:

private:
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
};

#endif // DATE_H
