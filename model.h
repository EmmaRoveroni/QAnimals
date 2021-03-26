#ifndef MODEL_H
#define MODEL_H
#include "contenitore.h"
#include "save_load.h"
#include "dati_finanziari.h"
#include "animale.h"
#include <vector>
using std::vector;

class Model
{
private:
    Contenitore<Animale*> con;
    save_load sl;
    dati_finanziari df;
    void Modelloaded();
public:
    Model();
    vector<Animale*> Modelcaricamentoanimali() const;
    dati_finanziari Modelcaricamentodatifinanziari() const;
    void Modelsaved();
    void ModelAggiungiAnimale(Animale* an);
    void ModelRemoveAnimale(u_int id);
    Animale* Modelsearchanimale(u_int id) const;
    bool Modelverifyid(u_int id) const;
    void Modelremoveacquisto(u_int id);
    void Modelremovevendita(u_int id);
    void ModelAggiungiAcquisto(acquisti a);
    void ModelAggiungiVendita(vendite v);
    void ModelUpdateAcquisto(double a);
    void ModelUpdateVendita(double v);
    void ModelUpdateBilancio(double b);
};

#endif // MODEL_H
