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
#include "operacionmet.h"
#include <math.h>
#define MIN(a,b) ((a)<(b)? (a):(b))
#define MAX(a,b) ((a)>(b)? (a):(b))
OperacionMet::OperacionMet(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP) :
    Operacion(parent,idCoor,dataZP)
{
    _totalPasos=2;
    _idCoorFPM=0;
    _coordenadas=_idCoor;
    _numberPixelsSensor=0;
    if(_dataZP->getSelectSensor()==DataZoneProject::Casi)
        _numberPixelsSensor=550;
    else if(_dataZP->getSelectSensor()==DataZoneProject::Tasi)
        _numberPixelsSensor=600;
    else if(_dataZP->getSelectSensor()==DataZoneProject::Aisa)
        _numberPixelsSensor=1024;
    else if(_dataZP->getSelectSensor()==DataZoneProject::Aisa_BE)
        _numberPixelsSensor=512;
    if (_dataZP->getFootPrintMask())
    {
        _totalPasos++;
        recalcularTablaFPM();
    }
    _cCortes=new CCMet(this,_coordenadas,_dataZP);
    if (_dataZP->getCutDtm())
    {
        listaCortes=_cCortes->generaListaCortes();
        _totalPasos=_totalPasos+listaCortes.count();
    }
    _wCoor->setIdentificadorCoordenadas(_coordenadas);

}
QString OperacionMet::getFileCnpOrigen()
{
    QString ficheroSalidaCnp=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+".cnp";
    return ficheroSalidaCnp;
}
void OperacionMet::recalcularTablaFPM()
{
       double esteF, oesteF, norteF, surF, este1, oeste1, norte1, sur1, este2, oeste2, norte2, sur2, xa ,ya ,xb ,yb;
       double x1 ,y1 ,x2 ,y2, x3 ,y3 ,x4 ,y4;
       xa=_idCoor->getXa();
       xb=_idCoor->getXb();
       ya=_idCoor->getYa();
       yb=_idCoor->getYb();

       double swath=_dataZP->getSizePixel()*_numberPixelsSensor*1.5;
       double xVector=(xa-xb)/sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
       double yVector=(ya-yb)/sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));

       qDebug()<< xVector <<"xVector";
       qDebug()<< yVector <<"yVector";

       x1=xa-0.5*swath*(yVector);
       y1=ya+0.5*swath*(xVector);

       x2=xa+0.5*swath*(yVector);
       y2=ya-0.5*swath*(xVector);

       x3=xb+0.5*swath*(yVector);
       y3=yb-0.5*swath*(xVector);

       x4=xb-0.5*swath*(yVector);
       y4=yb+0.5*swath*(xVector);
       //Calcular este oeste

//       esteF= MAX(x1,x2);
//       esteF= MAX(esteF,x3);
//       esteF= MAX(esteF,x4);

//       oesteF= MIN(x1,x2);
//       oesteF= MIN(oesteF,x3);
//       oesteF= MIN(oesteF,x4);
       QList<float> esteOeste;
       esteOeste << x1 << x2 << x3 << x4;
       qSort(esteOeste.begin(), esteOeste.end());
       esteF=esteOeste.last();
       oesteF=esteOeste.first();

   //Calcular norte sur
       QList<float> norteSur;
       norteSur << y1 << y2 << y3 << y4;
       qSort(norteSur.begin(), norteSur.end());
       norteF=norteSur.last();
       surF=norteSur.first();


       qDebug()<< x1 <<"x1";
       qDebug()<< x2 <<"x2";
       qDebug()<< x3 <<"x3";
       qDebug()<< x4 <<"x4";
       qDebug()<< esteF <<"esteF";
       qDebug()<< oesteF <<"oesteF";
       qDebug()<< y1 <<"y1";
       qDebug()<< y2 <<"y2";
       qDebug()<< y3 <<"y3";
       qDebug()<< y4 <<"y4";
       qDebug()<< norteF <<"norteF";
       qDebug()<< surF <<"surF";
       qDebug()<< _dataZP->getSizePixel() <<"_dataZP->getSizePixel()";
       qDebug()<< _numberPixelsSensor <<"_numberPixelsSensor";

       _idCoorFPM=new IdentificadorCoordenadas(this);
       _coordenadas=_idCoorFPM;
       _idCoorFPM->setIdentificador(_idCoor->getIdentificador());

       _idCoorFPM->setXa(esteF);
       _idCoorFPM->setXb(oesteF);
       _idCoorFPM->setYa(surF);
       _idCoorFPM->setYb(norteF);
}

