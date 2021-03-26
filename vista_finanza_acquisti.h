#ifndef VISTA_FINANZA_ACQUISTI_H
#define VISTA_FINANZA_ACQUISTI_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "vista_add_button.h"
using std::string;
#define u_int unsigned short

class Controller;

class vista_finanza_acquisti : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    QVBoxLayout* qvb;
    QTableWidget* tabellaacquisti;
    QLabel* ql;
public:
    explicit vista_finanza_acquisti(QWidget *parent = nullptr);
    void VistaFinanzaAcquistiSetController(Controller* ctr);
    void VistaFinanzaAcquistiAggiungiAcquisto(u_int id,string specie,double prezzo,QDate data);
public slots:
    void OnCellDoubleClicked(int riga,int col);
signals:
    void RimuoviAcquisto(u_int id,double prezzo);
};

#endif // VISTA_FINANZA_ACQUISTI_H
