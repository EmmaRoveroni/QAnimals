#ifndef VISTA_FINANZA_VENDITE_H
#define VISTA_FINANZA_VENDITE_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "vista_add_button.h"
using std::string;
#define u_int unsigned short

class Controller;

class vista_finanza_vendite : public QWidget
{
    Q_OBJECT
private:
    Controller * controller;
    QVBoxLayout* qvb;
    QTableWidget* tabellavendite;
    QLabel* ql;
public:
    explicit vista_finanza_vendite(QWidget *parent = nullptr);
    void VistaFinanzaVenditeSetController(Controller* ctr);
    void VistaFinanzaVenditeAggiungiVendita(u_int id,string specie,double prezzo,QDate data);
public slots:
    void OnCellDoubleClicked(int riga,int col);
signals:
    void RimuoviVendita(u_int id,double prezzo);
};

#endif // VISTA_FINANZA_VENDITE_H
