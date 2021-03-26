#include "vista_lista_add.h"
#include "controller.h"
vista_lista_add::vista_lista_add(QWidget *parent) : QWidget(parent)
{
    controller = nullptr;
    setWindowTitle("Aggiungi Animale");
    setMinimumWidth(350);
    qvb = new QVBoxLayout();
    inserireid = new QLineEdit();
    peso = new QLineEdit();
    altezza = new QLineEdit();
    lunghezza = new QLineEdit();
    eta = new QLineEdit();
    prezzo = new QLineEdit();
    sede = new QComboBox();
    specialita = new QLineEdit();
    boxanimale = new QComboBox();
    boxspecie = new QComboBox();
    velenoso = new QCheckBox();
    necrofago = new QCheckBox();
    erbivoro = new QGroupBox();
    specialita->hide();
    velenoso->hide();
    necrofago->hide();
    frugivoro = new QCheckBox(tr("Frugivoro"));
    folivoro = new QCheckBox(tr("Folivoro"));
    granivoro = new QCheckBox(tr("Granivoro"));
    nettarivoro = new QCheckBox(tr("Nettarivoro"));
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(frugivoro);
    vbox->addWidget(folivoro);
    vbox->addWidget(granivoro);
    vbox->addWidget(nettarivoro);
    erbivoro->setLayout(vbox);
    erbivoro->hide();
    QStringList qs1;
    qs1 << "--select--" <<" Erbivoro" << "Carnivoro" << "Onnivoro";
    boxanimale->addItems(qs1);
    QStringList qs2;
    qs2 << "--select--" << "Rinoceronte" << "Alligatore" << "Orso";
    boxspecie->addItems(qs2);
    QStringList qs3;
    qs3 << "--select--" <<"Nairobi" << "Pretoria" << "Mumbai";
    sede->addItems(qs3);
    inestinzione = new QCheckBox();
    qpb = new QPushButton();
    animaletitolo = new QLabel("Tipo Animale");
    specietitolo = new QLabel("Specie");
    inseriredati = new QLabel();
    Caratteristica1titolo = new QLabel();
    Caratteristica2titolo = new QLabel();
    Caratteristica3titolo = new QLabel();
    Specialitatitolo = new QLabel();
    inseriredati->setText("Inserire i dati");
    Acquistatotitolo = new QLabel();
    Acquistatotitolo->setText("L'animale è stato acquistato?");
    datatitolo = new QLabel();
    datatitolo->setText("Data acquisto");
    data = new QDateEdit();
    acquistato = new QCheckBox();
    idtitolo = new QLabel("ID");
    pesotitolo = new QLabel("Peso (Kg)");
    altezzatitolo = new QLabel("Altezza (m)");
    lunghezzatitolo = new QLabel("Lunghezza (m)");
    etatitolo = new QLabel("Eta");
    prezzotitolo = new QLabel("Prezzo");
    sedetitolo = new QLabel("Sede");
    inestinztitolo = new QLabel("Inestinzione");
    Caratteristica1titolo->hide();
    Caratteristica2titolo->hide();
    Caratteristica3titolo->hide();
    Specialitatitolo->hide();
    qpb->setText("OK");
    qpb->setVisible(true);
    qvb->addWidget(inseriredati);
    qvb->addWidget(Acquistatotitolo);
    qvb->addWidget(acquistato);
    qvb->addWidget(prezzotitolo);
    qvb->addWidget(prezzo);
    qvb->addWidget(datatitolo);
    qvb->addWidget(data);
    qvb->addWidget(idtitolo);
    qvb->addWidget(inserireid);
    qvb->addWidget(animaletitolo);
    qvb->addWidget(boxanimale);
    qvb->addWidget(Caratteristica1titolo);
    qvb->addWidget(erbivoro);
    qvb->addWidget(Caratteristica2titolo);
    qvb->addWidget(velenoso);
    qvb->addWidget(Caratteristica3titolo);
    qvb->addWidget(necrofago);
    qvb->addWidget(specietitolo);
    qvb->addWidget(boxspecie);
    qvb->addWidget(Specialitatitolo);
    qvb->addWidget(specialita);
    qvb->addWidget(pesotitolo);
    qvb->addWidget(peso);
    qvb->addWidget(altezzatitolo);
    qvb->addWidget(altezza);
    qvb->addWidget(lunghezzatitolo);
    qvb->addWidget(lunghezza);
    qvb->addWidget(etatitolo);
    qvb->addWidget(eta);
    qvb->addWidget(inestinztitolo);
    qvb->addWidget(inestinzione);
    qvb->addWidget(sedetitolo);
    qvb->addWidget(sede);
    qvb->addWidget(qpb);
    setLayout(qvb);
    connect(qpb,SIGNAL(clicked()),this,SLOT(OnAggiuntaConfermata()));
    connect(qpb,SIGNAL(clicked()),this,SLOT(close()));
    connect(boxanimale,SIGNAL(activated(int)),this,SLOT(OnTipoAnimaleScelto(int)));
    connect(boxspecie,SIGNAL(activated(int)),this,SLOT(OnSpecieAnimaleScelta(int)));
    connect(boxanimale,SIGNAL(activated(int)),this,SLOT(OnVincoloTipoAnimale(int)));
    connect(boxanimale,SIGNAL(activated(int)),this,SLOT(OnBoxSpecieAttivato(int)));
    connect(acquistato,SIGNAL(stateChanged(int)),this,SLOT(OnDatiAcquistoAttivato(int)));
}


