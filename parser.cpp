#include "parser.h"
#include "lexer.h"
#include "token.h"
#include <stdio.h>

Parser::Parser(string source)
{
    lexer = new Lexer(source);
    tok_act = lexer->getNextToken();
    if(tok_act.getType() == id){
        if(tok_act.getLexema() == "Q"){
            match(id);
            match(igual);
            match(llaveizq);
            if(tok_act.getType()== llaveder){
                lerr.push_back(Erros(lexer->getNlin(),"Conjunto de estados vacios"));
                tok_act = lexer->getNextToken();
            }
            else{
                while(tok_act.getType() != llaveder){
                    if(tok_act.getType() == id){
                        states.push_back(tok_act.getLexema());
                        match(id);
                        if(tok_act.getType()==coma){
                            match(coma);
                        }
                    }
                    else{
                        lerr.push_back(Erros(lexer->getNlin(),"Simbolo inesperado"));
                        tok_act = lexer->getNextToken();
                    }
                }
                match(llaveder);
                match(pcoma);
            }
        }
        else{
            lerr.push_back(Erros(lexer->getNlin(),"Conjunto de estados no definido"));
            tok_act = lexer->getNextToken();
        }
        if(tok_act.getLexema() == "F"){
            match(id);
            match(igual);
            match(llaveizq);
            if(tok_act.getType()== llaveder){
                lerr.push_back(Erros(lexer->getNlin(),"Conjunto de estados vacios"));
                tok_act = lexer->getNextToken();
            }
            else{
                while(tok_act.getType()!= llaveder){
                    if(tok_act.getType()== id){
                        statesf.push_back(tok_act.getLexema());
                        match(id);
                        if(tok_act.getType()==coma){
                            match(coma);
                        }
                    }
                }
                match(llaveder);
                match(pcoma);
            }
        }
        else{
            lerr.push_back(Erros(lexer->getNlin(),"Conjunto de estados finales no definido"));
            tok_act = lexer->getNextToken();
        }
        if(tok_act.getLexema() == "E"){
            match(id);
            match(igual);
            match(llaveizq);
            if(tok_act.getType()== llaveder){
                lerr.push_back(Erros(lexer->getNlin(),"Conjunto de estado vacios"));
                tok_act = lexer->getNextToken();
            }
            else{
                 if(tok_act.getType()== id){
                    err=tok_act.getLexema();
                    match(id);
                }
                }
                match(llaveder);
                match(pcoma);
            }
        }
        else{
            lerr.push_back(Erros(lexer->getNlin(),"Conjunto de estado de error no definido"));
            tok_act = lexer->getNextToken();
    }
    if(tok_act.getLexema() == "T"){
        match(id);
        match(igual);
        match(llaveizq);
        if(tok_act.getType()== llaveder){
            lerr.push_back(Erros(lexer->getNlin(),"Alfabeto vacio"));
            tok_act = lexer->getNextToken();
        }
        else{
            while(tok_act.getType()!= llaveder){
                if(tok_act.getType()== id){
                    if(tok_act.getLexema().size()==1){
                    alfabeto.push_back(tok_act.getLexema()[0]);
                    match(id);
                    if(tok_act.getType()==coma){
                        match(coma);
                    }
                    }
                }
            }
            match(llaveder);
            match(pcoma);
        }
    }
    else{
        lerr.push_back(Erros(lexer->getNlin(),"Alfabeto no definido"));
        tok_act = lexer->getNextToken();
    }

    S();
    if ( tok_act.getType() == eof )
        return;
    else {
        lerr.push_back(Erros(lexer->getNlin(),"Fin de cadena fuente inesperado"));
        tok_act = lexer->getNextToken();
    }
}


Parser::~Parser(){
    delete lexer;
}

void Parser::match(Token tok){
    if ( tok.getType() == tok_act.getType() )
        tok_act = lexer->getNextToken();
    else{
        lerr.push_back(Erros(lexer->getNlin(),"Simbolo inesperado"));
        tok_act = lexer->getNextToken();
    }
}

void Parser::S()
{
    if ( tok_act.getType() == parizq || tok_act.getType() == pcoma){
        E();
        S();
        return;
     }
    if(tok_act.getType() == eof){return;}
    lerr.push_back(Erros(lexer->getNlin(),"Simbolo inesperado"));
    tok_act = lexer->getNextToken();
}

void Parser::E()
{

    int i = 0;
    if ( tok_act.getType() == pcoma ){
        match( pcoma );
        return;
        }
    if ( tok_act.getType() == parizq ){
        match( parizq );

        for(string est : states){
            if(tok_act.getLexema()== est){
                est1 = tok_act.getLexema();
                match( id );
                i = 1;
                break;
            }
        }
        if(i == 0){
            lerr.push_back(Erros(lexer->getNlin(),"Estado no defifnido"));
            tok_act = lexer->getNextToken();
        }
        i = 0;
        match( coma );
        for(char ch : alfabeto){
            if(ch == tok_act.getLexema()[0]){
            ch1 = tok_act.getLexema()[0];
            i=1;
            break;
            }
        }
        if(i == 0){
            lerr.push_back(Erros(lexer->getNlin(),"Caracter no defifnido en el alfabeto"));
            tok_act = lexer->getNextToken();
        }else{
            match( id );
        }
        i = 0;
        match( parder );
        match( arrow );
        match( parizq );
        for(string est : states){
            if(tok_act.getLexema()== est){
                est2 = tok_act.getLexema();
                match( id );
                i = 1;
            }
        }
        if(i == 0){
            lerr.push_back(Erros(lexer->getNlin(),"Estado no defifnido"));
            tok_act = lexer->getNextToken();
        }
        i = 0;
        match( coma );
        for(char ch : alfabeto){
            if(ch == tok_act.getLexema()[0]){
            ch2 = tok_act.getLexema()[0];
            i=1;
            break;
            }
        }
        if(i == 0){
            lerr.push_back(Erros(lexer->getNlin(),"Caracter no defifnido en el alfabeto"));
            tok_act = lexer->getNextToken();
        }
        else
           {
            match( id );
        }
        i = 0;
        match( coma );
        M();
        match( parder );
        int nl=lexer->getNlin();
        conf.push_back(Config(est1,ch1,nl));
        mv.push_back(Mov(est2,ch2,mov));
        return;
        }
    if ( tok_act.getType() == eof ){
        return;
        }
    lerr.push_back(Erros(lexer->getNlin(),"Simbolo inesperado"));
    tok_act = lexer->getNextToken();
}

void Parser::M()
{
    if ( tok_act.getType() == izq ){
        mov = tok_act.getLexema()[0];
        match( izq );
        return;
        }
    if ( tok_act.getType() == der ){
        mov = tok_act.getLexema()[0];
        match( der );
        return;
        }
    if ( tok_act.getType() == stay ){
        mov = tok_act.getLexema()[0];
        match( stay );
        return;
        }
    lerr.push_back(Erros(lexer->getNlin(),"Simbolo inesperado"));
    tok_act = lexer->getNextToken();
}
