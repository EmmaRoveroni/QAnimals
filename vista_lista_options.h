#ifndef VISTA_LISTA_OPTIONS_H
#define VISTA_LISTA_OPTIONS_H
#include "model.h"
#include "vista_lista_add.h"
#include "vista_add_button.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
class Controller;
class vista_lista_options : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    QDialog* messaggio;
    QHBoxLayout* qhb;
    QVBoxLayout* qvb1;
    QVBoxLayout* qvb2;
    QVBoxLayout* qvb3;
    QVBoxLayout* qvb4;
    QVBoxLayout* qvb5;
    QVBoxLayout* qvb6;
    QVBoxLayout* qvb7;
    QVBoxLayout* qvb8;
    QVBoxLayout* qvb9;
    QVBoxLayout* qvb10;
    QVBoxLayout* qhbGrasso;
    QVBoxLayout* qhbVecchio;
    QVBoxLayout* qhbValore;
    QLabel* CaratteristicheTipoTitolo;
    QLabel* CaratteristicheSpecieTitolo;
    QLabel* AttributiAnimaleTitolo;
    QLabel* caratteristica1;
    QLabel* caratteristica2;
    QLabel* caratteristica3;
    QLabel* caratteristica4;
    QLabel* caratteristica5;
    QLabel* caratteristica6;
    QLabel* caratteristicaSpecie;
    QLabel* grasso;
    QLabel* vecchio;
    QLabel* valore;
    QLabel* attributititolo;
public:
    explicit vista_lista_options(QWidget *parent = nullptr);
    void VistaListaOptionsSetController(Controller* ctr);
    QDialog* getmessaggio() const;
    QLabel* getcaratteristica1() const;
    QLabel* getcaratteristica2() const;
    QLabel* getcaratteristica3() const;
    QLabel* getcaratteristica4() const;
    QLabel* getcaratteristica5() const;
    QLabel* getcaratteristica6() const;
    QLabel* getcaratteristicaSpecie() const;
    QLabel* getgrasso() const;
    QLabel* getvecchio() const;
    QLabel* getvalore() const;
};

#endif // VISTA_LISTA_OPTIONS_H
