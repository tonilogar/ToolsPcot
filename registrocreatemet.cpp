//    ToolsPcot
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
#include "registrocreatemet.h"

RegistroCreateMet::RegistroCreateMet(QObject *parent) :
    QObject(parent)
{
    _folderOut=QString();
    _ambitoProyecto=QString();
    _tamanyoPixel;
    _utm=-1;
    _dtm=false;
    _tamanyoCorte=-1;
    _numeroCanales=-1;
    _fprintM=false;
    _anchoPasada=-1;
    _offsetPasada=-1;
    _pathImageMet=QString();
    _exeSubScene=QString();
    _exeImaOpeGeo=QString();
    _exeFootPrintMask=QString();
    _exeExtraction=QString();
    _exeResize=QString();
    _utmDefecto=QString();
    _listaEjecutables=QJsonArray();

}

RegistroCreateMet::RegistroCreateMet(QObject *parent,QString folderOut,QString ambitoProyecto,int tamanyoPixel,
                                     int utm,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada,
                                     QString pathImageMet,QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask,
                                     QString exeExtraction, QString exeResize, QString utmDefecto, QJsonArray listaEjecutables):QObject(parent)
{
    _folderOut= folderOut;
    _ambitoProyecto= ambitoProyecto;
    _tamanyoPixel= tamanyoPixel;
    _utm= utm;
    _tamanyoCorte= tamanyoCorte;
    _numeroCanales= numeroCanales;
    _anchoPasada= anchoPasada;
    _offsetPasada= offsetPasada;
    _dtm=false;
    _fprintM=false;
    _pathImageMet= pathImageMet;
    _exeSubScene=exeSubScene;
    _exeFootPrintMask=exeFootPrintMask;
    _utmDefecto=utmDefecto;
    _listaEjecutables=listaEjecutables;
}


//Getter

QString RegistroCreateMet::getFolderOut()
{
    return _folderOut;
}
QString RegistroCreateMet::getAmbitoProyecto()
{
    return _ambitoProyecto;
}
int RegistroCreateMet::getTamanyPixel()
{
    return _tamanyoPixel;
}
int RegistroCreateMet::getUtm()
{
    return _utm;
}
int RegistroCreateMet::getTamanyoCorte()
{
    return _tamanyoCorte;
}
int RegistroCreateMet::getNumeroCanales()
{
    return _numeroCanales;
}
int RegistroCreateMet::getAnchoPasada()
{
    return _anchoPasada;
}
int RegistroCreateMet::getOffsetPasada()
{
    return _offsetPasada;
}
bool RegistroCreateMet::getCutDtm()
{
    return _dtm;
}
bool RegistroCreateMet::getFootPrintMask()
{
    return _fprintM;
}
QString RegistroCreateMet::getPathImageMet()
{
    return _pathImageMet;
}
QString RegistroCreateMet::getExeSubScene()
{
    return _exeSubScene;
}
QString RegistroCreateMet::getExeImaOpeGeo()
{
    return _exeImaOpeGeo;
}

QString RegistroCreateMet::getExeFootPrintMask()
{
    return _exeFootPrintMask;
}
QString RegistroCreateMet::getExeExtraction()
{
    return _exeExtraction;
}
QString RegistroCreateMet::getExeResize()
{
    return _exeResize;
}
QString RegistroCreateMet::getUtmDefecto()
{
    return _utmDefecto;
}
QJsonArray RegistroCreateMet::getListaEjecutables()
{
    return _listaEjecutables;
}

