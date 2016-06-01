#include "widgetregistro.h"

WidgetRegistro::WidgetRegistro(QWidget *parent) :
    QWidget(parent)
{
    _conectado=false;   //Conectado por defecto
    _activo=false;       //Activo por defecto
    _aproRegistro=0;

}

void WidgetRegistro::setRegistro(AProTPSection *reg)
{
    _aproRegistro=reg;
    connectRegistro();
}

void WidgetRegistro::conectarWidget(bool data)
{
    setConectado(data);
}

void WidgetRegistro::activarWidget(int check)
{
    if(check==Qt::Checked) {
        this->setActivo(true);
    }
    else this->setActivo(false);
}

void WidgetRegistro::setConectado(bool data)
{
    _conectado=data;
    if(data) {
        conectarInterface();
    }
    else {
        desconectarInterface();
        if(this->estaActivo()) {
            this->activarWidget(Qt::Unchecked);
        }
        if(estaCorrecto()!=Pasivo) {
            setCorreccion(Pasivo);
        }
    }
    emit conectado(_conectado);
}

bool WidgetRegistro::estaConectado() const
{
    return _conectado;
}

bool WidgetRegistro::estaActivo() const
{
    return _activo;
}

void WidgetRegistro::setActivo(bool data)
{
    _activo=data;
    if(data)
        activarInterface();
    else {
        desactivarInterface();
        if(estaCorrecto()!=Pasivo) {
            setCorreccion(Pasivo);
        }
    }
    emit activo(_activo);
}

void WidgetRegistro::setCorreccion(int correc)
{
    _correccionActual=correc;
    emit correccion(_correccionActual);
}

int WidgetRegistro::estaCorrecto() const
{
    return _correccionActual;
}

void WidgetRegistro::cambiarCorreccion(CorreccionRegistro c)
{
    _correccionActual=c;
}
void WidgetRegistro::recargaRegistro(QVariantMap mapa)
{
    loadRegistro(mapa);
}
