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
#include "ccmet.h"

CCMet::CCMet(QObject *parent, IdentificadorCoordenadas *ideCoordenadas, DataZoneProject *dataZProject) :
    CalculoCortes(parent,ideCoordenadas,dataZProject )
{
}

QList <CorteMet*> CCMet::generaListaCortes()
{
    QList <CorteMet*> listaCortes;
    QString identificador;
    int _numberPixelsSensor=0;
    if(_dataZProject->getSelectSensor()==DataZoneProject::Casi)
        _numberPixelsSensor=550;
    else if(_dataZProject->getSelectSensor()==DataZoneProject::Tasi)
        _numberPixelsSensor=600;
    else if(_dataZProject->getSelectSensor()==DataZoneProject::Aisa)
        _numberPixelsSensor=1024;
    else if(_dataZProject->getSelectSensor()==DataZoneProject::Aisa_BE)
        _numberPixelsSensor=512;

    if(_dataZProject->getCoordinateSystem()==DataZoneProject::Etrs89 || _dataZProject->getCoordinateSystem()==DataZoneProject::Ntf)
    {
        if(_dataZProject->getFootPrintMask())
        {
            identificador=_dataZProject->getFolderOut()+"\\"+_ideCoordenadas->getIdentificador()+"_FootPrintMask.rf";
        }
        else
        {
            if(_dataZProject->getAmbitoOperacion()==DataZoneProject::Catalunya)
            {
                identificador=_dataZProject->getFolderOut()+"\\"+_ideCoordenadas->getIdentificador()+"_ImaOpeGeO.rf";
            }
            else
            {
                identificador=_dataZProject->getFolderOut()+"\\"+_ideCoordenadas->getIdentificador()+"_Resize.rf";
            }
        }
    }
    if(_dataZProject->getCoordinateSystem()==DataZoneProject::Ed50)
    {
        identificador=_dataZProject->getFolderOut()+"\\"+_ideCoordenadas->getIdentificador()+"_ImaOpeGeO.rf";
    }

    double esteNew, oesteNew, norteNew, surNew, esteF, oesteF, norteF, surF, este1, oeste1, norte1, sur1, este2, oeste2, norte2, sur2, xa ,ya ,xb ,yb;
    double x1 ,y1 ,x2 ,y2, x3 ,y3 ,x4 ,y4;
    double pixelOld;
    if(_dataZProject->getAmbitoOperacion()==DataZoneProject::Catalunya)
    {
      pixelOld=2;
    }
    if(_dataZProject->getAmbitoOperacion()==DataZoneProject::Espanya)
    {
      pixelOld=5;
    }
    if(_dataZProject->getAmbitoOperacion()==DataZoneProject::Francia)
    {
      pixelOld=90;
    }
    xa=_ideCoordenadas->getXa();
    xb=_ideCoordenadas->getXb();
    ya=_ideCoordenadas->getYa();
    yb=_ideCoordenadas->getYb();

    double swath=_dataZProject->getSizePixel()*_numberPixelsSensor*1.5;
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

    //Calculo el numero de columnas y filas que tiene el Met
    qDebug()<< esteF << "este";
    qDebug()<< oesteF << "oeste";
    qDebug()<< norteF << "norte";
    qDebug()<< surF << "sur";

    int numeroColumTotal=((esteF-oesteF)/pixelOld);
    qDebug()<< numeroColumTotal << "numeroColumTotalSubScene";
    int numeroFilaTotal=((norteF-surF)/pixelOld);
    qDebug()<< numeroFilaTotal << "numeroColumTotalSubScene";


    norteNew=(norteF+(pixelOld/2))-_dataZProject->getSizePixel()/2;
    oesteNew=(oesteF+(pixelOld/2))-_dataZProject->getSizePixel()/2;

    int lin=numeroFilaTotal*(pixelOld/_dataZProject->getSizePixel());
    int col=numeroColumTotal*(pixelOld/_dataZProject->getSizePixel());
    surNew=norteNew-(lin-1)*_dataZProject->getSizePixel();
    esteNew=oesteNew+(col-1)*_dataZProject->getSizePixel();


    qDebug()<< esteNew << "esteNew";
    qDebug()<< oesteNew << "oesteNew";
    qDebug()<< norteNew << "norteNew";
    qDebug()<< surNew << "surNew";

    numeroColumTotal=((esteNew-oesteNew)/_dataZProject->getSizePixel())+1;
    qDebug()<< numeroColumTotal << "numeroColumTotalNew";
    numeroFilaTotal=((norteNew-surNew)/_dataZProject->getSizePixel())+1;
    qDebug()<< numeroFilaTotal << "numeroFilaTotalNew";

    int filaSup, filaInf, ColumnIz, ColumnDe;
    if(numeroColumTotal < numeroFilaTotal)
    {

        int verticalSize=(_dataZProject->getSizeCut()*1024*1024)/(4*(_dataZProject->getNumberCanals())*numeroColumTotal);
        float numeroTall=(float)numeroFilaTotal/verticalSize;
        qDebug()<< identificador << "identificador";
        qDebug()<< numeroTall << "numeroTall";
        numeroTall=(int)ceil(numeroTall);
        int verticalSizeDef=numeroFilaTotal/numeroTall;
        qDebug()<< numeroColumTotal << "numeroColumTotal";
        qDebug()<< verticalSize << "verticalSize";
        qDebug()<< numeroTall << "numeroTall ceill";
        qDebug()<< verticalSizeDef << "verticalSizeDef";
        int solape=0;
        int incremento=0;
        int resta=0;
        int x=0;
        if(numeroTall>1)
        {
            for(int i=1;i <= numeroTall;i++)
            {
                qDebug()<< "entro en el for de corte vertical";
                CorteMet *_datos=new CorteMet();
                qDebug()<< incremento << "incremento";
                qDebug()<< i << "iiiiiiiiiiiiiiiiiiiii";
                filaSup=incremento*x+1-solape-resta;
                qDebug()<< filaSup << "filaSup01";
                qDebug()<< incremento << "incremento";
                x++;
                solape=10;
                resta=1;
                incremento=verticalSizeDef;
                if(i==numeroTall)
                {
                    qDebug()<< "i==numeroTall";
                    filaInf=numeroFilaTotal;
                }
                else
                {
                    qDebug()<< "i!=numeroTall";
                    filaInf=verticalSizeDef*i;
                }
                qDebug()<< filaInf << "filaInf";
                ColumnIz=1;
                ColumnDe=numeroColumTotal;
                _datos->setFilaSup(filaSup);
                _datos->setFilaInf(filaInf);
                _datos->setColumnIz(ColumnIz);
                _datos->setColumnDer(ColumnDe);

                _datos->setNombreFileIn(identificador);
                listaCortes<<_datos;
            }
        }
        return listaCortes;
    }

    if(numeroFilaTotal < numeroColumTotal)
    {
        int horizontalSize=(_dataZProject->getSizeCut()*1024*1024)/(4*(_dataZProject->getNumberCanals())*numeroFilaTotal);
        float numeroTall=(float)numeroColumTotal/horizontalSize;
        qDebug()<< numeroTall << "numeroTall ceill";
        numeroTall=(int)ceil(numeroTall);
        qDebug()<< numeroTall << "numeroTall ceill";
        int horizontalSizeDef=numeroColumTotal/numeroTall;
        qDebug()<< numeroFilaTotal << "numeroFilaTotal";
        qDebug()<< horizontalSize << "horizontalSize";
        qDebug()<< horizontalSizeDef << "horizontalSizeDef";
        int solape=0;
        int incremento=0;
        int resta=0;
        int x=0;
        if(numeroTall>1)
        {
            for(int i=1;i <= numeroTall;i++)
            {
                qDebug()<< "entro en el for de corte horizontal";
                CorteMet *_datos=new CorteMet();
                qDebug()<< incremento << "incremento";
                qDebug()<< i << "iiiiiiiiiiiiiiiiiiiii";
                ColumnIz=incremento*x+1-solape-resta;
                qDebug()<< ColumnIz << "ColumnIz";
                qDebug()<< incremento << "incremento";
                x++;
                solape=10;
                resta=1;
                incremento=horizontalSizeDef;
                if(i==numeroTall)
                {
                    qDebug()<< "i==numeroTall";
                    ColumnDe=numeroColumTotal;
                }
                else
                {
                    qDebug()<< "i!=numeroTall";
                    ColumnDe=horizontalSizeDef*i;
                }
                qDebug()<< ColumnIz << "ColumnIz";
                qDebug()<< ColumnDe << "ColumnDe";
                filaSup=1;
                filaInf=numeroFilaTotal;
                _datos->setFilaSup(filaSup);
                _datos->setFilaInf(filaInf);
                _datos->setColumnIz(ColumnIz);
                _datos->setColumnDer(ColumnDe);
                _datos->setNombreFileIn(identificador);
                listaCortes<<_datos;
            }
        }
        return listaCortes;
    }
    return listaCortes;
}
