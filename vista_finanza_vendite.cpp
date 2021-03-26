#include "vista_finanza_vendite.h"
#include "controller.h"


vista_finanza_vendite::vista_finanza_vendite(QWidget *parent) : QWidget(parent)
{
    qvb = new QVBoxLayout();
    tabellavendite = new QTableWidget();
    ql = new QLabel("VENDITE");
    QStringList name_col;
    name_col<<"ID"<<"TipoAnimale"<<"PrezzoVendita"<<"Data"<<"";
    tabellavendite->setColumnCount(5);
    tabellavendite->setHorizontalHeaderLabels(name_col);
    tabellavendite->setColumnWidth(0,70);tabellavendite->setColumnWidth(1,150);
    tabellavendite->setColumnWidth(2,130);tabellavendite->setColumnWidth(3,150);
    tabellavendite->setColumnWidth(4,30);
    qvb->addWidget(ql);
    qvb->addWidget(tabellavendite);
    setLayout(qvb);
}

void vista_finanza_vendite::VistaFinanzaVenditeSetController(Controller* ctr){
    controller = ctr;
    connect(tabellavendite,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(OnCellDoubleClicked(int,int)));
}

void vista_finanza_vendite::VistaFinanzaVenditeAggiungiVendita(unsigned short id, std::string specie, double prezzo, QDate data)
{
    tabellavendite->setRowCount(tabellavendite->rowCount()+1);
    int riga = tabellavendite->rowCount()-1;
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(id));
    tabellavendite->setItem(riga,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* qtwi0 = new QTableWidgetItem();
    qtwi0->setText(QString::fromStdString(specie));
    tabellavendite->setItem(riga,1,qtwi0);
    qtwi0->setFlags(qtwi0->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* qtwi1 = new QTableWidgetItem();
    qtwi1->setText(QString::number(prezzo,'f',2));
    qtwi1->setFlags(qtwi1->flags() ^ Qt::ItemIsEditable);
    tabellavendite->setItem(riga,2,qtwi1);
    QTableWidgetItem* qtwi2 = new QTableWidgetItem();
    qtwi2->setText(data.toString());
    qtwi2->setFlags(qtwi2->flags() ^ Qt::ItemIsEditable);
    tabellavendite->setItem(riga,3,qtwi2);
    QTableWidgetItem* qtwd = new QTableWidgetItem();
    tabellavendite->setItem(riga,4,qtwd);
    qtwd->setIcon(QIcon(":/pre/icons/delete.png"));
    qtwd->setFlags(qtwd->flags() ^ Qt::ItemIsEditable);
}

void vista_finanza_vendite::OnCellDoubleClicked(int riga, int col)
{
    if(col==4){
    QMessageBox* msg = new QMessageBox();
    msg->setWindowTitle("Rimuovi vendita");
    msg->setIcon(QMessageBox::Question);
    msg->setText("Eliminare in modo permanente questa vendita?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg->setDefaultButton(QMessageBox::No);
    int risposta=msg->exec();
    if(risposta==QMessageBox::Yes){
        QTableWidgetItem* id=tabellavendite->takeItem(riga,0);
        QTableWidgetItem* prezzo=tabellavendite->takeItem(riga,2);
        emit RimuoviVendita(std::stoi(id->text().toStdString()),std::stod(prezzo->text().toStdString()));
        tabellavendite->removeRow(riga);
        }
    }
}


