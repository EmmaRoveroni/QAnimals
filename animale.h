#ifndef ANIMALE_H
#define ANIMALE_H
#include <string>
using std::string;
#define u_int unsigned short

class Animale
{
private:
    u_int ID;
    double Peso;        // Kilogrammi
    double Altezza;     // Metri
    double Lunghezza;   // Metri
    u_int Eta;
    bool InEstinz;
    string Sede;
public:
    Animale(u_int id=0,double Pe=0,double A=0,double L=0,u_int E=0,bool Ie=false,string S=string());
    virtual ~Animale() {}
    virtual bool isGrasso() const = 0;
    virtual bool isVecchio() const = 0;
    virtual bool isdiValore() const = 0;
    virtual string getTipo() const = 0;     //erbivoro , carnivoro , onnivoro
    virtual string getSpecie() const = 0;   //rinoceronte , orso , serpente
    virtual Animale* clone() const = 0;
    u_int getID() const;
    double getPeso() const;
    double getAltezza() const;
    double getLunghezza() const;
    u_int getEta() const;
    string getSede() const;
    bool getInEstinz() const;
};

#endif // ANIMALE_H
