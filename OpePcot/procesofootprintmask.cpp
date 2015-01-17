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
#include "procesofootprintmask.h"
#include "operacion.h"

ProcesoFootPrintMask::ProcesoFootPrintMask(QObject *parent,QString pathProceso) :
    Proceso(parent,pathProceso)
{
    metodoInvocado=Desconocido;
}
void ProcesoFootPrintMask::metodoMet(Operacion *op)
{
    metodoInvocado=Met;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}
void ProcesoFootPrintMask::metodoOrto(Operacion *op)
{
    metodoInvocado=Orto;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}
void ProcesoFootPrintMask::procesoIniciado()
{
    QFile fileCnp(_opeActual->getFileCnpOrigen());
    QTextStream flujo;
    flujo.setDevice(&fileCnp);
    if(!fileCnp.open(QFile::Text | QFile::WriteOnly))
    {
        _opeActual->setFallida("No tienes permisos para crear el cnp");
        _libre=true;
        emit procesoLibre();
        return;
    }
    flujo<< "2,1" << endl;
    flujo<< "1,1 " << _opeActual->getidenCoor()->getXa() << " " << _opeActual->getidenCoor()->getYa()<< " " << _opeActual->getIdentificador() << "_1" << endl;
    flujo<< "1,1 " << _opeActual->getidenCoor()->getXb() << " " << _opeActual->getidenCoor()->getYb()<< " " << _opeActual->getIdentificador() << "_2" << endl;
    fileCnp.close();
    if(metodoInvocado==Met)
    {
    qDebug()<< _opeActual->getFileOrigen()<< "fichero origen";
    _flujo << _opeActual->getFileOrigen() << endl;
    _flujo << _opeActual->getFileCnpOrigen() << endl;
    _flujo << _opeActual->getFileDestino() << endl;
    _flujo << "1" << endl;
    _flujo << _opeActual->getDataZoneProyect()->getAnchoPasada() << endl;
    _flujo << _opeActual->getDataZoneProyect()->getOffsetPasada() << endl;
   qDebug()<<  _opeActual->getDataZoneProyect()->getAnchoPasada() << " _opeActual->getDataZoneProyect()->getAnchoPasada()";
}
    if(metodoInvocado==Orto)
    {
        qDebug()<< _opeActual->getFileOrigen()<< "fichero origen";
        _flujo << _opeActual->getFileOrigen() << endl;
        _flujo << _opeActual->getFileCnpOrigen() << endl;
        _flujo << _opeActual->getFileDestino() << endl;
        _flujo << "2" << endl;
        _flujo << _opeActual->getDataZoneProyect()->getAnchoPasada() << endl;
        _flujo << "12" << endl;
    }
}
void ProcesoFootPrintMask::procesoTerminado(int fin)
{
    if (fin!=0)
    {
        QString mensajeError=_flujo.readAll();
        _opeActual->setFallida(mensajeError);
    }
    else
        _opeActual->incrementarPasos();
    qDebug()<< "procesoTerminado";
    _libre=true;
    emit procesoLibre();
}
