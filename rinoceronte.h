#ifndef RINOCERONTE_H
#define RINOCERONTE_H

#include "erbivoro.h"
class Rinoceronte:public Erbivoro
{
private:
    double Corno;
public:
    Rinoceronte(u_int id=0,double Pe=0,double A=0,double L=0,u_int E=0, bool Ie= false,
                string S=string(), vector<Tipo> t=vector<Tipo>(),double Co=0);
    Animale* clone() const;
    string getSpecie() const;
    double getCorno() const;
    bool isGrasso() const;
    bool isVecchio() const;
    bool isdiValore() const;
};

#endif // RINOCERONTE_H
