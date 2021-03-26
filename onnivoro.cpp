#include "onnivoro.h"

Onnivoro::Onnivoro(unsigned short id, double Pe, double A, double L, unsigned short E, bool Ie, string S,
                   vector<Tipo> t, bool ve, bool ne):
    Animale(id,Pe,A,L,E,Ie,S),Erbivoro(id,Pe,A,L,E,Ie,S,t),Carnivoro(id,Pe,A,L,E,Ie,S,ve,ne){}

std::string Onnivoro::getTipo() const
{
    return "Onnivoro";
}
