#include "controller.h"
#include <typeinfo>
#include "erbivoro.h"
using std::string;

vista_lista::vista_lista()
{
    controller = nullptr;
    qvb = new QVBoxLayout();
    inventario = new QTableWidget();
    vistaaddbutton = new vista_add_button();
    vistalistaadd = new vista_lista_add();
    vistalistavendita = new vista_lista_vendita();
    vistalistaoptions = new vista_lista_options();
    vistalistaadd->setMinimumHeight(900);
    qpb = vistaaddbutton->getqpb();
    qvb->addWidget(inventario);
    qvb->addWidget(vistaaddbutton);
    QStringList name_col;
    name_col<<"ID"<<"Tipo"<<"Specie"<<"Peso (Kg)"<<"Altezza (m)"<<"Lunghezza (m)"<<"Età"<<
              "InEstinzione"<<"Sede"<<""<<"";
    inventario->setColumnCount(11);
    inventario->setHorizontalHeaderLabels(name_col);
    inventario->setColumnWidth(0,100);inventario->setColumnWidth(1,100);inventario->setColumnWidth(2,100);
    inventario->setColumnWidth(3,100);inventario->setColumnWidth(4,200);inventario->setColumnWidth(5,200);
    inventario->setColumnWidth(6,100);inventario->setColumnWidth(7,100);inventario->setColumnWidth(8,100);
    inventario->setColumnWidth(9,30);inventario->setColumnWidth(10,30);
    connect(qpb, SIGNAL(clicked()),this,SLOT(OnApriVistaListaAdd()));
    setLayout(qvb);
}

void vista_lista::BuildVistaLista()
{
    int riga = -1;
    vector<Animale*> v = controller->ControllerGetModel()->Modelcaricamentoanimali();
    for(vector<Animale*>::iterator it = v.begin(); it != v.end();it++){
        riga++;
        inventario->setRowCount(inventario->rowCount()+1);
        QTableWidgetItem* qtw0 = new QTableWidgetItem();
        qtw0->setText(QString::number((*it)->getID()));
        qtw0->setFlags(qtw0->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,0,qtw0);
        QTableWidgetItem* qtw1 = new QTableWidgetItem();
        qtw1->setText(QString::fromStdString((*it)->getTipo()));
        qtw1->setFlags(qtw1->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,1,qtw1);
        QTableWidgetItem* qtw2 = new QTableWidgetItem();
        qtw2->setText(QString::fromStdString((*it)->getSpecie()));
        qtw2->setFlags(qtw2->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,2,qtw2);
        QTableWidgetItem* qtw3 = new QTableWidgetItem();
        qtw3->setText(QString::number((*it)->getPeso()));
        qtw3->setFlags(qtw3->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,3,qtw3);
        QTableWidgetItem* qtw4 = new QTableWidgetItem();
        qtw4->setText(QString::number((*it)->getAltezza()));
        qtw4->setFlags(qtw4->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,4,qtw4);
        QTableWidgetItem* qtw5 = new QTableWidgetItem();
        qtw5->setText(QString::number((*it)->getLunghezza()));
        qtw5->setFlags(qtw5->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,5,qtw5);
        QTableWidgetItem* qtw6 = new QTableWidgetItem();
        qtw6->setText(QString::number((*it)->getEta()));
        qtw6->setFlags(qtw6->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,6,qtw6);
        QTableWidgetItem* qtw7 = new QTableWidgetItem();
        QString s1 = (((*it)->getInEstinz()) ? "si" : "no");
        qtw7->setText(s1);
        qtw7->setFlags(qtw7->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,7,qtw7);
        QTableWidgetItem* qtw8 = new QTableWidgetItem();
        qtw8->setText(QString::fromStdString((*it)->getSede()));
        qtw8->setFlags(qtw8->flags() ^ Qt::ItemIsEditable);
        inventario->setItem(riga,8,qtw8);
        QTableWidgetItem* qtw9 = new QTableWidgetItem();
        qtw9->setFlags(qtw9->flags() ^ Qt::ItemIsEditable);
        qtw9->setIcon(QIcon(":/pre/icons/info.png"));
        inventario->setItem(riga,9,qtw9);
        QTableWidgetItem* qtw10 = new QTableWidgetItem();
        qtw10->setFlags(qtw10->flags() ^ Qt::ItemIsEditable);
        qtw10->setIcon(QIcon(":/pre/icons/delete.png"));
        inventario->setItem(riga,10,qtw10);
    }
}

void vista_lista::VistaListaSetController(Controller* ctr){
    controller = ctr;
    BuildVistaLista();
    connect(inventario,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(OnCellDoubleClicked(int,int)));
}

