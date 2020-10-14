#include "turingestruc.h"
#include "Config.h"
#include "Mov.h"
turingEstruc::turingEstruc(string est1,char ch1,string est2,char ch2,char mov)
{
   Config cf(est1,ch1);
   //Mov mvs(est2,ch2,mov);
   conf = cf;
  // mv = mvs;
}
Config turingEstruc::getConfig(){
    return conf;
}
Mov turingEstruc::getMov(){
    return mv;
}
