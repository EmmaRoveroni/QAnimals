#include "orso.h"

Orso::Orso(unsigned short id, double Pe, double A, double L, unsigned short E, bool Ie, string S, vector<Tipo> t,
           bool ve, bool ne, double pe):
Animale(id,Pe,A,L,E,Ie,S),Onnivoro(id,Pe,A,L,E,Ie,S,t,ve,ne),Pelliccia(pe){}

double Orso::getPelliccia() const
{
    return Pelliccia;
}

bool Orso::isGrasso() const
{
    return getPeso()/getAltezza() > 235;
}

bool Orso::isVecchio() const
{
    return getEta() > 30;
}

bool Orso::isdiValore() const
{
    return getPelliccia() > 20;
}

Animale *Orso::clone() const
{
    return new Orso(*this);
}

std::string Orso::getSpecie() const
{
    return "Orso";
}
