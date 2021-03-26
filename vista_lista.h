#ifndef VISTA_LISTA_H
#define VISTA_LISTA_H

#include "model.h"
#include <vista_lista_add.h>
#include "vista_lista_options.h"
#include "vista_lista_vendita.h"
#include <vista_add_button.h>
#include <QTableWidget>
#include "QTableWidgetItem"
#include <QVBoxLayout>
#include <QMessageBox>

class Controller;
class vista_lista:public QWidget
{
    Q_OBJECT
private:
    Controller * controller;
    QTableWidget* inventario;
    QVBoxLayout* qvb;
    QPushButton* qpb;
    vista_lista_add* vistalistaadd;
    vista_add_button* vistaaddbutton;
    vista_lista_options* vistalistaoptions;
    vista_lista_vendita* vistalistavendita;
    void BuildVistaLista();
public:
    vista_lista();
    void VistaListaSetController(Controller* ctr);
    void VistaListaAggiungiAnimale(u_int id,string an,string specie,double peso,double altezza,double lunghezza,u_int eta,
                                   bool inestinzione,string sede);
    QTableWidget* GetInventario() const;
    vista_lista_add* GetVistaListaAdd() const;
    vista_lista_options* GetVistaListaOptions() const;
    vista_lista_vendita* GetVistaListaVendita() const;
signals:
    void DatiRimozione(u_int id ,u_int riga);
public slots:
     void OnCellDoubleClicked(int riga,int col);
     void OnApriVistaListaAdd() const;
};

#endif // VISTA_LISTA_H
