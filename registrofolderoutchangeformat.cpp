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
#include "registrofolderoutchangeformat.h"
#include <QDebug>
RegistroFolderOutChangeFormat::RegistroFolderOutChangeFormat(QObject *parent) :
    QObject(parent)
{
  _folderAtt=QString();
  _folderPix=QString();
  _folderAtp=QString();
  _folderRf=QString();
  _folderJpg=QString();

}

RegistroFolderOutChangeFormat::RegistroFolderOutChangeFormat(QObject *parent,QString folderAtt,QString folderPix,QString folderAtp,QString folderRf,QString folderJpg
                               ) :
    QObject(parent)
{
  _folderAtt=folderAtt,
  _folderPix=folderPix,
  _folderAtp=folderAtp,
  _folderRf=folderRf,
  _folderJpg=folderJpg;

}


//Getter


QString RegistroFolderOutChangeFormat::getFolderAtt() const
{
return _folderAtt;
}
QString RegistroFolderOutChangeFormat::getFolderPix() const
{
return _folderPix;
}
QString RegistroFolderOutChangeFormat::getFolderAtp() const
{
return _folderAtp;
}
QString RegistroFolderOutChangeFormat::getFolderRf() const
{
return _folderRf;
}
QString RegistroFolderOutChangeFormat::getFolderJpg() const
{
return _folderJpg;
}


//Setters

void RegistroFolderOutChangeFormat::setFolderAtt(QString folderAtt)
{
_folderAtt=folderAtt;
}
void RegistroFolderOutChangeFormat::setFolderPix(QString folderPix)
{
_folderPix=folderPix;
}
void RegistroFolderOutChangeFormat::setFolderAtp(QString folderAtp)
{
_folderAtp=folderAtp;
}
void RegistroFolderOutChangeFormat::setFolderRf(QString folderRf)
{
_folderRf=folderRf;
}
void RegistroFolderOutChangeFormat::setFolderJpg(QString folderJpg)
{
_folderJpg=folderJpg;
}






















