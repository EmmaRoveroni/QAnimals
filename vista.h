#ifndef VISTA_H
#define VISTA_H

#include "vista_lista.h"
#include "vista_finanza.h"
#include <QBoxLayout>
#include <QMenuBar>
#include <QMessageBox>

class Controller;

class Vista:public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    vista_finanza* vistafinanza;
    vista_lista* vistalista;
    QVBoxLayout* mainlayout;
    QTabWidget* tabwidget;
    QMenuBar* menubar;
    QMenu* menu;
    QAction* exit;
    QAction* save;
    QMessageBox* messaggioerrore;
    void VistaAggiungiMenu();
public:
    Vista(QWidget *parent = nullptr);
    void VistaSetController(Controller* ctr);
    void VistaAggiungiAnimale(u_int id, string tipo, string specie,double peso,double altezza,double lunghezza,u_int eta,
                              bool inestinzione, string sede);
    void VistaAggiungiAcquisto(u_int id, string specie, double prezzo, QDate data);
    void VistaAggiungiVendita(u_int id,string specie,double prezzo,QDate data);
    vista_lista* GetVistaLista() const;
    vista_lista_add* GetVistaListaAdd() const;
    vista_lista_vendita* GetVistaListaVendita() const;
    vista_finanza* GetVistaFinanza() const;
public slots:
    void OnErroreInputSbagliato();
    void OnErroreIdDoppio();
};

#endif // VISTA_H
