#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "constants.h"

using namespace std;

class Token
{
private:
    int type;
    string lexema;
public:
    Token(int _type);
    Token();
    Token(const Token &t) {
        type=t.type;
        lexema=t.lexema;
    }

    static Token FinDeCadena(){
        Token fcad( eof );
        fcad.setLexema("Fin de Cadena");
        return fcad;
    }

    int getType(){return type;}
    void setType(int _type);
    void setLexema(string lexem);
    string getLexema(){return lexema;}
};

#endif // TOKEN_H
