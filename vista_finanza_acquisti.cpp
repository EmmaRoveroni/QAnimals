#include "vista_finanza_acquisti.h"
#include "controller.h"


vista_finanza_acquisti::vista_finanza_acquisti(QWidget *parent) : QWidget(parent)
{
    controller = nullptr;
    qvb = new QVBoxLayout();
    tabellaacquisti = new QTableWidget();
    ql = new QLabel("ACQUISTI");
    QStringList name_col;
    name_col<<"ID"<<"TipoAnimale"<<"PrezzoAcquisto"<<"Data"<<"";
    tabellaacquisti->setColumnCount(5);
    tabellaacquisti->setHorizontalHeaderLabels(name_col);
    tabellaacquisti->setColumnWidth(0,70);tabellaacquisti->setColumnWidth(1,150);
    tabellaacquisti->setColumnWidth(2,130);tabellaacquisti->setColumnWidth(3,150);
    tabellaacquisti->setColumnWidth(4,30);
    qvb->addWidget(ql);
    qvb->addWidget(tabellaacquisti);
    setLayout(qvb);
}

void vista_finanza_acquisti::VistaFinanzaAcquistiAggiungiAcquisto(u_int id, string specie, double prezzo, QDate data)
{
    tabellaacquisti->setRowCount(tabellaacquisti->rowCount()+1);
    int riga = tabellaacquisti->rowCount()-1;
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(id));
    tabellaacquisti->setItem(riga,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* qtwi0 = new QTableWidgetItem();
    qtwi0->setText(QString::fromStdString(specie));
    tabellaacquisti->setItem(riga,1,qtwi0);
    qtwi0->setFlags(qtwi0->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* qtwi1 = new QTableWidgetItem();
    qtwi1->setText(QString::number(prezzo,'f',2));
    qtwi1->setFlags(qtwi1->flags() ^ Qt::ItemIsEditable);
    tabellaacquisti->setItem(riga,2,qtwi1);
    QTableWidgetItem* qtwi2 = new QTableWidgetItem();
    qtwi2->setText(data.toString());
    qtwi2->setFlags(qtwi2->flags() ^ Qt::ItemIsEditable);
    tabellaacquisti->setItem(riga,3,qtwi2);
    QTableWidgetItem* qtwd = new QTableWidgetItem();
    tabellaacquisti->setItem(riga,4,qtwd);
    qtwd->setIcon(QIcon(":/pre/icons/delete.png"));
    qtwd->setFlags(qtwd->flags() ^ Qt::ItemIsEditable);
}

void vista_finanza_acquisti::OnCellDoubleClicked(int riga, int col)
{
    if(col==4){
    QMessageBox* msg = new QMessageBox();
    msg->setWindowTitle("Rimuovi acquisto");
    msg->setIcon(QMessageBox::Question);
    msg->setText("Eliminare in modo permanente questo acquisto?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg->setDefaultButton(QMessageBox::No);
    int risposta=msg->exec();
    if(risposta==QMessageBox::Yes){
        QTableWidgetItem* id=tabellaacquisti->takeItem(riga,0);
        QTableWidgetItem* prezzo=tabellaacquisti->takeItem(riga,2);
        emit RimuoviAcquisto(std::stoi(id->text().toStdString()),std::stod(prezzo->text().toStdString()));
        tabellaacquisti->removeRow(riga);
        }
    }
}
void vista_finanza_acquisti::VistaFinanzaAcquistiSetController(Controller* ctr){
    controller = ctr;
    connect(tabellaacquisti,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(OnCellDoubleClicked(int,int)));
}