void OperacionMet::aceptarProceso(Proceso *p)
{
    p->metodoMet(this);
}

QString OperacionMet::getFileOrigen()
{
    QString _fileOrigen;
    switch (contadorpasos) {
    case 0://Se genera un corte a partir del fichero origen de ambito con extraction o subscene
        _fileOrigen=_dataZP->getImageProject();
        break;
    case 1://A partir del resultado del case 0 si es etrs89 utilizamos geoTrans(catalunya) o resize (Espanya Francia)
        //Si es Ed50 y FpptPrintMask true utilizamos FootPintMask si es false utilizamos Geotrans
        _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_SubSene.rf";
        break;
    case 2://Si es etrs89 y footprint true utilizamos FootPrintMask si es false cortamos la escena cutDtm
        //Si es Ed50 y footprint true utilizamos Geotrans si es false cortamos la escena cutDtm
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if(_dataZP->getAmbitoOperacion()==DataZoneProject::Catalunya)
            {
                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO.rf";
            }
            else
            {
                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize.rf";
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask()==false)
            {
                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO.rf";
            }
            else
            {
                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask.rf";
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ntf)
        {
            _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize.rf";
        }
        break;
        //Si el case es superior a 2 cortamos los ficheros finales con cutdtm
    default:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if(_dataZP->getFootPrintMask()==true)

                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask.rf";
        }
        if(_dataZP->getFootPrintMask()==false)
        {
            if(_dataZP->getAmbitoOperacion()==DataZoneProject::Catalunya)
            {
                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO.rf";
            }
            if(_dataZP->getAmbitoOperacion()==DataZoneProject::Espanya)
            {
                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize.rf";
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO.rf";
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ntf)
        {
            if(_dataZP->getFootPrintMask()==true)
            {

                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask.rf";
            }
            else
            {
                _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize.rf";
            }
        }
        break;
    }
    qDebug()<< _fileOrigen << "_fileOrigen";
    return _fileOrigen;
}
QString OperacionMet::getFileDestino()
{
    QString _fileDestino;

    switch (contadorpasos) {
    case 0:
        _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_SubSene.rf";
        qDebug()<< _fileDestino << "_filedestino";
        break;
    case 1:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if(_dataZP->getAmbitoOperacion()==DataZoneProject::Catalunya)
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO.rf";
            }
            else
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize.rf";
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask())
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask.rf";
            }
            else
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO.rf";
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ntf)
        {
            _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize.rf";
        }
        break;
    case 2:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if(_dataZP->getFootPrintMask())
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask.rf";
            }
            else
            {
                if(_dataZP->getAmbitoOperacion()==DataZoneProject::Catalunya)
                {
                    _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO"+QString::number(contadorpasos-1)+".rf";
                }
                if(_dataZP->getAmbitoOperacion()==DataZoneProject::Espanya)
                {
                    _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize"+QString::number(contadorpasos-1)+".rf";
                }
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask())
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO.rf";
            }
            else
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO"+QString::number(contadorpasos-1)+".rf";
            }
        }

        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ntf)
        {
            if(_dataZP->getFootPrintMask())
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask.rf";
            }
            else
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize"+QString::number(contadorpasos-1)+".rf";
            }
        }
        break;
    default:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if(_dataZP->getFootPrintMask())
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask"+QString::number(contadorpasos-2)+".rf";
            }
            else
            {
                if(_dataZP->getAmbitoOperacion()==DataZoneProject::Catalunya)
                {
                    _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO"+QString::number(contadorpasos-1)+".rf";
                }
                if(_dataZP->getAmbitoOperacion()==DataZoneProject::Espanya)
                {
                    _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize"+QString::number(contadorpasos-1)+".rf";
                }

            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask())
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO"+QString::number(contadorpasos-2)+".rf";
            }
            else
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeO"+QString::number(contadorpasos-1)+".rf";
            }
        }

        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ntf)
        {
            if(_dataZP->getFootPrintMask())
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMask"+QString::number(contadorpasos-2)+".rf";
            }
            else
            {
                _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_Resize"+QString::number(contadorpasos-1)+".rf";
            }
        }
        break;
    }
    qDebug()<< _fileDestino << "_filedestino";
    return _fileDestino;
}
double OperacionMet::getEste()
{
    if(_dataZP->getFootPrintMask())
    {
        if(contadorpasos>2)
        {
            qDebug()<< listaCortes.at(contadorpasos-3)->getColumnDer() << "Este" << _coordenadas->getIdentificador();
            return listaCortes.at(contadorpasos-3)->getColumnDer();
        }
        qDebug()<< Operacion::getEste() << "Este" << _coordenadas->getIdentificador();
        return Operacion::getEste();
    }
    if(contadorpasos>1)
    {
        qDebug()<< listaCortes.at(contadorpasos-2)->getColumnDer() << "Este" << _coordenadas->getIdentificador();
        return listaCortes.at(contadorpasos-2)->getColumnDer();
    }
    qDebug()<< Operacion::getEste() << "Este" << _coordenadas->getIdentificador();
    return Operacion::getEste();
}

