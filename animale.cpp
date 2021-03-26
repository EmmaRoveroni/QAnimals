#include "animale.h"

Animale::Animale(unsigned short id, double Pe , double A , double L, unsigned short E, bool Ie, string S):
    ID(id),Peso(Pe), Altezza(A) ,Lunghezza(L), Eta(E) , InEstinz(Ie) , Sede(S) {}

u_int Animale::getID() const
{
    return ID;
}

double Animale::getPeso() const {return Peso;}

double Animale::getAltezza() const {return Altezza;}

double Animale::getLunghezza() const {return Lunghezza;}

u_int Animale::getEta() const {return Eta;}

string Animale::getSede() const {return Sede;}

bool Animale::getInEstinz() const {return InEstinz;}

