#include "erbivoro.h"

Erbivoro::Erbivoro(unsigned short id, double Pe , double A , double L, unsigned short E, bool Ie,
                   string S, vector<Tipo> t):
    Animale(id,Pe,A,L,E,Ie,S),Dieta(t){}

vector<Tipo> Erbivoro::getDieta() const {return Dieta;}


string Erbivoro::getTipo() const
{
    return "Erbivoro";
}

string Erbivoro::getFrugivoro() const
{
    vector<Tipo> l = getDieta();
    for(vector<Tipo>::const_iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Frugivoro){
            return "Frugivoro";
        }
    }
    return "Non è Frugivoro";
}

string Erbivoro::getFolivoro() const
{
    vector<Tipo> l = getDieta();
    for(vector<Tipo>::const_iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Folivoro){
            return "Folivoro";
        }
    }
    return "Non è Folivoro";
}

string Erbivoro::getGranivoro() const
{
    vector<Tipo> l = getDieta();
    for(vector<Tipo>::const_iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Granivoro){
            return "Granivoro";
        }
    }
    return "Non è Granivoro";
}

std::string Erbivoro::getNettarivoro() const
{
    vector<Tipo> l = getDieta();
    for(vector<Tipo>::const_iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Nettarivoro){
            return "Nettarivoro";
        }
    }
    return "Non è Nettarivoro";
}
