#include "controlworker.h"

ControlWorker::ControlWorker(QObject *parent) :
    QObject(parent)
{
    _worker=0;
    _listaOperaciones=QList <Operacion *>();
    _contadorOperacion=0;
    _contadorPasos=0;
}

void ControlWorker::setWorker(Worker *worker)
{
    if (_worker)
    {
        this->disconnect(_worker);
    }
    _worker=worker;
    connect(_worker,SIGNAL(workerLibre()),this,SLOT(siguienteOperacion()));
}


void ControlWorker::setListaOperaciones(QList <Operacion *> listaOperaciones)
{
    int contador=0;
    _listaOperaciones.clear();
    _listaOperaciones=listaOperaciones;
    foreach (Operacion *ope, _listaOperaciones)
    {
        contador+=ope->totalPasos();
        connect(ope,SIGNAL(pasoActualizado(int)),this,SLOT(pasoActualizado(int)));
        connect(ope,SIGNAL(operacionFallida(QString,int)),this,SLOT(errorOperacion(QString,int)));
    }
    emit rangoOperaciones(0,contador);
}
Worker* ControlWorker::getWorker()
{
    return _worker;
}
QList <Operacion *> ControlWorker::getListaOperaciones()
{
    return _listaOperaciones;
}
void ControlWorker::siguienteOperacion()
{
    _contadorOperacion++;
    if(_contadorOperacion < _listaOperaciones.count())
    {
        _worker->trabajarEn(_listaOperaciones[_contadorOperacion]);
    }
    else
    {
        emit operacionesTerminadas(true);
    }
}

void ControlWorker::pasoActualizado(int paso)
{
    _contadorPasos++;
    emit actualizarPaso(_contadorPasos);
}

void ControlWorker::errorOperacion(QString error, int pasos)
{
    _contadorPasos+=pasos;
    emit actualizarPaso(_contadorPasos);
    emit enviarError(error);

}
void ControlWorker::start()
{
    _contadorOperacion=0;
    _contadorPasos=0;
    _worker->trabajarEn(_listaOperaciones[0]);
}














