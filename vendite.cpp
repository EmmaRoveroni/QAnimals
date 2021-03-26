#include "vendite.h"

vendite::vendite(unsigned short i, string t, double p, string d) : id(i),tipoanimale(t),prezzove(p),data(d) {}

unsigned short vendite::getId() const
{
    return id;
}

string vendite::getTipoA() const
{
    return  tipoanimale;
}
double vendite::getPrezzoV() const
{
    return  prezzove;
}

string vendite::getData() const
{
    return data;
}