QTableWidget *vista_lista::GetInventario() const
{
    return inventario;
}

void vista_lista::OnApriVistaListaAdd() const
{
    vistalistaadd->getboxspecie()->setEnabled(false);
    vistalistaadd->getboxanimale()->setCurrentIndex(0);
    vistalistaadd->getboxspecie()->setCurrentIndex(0);
    vistalistaadd->getid()->setText("");
    vistalistaadd->getpeso()->setText("");
    vistalistaadd->getaltezza()->setText("");
    vistalistaadd->getlunghezza()->setText("");
    vistalistaadd->geteta()->setText("");
    vistalistaadd->getprezzo()->setText("0");
    vistalistaadd->getprezzo()->hide();
    vistalistaadd->getprezzotitolo()->hide();
    vistalistaadd->getdatatitolo()->hide();
    vistalistaadd->getdata()->hide();
    vistalistaadd->getsede()->setCurrentIndex(0);
    vistalistaadd->getspecialita()->setText("");
    vistalistaadd->getinestinzione()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getfrugivoro()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getfolivoro()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getgranivoro()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getnettarivoro()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getvelenoso()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getnecrofago()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getacquistato()->setCheckState(Qt::CheckState::Unchecked);
    vistalistaadd->getdata()->setDate(QDate(2020,1,1));
    vistalistaadd->geterb()->hide();
    vistalistaadd->getfrugivoro()->hide();
    vistalistaadd->getfolivoro()->hide();
    vistalistaadd->getgranivoro()->hide();
    vistalistaadd->getnettarivoro()->hide();
    vistalistaadd->getvelenoso()->hide();
    vistalistaadd->getnecrofago()->hide();
    vistalistaadd->getCaratteristica1titolo()->hide();
    vistalistaadd->getCaratteristica2titolo()->hide();
    vistalistaadd->getCaratteristica3titolo()->hide();
    vistalistaadd->getspecialitatitolo()->hide();
    vistalistaadd->getspecialita()->hide();
    vistalistaadd->show();
}

vista_lista_add *vista_lista::GetVistaListaAdd() const
{
    return vistalistaadd;
}

vista_lista_options *vista_lista::GetVistaListaOptions() const
{
    return vistalistaoptions;
}

