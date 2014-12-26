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
#include "registromet.h"

RegistroMet::RegistroMet(QObject *parent) :
    QObject(parent)
{
    _folderOut=QString();
    //tengo que pasar el Qstring a un valor enum
    _ambitoOperacion=DataZoneProject::Otro;
    _tamanyoPixel=-1;
    //tengo que pasar el Qstring a un valor enum
    _coordinateSystem=DataZoneProject::vacio;
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
    _listaEjecutables=QJsonArray();
    _selectSensor=DataZoneProject::Vacio;

}

RegistroMet::RegistroMet(QObject *parent,QString folderOut,DataZoneProject::Ambito ambitoOperacion,double tamanyoPixel,
                                     DataZoneProject::sistemaCoor coordinateSystem,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada,
                                     QString pathImageMet,QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask,
                                     QString exeExtraction, QString exeResize, QJsonArray listaEjecutables,
                                     DataZoneProject::Sensor selectSensor):QObject(parent)
{
    _folderOut= folderOut;
    _ambitoOperacion= ambitoOperacion;
    _tamanyoPixel= tamanyoPixel;
    _coordinateSystem=coordinateSystem;
    _tamanyoCorte= tamanyoCorte;
    _numeroCanales= numeroCanales;
    _anchoPasada= anchoPasada;
    _offsetPasada= offsetPasada;
    _dtm=false;
    _fprintM=false;
    _pathImageMet= pathImageMet;
    _exeSubScene=exeSubScene;
    _exeFootPrintMask=exeFootPrintMask;
    _listaEjecutables=listaEjecutables;
    _selectSensor=selectSensor;
}


//Getter

QString RegistroMet::getFolderOut()
{
    return _folderOut;
}
DataZoneProject::Ambito RegistroMet::getAmbitoOperacion()
{
 return _ambitoOperacion;
}
DataZoneProject::Sensor RegistroMet::getSelectSensor()
{
 return _selectSensor;
}

double RegistroMet::getTamanyPixel()
{
    return _tamanyoPixel;
}
DataZoneProject::sistemaCoor RegistroMet::getCoordinateSystem()
{
    return _coordinateSystem;
}
int RegistroMet::getTamanyoCorte()
{
    return _tamanyoCorte;
}
int RegistroMet::getNumeroCanales()
{
    return _numeroCanales;
}
int RegistroMet::getAnchoPasada()
{
    return _anchoPasada;
    qDebug()<< _anchoPasada << "_anchoPasada;";
}
int RegistroMet::getOffsetPasada()
{
    return _offsetPasada;
}
bool RegistroMet::getCutDtm()
{
    return _dtm;
}
bool RegistroMet::getFootPrintMask()
{
    return _fprintM;
}
QString RegistroMet::getPathImageMet()
{
    return _pathImageMet;
}
QString RegistroMet::getExeSubScene()
{
    return _exeSubScene;
}
QString RegistroMet::getExeImaOpeGeo()
{
    return _exeImaOpeGeo;
}

QString RegistroMet::getExeFootPrintMask()
{
    return _exeFootPrintMask;
}
QString RegistroMet::getExeExtraction()
{
    return _exeExtraction;
}
QString RegistroMet::getExeResize()
{
    return _exeResize;
}
QJsonArray RegistroMet::getListaEjecutables()
{
    return _listaEjecutables;
}

