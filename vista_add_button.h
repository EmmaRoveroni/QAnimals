#ifndef VISTA_ADD_BUTTON_H
#define VISTA_ADD_BUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
class vista_add_button:public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* qvb;
    QPushButton* qpb;
public:
    vista_add_button();
    QPushButton* getqpb() const;
};

#endif // VISTA_ADD_BUTTON_H
