#ifndef TURINGESTRUC_H
#define TURINGESTRUC_H
#include "Config.h"
#include "Mov.h"
#include "string"

using namespace std;

class turingEstruc
{
private:
       Config conf;
       Mov mv;
public:
    turingEstruc(string,char,string,char,char = 'I' || 'C' || 'D');
    Config getConfig();
    Mov getMov();
};

#endif // TURINGESTRUC_H
