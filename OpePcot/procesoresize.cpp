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
#include "procesoresize.h"
#include "operacion.h"
ProcesoResize::ProcesoResize(QObject *parent,QString pathProceso) :
    Proceso(parent,pathProceso)
{
}

void ProcesoResize::metodoMet(Operacion *op)
{
    metodoInvocado=Met;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}
void ProcesoResize::metodoOrto(Operacion *op)
{
    metodoInvocado=Orto;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}
void ProcesoResize::procesoIniciado()
{
#ifdef QT_DEBUG
    qDebug()<<"Class ProcesoResize::procesoIniciado() -> "<< _opeActual->getFileOrigen()<< "fichero origen Resize";
#endif
    _flujo << "1" << endl;
    _flujo << "n" << endl;
    _flujo << "a" << endl;
    _flujo << _opeActual->getFileOrigen() << endl;
    _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
    _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
    _flujo << _opeActual->getFileDestino() << endl;
#ifdef QT_DEBUG
    qDebug()<<"Class ProcesoResize::procesoIniciado() -> "<< _opeActual->getFileDestino()<< "fichero Destino Resize";
#endif

}

void ProcesoResize::procesoTerminado(int fin)
{
    if (fin!=0)
    {
        QString mensajeError=_flujo.readAll();
        _opeActual->setFallida(mensajeError);
    }
    else
        _opeActual->incrementarPasos();
#ifdef QT_DEBUG
    qDebug()<< "Class ProcesoResize::procesoTerminado() -> TERMINADO";
#endif
    _libre=true;
    emit procesoLibre();
}

