#ifndef ACQUISTI_H
#define ACQUISTI_H

#include <string>
using std::string;
#define u_int unsigned short

class acquisti
{
private:
    u_int id;
    string tipoanimale;
    double prezzoac;
    string data;
public:
    acquisti(u_int i,string t,double p,string d);
    u_int getId() const;
    string getTipoA() const;
    double getPrezzoA() const;
    string getData() const;
};

#endif // ACQUISTI_H
