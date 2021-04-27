#include <iostream>
#include "Adresse.h"
using namespace std;

int main()
{
    Adresse a("12, rue des Oliviers","",94000,"CRETEIL");
    cout << a.toString() << endl;
    return 0;
}
