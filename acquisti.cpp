#include "acquisti.h"

acquisti::acquisti(u_int i, string t, double p, string d) : id(i),tipoanimale(t),prezzoac(p),data(d) {}

u_int acquisti::getId() const
{
    return id;
}

string acquisti::getTipoA() const
{
    return  tipoanimale;
}
double acquisti::getPrezzoA() const
{
    return  prezzoac;
}

string acquisti::getData() const
{
    return data;
}
