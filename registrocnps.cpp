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
#include "registrocnps.h"

RegistroCnps::RegistroCnps(QObject *parent) :
    QObject(parent)
{
    _folderOut=QString();
}

RegistroCnps::RegistroCnps(QObject *parent,QString folderOut):
    QObject(parent)
{
   _folderOut= folderOut;
}

//Getter

QString RegistroCnps::getFolderOut()
{
return _folderOut;
}

//setters
void RegistroCnps::setFolderOut(QString folderOut)
{
_folderOut=folderOut;
}
void RegistroCnps::buildDataZoneProject(DataZoneProject *dataZP)
{
 dataZP->setFolderOut(_folderOut);
}
