#include "controller.h"
#include "rinoceronte.h"
#include "alligatore.h"
#include "orso.h"
#include "acquisti.h"
#include "vendite.h"
#include "exceptions.h"
#include <typeinfo>
using std::string;
#include <vector>
using std::vector;


Controller::Controller(Model* a,QObject *parent) : QObject(parent),model(a)
{
    vista = nullptr;
    messaggioerrore=new QMessageBox();
}

void Controller::ControllerSetVista(Vista *v) {
    vista =v;
    vistalista = v->GetVistaLista();
    vistalistaadd = v->GetVistaListaAdd();
    vistalistavendita = v->GetVistaListaVendita();
    vistafinanzaacquisti = v->GetVistaFinanza()->GetVistaFinanzaAcquisti();
    vistafinanzavendite = v->GetVistaFinanza()->GetVistaFinanzaVendite();
    connect(vistalistaadd,SIGNAL(DatiAggiunta(unsigned short,string,string,double,double,double,unsigned short,
    bool,string,bool,bool,bool,bool,bool,bool,double,bool,double,QDate)),this,
    SLOT(OnDatiAggiunta(unsigned short,string,string,double,double,double,unsigned short,bool,string,bool,bool,
    bool,bool,bool,bool,double,bool,double,QDate)));
    connect(vistalistavendita,SIGNAL(DatiVendita(unsigned short,string,double,QDate)),this,
            SLOT(OnDatiVendita(unsigned short,string,double,QDate)));
    connect(vistalista,SIGNAL(DatiRimozione(unsigned short,unsigned short)),this,SLOT(OnDatiRimozione(unsigned short,unsigned short)));
    connect(vistafinanzaacquisti,SIGNAL(RimuoviAcquisto(unsigned short,double)),this,
            SLOT(OnRimuoviAcquisto(unsigned short,double)));
    connect(vistafinanzavendite,SIGNAL(RimuoviVendita(unsigned short,double)),this,
            SLOT(OnRimuoviVendita(unsigned short,double)));

}

void Controller::OnControllerSalvataggio()
{
    model->Modelsaved();
}

void Controller::ControllerInputOk(unsigned short id, string specie, double peso, double altezza, double lunghezza, unsigned short eta, bool inestinz,
                                   string sede, double caratteristicaspecie, double prezzo)
{
    if (specie == "--select--") throw exceptions::inputnotok();
    else if (sede == "--select--") throw exceptions::inputnotok();
    else if (typeid(id)!=typeid(u_int) || id <= 0) throw exceptions::inputnotok();
    else if (typeid(peso)!=typeid(double) || peso <= 0) throw exceptions::inputnotok();
    else if (typeid(altezza)!=typeid(double) || altezza <= 0) throw exceptions::inputnotok();
    else if (typeid(lunghezza)!=typeid(double) || lunghezza <= 0) throw exceptions::inputnotok();
    else if (typeid(eta)!=typeid(u_int) || eta <= 0) throw exceptions::inputnotok();
    else if (typeid(inestinz)!=typeid(bool)) throw exceptions::inputnotok();
    else if (typeid(sede)!=typeid(string)) throw exceptions::inputnotok();
    else if (typeid(caratteristicaspecie)!=typeid(double) || caratteristicaspecie <= 0) throw exceptions::inputnotok();
    else if (typeid(prezzo)!=typeid(double) || prezzo < 0) throw exceptions::inputnotok();
}


Animale* Controller::ControllerSearchAnimale(unsigned short id) const
{

    return model->Modelsearchanimale(id);
}

Model* Controller::ControllerGetModel() const
{
    return model;
}

Vista *Controller::ControllerGetVista() const
{
    return vista;
}

void Controller::Controllerdoubleid(unsigned short id) const
{
    if (!model->Modelverifyid(id)){
        throw(exceptions::iddoppio());
    }
}

