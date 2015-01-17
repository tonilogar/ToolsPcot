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
    int este, oeste, norte, sur, xa ,ya ,xb ,yb;
    QString identificador;

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


    qDebug()<< identificador <<"identificador" << endl;
    xa=_ideCoordenadas->getXa();
    xb=_ideCoordenadas->getXb();
    ya=_ideCoordenadas->getYa();
    yb=_ideCoordenadas->getYb();
    //Calculo que coordenada es este, oeste, norte, sur
    if(xa==xb || xa>xb)
    {
        este=xa;
        oeste=xb;
    }
    else
    {
        oeste=xa;
        este=xb;
    }
    if(ya==yb || ya>yb)
    {
        norte=ya;
        sur=yb;
    }
    else
    {
        sur=ya;
        norte=yb;
    }
    //Calculo el numero de columnas y filas que tiene el Met
    qDebug()<< este << "este";
    qDebug()<< oeste << "oeste";
    qDebug()<< norte << "norte";
    qDebug()<< sur << "sur";

    int numeroColumTotal=((este-oeste)/_dataZProject->getSizePixel())+1;
    qDebug()<< numeroColumTotal << "numeroColumTotal";
    numeroColumTotal=numeroColumTotal-50;
    qDebug()<< numeroColumTotal << "numeroColumTotal - 50";


    int numeroFilaTotal=((norte-sur)/_dataZProject->getSizePixel())+1;


    qDebug()<< numeroFilaTotal << "numeroFilaTotal";
    numeroFilaTotal=numeroFilaTotal-50;
    qDebug()<< numeroFilaTotal << "numeroFilaTotal - 50";
    int filaSup, filaInf, ColumnIz, ColumnDe;
    if(numeroColumTotal < numeroFilaTotal)
    {

        int verticalSize=(_dataZProject->getSizeCut()*1024*1024)/(4*(_dataZProject->getNumberCanals())*numeroColumTotal);
        float numeroTall=(float)numeroFilaTotal/verticalSize;
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
