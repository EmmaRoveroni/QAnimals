#ifndef VISTA_LISTA_ADD_H
#define VISTA_LISTA_ADD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QDateEdit>
using std::string;
#define u_int unsigned short
class Controller;
class vista_lista_add : public QWidget
{
    Q_OBJECT
private:
        Controller* controller;
        QVBoxLayout* qvb;
        QLineEdit* inserireid;
        QLineEdit* peso;
        QLineEdit* altezza;
        QLineEdit* lunghezza;
        QLineEdit* eta;
        QLineEdit* prezzo;
        QComboBox* sede;
        QLineEdit* specialita;
        QComboBox* boxanimale;
        QComboBox* boxspecie;
        QCheckBox* velenoso;
        QCheckBox* necrofago;
        QGroupBox* erbivoro;
        QLabel* inseriredati;
        QLabel* idtitolo;
        QLabel* animaletitolo;
        QLabel* pesotitolo;
        QLabel* altezzatitolo;
        QLabel* lunghezzatitolo;
        QLabel* etatitolo;
        QLabel* prezzotitolo;
        QLabel* sedetitolo;
        QLabel* inestinztitolo;
        QLabel* Caratteristica1titolo;
        QLabel* Caratteristica2titolo;
        QLabel* Caratteristica3titolo;
        QLabel* Specialitatitolo;
        QLabel* Acquistatotitolo;
        QLabel* datatitolo;
        QDateEdit* data;
        QCheckBox* acquistato;
        QCheckBox* inestinzione;
        QPushButton* qpb;
        QLabel* specietitolo;
        QCheckBox *frugivoro;
        QCheckBox *folivoro;
        QCheckBox *granivoro;
        QCheckBox *nettarivoro;
public:
    explicit vista_lista_add(QWidget *parent = nullptr);
    void VistaListaAddSetController(Controller* ctr);
    QComboBox* getboxspecie() const;
    QComboBox* getboxanimale() const;
    QLineEdit* getid() const;
    QLineEdit* getpeso() const;
    QLineEdit* getaltezza() const;
    QLineEdit* getlunghezza() const;
    QLineEdit* geteta() const;
    QLineEdit* getprezzo() const;
    QComboBox* getsede() const;
    QLineEdit* getspecialita() const;
    QCheckBox* getinestinzione() const;
    QCheckBox* getfrugivoro() const;
    QCheckBox* getfolivoro() const;
    QCheckBox* getgranivoro() const;
    QCheckBox* getnettarivoro() const;
    QCheckBox* getvelenoso() const;
    QCheckBox* getnecrofago() const;
    QCheckBox* getacquistato() const;
    QGroupBox* geterb() const;
    QLabel* getdatatitolo() const;
    QDateEdit* getdata() const;
    QLabel* getCaratteristica1titolo() const;
    QLabel* getCaratteristica2titolo() const;
    QLabel* getCaratteristica3titolo() const;
    QLabel* getspecialitatitolo() const;
    QLabel* getprezzotitolo() const;
signals:
    void DatiAggiunta(u_int id ,string tipo,string specie,double peso,double altezza,double lunghezza,u_int eta,
                      bool inestinzione,string sede,bool frugivoro,bool folivoro,bool granivoro,bool nettarivoro,
                      bool velenoso,bool necrofago,double caratteristicaspecie,bool acquistato,double prezzoacquisto,
                      QDate dataacquisto);
public slots:
    void OnAggiuntaConfermata();
    void OnTipoAnimaleScelto(int a);
    void OnSpecieAnimaleScelta(int b);
    void OnVincoloTipoAnimale(int c);
    void OnBoxSpecieAttivato(int d);
    void OnDatiAcquistoAttivato(int e);

};

#endif // VISTA_LISTA_ADD_H
