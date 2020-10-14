/* 
 * File:   Mov.h
 * Author: Admin
 *
 * Created on 2 de enero de 2020, 3:08 a.m.
 */

#ifndef MOV_H
#define	MOV_H
#include <string>
#include <string.h>
using namespace std;
class Mov {
public:
    Mov(string, char,char = 'I' || 'C' || 'D');
    Mov(const Mov& orig);
    virtual ~Mov();
    string getState();
    char getCaracter();
    char getMove();
private:
    string estado;
    char carcter;
    char mov;
};

#endif	/* MOV_H */

