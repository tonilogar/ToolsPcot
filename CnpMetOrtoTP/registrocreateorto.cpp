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
#include "registrocreateorto.h"

RegistroCreateOrto::RegistroCreateOrto(QObject *parent) :
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
    _pathImageOrto=QString();
    _exeSubScene=QString();
    _exeImaOpeGeo=QString();
    _exeFootPrintMask=QString();
    _exeExtraction=QString();
    _exeResize=QString();
    _utmDefecto=QString();
    _listaEjecutables=QJsonArray();
    _selectSensor=DataZoneProject::Vacio;

}

RegistroCreateOrto::RegistroCreateOrto(QObject *parent,QString folderOut,DataZoneProject::Ambito ambitoOperacion,double tamanyoPixel,
                                     DataZoneProject::sistemaCoor coordinateSystem,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada,
                                     QString pathImageOrto,QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask,
                                     QString exeExtraction, QString exeResize, QString utmDefecto, QJsonArray listaEjecutables,
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
    _pathImageOrto= pathImageOrto;
    _exeSubScene=exeSubScene;
    _exeFootPrintMask=exeFootPrintMask;
    _utmDefecto=utmDefecto;
    _listaEjecutables=listaEjecutables;
    _selectSensor=selectSensor;
}


//Getter

QString RegistroCreateOrto::getFolderOut()
{
    return _folderOut;
}
DataZoneProject::Ambito RegistroCreateOrto::getAmbitoOperacion()
{
 return _ambitoOperacion;
}
DataZoneProject::Sensor RegistroCreateOrto::getSelectSensor()
{
 return _selectSensor;
}

double RegistroCreateOrto::getTamanyPixel()
{
    return _tamanyoPixel;
}
DataZoneProject::sistemaCoor RegistroCreateOrto::getCoordinateSystem()
{
    return _coordinateSystem;
}
int RegistroCreateOrto::getTamanyoCorte()
{
    return _tamanyoCorte;
}
int RegistroCreateOrto::getNumeroCanales()
{
    return _numeroCanales;
}
int RegistroCreateOrto::getAnchoPasada()
{
    return _anchoPasada;
    qDebug()<< _anchoPasada << "_anchoPasada;";
}
int RegistroCreateOrto::getOffsetPasada()
{
    return _offsetPasada;
}
bool RegistroCreateOrto::getCutDtm()
{
    return _dtm;
}
bool RegistroCreateOrto::getFootPrintMask()
{
    return _fprintM;
}
QString RegistroCreateOrto::getPathImageOrto()
{
    return _pathImageOrto;
}
QString RegistroCreateOrto::getExeSubScene()
{
    return _exeSubScene;
}
QString RegistroCreateOrto::getExeImaOpeGeo()
{
    return _exeImaOpeGeo;
}

QString RegistroCreateOrto::getExeFootPrintMask()
{
    return _exeFootPrintMask;
}
QString RegistroCreateOrto::getExeExtraction()
{
    return _exeExtraction;
}
QString RegistroCreateOrto::getExeResize()
{
    return _exeResize;
}
QString RegistroCreateOrto::getUtmDefecto()
{
    return _utmDefecto;
}
QJsonArray RegistroCreateOrto::getListaEjecutables()
{
    return _listaEjecutables;
}

