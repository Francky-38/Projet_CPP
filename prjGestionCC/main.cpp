#include "entete.h"

int main()
{
    Adresse a("12, rue des Oliviers","",94000,"CRETEIL");
    cout << a.toString() << endl;

    Client c(1,"BETY",&a,"bety@gmail.com");
    cout << c.toString() << endl;

    Client c2(111,"test",&a,"bety@gmail.com");
    cout << c2.toString() << endl;


    return 0;
}