vista_lista_vendita *vista_lista::GetVistaListaVendita() const
{
    return vistalistavendita;
}
void vista_lista::VistaListaAggiungiAnimale(unsigned short id, string an, string specie, double peso, double altezza, double lunghezza,
                                            unsigned short eta, bool inestinzione, string sede)
{
    inventario->setRowCount(inventario->rowCount()+1);
    int riga = inventario->rowCount()-1;
    QTableWidgetItem* qtwi0 = new QTableWidgetItem();
    qtwi0->setText(QString::number(id));
    qtwi0->setFlags(qtwi0->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,0,qtwi0);
    QTableWidgetItem* qtwi1 = new QTableWidgetItem();
    qtwi1->setText(QString::fromStdString(an));
    qtwi1->setFlags(qtwi1->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,1,qtwi1);
    QTableWidgetItem* qtwi2 = new QTableWidgetItem();
    qtwi2->setText(QString::fromStdString(specie));
    qtwi2->setFlags(qtwi2->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,2,qtwi2);
    QTableWidgetItem* qtwi3 = new QTableWidgetItem();
    qtwi3->setText(QString::number(peso));
    qtwi3->setFlags(qtwi3->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,3,qtwi3);
    QTableWidgetItem* qtwi4 = new QTableWidgetItem();
    qtwi4->setText(QString::number(altezza));
    qtwi4->setFlags(qtwi4->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,4,qtwi4);
    QTableWidgetItem* qtwi5 = new QTableWidgetItem();
    qtwi5->setText(QString::number(lunghezza));
    qtwi5->setFlags(qtwi5->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,5,qtwi5);
    QTableWidgetItem* qtwi6 = new QTableWidgetItem();
    qtwi6->setText(QString::number(eta));
    qtwi6->setFlags(qtwi6->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,6,qtwi6);
    QTableWidgetItem* qtwi7 = new QTableWidgetItem();
    QString s1 = (inestinzione ? "si" : "no");
    qtwi7->setText(s1);
    qtwi7->setFlags(qtwi7->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,7,qtwi7);
    QTableWidgetItem* qtwi8 = new QTableWidgetItem();
    qtwi8->setText(QString::fromStdString(sede));
    qtwi8->setFlags(qtwi8->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,8,qtwi8);
    QTableWidgetItem* qtwinfo = new QTableWidgetItem();
    qtwinfo->setIcon(QIcon(":/pre/icons/info.png"));
    qtwinfo->setFlags(qtwinfo->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,9,qtwinfo);
    QTableWidgetItem* qtwidel = new QTableWidgetItem();
    qtwidel->setIcon(QIcon(":/pre/icons/delete.png"));
    qtwidel->setFlags(qtwidel->flags() ^ Qt::ItemIsEditable);
    inventario->setItem(riga,10,qtwidel);
}
void vista_lista::OnCellDoubleClicked(int riga,int col)
{
    if(col==10){
    QMessageBox* msg = new QMessageBox();
    msg->setWindowTitle("Rimuovi Animale");
    QMessageBox* vendita = new QMessageBox();
    vendita->setWindowTitle("Vendita Animale");
    msg->setIcon(QMessageBox::Question);
    msg->setText("Eliminare in modo permanente questo animale?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msg->setDefaultButton(QMessageBox::Cancel);
    int risposta=msg->exec();
    if(risposta==QMessageBox::Yes){
        vendita->setIcon(QMessageBox::Question);
        vendita->setText("Aggiungere l'animale alla lista vendite?");
        vendita->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        vendita->setDefaultButton(QMessageBox::No);
        int risposta2 = vendita->exec();
        if (risposta2 == QMessageBox::Yes){
            vistalistavendita->getprezzo()->setText("0");
            vistalistavendita->getdata()->setDate(QDate(2020,1,1));
            vistalistavendita->assegnariga(riga);
            vistalistavendita->getdialog()->exec();
        }
        QTableWidgetItem* id=inventario->takeItem(riga,0);
        emit DatiRimozione(std::stoi(QString(id->text()).toStdString()),riga);
    }
    }
    else if (col==9){
        QTableWidgetItem* id = inventario->takeItem(riga,0);
        inventario->setItem(riga,0,id);
        Animale* an = controller->ControllerGetModel()->Modelsearchanimale(std::stoi(id->text().toStdString()));
        vector<Tipo> Dieta = vector<Tipo>();
        bool velenoso = false;
        bool necrofago = false;
        double corno = 0;
        double pelle = 0;
        double pelliccia = 0;
        bool grasso = an->isGrasso();
        bool vecchio = an->isVecchio();
        bool valore = an->isdiValore();
        Erbivoro* erb = dynamic_cast<Erbivoro*>(an);
        Carnivoro* car = dynamic_cast<Carnivoro*>(an);
        Onnivoro* onn = dynamic_cast<Onnivoro*>(an);
        vistalistaoptions->getcaratteristica1()->hide();
        vistalistaoptions->getcaratteristica2()->hide();
        vistalistaoptions->getcaratteristica3()->hide();
        vistalistaoptions->getcaratteristica4()->hide();
        vistalistaoptions->getcaratteristica5()->hide();
        vistalistaoptions->getcaratteristica6()->hide();
        if(erb){
            Dieta = erb->getDieta();
            vistalistaoptions->getcaratteristica1()->setText("Non è frugivoro");
            vistalistaoptions->getcaratteristica2()->setText("Non è folivoro");
            vistalistaoptions->getcaratteristica3()->setText("Non è granivoro");
            vistalistaoptions->getcaratteristica4()->setText("Non è nettarivoro");
            vistalistaoptions->getcaratteristica1()->setVisible(true);
            vistalistaoptions->getcaratteristica2()->setVisible(true);
            vistalistaoptions->getcaratteristica3()->setVisible(true);
            vistalistaoptions->getcaratteristica4()->setVisible(true);
            for(vector<Tipo>::const_iterator it = Dieta.begin();it!=Dieta.end();++it){
                if(*it==Frugivoro)
                {
                    vistalistaoptions->getcaratteristica1()->setText("E' frugivoro");
                }
                if(*it==Folivoro)
                {
                    vistalistaoptions->getcaratteristica2()->setText("E' folivoro");
                }
                if(*it==Granivoro)
                {
                    vistalistaoptions->getcaratteristica3()->setText("E' granivoro");
                }
                if(*it==Nettarivoro)
                {
                    vistalistaoptions->getcaratteristica4()->setText("E' nettarivoro");
                }
            }
            Rinoceronte* rinoceronte = dynamic_cast<Rinoceronte*>(an);
            if (rinoceronte){
                corno = rinoceronte->getCorno();
                vistalistaoptions->getcaratteristicaSpecie()->setText("Questo rinoceronte ha " + QString::number(corno) + " kg di corna");
                vistalistaoptions->getgrasso()->setText(grasso ? "Questo rinoceronte è grasso" : "Questo rinoceronte non è grasso");
                vistalistaoptions->getvecchio()->setText(vecchio ? "Questo rinoceronte è vecchio" : "Questo rinoceronte non è vecchio");
                vistalistaoptions->getvalore()->setText(valore ? "Questo rinoceronte è di valore" : "Questo rinoceronte non è di valore");
            }
        }
        if(car){
            velenoso = car->getvelenoso();
            necrofago = car->getnecrofago();
            vistalistaoptions->getcaratteristica1()->setVisible(true);
            vistalistaoptions->getcaratteristica2()->setVisible(true);
            if (velenoso)
            {
                vistalistaoptions->getcaratteristica1()->setText("E' velenoso");
            }
            else
            {
                vistalistaoptions->getcaratteristica1()->setText("Non è velenoso");
            }
            if (necrofago)
            {
                vistalistaoptions->getcaratteristica2()->setText("E' necrofago");
            }
            else
            {
                vistalistaoptions->getcaratteristica2()->setText("Non è necrofago");
            }
            Alligatore* alligatore = dynamic_cast<Alligatore*>(an);
            if (alligatore){
                pelle = alligatore->getPelle();
                vistalistaoptions->getcaratteristicaSpecie()->setText("Questo alligatore ha " + QString::number(pelle) + " kg di pelle");
                vistalistaoptions->getgrasso()->setText(grasso ? "Questo alligatore è grasso" : "Questo alligatore non è grasso");
                vistalistaoptions->getvecchio()->setText(vecchio ? "Questo alligatore è vecchio" : "Questo alligatore non è vecchio");
                vistalistaoptions->getvalore()->setText(valore ? "Questo alligatore è di valore" : "Questo alligatore non è di valore");
            }
        }
        if (onn)
        {
            Dieta = erb->getDieta();
            vistalistaoptions->getcaratteristica3()->setText("Non è frugivoro");
            vistalistaoptions->getcaratteristica4()->setText("Non è folivoro");
            vistalistaoptions->getcaratteristica5()->setText("Non è granivoro");
            vistalistaoptions->getcaratteristica6()->setText("Non è nettarivoro");
            vistalistaoptions->getcaratteristica3()->setVisible(true);
            vistalistaoptions->getcaratteristica4()->setVisible(true);
            vistalistaoptions->getcaratteristica5()->setVisible(true);
            vistalistaoptions->getcaratteristica6()->setVisible(true);
            for(vector<Tipo>::const_iterator it = Dieta.begin();it!=Dieta.end();++it){
                if(*it==Frugivoro)
                {
                    vistalistaoptions->getcaratteristica3()->setText("E' frugivoro");
                }
                if(*it==Folivoro)
                {
                    vistalistaoptions->getcaratteristica4()->setText("E' folivoro");
                }
                if(*it==Granivoro)
                {
                    vistalistaoptions->getcaratteristica5()->setText("E' granivoro");
                }
                if(*it==Nettarivoro)
                {
                    vistalistaoptions->getcaratteristica6()->setText("E' nettarivoro");
                }
            }
            velenoso = car->getvelenoso();
            necrofago = car->getnecrofago();
            vistalistaoptions->getcaratteristica1()->setVisible(true);
            vistalistaoptions->getcaratteristica2()->setVisible(true);
            if (velenoso)
            {
                vistalistaoptions->getcaratteristica1()->setText("E' velenoso");
            }
            else
            {
                vistalistaoptions->getcaratteristica1()->setText("Non è velenoso");
            }
            if (necrofago)
            {
                vistalistaoptions->getcaratteristica2()->setText("E' necrofago");
            }
            else
            {
                vistalistaoptions->getcaratteristica2()->setText("Non è necrofago");
            }
            Orso* orso = dynamic_cast<Orso*>(an);
            if (orso){
                pelliccia = orso->getPelliccia();
                vistalistaoptions->getcaratteristicaSpecie()->setText("Questo orso ha " + QString::number(pelliccia) + " kg di pelliccia");
                vistalistaoptions->getgrasso()->setText(grasso ? "Questo orso è grasso" : "Questo orso non è grasso");
                vistalistaoptions->getvecchio()->setText(vecchio ? "Questo orso è vecchio" : "Questo orso non è vecchio");
                vistalistaoptions->getvalore()->setText(valore ? "Questo orso è di valore" : "Questo orso non è di valore");
            }
        }
        vistalistaoptions->getmessaggio()->exec();
    }
}

