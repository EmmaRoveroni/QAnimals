#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "contenitore.h"
#include "rinoceronte.h"
#include "alligatore.h"
#include "orso.h"
#include "dati_finanziari.h"
#include <QWidget>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class save_load : public QWidget
{
    Q_OBJECT
private:
    static QString datianimali;
public:
    save_load();
    void save(const Contenitore<Animale*>& c,dati_finanziari d);
    void load(Contenitore<Animale*> & c,dati_finanziari& d);
};

#endif // SAVE_LOAD_H
