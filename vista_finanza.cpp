#include "vista_finanza.h"
#include "controller.h"
vista_finanza::vista_finanza(QWidget *parent) :QWidget(parent)
{
    controller = nullptr;
    totaleacquisti = 0;
    totalevendite = 0;
    bilancio = 0;
    qvb = new QVBoxLayout();
    qhb1 = new QHBoxLayout();
    qhb2 = new QHBoxLayout();
    vistafinanzaacquisti = new vista_finanza_acquisti();
    vistafinanzavendite = new vista_finanza_vendite();
    vistafinanzabilancio = new vista_finanza_bilancio();
    qhb2->addWidget(vistafinanzaacquisti );
    qhb2->addWidget(vistafinanzavendite);
    qhb2->addWidget(vistafinanzabilancio);
    qvb->addLayout(qhb1);
    qvb->addLayout(qhb2);
    setLayout(qvb);
}


void vista_finanza::BuildVistaFinanza()
{
    dati_finanziari d = controller->ControllerGetModel()->Modelcaricamentodatifinanziari();
    vector<acquisti> va = d.getListaAcquisti();
    vector<vendite> vv = d.getListaVendite();
    for(vector<acquisti>::iterator it = va.begin();it != va.end();it++){
        vistafinanzaacquisti->VistaFinanzaAcquistiAggiungiAcquisto((*it).getId(),(*it).getTipoA(),(*it).getPrezzoA(),QDate::fromString(QString::fromStdString((*it).getData())));
    }
    for(vector<vendite>::iterator it = vv.begin();it != vv.end();it++){
        vistafinanzavendite->VistaFinanzaVenditeAggiungiVendita((*it).getId(),(*it).getTipoA(),(*it).getPrezzoV(),QDate::fromString(QString::fromStdString((*it).getData())));
    }
    vistafinanzabilancio->VistaFinanzaBilancioSetValoriIniziali(d.getTotAcquisti(),d.getTotVendite(),d.getBilancio());
    totaleacquisti = d.getTotAcquisti();
    totalevendite = d.getTotVendite();
    bilancio = d.getBilancio();
}

void vista_finanza::VistaFinanzaSetController(Controller* ctr){
    controller = ctr;
    BuildVistaFinanza();
}


vista_finanza_acquisti* vista_finanza::GetVistaFinanzaAcquisti() const
{
    return vistafinanzaacquisti;
}
vista_finanza_vendite* vista_finanza::GetVistaFinanzaVendite() const
{
    return vistafinanzavendite;
}
void vista_finanza::VistaFinanzaAggiungiAcquisto(double acq)
{
    totaleacquisti += acq;
    bilancio -= acq;
    vistafinanzabilancio->VistaFinanzaBilancioSetAcquisto(totaleacquisti);
    vistafinanzabilancio->VistaFinanzaBilancioSetBilancio(bilancio);
}

void vista_finanza::VistaFinanzaAggiungiVendita(double ven)
{
    totalevendite += ven;
    bilancio += ven;
    vistafinanzabilancio->VistaFinanzaBilancioSetVendita(totalevendite);
    vistafinanzabilancio->VistaFinanzaBilancioSetBilancio(bilancio);
}

vista_finanza_bilancio *vista_finanza::GetVistaFinanzaBilancio() const
{
    return vistafinanzabilancio;
}

void vista_finanza::VistaFinanzaUpdateAcquisto(double prezzo)
{
    totaleacquisti -= prezzo;
    bilancio += prezzo;
    vistafinanzabilancio->VistaFinanzaBilancioSetAcquisto(totaleacquisti);
    vistafinanzabilancio->VistaFinanzaBilancioSetBilancio(bilancio);
}

void vista_finanza::VistaFinanzaUpdateVendita(double prezzo)
{
    totalevendite -= prezzo;
    bilancio -= prezzo;
    vistafinanzabilancio->VistaFinanzaBilancioSetVendita(totalevendite);
    vistafinanzabilancio->VistaFinanzaBilancioSetBilancio(bilancio);
}

