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
#include "procesogeotrans.h"
#include "operacion.h"

ProcesoGeoTrans::ProcesoGeoTrans(QObject *parent,QString pathProceso) :
    Proceso(parent,pathProceso)
{
}

void ProcesoGeoTrans::metodoMet(Operacion *op)
{
    metodoInvocado=Met;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}
void ProcesoGeoTrans::metodoOrto(Operacion *op)
{
    metodoInvocado=Orto;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}

void ProcesoGeoTrans::procesoIniciado()
{
    if(metodoInvocado==Met)
    {//si las cooordenadas son etrs89 y el ambito de proyecto es catalunya.
        if(_opeActual->getDataZoneProyect()->getCoordinateSystem()==DataZoneProject::Etrs89 && _opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Catalunya)
        {
            _flujo << _opeActual->getFileOrigen() << endl;
            _flujo << endl;
            _flujo << endl;
            _flujo << endl;
            _flujo << endl;
            _flujo << endl;
            _flujo << "1" << endl;
            _flujo << "UB91_ANIV" << endl;
            double sizePixel= _opeActual->getDataZoneProyect()->getSizePixel();
            _flujo << sizePixel << "," << sizePixel << endl;
            _flujo << endl;
            _flujo << _opeActual->getFileDestino() << endl;
            _flujo << endl;
            _flujo << "n" << endl;
        }
        if(_opeActual->getDataZoneProyect()->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Catalunya)
            {
                _flujo << _opeActual->getFileOrigen() << endl;
                _flujo << endl;
                _flujo << "100" << endl;
                _flujo << endl;
                _flujo << endl;
                _flujo << endl;
                _flujo << "1" << endl;
                _flujo << "800100402" << endl;
                _flujo << "UB91_ANIV" << endl;
                double sizePixel= _opeActual->getDataZoneProyect()->getSizePixel();
                _flujo << sizePixel << "," << sizePixel << endl;
                _flujo << endl;
                _flujo << _opeActual->getFileDestino() << endl;
                _flujo << endl;
                _flujo << "n" << endl;
            }
            if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Espanya)
            {
                _flujo << _opeActual->getFileOrigen() << endl;
                _flujo << endl;
                _flujo << "100" << endl;
                _flujo << endl;
                _flujo << endl;
                _flujo << endl;
                _flujo << endl;
                _flujo << "800100402" << endl;
                double sizePixel= _opeActual->getDataZoneProyect()->getSizePixel();
                _flujo << sizePixel << "," << sizePixel << endl;
                _flujo << endl;
                _flujo << _opeActual->getFileDestino() << endl;
                _flujo << endl;
                _flujo << "n" << endl;
            }
        }
    }
    if(metodoInvocado==Orto)

    {
            if(_opeActual->getDataZoneProyect()->getCoordinateSystem()==DataZoneProject::Ed50)
            {
                if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Catalunya)
                {
                    _flujo << _opeActual->getFileOrigen() << endl;
                    _flujo << endl;
                    _flujo << "100" << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << "3" << endl;
                    _flujo << "63" << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << "1" << endl;
                    _flujo << "800100402" << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << _opeActual->getFileDestino() << endl;
                    _flujo << endl;
                    _flujo << "2" << endl;
                    _flujo << "0" << endl;
                    _flujo << "n" << endl;

                }
                if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Espanya)
                {
                    _flujo << _opeActual->getFileOrigen() << endl;
                    _flujo << endl;
                    _flujo << "100" << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << "3" << endl;
                    _flujo << "56" << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << "1" << endl;
                    _flujo << "800100500" << endl;
                    _flujo << "700800600" << endl;
                    _flujo << "IBERGEO95" << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << endl;
                    _flujo << _opeActual->getFileDestino() << endl;
                    _flujo << endl;
                    _flujo << "2" << endl;
                    _flujo << "0" << endl;
                    _flujo << "n" << endl;
                }
            }
    }
}
void ProcesoGeoTrans::procesoTerminado(int fin)
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
