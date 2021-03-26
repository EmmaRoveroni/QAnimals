#include "vista_add_button.h"

vista_add_button::vista_add_button()
{
    qvb = new QVBoxLayout();
    qpb = new QPushButton();
    qpb->setText(QString("AGGIUNGI ANIMALE"));
    qvb->addWidget(qpb);
    setLayout(qvb);
}

QPushButton *vista_add_button::getqpb() const
{
    return qpb;
}
