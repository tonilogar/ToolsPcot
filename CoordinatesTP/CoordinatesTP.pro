#-------------------------------------------------
#
# Project created by QtCreator 2015-01-19T23:56:00
#
#-------------------------------------------------

QT       += widgets
win32:CONFIG(release,debug|release){
TARGET = CoordinatesTP
LIBS += -L../libs -lOpePcot
}
else:win32:CONFIG(debug,debug|release) {
TARGET = CoordinatesTPd
LIBS += -L../libs -lOpePcotd
}
TEMPLATE = lib

INCLUDEPATH += ..

DESTDIR =../libs

DEFINES += COORDINATESTP_LIBRARY

SOURCES += \
    modelocoordenadas.cpp \
    readercoordinates.cpp \
    readercoordinatesbasico.cpp \   
    tableviewcoordinates.cpp \
    dialoghelpfilecoordinates.cpp

HEADERS +=\
        coordinatestp_global.h \
    modelocoordenadas.h \
    readercoordinates.h \
    readercoordinatesbasico.h \
    tableviewcoordinates.h \
    dialoghelpfilecoordinates.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    tableviewcoordinates.ui \
    dialoghelpfilecoordinates.ui

RESOURCES += \
    resources.qrc



