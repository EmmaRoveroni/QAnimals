#include "alligatore.h"

Alligatore::Alligatore(unsigned short id, double Pe, double A, double L, unsigned short E, bool Ie, string S,
                       bool ve, bool ne, double pe):
Animale(id,Pe,A,L,E,Ie,S),Carnivoro(id,Pe,A,L,E,Ie,S,ve,ne),Pelle(pe) {}

double Alligatore::getPelle() const
{
    return Pelle;
}
bool Alligatore::isGrasso() const
{
    return getPeso()/getLunghezza() > 30;
}

bool Alligatore::isVecchio() const
{
    return getEta() > 30;
}

bool Alligatore::isdiValore() const
{
    return getPelle() > 10;
}


Animale* Alligatore::clone() const
{
    return new Alligatore(*this);
}

std::string Alligatore::getSpecie() const
{
    return "Alligatore";
}
