#ifndef ERBIVORO_H
#define ERBIVORO_H
#include "animale.h"
#include <vector>
using std::vector;
enum Tipo{Frugivoro,Folivoro,Granivoro,Nettarivoro};
class Erbivoro : virtual public Animale
{
private:
      vector<Tipo> Dieta;
public:
    Erbivoro(u_int id,double Pe=0,double A=0,double L=0,u_int E=0, bool Ie= false,
             string S=string(),vector<Tipo> t=vector<Tipo>());
    string getTipo() const;
    vector<Tipo> getDieta() const;
    string getFrugivoro() const;
    string getFolivoro() const;
    string getGranivoro() const;
    string getNettarivoro() const;
};

#endif // ERBIVORO_H
