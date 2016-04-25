#include "widgetregistro.h"

WidgetRegistro::WidgetRegistro(QWidget *parent) :
    QWidget(parent)
{
    estadoInterface=true;   //Activado por defecto
    _aproRegistro=0;
}

void WidgetRegistro::setRegistro(AProTPSection *reg)
{
    _aproRegistro=reg;
    connectRegistro();
}

void WidgetRegistro::setConectado(bool data)
{
    estadoInterface=data;
    if(data)
        conectarInterface();
    else desconectarInterface();
    emit conectado(estadoInterface);
}
