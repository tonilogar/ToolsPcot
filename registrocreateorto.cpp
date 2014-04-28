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
    _ambitoProyecto=QString();
    _tamanyoPixel;
    _utm=-1;
    _fprintM=false;
    _anchoPasada=-1;
    _offsetPasada=-1;
    _pathImageOrto=QString();
    _exeSubScene=QString();
}

RegistroCreateOrto::RegistroCreateOrto(QObject *parent,QString folderOut,QString ambitoProyecto,int tamanyoPixel,
int utm,int anchoPasada,int offsetPasada, QString pathImageOrto,QString exeSubScene):
    QObject(parent)
{
   _folderOut= folderOut;
   _ambitoProyecto= ambitoProyecto;
   _tamanyoPixel= tamanyoPixel;
   _utm= utm;
   _fprintM=false;
   _anchoPasada=anchoPasada;
   _offsetPasada= offsetPasada;
   _pathImageOrto=pathImageOrto;
   _exeSubScene=exeSubScene;
}


//Getter

QString RegistroCreateOrto::getFolderOut()
{
return _folderOut;
}
QString RegistroCreateOrto::getAmbitoProyecto()
{
return _ambitoProyecto;
}
int RegistroCreateOrto::getTamanyPixel()
{
return _tamanyoPixel;
}
int RegistroCreateOrto::getUtm()
{
return _utm;
}
int RegistroCreateOrto::getAnchoPasada()
{
return _anchoPasada;
}
int RegistroCreateOrto::getOffsetPasada()
{
return _offsetPasada;
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



//setters
void RegistroCreateOrto::setFolderOut(QString folderOut)
{
_folderOut=folderOut;
}
void RegistroCreateOrto::setAmbitoProyecto(QString ambitoProyecto)
{
_ambitoProyecto=ambitoProyecto;
}
void RegistroCreateOrto::setTamanyPixel(int tamanyoPixel)
{
_tamanyoPixel=tamanyoPixel;
}
void RegistroCreateOrto::setUtm(int utm)
{
_utm=utm;
}
void RegistroCreateOrto::setAnchoPasada(int anchoPasada)
{
_anchoPasada=anchoPasada;
}
void RegistroCreateOrto::setOffsetPasada(int offsetPasada)
{
_offsetPasada=offsetPasada;
}
void RegistroCreateOrto::setPathImageOrto(QString pathImageOrto)
{
_pathImageOrto=pathImageOrto;
}
void RegistroCreateOrto::setExeSubScene(QString exeSubScene)
{
_exeSubScene=exeSubScene;
}
void RegistroCreateOrto::setFootprintMask(int fprintM)
{

    if(fprintM==2)
    _fprintM=true;
    else
        _fprintM=false;
}


