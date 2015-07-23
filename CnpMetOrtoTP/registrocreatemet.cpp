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
#include "createmet.h"

RegistroCreateMet::RegistroCreateMet(QObject *parent) :
    AProTPSection(parent)
{
    _folderOut=QString();
    _widgetMet=0;
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
    _utmDefecto=QString();
    _listaEjecutables=QJsonArray();
    _selectSensor=DataZoneProject::Vacio;

}

RegistroCreateMet::RegistroCreateMet(QObject *parent,QString folderOut,DataZoneProject::Ambito ambitoOperacion,double tamanyoPixel,
                                     DataZoneProject::sistemaCoor coordinateSystem,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada,
                                     QString pathImageMet,QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask,
                                     QString exeExtraction, QString exeResize, QString utmDefecto, QJsonArray listaEjecutables,
                                     DataZoneProject::Sensor selectSensor):AProTPSection(parent)
{
    _folderOut= folderOut;
    _widgetMet=0;
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
    _utmDefecto=utmDefecto;
    _listaEjecutables=listaEjecutables;
    _selectSensor=selectSensor;
}

void RegistroCreateMet::setWidget(CreateMet *widget)
{
    _widgetMet=widget;
}
//Getter

QString RegistroCreateMet::getFolderOut()
{
    return _folderOut;
}
bool RegistroCreateMet::getMetEnabled() const
{
    return _metEnabled;
}
DataZoneProject::Ambito RegistroCreateMet::getAmbitoOperacion()
{
 return _ambitoOperacion;
}
DataZoneProject::Sensor RegistroCreateMet::getSelectSensor()
{
 return _selectSensor;
}

