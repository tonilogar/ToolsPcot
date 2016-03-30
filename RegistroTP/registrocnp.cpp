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

#include "registrocnp.h"


RegistroCnp::RegistroCnp(QObject *parent) :
    AProTPSection(parent)
{
    _folderOut=QString();
    _cnpsEnabled=false;
}

RegistroCnp::RegistroCnp(QObject *parent,QString folderOut):
    AProTPSection(parent)
{
   _folderOut= folderOut;
   _cnpsEnabled=false;
}

//Getter

QString RegistroCnp::getFolderOut()
{
return _folderOut;
}

bool RegistroCnp::getCnpsEnabled() const
{
    return _cnpsEnabled;
}

//setters
void RegistroCnp::setFolderOut(QString folderOut)
{
    _folderOut=folderOut;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
    emit this->changeFolderOut(_folderOut);
}

void RegistroCnp::setCnpsEnabled(bool enabled)
{
    _cnpsEnabled=enabled;
    AProTPSection::_stateChanged=false;
    emit estaActualizado(_stateChanged);
    this->cnpsEnabled(_cnpsEnabled);
}

void RegistroCnp::buildDataZoneProject(DataZoneProject *dataZP)
{
 dataZP->setFolderOut(_folderOut);
}

QString RegistroCnp::getNombreSection() const
{
    return QString("sectionCNP");
}

QJsonObject RegistroCnp::writeSection()
{
    QJsonObject resultado;
    resultado.insert("folderOut",this->_folderOut);
    resultado.insert("cnpsEnabled",_cnpsEnabled);
    AProTPSection::_stateChanged=true;
    emit this->estaActualizado(_stateChanged);
    return resultado;
}

bool RegistroCnp::processSection(QJsonObject archivo)
{
    if(!archivo.contains("sectionCNP"))
        return false;

    QJsonObject section=archivo.value("sectionCNP").toObject();
    _folderOut=section.value("folderOut").toString();
    _cnpsEnabled=section.value("cnpsEnabled").toBool();
    _stateChanged=true;
    emit estaActualizado(_stateChanged);
    emit this->cnpsEnabled(_cnpsEnabled);
    emit this->changeFolderOut(_folderOut);

    return true;
}

void RegistroCnp::resetSection()
{
    _folderOut.clear();
    _stateChanged=true;
    emit estaActualizado(_stateChanged);
    emit this->changeFolderOut(_folderOut);
}
