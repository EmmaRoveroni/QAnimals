#include "controller.h"
#include "vista.h"
Vista::Vista(QWidget *parent) : QWidget(parent){
    controller = nullptr;
    mainlayout = new QVBoxLayout();
    tabwidget = new QTabWidget;
    messaggioerrore = new QMessageBox();
    vistalista = new vista_lista();
    vistafinanza = new vista_finanza();
    tabwidget->addTab(vistalista,QIcon(),"INVENTARIO");
    tabwidget->addTab(vistafinanza,QIcon(),"FINANZA");
    VistaAggiungiMenu();
    mainlayout->addWidget(tabwidget);
    setLayout(mainlayout);
}

void Vista::VistaAggiungiAnimale(unsigned short id, string tipo, string specie, double peso, double altezza, double lunghezza,
                                 unsigned short eta, bool inestinzione, string sede)
{
    vistalista->VistaListaAggiungiAnimale(id,tipo,specie,peso,altezza,lunghezza,eta,inestinzione,sede);
}


void Vista::VistaAggiungiAcquisto(unsigned short id, string specie, double prezzo, QDate data)
{
    vistafinanza->GetVistaFinanzaAcquisti()->VistaFinanzaAcquistiAggiungiAcquisto(id,specie,prezzo,data);
    vistafinanza->VistaFinanzaAggiungiAcquisto(prezzo);
}

void Vista::VistaAggiungiVendita(unsigned short id, string specie, double prezzo, QDate data)
{
    vistafinanza->GetVistaFinanzaVendite()->VistaFinanzaVenditeAggiungiVendita(id,specie,prezzo,data);
    vistafinanza->VistaFinanzaAggiungiVendita(prezzo);
}

vista_lista *Vista::GetVistaLista() const
{
    return vistalista;
}

void Vista::VistaAggiungiMenu(){
    menubar = new QMenuBar();
    menu = new QMenu("MENU",menubar);
    exit = new QAction("CHIUDI",menu);
    save = new QAction("SALVA",menu);
    menu->addAction(exit);
    menu->addAction(save);
    menubar->addMenu(menu);
    mainlayout->addWidget(menubar);
}



void Vista::VistaSetController(Controller * ctr)
{
    controller = ctr;
    vistalista->VistaListaSetController(ctr);
    vistalista->GetVistaListaAdd()->VistaListaAddSetController(ctr);
    vistalista->GetVistaListaOptions()->VistaListaOptionsSetController(ctr);
    vistalista->GetVistaListaVendita()->VistaListaVenditaSetController(ctr);
    vistafinanza->VistaFinanzaSetController(ctr);
    vistafinanza->GetVistaFinanzaAcquisti()->VistaFinanzaAcquistiSetController(ctr);
    vistafinanza->GetVistaFinanzaVendite()->VistaFinanzaVenditeSetController(ctr);
    vistafinanza->GetVistaFinanzaBilancio()->VistaFinanzaBilancioSetController(ctr);
    connect(save,SIGNAL(triggered()),controller,SLOT(OnControllerSalvataggio()));
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    connect(controller,SIGNAL(ErroreInputSbagliato()),this,SLOT(OnErroreInputSbagliato()));
    connect(controller,SIGNAL(ErroreIdDoppio()),this,SLOT(OnErroreIdDoppio()));
}

void Vista::OnErroreInputSbagliato()
{
    messaggioerrore->setIcon(QMessageBox::Warning);
    messaggioerrore->setText("I valori inseriti non sono accettabili");
    messaggioerrore->setEscapeButton(QMessageBox::Ok);
    messaggioerrore->exec();
}

void Vista::OnErroreIdDoppio()
{
    messaggioerrore->setIcon(QMessageBox::Warning);
    messaggioerrore->setText("E' già presente un animale con questo ID");
    messaggioerrore->setEscapeButton(QMessageBox::Ok);
    messaggioerrore->exec();
}

vista_lista_add *Vista::GetVistaListaAdd() const
{
    return vistalista->GetVistaListaAdd();
}

vista_lista_vendita *Vista::GetVistaListaVendita() const
{
    return vistalista->GetVistaListaVendita();
}

vista_finanza *Vista::GetVistaFinanza() const
{
    return vistafinanza;
}

