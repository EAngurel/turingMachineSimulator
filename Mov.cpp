/* 
 * File:   Mov.cpp
 * Author: Admin
 * 
 * Created on 2 de enero de 2020, 3:08 a.m.
 */

#include <algorithm>

#include "Mov.h"

Mov::Mov(string state, char crt, char mv) {
    estado = state;
    carcter = crt;
    mov = mv;
}

Mov::Mov(const Mov& orig) {
    this->carcter=orig.carcter;
    this->estado=orig.estado;
    this->mov=orig.mov;
}

Mov::~Mov() {
}

string Mov::getState(){
    return estado;
}
char Mov::getCaracter(){
    return carcter;
}
char Mov::getMove(){
    return mov;
}
