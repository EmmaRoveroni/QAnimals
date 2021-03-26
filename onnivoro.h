#ifndef ONNIVORO_H
#define ONNIVORO_H

#include "erbivoro.h"
#include "carnivoro.h"
class Onnivoro:public Erbivoro ,public Carnivoro
{
public:
    Onnivoro(u_int id,double Pe=0,double A=0,double L=0,u_int E=0,bool Ie=false,
             string S=string(),vector<Tipo> t = vector<Tipo>(),bool ve = false,bool ne= false);
    virtual string getTipo() const;
};

#endif // ONNIVORO_H
