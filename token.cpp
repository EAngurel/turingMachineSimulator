#include "token.h"

Token::Token(int _type)
{
    type = _type;
}
Token::Token()
{
}
void Token::setType(int _type){
    type = _type;
}
void Token::setLexema(string lexem){
    lexema = lexem;
}

