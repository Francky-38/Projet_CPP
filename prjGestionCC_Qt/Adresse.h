#ifndef ADRESSE_H
#define ADRESSE_H

#include <QString>
#include <iostream>
#include <sstream>

using namespace std;

class Adresse
{
public:
    Adresse();
    Adresse(string,string,unsigned long,string);

    ~Adresse();

    QString Getlib()
    {
        return QString::fromStdString(lib);
    }
    void Setlib(string val)
    {
        lib = val;
    }
    QString Getcomplement()
    {
        return QString::fromStdString(complement);
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
    QString Getville()
    {
        string str = ville;
        for (auto & c: str) c = toupper(c);
        return QString::fromStdString(str);
    }
    void Setville(string val)
    {
        ville = val;
    }

    QString toString();
protected:

private:
    string lib;
    string complement;
    unsigned long CP;
    string ville;
};

#endif // ADRESSE_H
