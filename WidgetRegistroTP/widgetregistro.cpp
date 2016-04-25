#include "widgetregistro.h"

WidgetRegistro::WidgetRegistro(QWidget *parent) :
    QWidget(parent)
{
    _conectado=true;   //Activado por defecto
    _aproRegistro=0;

    //Preparar la maquina de estados
    //1.- Preparar los estados
    QState *desconectado=new QState(0);
    QState *conectado=new QState(0);

    //2.-Preparar las transiciones
    BoolTransition *t1=new BoolTransition(true);
    BoolTransition *t2=new BoolTransition(false);

    t1->setTargetState(conectado);
    desconectado->addTransition(t1);

    t2->setTargetState(desconectado);
    conectado->addTransition(t2);

    //3.- Indicar los cambios de un estado a otro
    desconectado->assignProperty(this,"conectado",false);
    conectado->assignProperty(this,"conectado",true);

    //4.- Añadir los estados a la maquina
    _mEstado.addState(desconectado);
    _mEstado.addState(conectado);
    _mEstado.setInitialState(desconectado);

    //5.- Iniciar la maquina
    _mEstado.start();
}

void WidgetRegistro::setRegistro(AProTPSection *reg)
{
    _aproRegistro=reg;
    connectRegistro();
}

void WidgetRegistro::conectarWidget(bool data)
{
    _mEstado.postEvent(new BoolEvent(data));
}

void WidgetRegistro::setConectado(bool data)
{
    _conectado=data;
    if(data)
        conectarInterface();
    else desconectarInterface();
    emit conectado(_conectado);
}

bool WidgetRegistro::estaConectado() const
{
    return _conectado;
}
