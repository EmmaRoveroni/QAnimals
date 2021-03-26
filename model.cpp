#include "model.h"

Model::Model(){
    Modelloaded();
}

void Model::ModelAggiungiAnimale(Animale *an) {
    con.push_back(an);
}

void Model::ModelRemoveAnimale(unsigned short id)
{
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
        if((*it).info->getID()==id)
        {
            con.pop(it);return;
        }
    }
}
Animale *Model::Modelsearchanimale(unsigned short id) const
{
    Animale* an = nullptr;
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
        if((*it).info->getID()==id)
        {
            an = (*it).info->clone();
        }
    }
    return an;
}

bool Model::Modelverifyid(unsigned short id) const
{
    bool verify = true;
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
        if((*it).info->getID()==id)
        {
            verify = false;
        }
    }
    return verify;
}

void Model::Modelloaded()
{
    sl.load(con,df);
}

void Model::Modelsaved()
{
    sl.save(con,df);
}

void Model::ModelAggiungiAcquisto(acquisti a)
{
    df.DatiFinanziariAggiungiAcquisto(a);
}

void Model::ModelAggiungiVendita(vendite v)
{
    df.DatiFinanziariAggiungiVendita(v);
}

void Model::ModelUpdateAcquisto(double a)
{
    df.DatiFinanziariSetAcquisti(a);
}

void Model::ModelUpdateVendita(double v)
{
    df.DatiFinanziariSetVendite(v);
}

void Model::ModelUpdateBilancio(double b)
{
    df.DatiFinanziariSetBilancio(b);
}

vector<Animale*> Model::Modelcaricamentoanimali() const
{
    vector<Animale*> v;
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
            v.push_back((*it).info->clone());
    }
    return v;
}

dati_finanziari Model::Modelcaricamentodatifinanziari() const
{
    return df;
}

void Model::Modelremoveacquisto(unsigned short id)
{
    df.DatiFinanziariTogliAcquisto(id);
}

void Model::Modelremovevendita(unsigned short id)
{
    df.DatiFinanziariTogliVendita(id);
}