void Controller::ControllerUpdateAcquisto(double acquisto) const
{
    model->ModelUpdateAcquisto(acquisto);
}

void Controller::ControllerUpdateVendita(double vendita) const
{
    model->ModelUpdateVendita(vendita);
}

void Controller::ControllerUpdateBilancio(double bilancio) const
{
    model->ModelUpdateBilancio(bilancio);
}


void Controller::OnDatiAggiunta(unsigned short id, string tipo, string specie, double peso, double altezza, double lunghezza, unsigned short eta,
                                bool inestinzione, string sede, bool frugivoro, bool folivoro, bool granivoro,
                                bool nettarivoro, bool velenoso, bool necrofago, double caratteristicaspecie,
                                bool acquisto, double prezzo, QDate data)
{
    try{ControllerInputOk(id,specie,peso,altezza,lunghezza,eta,inestinzione,sede,caratteristicaspecie,prezzo);}
    catch(exceptions::inputnotok) {
        emit ErroreInputSbagliato();
        return;
    };
    try{Controllerdoubleid(id);}
    catch(exceptions::iddoppio) {
        emit ErroreIdDoppio();
        return;
    };
    Animale* animal = nullptr;
    if (specie == "Rinoceronte")
    {
        vector<Tipo> Dieta;
        if(frugivoro == true){
            Dieta.push_back(Frugivoro);
        }
        if(folivoro == true){
            Dieta.push_back(Folivoro);
        }
        if(granivoro == true){
            Dieta.push_back(Granivoro);
        }
        if(nettarivoro == true){
            Dieta.push_back(Nettarivoro);
        }
        animal =  new Rinoceronte(id,peso,altezza,lunghezza,eta,inestinzione,sede,Dieta,caratteristicaspecie);
    }
    else if (specie == "Alligatore")
    {
        animal = new Alligatore(id,peso,altezza,lunghezza,eta,inestinzione,sede,velenoso,necrofago,caratteristicaspecie);
    }
    else
    {
        vector<Tipo> Dieta;
        if(frugivoro == true){
            Dieta.push_back(Frugivoro);
        }
        if(folivoro == true){
            Dieta.push_back(Folivoro);
        }
        if(granivoro == true){
            Dieta.push_back(Granivoro);
        }
        if(nettarivoro == true){
            Dieta.push_back(Nettarivoro);
        }
        animal = new Orso(id,peso,altezza,lunghezza,eta,inestinzione,sede,Dieta,velenoso,necrofago,caratteristicaspecie);
    }
    model->ModelAggiungiAnimale(animal);
    vista->VistaAggiungiAnimale(id,tipo,specie,peso,altezza,lunghezza,eta,inestinzione,sede);
    if (acquisto == true)
    {
        vista->VistaAggiungiAcquisto(id,specie,prezzo,data);
        acquisti* a= new acquisti(id,specie,prezzo,data.toString().toStdString());
        model->ModelAggiungiAcquisto(*a);
    }
}

void Controller::OnDatiVendita(unsigned short id, string specie, double prezzo, QDate data)
{
    vista->VistaAggiungiVendita(id,specie,prezzo,data);
    vendite* v= new vendite(id,specie,prezzo,data.toString().toStdString());
    model->ModelAggiungiVendita(*v);
}

void Controller::OnDatiRimozione(unsigned short id, unsigned short riga)
{
    model->ModelRemoveAnimale(id);
    vista->GetVistaLista()->GetInventario()->removeRow(riga);
}

void Controller::OnRimuoviAcquisto(unsigned short id, double prezzo)
{
    model->Modelremoveacquisto(id);
    vista->GetVistaFinanza()->VistaFinanzaUpdateAcquisto(prezzo);
}

void Controller::OnRimuoviVendita(unsigned short id, double prezzo)
{
    model->Modelremovevendita(id);
    vista->GetVistaFinanza()->VistaFinanzaUpdateVendita(prezzo);
}


