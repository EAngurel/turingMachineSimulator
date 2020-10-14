#ifndef ERROS_H
#define ERROS_H
#include <string>
using namespace std;

class Erros
{
private:
    int line;
    string msgerror;
public:
    Erros();
    Erros(int,string);
    Erros(const Erros &er);
    int getNline(){return line;}
    string getMsgerr(){return msgerror;}
};

#endif // ERROS_H
