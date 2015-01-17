//    DepuPcot
//    Copyright (C) {2014}  {Antonio López García}
//    tologar@gmail.com

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "worker.h"

Worker::Worker(QObject *parent, QList < Proceso*> listaProcesos) :
    QObject(parent)
{
    _operacionActual=0;
    _listaProcesos=listaProcesos;
    contadorProceso=0;
    libre=true;
    cancelado=false;
    foreach(Proceso *elemento, _listaProcesos)
    {
        connect(elemento,SIGNAL(procesoLibre()),this,SLOT(siguienteProceso()));
    }
}

Operacion* Worker::getOperacionActual()
{
    return _operacionActual;
}

void Worker::trabajarEn(Operacion *operacionActual)
{
    if(operacionActual->isCompleta() || operacionActual->isFallida())
    {
        emit workerLibre();
        return;
    }
    if(cancelado)
    {
        operacionActual->setFallida("Cancelada desde el worker");
        emit workerLibre();
        return;
    }
    libre=false;
    emit workerOcupado();
    contadorProceso=0;
    _operacionActual=operacionActual;
    _operacionActual->aceptarProceso(_listaProcesos.first());
    contadorProceso++;
}

void Worker::siguienteProceso()
{

    if(_operacionActual->isCompleta() || _operacionActual->isFallida())
    {
        libre=true;
        emit workerLibre();
        return;

    }
    _operacionActual->aceptarProceso(_listaProcesos.at(contadorProceso));
    qDebug()<< "siguiente proceso";
    contadorProceso++;
}
bool Worker::isLibre()
{
    return libre;
}
bool Worker::isCancelado()
{
    return cancelado;
}
void  Worker::cancelar()
{
    if(!libre && !cancelado)
    {
        cancelado=true;
        for(int i=contadorProceso-1;i<_listaProcesos.count();i++)
        {
            _listaProcesos[i]->kill();
        }
        libre=true;
        emit workerLibre();
    }
}


void Worker::reset()
{
    if(libre)
    {
        cancelado=false;
    }

}










