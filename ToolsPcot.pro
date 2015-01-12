#-------------------------------------------------
#
# Project created by QtCreator 2013-06-05T22:42:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToolsPcot
TEMPLATE = app
# el INCLUDEPATH y LIBS indica el camino a la libreria operacionPcot
INCLUDEPATH += ../libsHeaders
LIBS += -L../libs -lOperacionPcot
SOURCES += main.cpp\
        mainwindow.cpp \
    tableviewcoordinates.cpp \
    modelocoordenadas.cpp \
    createorto.cpp \
    createmet.cpp \
    createcnps.cpp \
    indexbutton.cpp \
    lanzadoroperaciones.cpp \
    dialoghelpfilecoordinates.cpp \
    ficherodatosambitopro.cpp \
    dialogopreferencias.cpp \
    controlworker.cpp \
    dialogprogresoope.cpp \
    readercoordinates.cpp \
    registrocnps.cpp \
    registromet.cpp \
    registroorto.cpp \
    readercoordinatesbasico.cpp

HEADERS  += mainwindow.h \
    tableviewcoordinates.h \
    modelocoordenadas.h \
    createorto.h \
    createmet.h \
    createcnps.h \
    indexbutton.h \
    lanzadoroperaciones.h \
    dialoghelpfilecoordinates.h \
    ficherodatosambitopro.h \
    dialogopreferencias.h \
    controlworker.h \
    dialogprogresoope.h \
    readercoordinates.h \
    registrocnps.h \
    registromet.h \
    registroorto.h \
    readercoordinatesbasico.h

FORMS    += mainwindow.ui \
    tableviewcoordinates.ui \
    createorto.ui \
    createmet.ui \
    createcnps.ui \
    dialoghelpfilecoordinates.ui \
    dialogopreferencias.ui \
    dialogprogresoope.ui

RESOURCES += \
    recursos.qrc
