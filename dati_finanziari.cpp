#include "dati_finanziari.h"
dati_finanziari::dati_finanziari() {}

void dati_finanziari::DatiFinanziariAggiungiAcquisto(acquisti acq)
{
    listaAcquisti.push_back(acq);
}

void dati_finanziari::DatiFinanziariAggiungiVendita(vendite ven)
{
    listaVendite.push_back(ven);
}

void dati_finanziari::DatiFinanziariSetAcquisti(double acq)
{
    totacquisti = acq;
}

void dati_finanziari::DatiFinanziariSetVendite(double ven)
{
    totvendite = ven;
}

void dati_finanziari::DatiFinanziariSetBilancio(double bil)
{
    bilancio = bil;
}

vector<acquisti> dati_finanziari::getListaAcquisti() const
{
    return listaAcquisti;
}

vector<vendite> dati_finanziari::getListaVendite() const
{
    return listaVendite;
}

double dati_finanziari::getTotAcquisti() const
{
    return totacquisti;
}

double dati_finanziari::getTotVendite() const
{
    return totvendite;
}

double dati_finanziari::getBilancio() const
{
    return bilancio;
}

void dati_finanziari::DatiFinanziariTogliAcquisto(u_int id)
{
    for(vector<acquisti>::iterator it = listaAcquisti.begin(); it != listaAcquisti.end();it++){
        if((*it).getId()==id){
            listaAcquisti.erase(it);return;
        }
    }
}

void dati_finanziari::DatiFinanziariTogliVendita(u_int id)
{
    for(vector<vendite>::iterator it = listaVendite.begin(); it != listaVendite.end();it++){
        if((*it).getId()==id){
            listaVendite.erase(it);return;
        }
    }
}

