/* 
 * File:   Config.cpp
 * Author: Admin
 * 
 * Created on 2 de enero de 2020, 3:08 a.m.
 */

#include "Config.h"

Config::Config(string estat, char caract, int ln) {
    estado = estat;
    carct = caract;
    linenumber = ln;
}

Config::Config(const Config& orig) {
    this->estado=orig.estado;
    this->carct=orig.carct;
    this->linenumber=orig.linenumber;
}

Config::~Config() {
}
void Config::setLineNumber(int ln){
    linenumber=ln;
}

