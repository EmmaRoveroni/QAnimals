#include "vista.h"
#include "controller.h"
#include "model.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <iomanip>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Controller c(&m);
    Vista v;
    c.ControllerSetVista(&v);
    v.VistaSetController(&c);
    v.show();
    a.setWindowIcon(QIcon(":/pre/icons/logo.jpg"));
    return a.exec();
}
