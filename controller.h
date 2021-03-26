#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vista.h"
#include "model.h"
#include <QMessageBox>
class Controller : public QObject
{
    Q_OBJECT
private:
    Vista* vista;
    Model* model;
    vista_lista* vistalista;
    vista_lista_add* vistalistaadd;
    vista_lista_vendita* vistalistavendita;
    vista_finanza_acquisti* vistafinanzaacquisti;
    vista_finanza_vendite* vistafinanzavendite;
    QMessageBox* messaggioerrore;
public:
    explicit Controller(Model* a,QObject *parent = nullptr);
    void ControllerSetVista(Vista* v);
    Model* ControllerGetModel() const;
    Vista* ControllerGetVista() const;
    void ControllerInputOk(u_int id,string specie,double peso,double altezza,double lunghezza,u_int eta,
                           bool inestinzione,string sede,double caratteristicaspecie,double prezzo);
    void Controllerdoubleid(u_int id) const;
    Animale* ControllerSearchAnimale(u_int id) const;
    void ControllerUpdateAcquisto(double a) const;
    void ControllerUpdateVendita(double v) const;
    void ControllerUpdateBilancio(double b) const;
public slots:
     void OnDatiAggiunta(u_int id,string tipo,string specie,double peso,double altezza,double lunghezza,u_int eta,
                         bool inestinzione,string sede,bool frugivoro,bool folivoro,bool granivoro,bool nettarivoro,
                         bool velenoso,bool necrofago,double caratteristicaspecie,bool acquistato,
                         double prezzo,QDate data);
     void OnDatiVendita(u_int id,string specie,double prezzo,QDate data);
     void OnDatiRimozione(u_int id,u_int riga);
     void OnRimuoviAcquisto(u_int id,double prezzo);
     void OnRimuoviVendita(u_int id,double prezzo);
     void OnControllerSalvataggio();
signals:
    void ErroreInputSbagliato();
    void ErroreIdDoppio();
};

#endif // CONTROLLER_H
