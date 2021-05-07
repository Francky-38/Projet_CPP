#ifndef ADRESSE_H
#define ADRESSE_H

#include <iostream>
#include <sstream>

using namespace std;

class Adresse
{
public:
    Adresse();
    Adresse(string,string,unsigned long,string);

    ~Adresse();

    string Getlib()
    {
        return lib;
    }
    void Setlib(string val)
    {
        lib = val;
    }
    string Getcomplement()
    {
        return complement;
    }
    void Setcomplement(string val)
    {
        complement = val;
    }
    unsigned long GetCP()
    {
        return CP;
    }
    void SetCP(unsigned long val)
    {
        CP = val;
    }
    string Getville()
    {
        string str = ville;
        for (auto & c: str) c = toupper(c);
        return str;
    }
    void Setville(string val)
    {
        ville = val;
    }

    string toString();
protected:

private:
    string lib;
    string complement;
    unsigned long CP;
    string ville;
};

#endif // ADRESSE_H
