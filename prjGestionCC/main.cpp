#include "entete.h"

int main()
{
    Adresse a("12, rue des Oliviers","",94000,"CRETEIL");
    cout << a.toString() << endl;

    Client c(1,"BETY",&a,"bety@gmail.com");
    cout << c.toString() << endl;

    try
    {
        Client c2(111,"01234567890123456789012345678901234567890123456789AA",&a,"bety@gmail.com");
        cout << c2.toString() << endl;
    }
    catch (GccExeption& e)
    {
        cout << endl << e.what() << endl;
    }
    catch(exception& e)
    {
        cout<< endl << "exception " << e.what();
    }
    catch(...)
    {
        cout<< endl << "Autre Erreur !";
    }
    Adresse a2("125, rue LaFayette","Digicode 1432",94120,"FONTENAY SOUS BOIS");
    Professionnel p(2,"AXA",&a2,"info@axa.fr", "12548795641122",Status::SARL,&a2);
    cout << endl << p.toString();
    //cout << endl << "test Status " << test;

    return 0;
}
