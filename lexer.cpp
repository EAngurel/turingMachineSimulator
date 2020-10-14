#include "lexer.h"

Lexer::Lexer(string _source)
{
    source = _source;
    ptr = 0;
}

void Lexer::omitirComentariosYEspacios(){
    while (true){

        if (source[ptr] == '/')
        {
            if (source[ptr+1] == '*')
            {
                ptr+=2;
                bool close = true;
                while(close)
                {
                    if (source[ptr] == '*')
                    {
                        if (source[ptr+1] == '/')
                        {
                            close = false;
                            ptr +=2;
                        }
                    }
                    else
                    {
                        ptr++;
                    }

                }
            }
            else if (source[ptr+1] == '/'){
                ptr+=2;
                bool close = false;
                while(close)
                {
                    if (source[ptr] == '\n')
                    {
                        close = true;
                        ptr +=1;
                        nl++;
                    }
                    else
                    {
                        ptr++;
                    }
                }
            }
        }
        else if (source[ptr] == '\n'|| source[ptr] == '\t' || source[ptr] == ' ')
        {
            if (source[ptr] == '\n'){
                nl++;
            }
            ptr++;
            bool close = false;
            while(close)
            {
                if (source[ptr] != '\n' && source[ptr] != '\t' && source[ptr] == ' ')
                {
                    close = true;
                }
                else
                {
                    if (source[ptr] == '\n'){
                        nl++;
                    }
                    ptr++;
                }
            }
        } else {
            break;
        }
    }
}

Token Lexer::getNextToken(){

    omitirComentariosYEspacios();

    if (ptr >= source.length()){
        return Token::FinDeCadena();
    }
    char next_char = source[ptr];
    switch (next_char) {
    case '-':
        if (source[ptr+1] == '>'){
            ptr+=2;
            Token arr(arrow);
            arr.setLexema("->");
            return arr;
        }
    case '(':
    {
        ptr+=1;
        Token par(parizq);
        par.setLexema("(");
        return par;
    }
    case ')':
    {
        ptr+=1;
        Token pard(parder);
        pard.setLexema(")");
        return pard;
    }
    case '{':
    {
        ptr+=1;
        Token llavei(llaveizq);
        llavei.setLexema("{");
        return llavei;
    }
    case '}':
    {
        ptr+=1;
        Token llaved(llaveder);
        llaved.setLexema("}");
        return llaved;
    }
    case ',':
    {
        ptr+=1;
        Token com(coma);
        com.setLexema(",");
        return com;
    }
    case ';':
    {
        ptr+=1;
        Token pcom(pcoma);
        pcom.setLexema(";");
        return pcom;
    }
    case '=':
    {
        ptr+=1;
        Token equ(igual);
        equ.setLexema("=");
        return equ;
    }
    default:
        break;
    }

#define ISALPHANUM(x) ((x)>='a' && (x)<='z') || ((x) >= 'A' && (x) <= 'Z') || ((x) >= '0' && (x) <= '9') || ((x) == '_')|| (x) == '$'
    if (ISALPHANUM(next_char)){
        string posibleId = "";
        while (ISALPHANUM(source[ptr])){
            posibleId += source[ptr];
            ptr++;
        }
        if (posibleId == "I"){
            Token iz(izq);
            iz.setLexema("I");
            return iz;
        }
        else if (posibleId == "D"){
            Token de(der);
            de.setLexema("D");
            return de;
        }
        else if (posibleId == "C"){
            Token st(stay);
            st.setLexema("C");
            return st;
        }
        else{
            Token pid(id);
            pid.setLexema(posibleId);
            return pid;
        }
    }

    Token er(err);
    er.setLexema("Error");
    return er;
}

