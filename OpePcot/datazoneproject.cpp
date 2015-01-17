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
#include "datazoneproject.h"

DataZoneProject::DataZoneProject(QObject *parent) :
    QObject(parent)
{
    _zoneProject=QString();
    _imageProject=QString();
    _sizePixel=0;
    _cutDtm=false;
    _sizeCut=0;
    _numberCanals=0;
    _footPrintMask=false;
    _anchoPasada=0;
    _offsetPasada=0;
    _folderOut=QString();
    _numberCuts=0;
    _ambitoOperacion=Otro;
    _coordinateSystem=vacio;
    _selectSensor=Vacio;
}
DataZoneProject::DataZoneProject(QObject *parent,QString zoneProject, QString imageProject, double sizePixel, sistemaCoor coordinateSystem, bool cutDtm,
                                 int sizeCut, int numberCanals, bool footPrintMask, int anchoPasada, int offsetPasada, QString folderOut, Ambito ambitoOperacion, Sensor selectSensor)
{
    _zoneProject=zoneProject;
    _imageProject=imageProject;
    _sizePixel=sizePixel;
    _coordinateSystem=coordinateSystem;
    _cutDtm=cutDtm;
    _sizeCut=sizeCut;
    _numberCanals=numberCanals;
    _footPrintMask=footPrintMask;
    _anchoPasada=anchoPasada;
    _offsetPasada=offsetPasada;
    _folderOut=folderOut;
    _ambitoOperacion=ambitoOperacion;
    _selectSensor=selectSensor;

}



//Getter
DataZoneProject::Ambito DataZoneProject::getAmbitoOperacion()
{
 return _ambitoOperacion;
}
DataZoneProject::Sensor DataZoneProject::getSelectSensor()
{
  return _selectSensor;
}

QString DataZoneProject::getZoneProject()
{
    return _zoneProject;
}
QString DataZoneProject::getImageProject()
{
    return _imageProject;
}

double DataZoneProject::getSizePixel()
{
    return _sizePixel;
}
DataZoneProject::sistemaCoor DataZoneProject::getCoordinateSystem()
{
    return _coordinateSystem;
}
bool DataZoneProject::getCutDtm()
{
    return _cutDtm;
}
int DataZoneProject::getSizeCut()
{
    return _sizeCut;
}
int DataZoneProject::getNumberCanals()
{
    return _numberCanals;
}
bool DataZoneProject::getFootPrintMask()
{
    return _footPrintMask;
}
int DataZoneProject::getAnchoPasada()
{
    return _anchoPasada;
}
int DataZoneProject::getOffsetPasada()
{
    return _offsetPasada;
}
QString DataZoneProject::getFolderOut()
{
    return _folderOut;
}



//Setter

void DataZoneProject::setAmbitoOperacion(Ambito ambitoOperacion)
{
 _ambitoOperacion=ambitoOperacion;
}
void DataZoneProject::setSelectSensor(Sensor selectSensor)
{
 _selectSensor=selectSensor;
}

void DataZoneProject::setZoneProject(QString zoneProject)
{
    _zoneProject=zoneProject;
}
void DataZoneProject::setImageProject(QString imageProject)
{
    _imageProject=imageProject;
}
void DataZoneProject::setSizePixel(double sizePixel)
{
    _sizePixel=sizePixel;
}
void DataZoneProject::setCoordinateSystem(sistemaCoor coordinateSystem)
{
    _coordinateSystem=coordinateSystem;
}
void DataZoneProject::setCutDtm(bool cutDtm)
{
    _cutDtm=cutDtm;
}
void DataZoneProject::setSizeCut(int sizeCut)
{
    _sizeCut=sizeCut;
}
void DataZoneProject::setNumberCanals(int numberCanals)
{
    _numberCanals=numberCanals;
}
void DataZoneProject::setFootPrintMask(bool footPrintMask)
{
    _footPrintMask=footPrintMask;
}
void DataZoneProject::setAnchoPasada(int anchoPasada)
{
    _anchoPasada=anchoPasada;
}
void DataZoneProject::setOffsetPasada(int offsetPasada)
{
    _offsetPasada=offsetPasada;
}
void DataZoneProject::setFolderOut(QString folderOut)
{
    _folderOut=folderOut;
}

