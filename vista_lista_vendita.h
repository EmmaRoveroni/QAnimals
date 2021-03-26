#ifndef VISTA_LISTA_VENDITA_H
#define VISTA_LISTA_VENDITA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QDialog>
#include <QPushButton>
using std::string;
#define u_int unsigned short

class Controller;

class vista_lista_vendita : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    QPushButton* qpb;
    QVBoxLayout* qvb;
    QLabel* dativendita;
    QLabel* prezzotitolo;
    QLabel* datatitolo;
    QLineEdit* prezzo;
    QDateEdit* data;
    QDialog* qd;
    u_int riga;
public:
    explicit vista_lista_vendita(QWidget *parent = nullptr);
    void VistaListaVenditaSetController(Controller* ctr);
    QDialog* getdialog() const;
    void assegnariga(u_int r);
    QDateEdit* getdata() const;
    QLineEdit* getprezzo() const;
signals:
    void DatiVendita(u_int id,string specie,double prezzo,QDate data);
public slots:
    void OnVenditaConfermata();
};

#endif // VISTA_LISTA_VENDITA_H
