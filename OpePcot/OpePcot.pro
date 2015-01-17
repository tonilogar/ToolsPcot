#-------------------------------------------------
#
# Project created by QtCreator 2014-08-20T23:47:31
#
#-------------------------------------------------

QT       += widgets

TARGET = OpePcot
TEMPLATE = lib

DEFINES += OPERACIONPCOT_LIBRARY
DESTDIR =../libs
SOURCES += \
    operacion.cpp \
    identificadorcoordenadas.cpp \
    datazoneproject.cpp \
    workcoordinates.cpp \
    proceso.cpp \
    calculocortes.cpp \
    ccmet.cpp \
    workermet.cpp \
    worker.cpp \
    procesosubscene.cpp \
    procesoresize.cpp \
    procesogeotrans.cpp \
    procesofootprintmask.cpp \
    procesoextraction.cpp \
    procesocutfiles.cpp \
    pocesocnp.cpp \
    operacionmet.cpp \
    operacioncnp.cpp \
    cortemet.cpp \
    operacionorto.cpp \
    workerorto.cpp \
    listaprocesos.cpp

HEADERS +=\
        operacionpcot_global.h \
    operacion.h \
    identificadorcoordenadas.h \
    datazoneproject.h \
    workcoordinates.h \
    proceso.h \
    calculocortes.h \
    ccmet.h \
    workermet.h \
    worker.h \
    procesosubscene.h \
    procesoresize.h \
    procesogeotrans.h \
    procesofootprintmask.h \
    procesoextraction.h \
    procesocutfiles.h \
    pocesocnp.h \
    operacionmet.h \
    operacioncnp.h \
    cortemet.h \
    operacionorto.h \
    workerorto.h \
    listaprocesos.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
