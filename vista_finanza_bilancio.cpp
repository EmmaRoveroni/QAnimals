#include "vista_finanza_bilancio.h"
#include "controller.h"

vista_finanza_bilancio::vista_finanza_bilancio(QWidget *parent) : QWidget(parent)
{
    controller = nullptr;
    qvb = new QVBoxLayout();
    tabellabilancio = new QTableWidget();
    ql = new QLabel("BILANCIO");
    QStringList name_col;
    name_col<<"Costo";
    QStringList name_row;
    name_row<<"TotaleAcquisti" << "TotaleVendite" << "Bilancio";
    tabellabilancio->setColumnCount(1);
    tabellabilancio->setRowCount(3);
    tabellabilancio->setHorizontalHeaderLabels(name_col);
    tabellabilancio->setVerticalHeaderLabels(name_row);
    tabellabilancio->setColumnWidth(0,100);
    qvb->addWidget(ql);
    qvb->addWidget(tabellabilancio);
    setLayout(qvb);
}

void vista_finanza_bilancio::VistaFinanzaBilancioSetValoriIniziali(double acq, double ven, double bil)
{

    if(tabellabilancio->item(0,0))
    {
        tabellabilancio->takeItem(0,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(acq,'f',2));
    tabellabilancio->setItem(0,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);

    if(tabellabilancio->item(1,0))
    {
        tabellabilancio->takeItem(1,0);
    }
    QTableWidgetItem* qtwi1 = new QTableWidgetItem();
    qtwi1->setText(QString::number(ven,'f',2));
    tabellabilancio->setItem(1,0,qtwi1);
    qtwi1->setFlags(qtwi1->flags() ^ Qt::ItemIsEditable);

    if(tabellabilancio->item(2,0))
    {
        tabellabilancio->takeItem(2,0);
    }
    QTableWidgetItem* qtwi2 = new QTableWidgetItem();
    qtwi2->setText(QString::number(bil,'f',2));
    tabellabilancio->setItem(2,0,qtwi2);
    qtwi2->setFlags(qtwi2->flags() ^ Qt::ItemIsEditable);
}

void vista_finanza_bilancio::VistaFinanzaBilancioSetAcquisto(double acq)
{
    if(tabellabilancio->item(0,0))
    {
        tabellabilancio->takeItem(0,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(acq,'f',2));
    tabellabilancio->setItem(0,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    controller->ControllerUpdateAcquisto(acq);

}

void vista_finanza_bilancio::VistaFinanzaBilancioSetVendita(double ven)
{
    if(tabellabilancio->item(1,0))
    {
        tabellabilancio->takeItem(1,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(ven,'f',2));
    tabellabilancio->setItem(1,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    controller->ControllerUpdateVendita(ven);
}

void vista_finanza_bilancio::VistaFinanzaBilancioSetBilancio(double bil)
{
    if(tabellabilancio->item(2,0))
    {
        tabellabilancio->takeItem(2,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(bil,'f',2));
    tabellabilancio->setItem(2,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    controller->ControllerUpdateBilancio(bil);
}


void vista_finanza_bilancio::VistaFinanzaBilancioSetController(Controller *ctr)
{
    controller = ctr;
}

