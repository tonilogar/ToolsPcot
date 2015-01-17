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
#include "operacionorto.h"
#include <math.h>
OperacionOrto::OperacionOrto(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP) :
    Operacion(parent,idCoor,dataZP)
{
    _totalPasos=1;
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
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if (_dataZP->getFootPrintMask())
            {
                _totalPasos+=3;
                recalcularTablaFPM();
            }
            else if(_dataZP->getCutDtm())
            {
                _totalPasos+=2;
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if (_dataZP->getFootPrintMask() && _dataZP->getCutDtm()==false)
            {
                _totalPasos++;
                recalcularTablaFPM();
            }
            if (_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
            {
               _totalPasos+=2;
                recalcularTablaFPM();
            }
            if (_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
            {
               _totalPasos++;
            }
        }

        //Codigo AM
//        else
//        {
//            if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
//            {
//                _totalPasos+=2;
//                recalcularTablaFPM();
//            }
//            else
//            {
//                if(_dataZP->getCutDtm())
//                {
//                    _totalPasos++;
//                }
//                else if (_dataZP->getFootPrintMask())
//                {
//                    _totalPasos+=2;
//                    recalcularTablaFPM();
//                }
//            }
//        }
        _cCortes=new CCMet(this,_coordenadas,_dataZP);
        if (_dataZP->getCutDtm())
        {
            listaCortes=_cCortes->generaListaCortes();
            _totalPasos=_totalPasos+listaCortes.count();
        }
        _wCoor->setIdentificadorCoordenadas(_coordenadas);

}

QString OperacionOrto::getFileCnpOrigen()
{
    QString ficheroSalidaCnp=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+".cnp";
    return ficheroSalidaCnp;
}

void OperacionOrto::recalcularTablaFPM()
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

    x1=xa+0.5*swath*(-yVector);
    y1=ya+0.5*swath*(xVector);

    x2=xa-0.5*swath*(-yVector);
    y2=ya-0.5*swath*(xVector);

    x3=xb-0.5*swath*(-yVector);
    y3=yb-0.5*swath*(xVector);

    x4=xb+0.5*swath*(-yVector);
    y4=yb+0.5*swath*(xVector);
    //Calcular este oeste
    if(x1==x2 || x1>x2)
    {
        este1=x1;
        oeste1=x2;
    }
    else
    {
        oeste1=x1;
        este1=x2;
    }
    if(x3==x4 || x3>x4)
    {
        este2=x3;
        oeste2=x4;
    }
    else
    {
        oeste2=x3;
        este2=x4;
    }

    if(este1==este2 || este1>este2)
    {
        esteF=este1;
    }
    else
    {
        esteF=este2;
    }

    if(oeste1==oeste2 || oeste1>oeste2)
    {
        oesteF=este2;
    }
    else
    {
        oesteF=oeste1;
    }

//Calcular norte sur
    if(y1==y2 || y1>y2)
    {
        norte1=y1;
        sur1=y2;
    }
    else
    {
        sur1=y1;
        norte1=y2;
    }
    if(y3==y4 || y3>y4)
    {
        norte2=y3;
        sur2=y4;
    }
    else
    {
        sur2=y3;
        norte2=y4;
    }

    if(norte1==norte2 || norte1>norte2)
    {
        norteF=norte1;
    }
    else
    {
        norteF=norte2;
    }

    if(sur1==sur2 || sur1>sur2)
    {
        surF=sur2;
    }
    else
    {
        surF=sur1;
    }


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




//    if(xa==xb || xa>xb)
//    {
//        esteF=xa+((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        oesteF=xb-((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        xa=esteF;
//        xb=oesteF;
//    }
//    else
//    {
//        oesteF=xa-((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        esteF=xb+((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        xa=oesteF;
//        xb=esteF;
//    }
//    if(ya==yb || ya>yb)
//    {
//        norteF=ya+((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        surF=yb-((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        ya=norteF;
//        yb=surF;
//    }
//    else
//    {
//        surF=ya-((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        norteF=yb+((_dataZP->getSizePixel())*sizePixel*_numberPixelsSensor*2);
//        ya=surF;
//        yb=norteF;
//    }
    _coordenadas=_idCoorFPM;
    _idCoorFPM->setIdentificador(_idCoor->getIdentificador());
    _idCoorFPM->setXa(esteF);
    _idCoorFPM->setXb(oesteF);
    _idCoorFPM->setYa(surF);
    _idCoorFPM->setYb(norteF);
}



void OperacionOrto::aceptarProceso(Proceso *p)
{
    p->metodoOrto(this);
}

QString OperacionOrto::getFileOrigen()
{
    QString _fileOrigen;
    switch (contadorpasos) {
    case 0://Se genera un corte a partir del fichero origen de ambito con subscene
        _fileOrigen=_dataZP->getImageProject();
        break;
    case 1:
        _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_TallOrto.rf";
        break;
   case 2:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask())
            {
             _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto.rf";
            }
            else
            {
              _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeoOrto.rf";
            }
        }
        else
        {
          _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";
        }
        break;
    case 3:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
            {
            _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";
            }
            if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
            {
            _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeoOrto.rf";
            }
            if(_dataZP->getFootPrintMask()==true && _dataZP->getCutDtm()==false)
            {
            _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeoOrto.rf";
            }
        }
        else //Si el sistema de coordenadas es etrs89 o ntf
        {
            if(_dataZP->getFootPrintMask())
            {
             _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto.rf";
            }
            else
            {
              _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";
            }
        }
        break;

        default:

        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {

             _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";

        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if(_dataZP->getFootPrintMask())
            {
           _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto.rf";
            }
            if(_dataZP->getFootPrintMask()==false)
            {
           _fileOrigen=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";
            }

        }

        break;
    }
    //qDebug()<< _fileOrigen << "_fileOrigen";
    //qDebug()<< contadorpasos << "contadorpasos";
    return _fileOrigen;
}

