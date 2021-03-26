#include "vista_lista_options.h"
#include "controller.h"
vista_lista_options::vista_lista_options(QWidget *parent) : QWidget(parent)
{
    controller = nullptr;
    messaggio = new QDialog();
    QString titolofinestra = "Info";
    messaggio->setWindowTitle(titolofinestra);
    qhb = new QHBoxLayout();
    qvb1 = new QVBoxLayout();
    qvb2 = new QVBoxLayout();
    qvb3 = new QVBoxLayout();
    caratteristica1 = new QLabel();
    caratteristica2 = new QLabel();
    caratteristica3 = new QLabel();
    caratteristica4 = new QLabel();
    caratteristica5 = new QLabel();
    caratteristica6 = new QLabel();
    grasso = new QLabel();
    vecchio = new QLabel();
    valore = new QLabel();
    qvb4 = new QVBoxLayout();
    qvb5 = new QVBoxLayout();
    qvb6 = new QVBoxLayout();
    qvb7 = new QVBoxLayout();
    qvb8 = new QVBoxLayout();
    qvb9 = new QVBoxLayout();
    qvb10 = new QVBoxLayout();
    qhbGrasso = new QVBoxLayout();
    qhbVecchio = new QVBoxLayout();
    qhbValore = new QVBoxLayout();
    caratteristica1->hide();
    caratteristica2->hide();
    caratteristica3->hide();
    caratteristica4->hide();
    caratteristica5->hide();
    caratteristica6->hide();
    caratteristicaSpecie = new QLabel();
    CaratteristicheTipoTitolo = new QLabel("Caratteristiche Tipo");
    CaratteristicheSpecieTitolo = new QLabel("Caratteristiche Specie");
    AttributiAnimaleTitolo = new QLabel("Attributi Animale");
    qvb1->addWidget(CaratteristicheTipoTitolo);
    qvb1->setAlignment(CaratteristicheTipoTitolo,Qt::AlignTop);
    qvb2->addWidget(CaratteristicheSpecieTitolo);
    qvb2->setAlignment(CaratteristicheSpecieTitolo,Qt::AlignTop);
    qvb3->addWidget(AttributiAnimaleTitolo);
    qvb3->setAlignment(AttributiAnimaleTitolo,Qt::AlignTop);
    qvb4->addWidget(caratteristica1);
    qvb5->addWidget(caratteristica2);
    qvb6->addWidget(caratteristica3);
    qvb7->addWidget(caratteristica4);
    qvb8->addWidget(caratteristica5);
    qvb9->addWidget(caratteristica6);
    qvb10->addWidget(caratteristicaSpecie);
    qhbGrasso->addWidget(grasso);
    qhbVecchio->addWidget(vecchio);
    qhbValore->addWidget(valore);
    qvb1->addLayout(qvb4);
    qvb1->addLayout(qvb5);
    qvb1->addLayout(qvb6);
    qvb1->addLayout(qvb7);
    qvb1->addLayout(qvb8);
    qvb1->addLayout(qvb9);
    qvb2->addLayout(qvb10);
    qvb3->addLayout(qhbGrasso);
    qvb3->addLayout(qhbVecchio);
    qvb3->addLayout(qhbValore);
    qvb1->addStretch(0);
    qvb2->addStretch(0);
    qvb3->addStretch(0);
    qvb4->setAlignment(qvb4,Qt::AlignTop);
    qvb1->setAlignment(qvb5,Qt::AlignTop);
    qvb1->setAlignment(qvb6,Qt::AlignTop);
    qvb1->setAlignment(qvb7,Qt::AlignTop);
    qvb1->setAlignment(qvb8,Qt::AlignTop);
    qvb1->setAlignment(qvb9,Qt::AlignTop);
    qvb2->setAlignment(qvb10,Qt::AlignTop);
    qvb3->setAlignment(qhbGrasso,Qt::AlignTop);
    qvb3->setAlignment(qhbVecchio,Qt::AlignTop);
    qvb3->setAlignment(qhbValore,Qt::AlignTop);
    qhb->addLayout(qvb1);
    qhb->addLayout(qvb2);
    qhb->addLayout(qvb3);
    messaggio->setLayout(qhb);
}

QDialog *vista_lista_options::getmessaggio() const
{
    return messaggio;
}

QLabel *vista_lista_options::getcaratteristica1() const
{
    return caratteristica1;
}

QLabel *vista_lista_options::getcaratteristica2() const
{
    return caratteristica2;
}

QLabel *vista_lista_options::getcaratteristica3() const
{
    return caratteristica3;
}

QLabel *vista_lista_options::getcaratteristica4() const
{
    return caratteristica4;
}

QLabel *vista_lista_options::getcaratteristica5() const
{
    return caratteristica5;
}

QLabel *vista_lista_options::getcaratteristica6() const
{
    return caratteristica6;
}


QLabel* vista_lista_options::getcaratteristicaSpecie() const
{
    return caratteristicaSpecie;
}

QLabel *vista_lista_options::getgrasso() const
{
    return grasso;
}

QLabel *vista_lista_options::getvecchio() const
{
    return vecchio;
}

QLabel *vista_lista_options::getvalore() const
{
    return valore;
}
void vista_lista_options::VistaListaOptionsSetController(Controller* ctr){
    controller = ctr;
}