void vista_lista_add::OnAggiuntaConfermata()
{
    emit DatiAggiunta(inserireid->text().toUInt(),boxanimale->currentText().toStdString(),
                      boxspecie->currentText().toStdString(),peso->text().toDouble(),altezza->text().toDouble(),
                      lunghezza->text().toDouble(),eta->text().toUInt(),inestinzione->isChecked(),sede->currentText().toStdString(),
                      frugivoro->isChecked(),folivoro->isChecked(),granivoro->isChecked(),nettarivoro->isChecked(),
                      velenoso->isChecked(),necrofago->isChecked(),specialita->text().toDouble(),
                      acquistato->isChecked(),prezzo->text().toDouble(),data->date());
}

void vista_lista_add::OnTipoAnimaleScelto(int a)
{
    erbivoro->hide();
    velenoso->hide();
    necrofago->hide();
    Caratteristica1titolo->hide();
    Caratteristica2titolo->hide();
    Caratteristica3titolo->hide();
    frugivoro->setCheckState(Qt::CheckState::Unchecked);
    folivoro->setCheckState(Qt::CheckState::Unchecked);
    granivoro->setCheckState(Qt::CheckState::Unchecked);
    nettarivoro->setCheckState(Qt::CheckState::Unchecked);
    velenoso->setCheckState(Qt::CheckState::Unchecked);
    necrofago->setCheckState(Qt::CheckState::Unchecked);
    if(a==1)
    {

        Caratteristica1titolo->setVisible(true);
        Caratteristica1titolo->setText("Dieta");
        erbivoro->setVisible(true);
        frugivoro->setVisible(true);
        folivoro->setVisible(true);
        granivoro->setVisible(true);
        nettarivoro->setVisible(true);
    }
    if(a==2)
    {
        Caratteristica2titolo->setVisible(true);
        Caratteristica2titolo->setText("Velenoso");
        velenoso->setVisible(true);
        Caratteristica3titolo->setVisible(true);
        Caratteristica3titolo->setText("Necrofago");
        necrofago->setVisible(true);
    }
    if(a==3)
    {
        Caratteristica1titolo->setVisible(true);
        Caratteristica1titolo->setText("Dieta");
        erbivoro->setVisible(true);
        frugivoro->setVisible(true);
        folivoro->setVisible(true);
        granivoro->setVisible(true);
        nettarivoro->setVisible(true);
        Caratteristica2titolo->setVisible(true);
        Caratteristica2titolo->setText("Velenoso");
        velenoso->setVisible(true);
        Caratteristica3titolo->setVisible(true);
        Caratteristica3titolo->setText("Necrofago");
        necrofago->setVisible(true);
    }
}