//setters
void RegistroCreateOrto::setFolderOut(QString folderOut)
{
    _folderOut=folderOut;
    qDebug()<< _folderOut << "_folderOut------------------------------";
}
void RegistroCreateOrto::setAmbitoOperacion(DataZoneProject::Ambito ambitoOperacion)
{
 _ambitoOperacion=ambitoOperacion;
    qDebug()<< _ambitoOperacion << "_ambitoOperacion------------------------------";
}
void RegistroCreateOrto::setSelectSensor(DataZoneProject::Sensor selectSensor)
{
 _selectSensor=selectSensor;
    qDebug()<< _selectSensor << "_selectSensor------------------------------";
}
void RegistroCreateOrto::setTamanyPixel(double tamanyoPixel)
{
    _tamanyoPixel=tamanyoPixel;
    qDebug()<< _tamanyoPixel << "_tamanyoPixel------------------------------";
}
void RegistroCreateOrto::setCoordinateSystem(DataZoneProject::sistemaCoor coordinateSystem)
{
    _coordinateSystem=coordinateSystem;
}
void RegistroCreateOrto::setTamanyoCorte(int tamanyoCorte)
{
    _tamanyoCorte=tamanyoCorte;
    qDebug()<< _tamanyoCorte << "_tamanyoCorte------------------------------";
}
void RegistroCreateOrto::setNumeroCanales(int numeroCanales)
{
    _numeroCanales=numeroCanales;
    qDebug()<< _numeroCanales << "_numeroCanales------------------------------";
}
void RegistroCreateOrto::setAnchoPasada(int anchoPasada)
{
    _anchoPasada=anchoPasada;
    qDebug()<< _anchoPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateOrto::setOffsetPasada(int offsetPasada)
{
    _offsetPasada=offsetPasada;
    qDebug()<< _offsetPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateOrto::setPathImageOrto(QString pathImageOrto)
{
    _pathImageOrto=pathImageOrto;
    qDebug()<< _pathImageOrto << "_pathImageOrto------------------------------";
}
void RegistroCreateOrto::setExeSubScene(QString exeSubScene)
{
    _exeSubScene=exeSubScene;
    qDebug()<< _exeSubScene << "_exeSubScene------------------------------";
}
void RegistroCreateOrto::setExeImaOpeGeo(QString exeImaOpeGeo)
{
    _exeImaOpeGeo=exeImaOpeGeo;
    qDebug()<< _exeImaOpeGeo << "_exeImaOpeGeo------------------------------";
}

void RegistroCreateOrto::setExeFootPrintMask(QString exeFootPrintMask)
{
    _exeFootPrintMask=exeFootPrintMask;
    qDebug()<< _exeFootPrintMask << "_exeFootPrintMask------------------------------";
}
void RegistroCreateOrto::setExeExtraction(QString exeExtraction)
{
    _exeExtraction=exeExtraction;
    qDebug()<< _exeExtraction << "_exeExtraction------------------------------";
}
void RegistroCreateOrto::setExeResize(QString exeResize)
{
    _exeResize=exeResize;
    qDebug()<< _exeResize << "_exeResize------------------------------";
}
void RegistroCreateOrto::setUtmDefecto(QString utmDefecto)
{
    _utmDefecto=utmDefecto;
    qDebug()<< _utmDefecto << "_utmDefecto------------------------------";
}
void RegistroCreateOrto::setListaEjecutables(QJsonArray listaEjecutables)
{
    _listaEjecutables=listaEjecutables;
}


void RegistroCreateOrto::setCutDtm(int dtm)
{
    if(dtm==2)
        _dtm=true;
    else
        _dtm=false;
}
void RegistroCreateOrto::setFootprintMask(int fprintM)
{

    if(fprintM==2)
        _fprintM=true;
    else
        _fprintM=false;
}

void RegistroCreateOrto::buildDataZoneProject(DataZoneProject *dataZP)
{
    dataZP->setAmbitoOperacion(_ambitoOperacion);
    dataZP->setAnchoPasada(_anchoPasada);
    dataZP->setCutDtm(_dtm);
    dataZP->setFolderOut(_folderOut);
    dataZP->setFootPrintMask(_fprintM);
    dataZP->setImageProject(_pathImageOrto);
    dataZP->setNumberCanals(_numeroCanales);
    dataZP->setOffsetPasada(_offsetPasada);
    dataZP->setSizeCut(_tamanyoCorte);
    dataZP->setSizePixel(_tamanyoPixel);
    dataZP->setCoordinateSystem(_coordinateSystem);
    dataZP->setSelectSensor(_selectSensor);
}

QMap<QString, QString> RegistroCreateOrto::getMapExe()
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


