#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>

using namespace std;

class Date
{
    public:
        Date();
        Date(unsigned int,unsigned int,unsigned int);
        virtual ~Date();

        unsigned int Getjour() { return jour; }
        void Setjour(unsigned int val) { jour = val; }
        unsigned int Getmois() { return mois; }
        void Setmois(unsigned int val) { mois = val; }
        unsigned int Getannee() { return annee; }
        void Setannee(unsigned int val) { annee = val; }

        string toString();

    protected:

    private:
        unsigned int jour;
        unsigned int mois;
        unsigned int annee;
};

#endif // DATE_H
