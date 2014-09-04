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
    registrocoordenadas.cpp \
    modelocoordenadas.cpp \
    createorto.cpp \
    createmet.cpp \
    createcnps.cpp \
    registrocreatemet.cpp \
    registrocreatecnps.cpp \
    registrocreateorto.cpp \
    tableviewraw.cpp \
    signopasadadelegate.cpp \
    registroraw.cpp \
    registrofolderoutchangeformat.cpp \
    modeloraw.cpp \
    foldersoutchangeformat.cpp \
    dialogoraw.cpp \
    armclasefilesout.cpp \
    indexbutton.cpp \
    ficherosraw.cpp \
    tableviewrawtasi.cpp \
    lanzadoroperaciones.cpp \
    dialoghelpfilecoordinates.cpp \
    ficherodatosambitopro.cpp \
    debugqprocess.cpp \
    operacionprogresdialog.cpp \
    operacionbase.cpp \
    operacionmet.cpp \
    operacionorto.cpp \
    ometdatosejecucion.cpp \
    cortemet.cpp \
    dialogopreferencias.cpp \
    combinecnp.cpp \
    correction.cpp \
    diferences.cpp

HEADERS  += mainwindow.h \
    tableviewcoordinates.h \
    registrocoordenadas.h \
    modelocoordenadas.h \
    registrocreateorto.h \
    registrocreatemet.h \
    registrocreatecnps.h \
    createorto.h \
    createmet.h \
    createcnps.h \
    tableviewraw.h \
    signopasadadelegate.h \
    registroraw.h \
    registrofolderoutchangeformat.h \
    modeloraw.h \
    foldersoutchangeformat.h \
    dialogoraw.h \
    armclasefilesout.h \
    indexbutton.h \
    ficherosraw.h \
    tableviewrawtasi.h \
    lanzadoroperaciones.h \
    dialoghelpfilecoordinates.h \
    ficherodatosambitopro.h \
    debugqprocess.h \
    operacionprogresdialog.h \
    operacionbase.h \
    operacionmet.h \
    operacionorto.h \
    ometdatosejecucion.h \
    cortemet.h \
    dialogopreferencias.h \
    combinecnp.h \
    correction.h \
    diferences.h

FORMS    += mainwindow.ui \
    tableviewcoordinates.ui \
    createorto.ui \
    createmet.ui \
    createcnps.ui \
    foldersoutchangeformat.ui \
    dialogoraw.ui \
    tableviewraw.ui \
    ficherosraw.ui \
    tableviewrawtasi.ui \
    dialoghelpfilecoordinates.ui \
    operacionprogresdialog.ui \
    dialogopreferencias.ui \
    combinecnp.ui \
    correction.ui \
    diferences.ui

RESOURCES += \
    recursos.qrc