//setters
void RegistroCreateMet::setFolderOut(QString folderOut)
{
    _folderOut=folderOut;
    qDebug()<< _folderOut << "_folderOut------------------------------";
}
void RegistroCreateMet::setAmbitoProyecto(QString ambitoProyecto)
{
    _ambitoProyecto=ambitoProyecto;
    qDebug()<< _ambitoProyecto << "_ambitoProyecto------------------------------";
}
void RegistroCreateMet::setTamanyPixel(int tamanyoPixel)
{
    _tamanyoPixel=tamanyoPixel;
    qDebug()<< _tamanyoPixel << "_tamanyoPixel------------------------------";
}
void RegistroCreateMet::setUtm(int utm)
{
    _utm=utm;
    qDebug()<< _utm << "_utm------------------------------";
}
void RegistroCreateMet::setTamanyoCorte(int tamanyoCorte)
{
    _tamanyoCorte=tamanyoCorte;
    qDebug()<< _tamanyoCorte << "_tamanyoCorte------------------------------";
}
void RegistroCreateMet::setNumeroCanales(int numeroCanales)
{
    _numeroCanales=numeroCanales;
    qDebug()<< _numeroCanales << "_numeroCanales------------------------------";
}
void RegistroCreateMet::setAnchoPasada(int anchoPasada)
{
    _anchoPasada=anchoPasada;
    qDebug()<< _anchoPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateMet::setOffsetPasada(int offsetPasada)
{
    _offsetPasada=offsetPasada;
    qDebug()<< _offsetPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateMet::setPathImageMet(QString pathImageMet)
{
    _pathImageMet=pathImageMet;
    qDebug()<< _ambitoProyecto << "_pathImageMet------------------------------";
}
void RegistroCreateMet::setExeSubScene(QString exeSubScene)
{
    _exeSubScene=exeSubScene;
    qDebug()<< _exeSubScene << "_exeSubScene------------------------------";
}
void RegistroCreateMet::setExeImaOpeGeo(QString exeImaOpeGeo)
{
    _exeImaOpeGeo=exeImaOpeGeo;
    qDebug()<< _exeImaOpeGeo << "_exeImaOpeGeo------------------------------";
}

void RegistroCreateMet::setExeFootPrintMask(QString exeFootPrintMask)
{
    _exeFootPrintMask=exeFootPrintMask;
    qDebug()<< _exeFootPrintMask << "_exeFootPrintMask------------------------------";
}
void RegistroCreateMet::setExeExtraction(QString exeExtraction)
{
    _exeExtraction=exeExtraction;
    qDebug()<< _exeExtraction << "_exeExtraction------------------------------";
}
void RegistroCreateMet::setExeResize(QString exeResize)
{
    _exeResize=exeResize;
    qDebug()<< _exeResize << "_exeResize------------------------------";
}
void RegistroCreateMet::setUtmDefecto(QString utmDefecto)
{
    _utmDefecto=utmDefecto;
    qDebug()<< _utmDefecto << "_utmDefecto------------------------------";
}
void RegistroCreateMet::setListaEjecutables(QJsonArray listaEjecutables)
{
    _listaEjecutables=listaEjecutables;
}


void RegistroCreateMet::setCutDtm(int dtm)
{
    if(dtm==2)
        _dtm=true;
    else
        _dtm=false;
}
void RegistroCreateMet::setFootprintMask(int fprintM)
{

    if(fprintM==2)
        _fprintM=true;
    else
        _fprintM=false;
}

void RegistroCreateMet::buildDataZoneProject(DataZoneProject *dataZP)
{
    if (_ambitoProyecto=="Catalunya")
    {
        dataZP->setAmbitoOperacion(DataZoneProject::Catalunya);
    }
    else if(_ambitoProyecto=="Francia")
    {
        dataZP->setAmbitoOperacion(DataZoneProject::Francia);
    }
    else
    {
        dataZP->setAmbitoOperacion(DataZoneProject::Espanya);
    }
    dataZP->setAnchoPasada(_anchoPasada);
    dataZP->setCutDtm(_dtm);
    dataZP->setFolderOut(_folderOut);
    dataZP->setFootPrintMask(_fprintM);
    dataZP->setImageProject(_pathImageMet);
    dataZP->setNumberCanals(_numeroCanales);
    dataZP->setOffsetPasada(_offsetPasada);
    dataZP->setSizeCut(_tamanyoCorte);
    dataZP->setSizePixel(_tamanyoPixel);
    dataZP->setUtm(_utm);
}




