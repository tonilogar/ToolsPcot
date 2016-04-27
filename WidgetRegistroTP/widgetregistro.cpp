#include "widgetregistro.h"

WidgetRegistro::WidgetRegistro(QWidget *parent) :
    QWidget(parent)
{
    _conectado=true;   //Conectado por defecto
    _activo=true;       //Activo por defecto
    _aproRegistro=0;

    //Preparar la maquina de estados
    //1.- Preparar los estados
    QState *desconectado=new QState(0);
    _estadoConectado=new QStateMachine(0);

    //2.-Preparar las transiciones
    BoolTransition *t1=new BoolTransition(true);
    BoolTransition *t2=new BoolTransition(false);

    t1->setTargetState(_estadoConectado);
    desconectado->addTransition(t1);

    t2->setTargetState(desconectado);
    _estadoConectado->addTransition(t2);

    //3.- Indicar los cambios de un estado a otro
    desconectado->assignProperty(this,"conectado",false);
    desconectado->assignProperty(this,"activo",false);
    _estadoConectado->assignProperty(this,"conectado",true);

    //4.- Añadir los estados a la maquina
    _mEstado.addState(desconectado);
    _mEstado.addState(_estadoConectado);
    _mEstado.setInitialState(desconectado);

    //Preparar la maquina de estadoConectado
    QState *activo=new QState(0);
    QState *inactivo=new QState(0);

    CheckTransition *tA1=new CheckTransition(Qt::Checked);
    CheckTransition *tA2=new CheckTransition(Qt::Unchecked);

    tA1->setTargetState(activo);
    inactivo->addTransition(tA1);

    tA2->setTargetState(inactivo);
    activo->addTransition(tA2);

    activo->assignProperty(this,"activo",true);
    inactivo->assignProperty(this,"activo",false);

    _estadoConectado->addState(activo);
    _estadoConectado->addState(inactivo);
    _estadoConectado->setInitialState(inactivo);

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

void WidgetRegistro::activarWidget(int check)
{
    _estadoConectado->postEvent(new CheckEvent(static_cast<Qt::CheckState>(check)));
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

bool WidgetRegistro::estaActivo() const
{
    return _activo;
}

void WidgetRegistro::setActivo(bool data)
{
    _activo=data;
    if(data)
        activarInterface();
    else desactivarInterface();
    emit activo(_activo);
}
