QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acquisti.cpp \
    alligatore.cpp \
    animale.cpp \
    carnivoro.cpp \
    contenitore.cpp \
    controller.cpp \
    dati_finanziari.cpp \
    erbivoro.cpp \
    exceptions.cpp \
    main.cpp \
    model.cpp \
    onnivoro.cpp \
    orso.cpp \
    rinoceronte.cpp \
    save_load.cpp \
    vendite.cpp \
    vista.cpp \
    vista_add_button.cpp \
    vista_finanza.cpp \
    vista_finanza_acquisti.cpp \
    vista_finanza_bilancio.cpp \
    vista_finanza_vendite.cpp \
    vista_lista.cpp \
    vista_lista_add.cpp \
    vista_lista_options.cpp \
    vista_lista_vendita.cpp

HEADERS += \
    acquisti.h \
    alligatore.h \
    animale.h \
    carnivoro.h \
    contenitore.h \
    controller.h \
    dati_finanziari.h \
    erbivoro.h \
    exceptions.h \
    model.h \
    onnivoro.h \
    orso.h \
    rinoceronte.h \
    save_load.h \
    vendite.h \
    vista.h \
    vista_add_button.h \
    vista_finanza.h \
    vista_finanza_acquisti.h \
    vista_finanza_bilancio.h \
    vista_finanza_vendite.h \
    vista_lista.h \
    vista_lista_add.h \
    vista_lista_options.h \
    vista_lista_vendita.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
