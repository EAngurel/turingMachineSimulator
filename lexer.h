#ifndef LEXER_H
#define LEXER_H
#include <set>
#include "token.h"

class Lexer
{
private:
    string source;
    unsigned int ptr;
    int nl = 1;
public:
    Lexer(string _source);
    Lexer();
    void omitirComentariosYEspacios();
    Token getNextToken();
    int getNlin(){return nl;};
};

#endif // LEXER_H
