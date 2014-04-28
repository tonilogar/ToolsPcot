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
#include "registroraw.h"

RegistroRaw::RegistroRaw(QObject *parent) :
    QObject(parent)
{
    _name=QString();
    _path=QString();
    _signoPasada=0;
    _stripNumber=0;
    _fileNumber=0;
    _canalRed=0;
    _canalGreen=0;
    _canalBlue=0;
   }

RegistroRaw::RegistroRaw(QObject *parent, QString name, QString path)
    : QObject(parent)
{
    _name=name;
    _path=path;
    _signoPasada=0;
    _stripNumber=0;
    _fileNumber=0;
    _canalRed=0;
    _canalGreen=0;
    _canalBlue=0;
}