void vista_lista_add::OnSpecieAnimaleScelta(int a)
{
        if (boxspecie->itemText(a) == "--select--"){
            Specialitatitolo->hide();
            specialita->hide();
        }
        if (boxspecie->itemText(a) == "Rinoceronte"){
            Specialitatitolo->setText("Corno");
            Specialitatitolo->setVisible(true);
            specialita->setVisible(true);
        }
        if (boxspecie->itemText(a) == "Alligatore"){
            Specialitatitolo->setText("Pelle");
            Specialitatitolo->setVisible(true);
            specialita->setVisible(true);
        }
        if (boxspecie->itemText(a) == "Orso") {
            Specialitatitolo->setText("Pelliccia");
            Specialitatitolo->setVisible(true);
            specialita->setVisible(true);
        }
}

void vista_lista_add::OnVincoloTipoAnimale(int a)
{
    for (int i=0;i<4;i++){
        boxspecie->removeItem(0);
    }
    if(a==1){
        QStringList qs;
        qs << "--select--"<< "Rinoceronte";
        boxspecie->addItems(qs);
        Specialitatitolo->hide();
        specialita->hide();
    }
    if(a==2){
        QStringList qs;
        qs << "--select--"<< "Alligatore";
        boxspecie->addItems(qs);
        Specialitatitolo->hide();
        specialita->hide();
    }
    if(a==3){
        QStringList qs;
        qs << "--select--"<< "Orso";
        boxspecie->addItems(qs);
        Specialitatitolo->hide();
        specialita->hide();
    }

}

void vista_lista_add::OnBoxSpecieAttivato(int d)
{
    boxspecie->setEnabled(true);
}

void vista_lista_add::OnDatiAcquistoAttivato(int e)
{
    prezzo->setText("0");
    data->setDate(QDate(2020,1,1));
    if(e==2){
        prezzotitolo->setVisible(true);
        prezzo->setVisible(true);
        datatitolo->setVisible(true);
        data->setVisible(true);
    }
    if(e==0){
        prezzotitolo->hide();
        prezzo->hide();
        datatitolo->hide();
        data->hide();
    }
}

void vista_lista_add::VistaListaAddSetController(Controller* ctr){
    controller = ctr;
}

QComboBox *vista_lista_add::getboxspecie() const
{
    return boxspecie;
}

QComboBox *vista_lista_add::getboxanimale() const
{
    return boxanimale;
}

QLineEdit *vista_lista_add::getid() const
{
    return inserireid;
}

QLineEdit *vista_lista_add::getpeso() const
{
    return peso;
}

QLineEdit *vista_lista_add::getaltezza() const
{
    return altezza;
}

QLineEdit *vista_lista_add::getlunghezza() const
{
    return lunghezza;
}

QLineEdit *vista_lista_add::geteta() const
{
    return eta;
}

QLineEdit *vista_lista_add::getprezzo() const
{
    return prezzo;
}


QComboBox *vista_lista_add::getsede() const
{
    return sede;
}

QLineEdit *vista_lista_add::getspecialita() const
{
    return specialita;
}


QCheckBox *vista_lista_add::getinestinzione() const
{
    return inestinzione;
}

QCheckBox *vista_lista_add::getfrugivoro() const
{
    return frugivoro;
}

QCheckBox *vista_lista_add::getfolivoro() const
{
    return folivoro;
}

QCheckBox *vista_lista_add::getgranivoro() const
{
    return granivoro;
}

QCheckBox *vista_lista_add::getnettarivoro() const
{
    return nettarivoro;
}

QCheckBox *vista_lista_add::getvelenoso() const
{
    return velenoso;
}

QCheckBox *vista_lista_add::getnecrofago() const
{
    return necrofago;
}

QCheckBox *vista_lista_add::getacquistato() const
{
    return acquistato;
}

QGroupBox *vista_lista_add::geterb() const
{
    return erbivoro;
}

QLabel *vista_lista_add::getdatatitolo() const
{
    return datatitolo;
}

QDateEdit *vista_lista_add::getdata() const
{
    return data;
}

QLabel *vista_lista_add::getCaratteristica1titolo() const
{
    return Caratteristica1titolo;
}

QLabel *vista_lista_add::getCaratteristica2titolo() const
{
    return Caratteristica2titolo;
}

QLabel *vista_lista_add::getCaratteristica3titolo() const
{
    return Caratteristica3titolo;
}

QLabel *vista_lista_add::getspecialitatitolo() const
{
    return Specialitatitolo;
}

QLabel *vista_lista_add::getprezzotitolo() const
{
    return prezzotitolo;
}

