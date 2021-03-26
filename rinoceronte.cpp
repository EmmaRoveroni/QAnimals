#include "rinoceronte.h"

Rinoceronte::Rinoceronte(unsigned short id, double Pe, double A, double L, unsigned short E, bool Ie, string S, vector<Tipo> t, double Co):
Animale(id,Pe,A,L,E,Ie,S),Erbivoro(id,Pe,A,L,E,Ie,S,t),Corno(Co){}

bool Rinoceronte::isGrasso() const
{
    return getPeso()/getAltezza() > 1300;
}

bool Rinoceronte::isVecchio() const
{
    return getEta() > 40;
}

bool Rinoceronte::isdiValore() const
{
    return getCorno() > 13;
}


double Rinoceronte::getCorno() const
{
    return Corno;
}

Animale *Rinoceronte::clone() const
{
    return new Rinoceronte(*this);
}

std::string Rinoceronte::getSpecie() const
{
    return "Rinoceronte";
}


