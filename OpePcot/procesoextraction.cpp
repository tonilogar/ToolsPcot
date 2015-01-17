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
#include "procesoextraction.h"
#include "operacion.h"
ProcesoExtraction::ProcesoExtraction(QObject *parent,QString pathProceso) :
    Proceso(parent,pathProceso)
{
}

void ProcesoExtraction::metodoMet(Operacion *op)
{
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}

void ProcesoExtraction::procesoIniciado()
{
    _flujo << "63" << endl;
    _flujo << "1" << endl;
    _flujo << _opeActual->getOeste() << endl;
    _flujo << _opeActual->getSur() << endl;
    _flujo << _opeActual->getEste() << endl;
    _flujo << _opeActual->getNorte() << endl;
    _flujo << "2" << endl;
    _flujo << "n" << endl;
    _flujo << "2" << endl;
    _flujo << _opeActual->getFileDestino()<< endl;
    _flujo << "n" << endl;
    _flujo << "n" << endl;
    qDebug()<<_opeActual->getOeste()<< "_opeActual->getOeste()";
    qDebug()<<_opeActual->getSur()<< "_opeActual->getSur()";
    qDebug()<<_opeActual->getEste()<< "_opeActual->getEste()";
    qDebug()<<_opeActual->getNorte()<< "_opeActual->getNorte()";
    qDebug()<< _opeActual->getFileDestino()<< "fichero Destino Extraction";
}
void ProcesoExtraction::procesoTerminado(int fin)
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
