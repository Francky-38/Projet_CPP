#ifndef ENTETE_H_INCLUDED
#define ENTETE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <QApplication>
#include <QSettings>
#include <QtDebug>

#include "Mainwindow.h"
#include "Adresse.h"
#include "Client.h"
#include "Professionnel.h"
#include "Particulier.h"
#include "GccExeption.h"
#include "Date.h"


using namespace std;

typedef struct transac
{
    string noCompte;
    float retrait;
    float depot;
    float cb;

    void init(string no)
    {
        noCompte = no;
        retrait = depot = cb = 0;
    }

} S_Transac;

void split(const string&, char, vector<string>&);
void transac(S_Transac);

#endif // ENTETE_H_INCLUDED


//#include <comutil.h>
//#include <iomanip>

//#include <cstring>
//#include <exception>
//#include <cctype>
//#include <sstream>
//#include <algorithm>
//#include <functional>
