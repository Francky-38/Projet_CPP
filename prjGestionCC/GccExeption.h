#ifndef GCCEXEPTION_H
#define GCCEXEPTION_H

#include <iostream>
#include <exception>

using namespace std;

enum class GccErreurs {
    ERR_NOM = 10,
    ERR_PRENOM = 20,
    ERR_MAIL = 30,
    ERR_SIRET = 40,
    ERR_OPEN_FILE = 50,
};

class GccExeption: public exception
{
    private:
        string message;
    public:
        GccExeption(string msg) throw();
        GccExeption(int) throw();
        GccExeption(GccErreurs) throw();
        ~GccExeption() throw();

        /*virtual*/ const char* what() const throw() override ;

};

#endif // GCCEXEPTION_H
