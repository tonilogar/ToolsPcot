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
#include "createorto.h"

RegistroCreateOrto::RegistroCreateOrto(QObject *parent) :
    AProTPSection(parent)
{
    _folderOut=QString();
     _widgetOrto=0;
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
                                     DataZoneProject::Sensor selectSensor):AProTPSection(parent)
{
    _folderOut= folderOut;
    _widgetOrto=0;
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

void RegistroCreateOrto::setWidget(CreateOrto *widget)
{
    _widgetOrto=widget;
}
//Getter

QString RegistroCreateOrto::getFolderOut()
{
    return _folderOut;
}
bool RegistroCreateOrto::getOrtoEnabled() const
{
    return _ortoEnabled;
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
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _folderOut << "_folderOut------------------------------";
}
void RegistroCreateOrto::setOrtoEnabled(bool enabled)
{
    _ortoEnabled=enabled;
    AProTPSection::_stateChanged=false;
    emit estaActualizado(_stateChanged);
}
void RegistroCreateOrto::setAmbitoOperacion(DataZoneProject::Ambito ambitoOperacion)
{
    _ambitoOperacion=ambitoOperacion;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
       qDebug()<< _ambitoOperacion << "_ambitoOperacion------------------------------";
}
void RegistroCreateOrto::setSelectSensor(DataZoneProject::Sensor selectSensor)
{
    _selectSensor=selectSensor;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
       qDebug()<< _selectSensor << "_selectSensor------------------------------";
}
void RegistroCreateOrto::setTamanyPixel(double tamanyoPixel)
{
    _tamanyoPixel=tamanyoPixel;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _tamanyoPixel << "_tamanyoPixel------------------------------";
}
void RegistroCreateOrto::setCoordinateSystem(DataZoneProject::sistemaCoor coordinateSystem)
{
    _coordinateSystem=coordinateSystem;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
}
void RegistroCreateOrto::setTamanyoCorte(int tamanyoCorte)
{
    _tamanyoCorte=tamanyoCorte;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _tamanyoCorte << "_tamanyoCorte------------------------------";
}
void RegistroCreateOrto::setNumeroCanales(int numeroCanales)
{
    _numeroCanales=numeroCanales;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _numeroCanales << "_numeroCanales------------------------------";
}
void RegistroCreateOrto::setAnchoPasada(int anchoPasada)
{
    _anchoPasada=anchoPasada;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _anchoPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateOrto::setOffsetPasada(int offsetPasada)
{
    _offsetPasada=offsetPasada;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    qDebug()<< _offsetPasada << "_ambitoProyecto------------------------------";
}
void RegistroCreateOrto::setPathImageOrto(QString pathImageOrto)
{
    _pathImageOrto=pathImageOrto;
    qDebug()<< _pathImageOrto << "_pathImagOrto------------------------------";
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

QString RegistroCreateOrto::getNombreSection() const
{
    return QString("sectionOrto");
}

QJsonObject RegistroCreateOrto::writeSection()
{
    QJsonObject resultado;
    resultado.insert("folderOut",this->_folderOut);
    resultado.insert("ortoEnabled",_ortoEnabled);
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
    resultado.insert("pathImageOrto",_pathImageOrto);
    resultado.insert("utmDefecto",_utmDefecto);
    AProTPSection::_stateChanged=true;
    emit this->estaActualizado(_stateChanged);
    return resultado;
}

bool RegistroCreateOrto::processSection(QJsonObject archivo)
{
    _widgetOrto->disconnectRegistro();
    if(!archivo.contains("sectionOrto"))
        return false;

    QJsonObject section=archivo.value("sectionOrto").toObject();
    _folderOut=section.value("folderOut").toString();
    _ortoEnabled=section.value("ortoEnabled").toBool();
    _tamanyoPixel=section.value("tamanyoPixel").toDouble();
    _dtm=section.value("dtm").toBool();
    _numeroCanales=section.value("numeroCanales").toInt();
    _tamanyoCorte=section.value("tamanyoCorte").toInt();
    _fprintM=section.value("fprintM").toBool();
    _offsetPasada=section.value("offsetPasada").toInt();
    _anchoPasada=section.value("anchoPasada").toInt();
    _pathImageOrto=section.value("pathImageOrto").toString();
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
    _widgetOrto->connectRegistro();
    return true;
}

void RegistroCreateOrto::resetSection()
{
    _widgetOrto->disconnectRegistro();
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
    _widgetOrto->connectRegistro();
}