double RegistroCreateMet::getTamanyPixel()
{
    return _tamanyoPixel;
}
DataZoneProject::sistemaCoor RegistroCreateMet::getCoordinateSystem()
{
    return _coordinateSystem;
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
    qDebug()<< _anchoPasada << "_anchoPasada;";
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
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _folderOut << "_folderOut------------------------------";
}
void RegistroCreateMet::setMetEnabled(bool enabled)
{
    _metEnabled=enabled;
    AProTPSection::_stateChanged=false;
    emit estaActualizado(_stateChanged);
}
void RegistroCreateMet::setAmbitoOperacion(DataZoneProject::Ambito ambitoOperacion)
{
 _ambitoOperacion=ambitoOperacion;
 AProTPSection::_stateChanged=false;
 emit this->estaActualizado(_stateChanged);
    qDebug()<< _ambitoOperacion << "_ambitoOperacion------------------------------";
}
void RegistroCreateMet::setSelectSensor(DataZoneProject::Sensor selectSensor)
{
 _selectSensor=selectSensor;
 AProTPSection::_stateChanged=false;
 emit this->estaActualizado(_stateChanged);
    qDebug()<< _selectSensor << "_selectSensor------------------------------";
}
void RegistroCreateMet::setTamanyPixel(double tamanyoPixel)
{
    _tamanyoPixel=tamanyoPixel;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _tamanyoPixel << "_tamanyoPixel------------------------------";
}
void RegistroCreateMet::setCoordinateSystem(DataZoneProject::sistemaCoor coordinateSystem)
{
    _coordinateSystem=coordinateSystem;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
}
void RegistroCreateMet::setTamanyoCorte(int tamanyoCorte)
{
    _tamanyoCorte=tamanyoCorte;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _tamanyoCorte << "_tamanyoCorte------------------------------";
}
void RegistroCreateMet::setNumeroCanales(int numeroCanales)
{
    _numeroCanales=numeroCanales;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _numeroCanales << "_numeroCanales------------------------------";
}
void RegistroCreateMet::setAnchoPasada(int anchoPasada)
{
    _anchoPasada=anchoPasada;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _anchoPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateMet::setOffsetPasada(int offsetPasada)
{
    _offsetPasada=offsetPasada;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _offsetPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateMet::setPathImageMet(QString pathImageMet)
{
    _pathImageMet=pathImageMet;
    qDebug()<< _pathImageMet << "_pathImageMet------------------------------";
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

QMap<QString, QString> RegistroCreateMet::getMapExe()
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

QString RegistroCreateMet::getNombreSection() const
{
    return QString("sectionMET");
}

QJsonObject RegistroCreateMet::writeSection()
{
    QJsonObject resultado;
    resultado.insert("folderOut",this->_folderOut);   
    resultado.insert("metEnabled",_metEnabled);
    resultado.insert("tamanyoPixel",_tamanyoPixel);
    resultado.insert("dtm",_dtm);
    resultado.insert("tamanyoCorte",_tamanyoCorte);
    resultado.insert("numeroCanales",_numeroCanales);
    resultado.insert("fprintM",_fprintM);
    resultado.insert("offsetPasada",_offsetPasada);
    switch (_coordinateSystem) {
    case DataZoneProject::Etrs89:
        resultado.insert("coordinateSystem","Etrs89");
        break;
    case DataZoneProject::Ed50:
        resultado.insert("coordinateSystem","Ed50");
        break;
    case DataZoneProject::Ntf:
        resultado.insert("coordinateSystem","Ntf");
        break;
        default:
        resultado.insert("coordinateSystem","vacio");
        break;
    }
    switch (_ambitoOperacion) {
    case DataZoneProject::Catalunya:
        resultado.insert("ambitoOperacion","Catalunya");
        break;
    case DataZoneProject::Espanya:
        resultado.insert("ambitoOperacion","Espanya");
        break;
    case DataZoneProject::Francia:
        resultado.insert("ambitoOperacion","Francia");
        break;
    default:
         resultado.insert("ambitoOperacion","Otro");
        break;
    }
    switch (_selectSensor) {
    case DataZoneProject::Casi:
        resultado.insert("selectSensor","Casi");
        break;
    case DataZoneProject::Tasi:
        resultado.insert("selectSensor","Tasi");
        break;
    case DataZoneProject::Aisa:
        resultado.insert("selectSensor","Aisa");
        break;
    case DataZoneProject::Aisa_BE:
        resultado.insert("selectSensor","Aisa_BE");
        break;
    default:
         resultado.insert("selectSensor","Vacio");
        break;
    }
    resultado.insert("anchoPasada",_anchoPasada);
    resultado.insert("pathImageMet",_pathImageMet);
    resultado.insert("utmDefecto",_utmDefecto);
    AProTPSection::_stateChanged=true;
    emit this->estaActualizado(_stateChanged);
    return resultado;
}

bool RegistroCreateMet::processSection(QJsonObject archivo)
{
    _widgetMet->disconnectRegistro();
    if(!archivo.contains("sectionMET"))
        return false;

    QJsonObject section=archivo.value("sectionMET").toObject();
    _folderOut=section.value("folderOut").toString();
    _metEnabled=section.value("metEnabled").toBool();
    _tamanyoPixel=section.value("tamanyoPixel").toDouble();
    _dtm=section.value("dtm").toBool();
    _numeroCanales=section.value("numeroCanales").toInt();
    _tamanyoCorte=section.value("tamanyoCorte").toInt();
    _fprintM=section.value("fprintM").toBool();
    _offsetPasada=section.value("offsetPasada").toInt();
    _anchoPasada=section.value("anchoPasada").toInt();
    _pathImageMet=section.value("pathImageMet").toString();
    _utmDefecto=section.value("utmDefecto").toString();

    QString coordinateSystem=section.value("coordinateSystem").toString();
    if (coordinateSystem=="Etrs89")
    {
      _coordinateSystem=DataZoneProject::Etrs89;
    }
    else if(coordinateSystem=="Ed50")
    {
      _coordinateSystem=DataZoneProject::Ed50;
    }
    else if(coordinateSystem=="Ntf")
    {
      _coordinateSystem=DataZoneProject::Ntf;
    }
    else
       _coordinateSystem=DataZoneProject::vacio;

    QString ambitoOperacion=section.value("ambitoOperacion").toString();

    if (ambitoOperacion=="Catalunya")
    {
      _ambitoOperacion=DataZoneProject::Catalunya;
    }
    else if(ambitoOperacion=="Espanya")
    {
      _ambitoOperacion=DataZoneProject::Espanya;
    }
    else if(ambitoOperacion=="Francia")
    {
      _ambitoOperacion=DataZoneProject::Francia;
    }
    else
       _ambitoOperacion=DataZoneProject::Otro;

   QString selectSensor=section.value("selectSensor").toString();
   if (selectSensor=="Casi")
   {
     _selectSensor=DataZoneProject::Casi;
   }
   else if(selectSensor=="Tasi")
   {
     _selectSensor=DataZoneProject::Tasi;
   }
   else if(selectSensor=="Aisa")
   {
     _selectSensor=DataZoneProject::Aisa;
   }
   else if(selectSensor=="Aisa_BE")
   {
     _selectSensor=DataZoneProject::Aisa_BE;
   }
   else
      _selectSensor=DataZoneProject::Vacio;
    _stateChanged=true;
    emit estaActualizado(_stateChanged);
    _widgetMet->connectRegistro();
    return true;
}

void RegistroCreateMet::resetSection()
{
    _widgetMet->disconnectRegistro();
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
    _utmDefecto=QString();
    _selectSensor=DataZoneProject::Vacio;
    _stateChanged=true;    
    emit estaActualizado(_stateChanged);
    _widgetMet->connectRegistro();
}








































