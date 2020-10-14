#ifndef PARSER_H
#define PARSER_H
#include <list>
#include "lexer.h"
#include "Config.h"
#include "Mov.h"
#include "token.h"
#include "erros.h"

class Parser
{
private:
    Lexer *lexer;
    list<string> states;
    list<string> statesf;
    string err;
    list<char> alfabeto;
    list<Config> conf;
    list<Mov> mv;
    list<Erros> lerr;
    string est1,est2;
    char ch1,ch2,mov;
    Token tok_act;
public:
    Parser(string source);
    ~Parser();
    void match(Token tok);

    void S();
    void E();
    void M();
    list<Config> getConfgList() {
        return conf;
    }
    list<Mov> getMovList(){return mv;}
    list<string> getFinalStatesList(){return statesf;}
    string getErrorState(){return err;}
    list<Erros> getErrorList(){return lerr;}
    list<char> getAlphabet(){return alfabeto;}
};

#endif // PARSER_H
