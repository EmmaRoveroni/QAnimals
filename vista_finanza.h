#ifndef VISTA_FINANZA_H
#define VISTA_FINANZA_H
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "vista_finanza_acquisti.h"
#include "vista_finanza_vendite.h"
#include "vista_finanza_bilancio.h"
#include "dati_finanziari.h"
class vista_finanza : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    double totaleacquisti;
    double totalevendite;
    double bilancio;
    QVBoxLayout* qvb;
    QHBoxLayout* qhb1;
    QHBoxLayout* qhb2;
    vista_finanza_acquisti* vistafinanzaacquisti;
    vista_finanza_vendite* vistafinanzavendite;
    vista_finanza_bilancio* vistafinanzabilancio;
    void BuildVistaFinanza();
public:
   void VistaFinanzaSetController(Controller* ctr);
   explicit vista_finanza(QWidget *parent = nullptr);
   vista_finanza_acquisti* GetVistaFinanzaAcquisti() const;
   vista_finanza_vendite* GetVistaFinanzaVendite() const;
   vista_finanza_bilancio* GetVistaFinanzaBilancio() const;
   void VistaFinanzaAggiungiAcquisto(double acq);
   void VistaFinanzaAggiungiVendita(double ven);
   void VistaFinanzaUpdateAcquisto(double prezzo);
   void VistaFinanzaUpdateVendita(double prezzo);
};

#endif // VISTA_FINANZA_H
