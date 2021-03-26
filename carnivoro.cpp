#include "carnivoro.h"

Carnivoro::Carnivoro(unsigned short id, double Pe, double A, double L, unsigned short E, bool Ie, string S, bool ve, bool ne):
    Animale(id,Pe,A,L,E,Ie,S),velenoso(ve),necrofago(ne){}

string Carnivoro::getTipo() const
{
    return "Carnivoro";
}

bool Carnivoro::getvelenoso() const {return velenoso;}

bool Carnivoro::getnecrofago() const {return necrofago;}
