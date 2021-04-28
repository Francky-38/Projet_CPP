#include "Date.h"

Date::Date()
{
    Setjour(0);
    Setmois(0);
    Setannee(0);
}
Date::Date(unsigned int j, unsigned int m, unsigned int a)
{
    Setjour(j);
    Setmois(m);
    Setannee(a);
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
