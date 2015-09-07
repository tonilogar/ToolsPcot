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
#include "procesosubscene.h"
#include "operacion.h"
ProcesoSubScene::ProcesoSubScene(QObject *parent,QString pathProceso) :
    Proceso(parent,pathProceso)
{
}

void ProcesoSubScene::metodoMet(Operacion *op)
{
    metodoInvocado=Met;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}
void ProcesoSubScene::metodoOrto(Operacion *op)
{
    metodoInvocado=Orto;
    _opeActual=op;
    _libre=false;
    emit procesoOcupado();
    _proceso.start(_pathProceso);
}
void ProcesoSubScene::procesoIniciado()
{
    //El proceso subScene de met solo se utiliza para Espanya y Francia
    if(metodoInvocado==Met)
    {
        _flujo << _opeActual->getFileOrigen() << endl;
#ifdef QT_DEBUG
        qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<< _opeActual->getFileOrigen() << ", imagenBase";
#endif
        _flujo << "s" << endl;
        _flujo << "n" << endl;
        _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
#ifdef QT_DEBUG
        qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getOeste() << ", " << _opeActual->getEste() << ", "<< _opeActual->getNorte() << ", "<< _opeActual->getSur() << "las 4 coordenadas ";
        qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getNorte()<< "_opeActual->getNorte()SubScene";
        qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getSur()<< "_opeActual->getSur()SubScene";
        qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getEste()<< "_opeActual->getEste()SubScene";
        qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getOeste()<< "_opeActual->getOeste()SubScene";
#endif
        _flujo << "n" << endl;
        _flujo << "n" << endl;
        _flujo << _opeActual->getFileDestino() << endl;
#ifdef QT_DEBUG
        qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getFileDestino() << "identificador";
#endif
        _flujo << endl;
    }
    if(metodoInvocado==Orto)
    {//No cambio el sistema de coordenadas
        if(_opeActual->getDataZoneProyect()->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            _flujo << "http:" << endl;
            if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Espanya)
            {
                _flujo << "8" << endl;
                _flujo << _opeActual->getFileOrigen() << endl;
                _flujo << "2" << endl;
                _flujo << "1" << endl;
                _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                _flujo << endl;
                _flujo << "4" << endl;
                _flujo << "s" << endl;
                _flujo << "n" << endl;
                _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                _flujo << "n" << endl;
                _flujo << "n" << endl;
                _flujo << _opeActual->getFileDestino() << endl;
                _flujo << endl;
            }
            if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Catalunya)
            {
                _flujo << "8" << endl;
                _flujo << _opeActual->getFileOrigen() << endl;
                 _flujo << "12" << endl;
                _flujo << "2" << endl;
                _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                _flujo << "4" << endl;
                _flujo << "s" << endl;
                _flujo << "n" << endl;
                _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                _flujo << "n" << endl;
#ifdef QT_DEBUG
                qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<< _opeActual->getNorte()<< "_opeActual->getNorte()";
                qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getSur()<< "_opeActual->getSur()";
                qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getEste()<< "_opeActual->getEste()";
                qDebug()<<"Class ProcesoSubScene::procesoIniciado() -> "<<_opeActual->getOeste()<< "_opeActual->getOeste()";
#endif
                _flujo << "n" << endl;
                _flujo << _opeActual->getFileDestino() << endl;
                _flujo << endl;
            }
        }
        //si el sistema de coordenadas es ed50 y footPrintMask es false
        if(_opeActual->getDataZoneProyect()->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            _flujo << "http:" << endl;
            if(_opeActual->getDataZoneProyect()->getFootPrintMask()==false && _opeActual->getDataZoneProyect()->getCutDtm()==false)
            {
                if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Espanya)
                {
                    _flujo << "8" << endl;
                    _flujo << _opeActual->getFileOrigen() << endl;
                    _flujo << "2" << endl;
                    _flujo << "13" << endl;
                    //Trunco el tamanyo de pixel porque el fichero que le pase a la operacion geotrans
                    //tiene que tener el tamanyo de pixel integer sin decimales
                    _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                    _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                    _flujo << endl;
                    _flujo << "4" << endl;
                    _flujo << "s" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                    _flujo << "n" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getFileDestino() << endl;
                    _flujo << endl;
                }
                if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Catalunya )
                {
                    _flujo << "8" << endl;
                    _flujo << _opeActual->getFileOrigen() << endl;
                    _flujo << "12" << endl;
                    _flujo << "1" << endl;
                    //Trunco el tamanyo de pixel porque el fichero que le pase a la operacion geotrans
                    //tiene que tener el tamanyo de pixel integer sin decimales
                    _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                    _flujo << _opeActual->getDataZoneProyect()->getSizePixel() << endl;
                    _flujo << "6" << endl;
                    _flujo << "s" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                    _flujo << "n" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getFileDestino() << endl;
                    _flujo << endl;
                }
            }
            else//si el sistema de coordenadas es ed50 y footPrintMask es true
            {
                if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Espanya)
                {
                    _flujo << "8" << endl;
                    _flujo << _opeActual->getFileOrigen() << endl;
                    _flujo << "2" << endl;
                    _flujo << "1" << endl;
                    //Trunco el tamanyo de pixel porque el fichero que le pase a la operacion geotrans
                    //tiene que tener el tamanyo de pixel integer sin decimales
                    float sizePixel=_opeActual->getDataZoneProyect()->getSizePixel();
                    sizePixel=(int)trunc(sizePixel);
                    if(sizePixel==0)
                    {
                     sizePixel=1;
                    }
                    _flujo << sizePixel << endl;
                    _flujo << sizePixel << endl;
                    _flujo << endl;
                    _flujo << "4" << endl;
                    _flujo << "s" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                    _flujo << "n" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getFileDestino() << endl;
                    _flujo << endl;
                }


                if(_opeActual->getDataZoneProyect()->getFootPrintMask()==false && _opeActual->getDataZoneProyect()->getCutDtm()==true)
                {
                    if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Espanya)
                    {
                        _flujo << "8" << endl;
                        _flujo << _opeActual->getFileOrigen() << endl;
                        _flujo << "2" << endl;
                        _flujo << "1" << endl;
                        //Trunco el tamanyo de pixel porque el fichero que le pase a la operacion geotrans
                        //tiene que tener el tamanyo de pixel integer sin decimales
                        float sizePixel=_opeActual->getDataZoneProyect()->getSizePixel();
                        sizePixel=(int)trunc(sizePixel);
                        if(sizePixel==0)
                        {
                         sizePixel=1;
                        }
                        _flujo << sizePixel << endl;
                        _flujo << sizePixel << endl;
                        _flujo << endl;
                        _flujo << "4" << endl;
                        _flujo << "s" << endl;
                        _flujo << "n" << endl;
                        _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                        _flujo << "n" << endl;
                        _flujo << "n" << endl;
                        _flujo << _opeActual->getFileDestino() << endl;
                        _flujo << endl;
                    }
                    if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Catalunya )
                    {
                        _flujo << "8" << endl;
                        _flujo << _opeActual->getFileOrigen() << endl;
                        _flujo << "12" << endl;
                        _flujo << "2" << endl;
                        //Trunco el tamanyo de pixel porque el fichero que le pase a la operacion geotrans
                        //tiene que tener el tamanyo de pixel integer sin decimales
                        float sizePixel=_opeActual->getDataZoneProyect()->getSizePixel();
                        sizePixel=(int)trunc(sizePixel);
                        if(sizePixel==0)
                        {
                         sizePixel=1;
                        }
                        _flujo << sizePixel << endl;
                        _flujo << sizePixel << endl;
                        _flujo << "6" << endl;
                        _flujo << "s" << endl;
                        _flujo << "n" << endl;
                        _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                        _flujo << "n" << endl;
                        _flujo << "n" << endl;
                        _flujo << _opeActual->getFileDestino() << endl;
                        _flujo << endl;
                    }
                }
                if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Catalunya)
                {
                    _flujo << "8" << endl;
                    _flujo << _opeActual->getFileOrigen() << endl;
                    _flujo << "12" << endl;
                    _flujo << "2" << endl;
                    //Trunco el tamanyo de pixel porque el fichero que le pase a la operacion geotrans
                    //tiene que tener el tamanyo de pixel integer sin decimales
                    float sizePixel=_opeActual->getDataZoneProyect()->getSizePixel();
                    sizePixel=(int)trunc(sizePixel);
                    if(sizePixel==0)
                    {
                     sizePixel=1;
                    }
                    _flujo << sizePixel << endl;
                    _flujo << sizePixel << endl;
                    _flujo << "6" << endl;
                    _flujo << "s" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getOeste() << " " << _opeActual->getEste() << " "<< _opeActual->getNorte() << " "<< _opeActual->getSur() << " " << endl;
                    _flujo << "n" << endl;
                    _flujo << "n" << endl;
                    _flujo << _opeActual->getFileDestino() << endl;
                    _flujo << endl;
                }
            }
        }
        if(_opeActual->getDataZoneProyect()->getAmbitoOperacion()==DataZoneProject::Francia)
        {
            // Tengo que hacer el servidor wms para trabajar con las ortofotos de Francia
        }

    }
}
void ProcesoSubScene::procesoTerminado(int fin)
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

