#ifndef ORSO_H
#define ORSO_H

#include "onnivoro.h"
class Orso:public Onnivoro
{
private:
    double Pelliccia;
public:
    Orso(u_int id = 0,double Pe=0,double A=0,double L=0,u_int E=0, bool Ie= false,
         string S=string(), vector<Tipo> t=vector<Tipo>(),bool ve = false,bool ne= false,double pe=0);
    Animale* clone() const;
    string getSpecie() const;
    double getPelliccia() const;
    bool isGrasso() const;
    bool isVecchio() const;
    bool isdiValore() const;
};

#endif // ORSO_H

