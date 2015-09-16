QT       += widgets
win32:CONFIG(release,debug|release){
TARGET = RegistroCnpMetOrto
LIBS += -L../libs -lOpePcot -lCnpMetOrtoTP -lCoordinatesTP
}
else:win32:CONFIG(debug,debug|release) {
TARGET = RegistroCnpMetOrto
LIBS += -L../libs -lOpePcotd -lCnpMetOrtoTPd -lCoordinatesTPd
}
TEMPLATE = lib

INCLUDEPATH += ..
DESTDIR =../libs

DEFINES += REGISTROCNPMETORTOTP_LIBRARY

SOURCES += \
    registrocreatecnps.cpp \
    registrocreatemet.cpp \
    registrocreateorto.cpp

HEADERS +=\
        componentestp_global.h \
    registrocreatecnps.h \
    registrocreatemet.h \
    registrocreateorto.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
