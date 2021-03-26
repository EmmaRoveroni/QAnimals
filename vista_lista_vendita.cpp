#include "vista_lista_vendita.h"
#include "controller.h"

vista_lista_vendita::vista_lista_vendita(QWidget *parent) : QWidget(parent)
{
    controller = nullptr;
    qd = new QDialog();
    qd->setWindowTitle("Vendita Animale");
    qd->setMinimumWidth(300);
    qpb = new QPushButton();
    qpb->setText("Ok");
    qvb = new QVBoxLayout();
    dativendita = new QLabel();
    dativendita->setText("Dati Vendita");
    prezzotitolo = new QLabel();
    prezzotitolo->setText("Prezzo Vendita");
    datatitolo = new QLabel();
    datatitolo->setText("Data vendita");
    prezzo = new QLineEdit();
    data = new QDateEdit();
    qvb->addWidget(dativendita);
    qvb->addWidget(prezzotitolo);
    qvb->addWidget(prezzo);
    qvb->addWidget(datatitolo);
    qvb->addWidget(data);
    qvb->addWidget(qpb);
    qvb->addStretch(0);
    qd->setLayout(qvb);
    connect(qpb,SIGNAL(clicked()),this,SLOT(OnVenditaConfermata()));
    connect(qpb,SIGNAL(clicked()),qd,SLOT(close()));
}

QDialog *vista_lista_vendita::getdialog() const
{
    return qd;
}

void vista_lista_vendita::VistaListaVenditaSetController(Controller *ctr)
{
    controller = ctr;
}

void vista_lista_vendita::assegnariga(u_int r)
{
    riga = r;
}

QDateEdit* vista_lista_vendita::getdata() const
{
    return data;
}

QLineEdit* vista_lista_vendita::getprezzo() const
{
    return prezzo;
}

void vista_lista_vendita::OnVenditaConfermata()
{
    QTableWidgetItem* id=controller->ControllerGetVista()->GetVistaLista()->GetInventario()->takeItem(riga,0);
    controller->ControllerGetVista()->GetVistaLista()->GetInventario()->setItem(riga,0,id);
    QTableWidgetItem* specie=controller->ControllerGetVista()->GetVistaLista()->GetInventario()->takeItem(riga,2);
    emit DatiVendita(std::stoi(id->text().toStdString()),specie->text().toStdString(),prezzo->text().toDouble(),
                     data->date());
}
