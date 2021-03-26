#ifndef CARNIVORO_H
#define CARNIVORO_H
#include "animale.h"
class Carnivoro :virtual public Animale
{
private:
    bool velenoso;
    bool necrofago;
public:
    Carnivoro(u_int id=0,double Pe=0,double A=0,double L=0,u_int E=0,bool Ie=false,
              string S=string(),bool ve = false,bool ne= false);
    string getTipo() const;
    bool getvelenoso() const;
    bool getnecrofago() const;
};

#endif // CARNIVORO_H