QString OperacionOrto::getFileDestino()
{
    QString _fileDestino;

    switch (contadorpasos) {
    case 0:
        _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_TallOrto.rf";
        break;
    case 1:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
            {
            if(_dataZP->getFootPrintMask())
            {
              _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto.rf";
            }
            else
            {
              _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeoOrto.rf";
            }
        }
        else
            {
            if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm()==false)
            {
               _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto.rf";
            }
            if(_dataZP->getCutDtm())
            {
              _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";
            }
        }
        break;
    case 2:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask())
            {
             _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ImaOpeGeoOrto.rf";
            }
            else
            {
              _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";
            }
        }
        else
        {
            if(_dataZP->getFootPrintMask())
            {
             _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto.rf";
            }
            else
            {
              _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-1)+".rf";
            }
        }
        break;
    case 3:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask()==false)
            {
            _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-2)+".rf";
            }
            else
            {
               _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto.rf";
            }
        }
        else //Si el sistema de coordenadas es etrs89
        {
            if(_dataZP->getFootPrintMask())
            {
             _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto"+QString::number(contadorpasos-2)+".rf";
            }
            else
            {
              _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-1)+".rf";
            }
        }
        break;
//        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
//        {
//            if(_dataZP->getFootPrintMask())
//            {
//             _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-3)+".rf";
//            }
//            else
//            {
//               _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-2)+".rf";
//            }
//        }
        default:
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
        {
            if(_dataZP->getFootPrintMask())
            {
             _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-3)+".rf";
            }
            else
            {
               _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-2)+".rf";
            }
        }
        if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
        {
            if(_dataZP->getFootPrintMask())
            {
             _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_FootPrintMaskOrto"+QString::number(contadorpasos-2)+".rf";
            }
            else
            {
               _fileDestino=_dataZP->getFolderOut()+"\\"+_coordenadas->getIdentificador()+"_ResizeOrto"+QString::number(contadorpasos-1)+".rf";
            }
        }

        break;

    }
    //qDebug()<< _fileDestino << "_fileDestino";
    //qDebug()<< contadorpasos << "contadorpasos";
    return _fileDestino;
}

double OperacionOrto::getEste()
{
    if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnDer();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnDer();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==2)
        {
            return listaCortes.at(contadorpasos-2)->getColumnDer();
        }
        if(contadorpasos>2)
        {
            return listaCortes.at(contadorpasos-2)->getColumnDer();
        }
    }
    }
    if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==4)
        {
            return listaCortes.at(contadorpasos-4)->getColumnDer();
        }
        if(contadorpasos>4)
        {
            return listaCortes.at(contadorpasos-4)->getColumnDer();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnDer();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnDer();
        }
    }
    }
    return Operacion::getEste();
}

double OperacionOrto::getOeste()
{
    if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnIz();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnIz();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==2)
        {
            return listaCortes.at(contadorpasos-2)->getColumnIz();
        }
        if(contadorpasos>2)
        {
            return listaCortes.at(contadorpasos-2)->getColumnIz();
        }
    }
    }
    if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==4)
        {
            return listaCortes.at(contadorpasos-4)->getColumnIz();
        }
        if(contadorpasos>4)
        {
            return listaCortes.at(contadorpasos-4)->getColumnIz();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnIz();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getColumnIz();
        }
    }
    }
    return Operacion::getOeste();
}
double OperacionOrto::getNorte()
{
    if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaSup();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaSup();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==2)
        {
            return listaCortes.at(contadorpasos-2)->getFilaSup();
        }
        if(contadorpasos>2)
        {
            return listaCortes.at(contadorpasos-2)->getFilaSup();
        }
    }
    }

    if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==4)
        {
            return listaCortes.at(contadorpasos-4)->getFilaSup();
        }
        if(contadorpasos>4)
        {
            return listaCortes.at(contadorpasos-4)->getFilaSup();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaSup();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaSup();
        }
    }
    }
    return Operacion::getNorte();
}
double OperacionOrto::getSur()
{
    if(_dataZP->getCoordinateSystem()==DataZoneProject::Etrs89)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaInf();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaInf();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==2)
        {
            return listaCortes.at(contadorpasos-2)->getFilaInf();
        }
        if(contadorpasos>2)
        {
            return listaCortes.at(contadorpasos-2)->getFilaInf();
        }
    }
    }
    if(_dataZP->getCoordinateSystem()==DataZoneProject::Ed50)
    {
    if(_dataZP->getFootPrintMask() && _dataZP->getCutDtm())
    {
        if(contadorpasos==4)
        {
            return listaCortes.at(contadorpasos-4)->getFilaInf();
        }
        if(contadorpasos>4)
        {
            return listaCortes.at(contadorpasos-4)->getFilaInf();
        }
    }
    if(_dataZP->getFootPrintMask()==false && _dataZP->getCutDtm())
    {
        if(contadorpasos==3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaInf();
        }
        if(contadorpasos>3)
        {
            return listaCortes.at(contadorpasos-3)->getFilaInf();
        }
    }
    }
    return Operacion::getSur();
}

