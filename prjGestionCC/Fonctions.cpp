#include "entete.h"

//fonction qui retourne '1' si la date est valide sinon '0'
void split(const string &chaine, char delimiteur, vector<string>& elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}
void transac(S_Transac tr)
{
    cout << "---------------" << endl;
    cout << "--- Compte : " << tr.noCompte << endl;
    cout << "     - retrait : " << tr.retrait << endl;
    cout << "     - depot   : " << tr.depot << endl;
    cout << "     - CB      : " << tr.cb << endl;
    cout << "     ==> transaction : " << tr.depot - tr.retrait - tr.cb << endl;
    cout << "---------------" << endl;
}

