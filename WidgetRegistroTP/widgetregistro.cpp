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
    _estadoActivo=new QStateMachine(0);

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
    desconectado->assignProperty(this,"correccion",Pasivo);
    _estadoConectado->assignProperty(this,"conectado",true);

    //4.- Añadir los estados a la maquina
    _mEstado.addState(desconectado);
    _mEstado.addState(_estadoConectado);
    _mEstado.setInitialState(desconectado);

    //Preparar la maquina de estadoConectado
    QState *inactivo=new QState(0);

    CheckTransition *tA1=new CheckTransition(Qt::Checked);
    CheckTransition *tA2=new CheckTransition(Qt::Unchecked);

    tA1->setTargetState(_estadoActivo);
    inactivo->addTransition(tA1);

    tA2->setTargetState(inactivo);
    _estadoActivo->addTransition(tA2);

    _estadoActivo->assignProperty(this,"activo",true);
    inactivo->assignProperty(this,"activo",false);
    inactivo->assignProperty(this,"correccion",Pasivo);

    _estadoConectado->addState(_estadoActivo);
    _estadoConectado->addState(inactivo);
    _estadoConectado->setInitialState(inactivo);

    //Preparar la maquina de estadoActivo
    QState *pasivo=new QState(_estadoActivo);
    QState *parcialCorrecto=new QState(_estadoActivo);
    QState *correcto=new QState(_estadoActivo);

    pasivo->assignProperty(this,"correccion",Pasivo);
    parcialCorrecto->assignProperty(this,"correccion",ParcialCorrecto);
    correcto->assignProperty(this,"correccion",Correcto);

    IntTransition *tC1=new IntTransition(1);
    IntTransition *tC2=new IntTransition(2);

    tC1->setTargetState(parcialCorrecto);
    pasivo->addTransition(tC1);

    tC2->setTargetState(correcto);
    pasivo->addTransition(tC2);

    IntTransition *tC3=new IntTransition(0);
    IntTransition *tC4=new IntTransition(2);

    tC3->setTargetState(pasivo);
    parcialCorrecto->addTransition(tC3);

    tC4->setTargetState(correcto);
    parcialCorrecto->addTransition(tC4);

    IntTransition *tC5=new IntTransition(1);
    IntTransition *tC6=new IntTransition(0);

    tC5->setTargetState(parcialCorrecto);
    correcto->addTransition(tC5);

    tC6->setTargetState(pasivo);
    correcto->addTransition(tC6);

    _estadoActivo->setInitialState(pasivo);

    //DEP
    //
    connect(_estadoActivo,SIGNAL(started()),this,SLOT(maquinaActivada()));
    connect(pasivo,SIGNAL(entered()),this,SLOT(estadoPasivo()));
    connect(correcto,SIGNAL(entered()),this,SLOT(estadoCorrecto()));


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
    switch(c)
    {
    case Pasivo:
        _estadoActivo->postEvent(new IntEvent(0));
        break;
    case ParcialCorrecto:
        _estadoActivo->postEvent(new IntEvent(1));
        break;
    case Correcto:
        _estadoActivo->postEvent(new IntEvent(2));
        break;
    default:
        break;
    }

}
