/* 
 * File:   Config.h
 * Author: Admin
 *
 * Created on 2 de enero de 2020, 3:08 a.m.
 */

#ifndef CONFIG_H
#define	CONFIG_H
#include <string>
using namespace std;
class Config {
public:
    Config(string,char,int);
    Config(const Config& orig);
    virtual ~Config();
    string getState(){return estado;};
    char getCharacter(){return carct;};
    void setLineNumber(int);
    int getLineNumber(){return linenumber;};
private:
    string estado;
    char carct;
    int linenumber;
};

#endif	/* CONFIG_H */

