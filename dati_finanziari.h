#ifndef DATI_FINANZIARI_H
#define DATI_FINANZIARI_H

#include "acquisti.h"
#include "vendite.h"
#include <vector>
using std::vector;
class dati_finanziari
{
private:
    vector<acquisti> listaAcquisti;
    vector<vendite> listaVendite;
    double totacquisti;
    double totvendite;
    double bilancio;
public:
    dati_finanziari();
    void DatiFinanziariAggiungiAcquisto(acquisti acq);
    void DatiFinanziariAggiungiVendita(vendite ven);
    void DatiFinanziariSetAcquisti(double acq);
    void DatiFinanziariSetVendite(double ven);
    void DatiFinanziariSetBilancio(double bil);
    vector<acquisti> getListaAcquisti() const;
    vector<vendite> getListaVendite() const;
    double getTotAcquisti() const;
    double getTotVendite() const;
    double getBilancio() const;
    void DatiFinanziariTogliAcquisto(u_int id);
    void DatiFinanziariTogliVendita(u_int id);
};

#endif // DATI_FINANZIARI_H
