#ifndef VISTA_FINANZA_BILANCIO_H
#define VISTA_FINANZA_BILANCIO_H
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>
class Controller;

class vista_finanza_bilancio : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* qvb;
    QTableWidget* tabellabilancio;
    QLabel* ql;
    Controller* controller;
public:
    explicit vista_finanza_bilancio(QWidget *parent = nullptr);
    void VistaFinanzaBilancioSetAcquisto(double acq);
    void VistaFinanzaBilancioSetValoriIniziali(double acq,double ven,double bil);
    void VistaFinanzaBilancioSetVendita(double ven);
    void VistaFinanzaBilancioSetBilancio(double bil);
    void VistaFinanzaBilancioSetController(Controller* ctr);
};

#endif // VISTA_FINANZA_BILANCIO_H
