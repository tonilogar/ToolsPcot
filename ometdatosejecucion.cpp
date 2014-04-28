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
#include "ometdatosejecucion.h"

OmetDatosEjecucion::OmetDatosEjecucion(QObject *parent) :
    QObject(parent)
{
    fileSubScene=QString();
    fileOpegeo=QString();
    fileFootPrintMask=QString();
    fileExtraction=QString();
    fileResize=QString();
    fileCutDtm=QString();

}
//Setters
void OmetDatosEjecucion::setFileSubScene(QString fSubScene)
{
 fileSubScene=fSubScene;
}

void OmetDatosEjecucion::setFileOpegeo(QString fOpegeo)
{
  fileOpegeo=fOpegeo;
}
void OmetDatosEjecucion::setFileFootPrintMask(QString fFootPrintMask)
{
  fileFootPrintMask=fFootPrintMask;
}
void OmetDatosEjecucion::setFileExtraction(QString fExtraction)
{
  fileExtraction=fExtraction;
}
void OmetDatosEjecucion::setFileResize(QString fResize)
{
  fileResize=fResize;
}
void OmetDatosEjecucion::setFileCutDtm(QString fCutDtm)
{
 fileCutDtm=fCutDtm;
}


//Getters
QString OmetDatosEjecucion::getFileSubScene()
{
 return fileSubScene;
}

QString OmetDatosEjecucion::getFileOpegeo()
{
  return fileOpegeo;
}
QString OmetDatosEjecucion::getFileFootPrintMask()
{
  return fileFootPrintMask;
}
QString OmetDatosEjecucion::getFileExtraction()
{
  return fileExtraction;
}
QString OmetDatosEjecucion::getFileResize()
{
  return fileResize;
}
QString OmetDatosEjecucion::getFileCutDtm()
{
 return fileCutDtm;
}
