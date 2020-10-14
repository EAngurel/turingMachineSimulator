#include "erros.h"

Erros::Erros()
{
}
Erros::Erros(int nl,string msge)
{   line = nl;
    msgerror = msge;
}
Erros::Erros(const Erros &er)
{
    line = er.line;
    msgerror = er.msgerror;
}