//setters
void RegistroMet::setFolderOut(QString folderOut)
{
    _folderOut=folderOut;
    qDebug()<< _folderOut << "_folderOut------------------------------";
}
void RegistroMet::setAmbitoOperacion(DataZoneProject::Ambito ambitoOperacion)
{
 _ambitoOperacion=ambitoOperacion;
    qDebug()<< _ambitoOperacion << "_ambitoOperacion------------------------------";
}
void RegistroMet::setSelectSensor(DataZoneProject::Sensor selectSensor)
{
 _selectSensor=selectSensor;
    qDebug()<< _selectSensor << "_selectSensor------------------------------";
}
void RegistroMet::setTamanyPixel(double tamanyoPixel)
{
    _tamanyoPixel=tamanyoPixel;
    qDebug()<< _tamanyoPixel << "_tamanyoPixel------------------------------";
}
void RegistroMet::setCoordinateSystem(DataZoneProject::sistemaCoor coordinateSystem)
{
    _coordinateSystem=coordinateSystem;
}
void RegistroMet::setTamanyoCorte(int tamanyoCorte)
{
    _tamanyoCorte=tamanyoCorte;
    qDebug()<< _tamanyoCorte << "_tamanyoCorte------------------------------";
}
void RegistroMet::setNumeroCanales(int numeroCanales)
{
    _numeroCanales=numeroCanales;
    qDebug()<< _numeroCanales << "_numeroCanales------------------------------";
}
void RegistroMet::setAnchoPasada(int anchoPasada)
{
    _anchoPasada=anchoPasada;
    qDebug()<< _anchoPasada << "_ambitoProyecto------------------------------";
}
void RegistroMet::setOffsetPasada(int offsetPasada)
{
    _offsetPasada=offsetPasada;
    qDebug()<< _offsetPasada << "_ambitoProyecto------------------------------";
}
void RegistroMet::setPathImageMet(QString pathImageMet)
{
    _pathImageMet=pathImageMet;
    qDebug()<< _pathImageMet << "_pathImageMet------------------------------";
}
void RegistroMet::setExeSubScene(QString exeSubScene)
{
    _exeSubScene=exeSubScene;
    qDebug()<< _exeSubScene << "_exeSubScene------------------------------";
}
void RegistroMet::setExeImaOpeGeo(QString exeImaOpeGeo)
{
    _exeImaOpeGeo=exeImaOpeGeo;
    qDebug()<< _exeImaOpeGeo << "_exeImaOpeGeo------------------------------";
}

void RegistroMet::setExeFootPrintMask(QString exeFootPrintMask)
{
    _exeFootPrintMask=exeFootPrintMask;
    qDebug()<< _exeFootPrintMask << "_exeFootPrintMask------------------------------";
}
void RegistroMet::setExeExtraction(QString exeExtraction)
{
    _exeExtraction=exeExtraction;
    qDebug()<< _exeExtraction << "_exeExtraction------------------------------";
}
void RegistroMet::setExeResize(QString exeResize)
{
    _exeResize=exeResize;
    qDebug()<< _exeResize << "_exeResize------------------------------";
}
void RegistroMet::setListaEjecutables(QJsonArray listaEjecutables)
{
    _listaEjecutables=listaEjecutables;
}


void RegistroMet::setCutDtm(int dtm)
{
    if(dtm==2)
        _dtm=true;
    else
        _dtm=false;
}
void RegistroMet::setFootprintMask(int fprintM)
{

    if(fprintM==2)
        _fprintM=true;
    else
        _fprintM=false;
}

void RegistroMet::buildDataZoneProject(DataZoneProject *dataZP)
{
    dataZP->setAmbitoOperacion(_ambitoOperacion);
    dataZP->setAnchoPasada(_anchoPasada);
    dataZP->setCutDtm(_dtm);
    dataZP->setFolderOut(_folderOut);
    dataZP->setFootPrintMask(_fprintM);
    dataZP->setImageProject(_pathImageMet);
    dataZP->setNumberCanals(_numeroCanales);
    dataZP->setOffsetPasada(_offsetPasada);
    dataZP->setSizeCut(_tamanyoCorte);
    dataZP->setSizePixel(_tamanyoPixel);
    dataZP->setCoordinateSystem(_coordinateSystem);
    dataZP->setSelectSensor(_selectSensor);
}

QMap<QString, QString> RegistroMet::getMapExe()
{
    qDebug()<< _listaEjecutables <<"_listaEjecutables";
 QMap<QString, QString> qMapExe;
 foreach (QJsonValue qJson, _listaEjecutables)
 {
     QString nombre=qJson.toObject().value("Nombre").toString();
     QString valor=qJson.toObject().value("Path").toString();
     qDebug()<< nombre<<"nombre_listaEjecutables";
     qDebug()<< valor <<"valor_listaEjecutables";
     qMapExe.insert(nombre,valor);
 }
 return qMapExe;
}


