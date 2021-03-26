#ifndef ALLIGATORE_H
#define ALLIGATORE_H

#include "carnivoro.h"
class Alligatore:public Carnivoro
{
private:
    double Pelle;
public:
    Alligatore(u_int id=0, double Pe=0, double A=0,double L=0, u_int E=0, bool Ie=false,
               string S=string(), bool ve = false, bool ne= false, double pe = 0);
               //Per un serpente il campo altezza viene utilizzato come lunghezza
    Animale* clone() const;
    string getSpecie() const;
    double getPelle() const;
    bool isGrasso() const;
    bool isVecchio() const;
    bool isdiValore() const;
};

#endif // ALLIGATORE_H
