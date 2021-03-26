#ifndef VENDITE_H
#define VENDITE_H

#include <string>
using std::string;
#define u_int unsigned short

class vendite
{
private:
    u_int id;
    string tipoanimale;
    double prezzove;
    string data;
public:
    vendite(u_int i,string t,double p,string d);
    u_int getId() const;
    string getTipoA() const;
    double getPrezzoV() const;
    string getData() const;
};

#endif // VENDITE_H