double OperacionMet::getOeste()
{
    if(_dataZP->getFootPrintMask())
    {
        if(contadorpasos>2)
        {
            qDebug()<< listaCortes.at(contadorpasos-3)->getColumnIz() << "Oeste" << _coordenadas->getIdentificador();
            return listaCortes.at(contadorpasos-3)->getColumnIz();
        }
        qDebug()<< Operacion::getOeste() << "Oeste" << _coordenadas->getIdentificador();
        return Operacion::getOeste();
    }
    if(contadorpasos>1)
    {
        qDebug()<< listaCortes.at(contadorpasos-2)->getColumnIz() << "Oeste" << _coordenadas->getIdentificador();
        return listaCortes.at(contadorpasos-2)->getColumnIz();
    }
    qDebug()<< Operacion::getOeste() << "Oeste" << _coordenadas->getIdentificador();
    return Operacion::getOeste();
}
double OperacionMet::getNorte()
{
    if(_dataZP->getFootPrintMask())
    {
        if(contadorpasos>2)
        {
            qDebug()<< listaCortes.at(contadorpasos-3)->getFilaSup() << "Norte" << _coordenadas->getIdentificador();
            return listaCortes.at(contadorpasos-3)->getFilaSup();
        }
        qDebug()<< Operacion::getNorte() << "Norte" << _coordenadas->getIdentificador();
        return Operacion::getNorte();
    }
    if(contadorpasos>1)
    {
        qDebug()<< listaCortes.at(contadorpasos-2)->getFilaSup() << "Norte" << _coordenadas->getIdentificador();
        return listaCortes.at(contadorpasos-2)->getFilaSup();
    }
    qDebug()<< Operacion::getNorte() << "Norte" << _coordenadas->getIdentificador();
    return Operacion::getNorte();
}
double OperacionMet::getSur()
{
    if(_dataZP->getFootPrintMask())
    {
        if(contadorpasos>2)
        {
            qDebug()<< listaCortes.at(contadorpasos-3)->getFilaInf() << "Sur" << _coordenadas->getIdentificador();
            return listaCortes.at(contadorpasos-3)->getFilaInf();
        }
        qDebug()<< Operacion::getSur() << "Sur" << _coordenadas->getIdentificador();
        return Operacion::getSur();
    }
    if(contadorpasos>1)
    {
        qDebug()<< listaCortes.at(contadorpasos-2)->getFilaInf() << "Sur" << _coordenadas->getIdentificador();
        return listaCortes.at(contadorpasos-2)->getFilaInf();
    }
    qDebug()<< Operacion::getSur() << "Sur" << _coordenadas->getIdentificador();
    return Operacion::getSur();
}

