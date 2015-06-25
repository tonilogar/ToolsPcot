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

#include "registrocreatecnps.h"
#include "createcnps.h"

RegistroCreateCnps::RegistroCreateCnps(QObject *parent) :
    AProTPSection(parent)
{
    _folderOut=QString();
    _widgetCnps=0;
    _cnpsEnabled=false;
}

RegistroCreateCnps::RegistroCreateCnps(QObject *parent,QString folderOut):
    AProTPSection(parent)
{
   _folderOut= folderOut;
   _widgetCnps=0;
   _cnpsEnabled=false;
}

void RegistroCreateCnps::setWidget(CreateCnps *widget)
{
    _widgetCnps=widget;
}

//Getter

QString RegistroCreateCnps::getFolderOut()
{
return _folderOut;
}

bool RegistroCreateCnps::getCnpsEnabled() const
{
    return _cnpsEnabled;
}

//setters
void RegistroCreateCnps::setFolderOut(QString folderOut)
{
    _folderOut=folderOut;
    AProTPSection::_stateChanged=false;
    emit this->estaActualizado(_stateChanged);
}

void RegistroCreateCnps::setCnpsEnabled(bool enabled)
{
    _cnpsEnabled=enabled;
    AProTPSection::_stateChanged=false;
    emit estaActualizado(_stateChanged);
}

void RegistroCreateCnps::buildDataZoneProject(DataZoneProject *dataZP)
{
 dataZP->setFolderOut(_folderOut);
}

QString RegistroCreateCnps::getNombreSection() const
{
    return QString("sectionCNP");
}

QJsonObject RegistroCreateCnps::writeSection()
{
    QJsonObject resultado;
    resultado.insert("folderOut",this->_folderOut);
    resultado.insert("cnpsEnabled",_cnpsEnabled);

    return resultado;
    AProTPSection::_stateChanged=true;
    emit this->estaActualizado(_stateChanged);
}

bool RegistroCreateCnps::processSection(QJsonObject archivo)
{
    _widgetCnps->disconnectRegistro();
    if(!archivo.contains("sectionCNP"))
        return false;

    QJsonObject section=archivo.value("sectionCNP").toObject();
    _folderOut=section.value("folderOut").toString();
    _cnpsEnabled=section.value("cnpsEnabled").toBool();
    _stateChanged=true;
    emit estaActualizado(_stateChanged);
    _widgetCnps->connectRegistro();

    return true;
}

void RegistroCreateCnps::resetSection()
{
    _widgetCnps->disconnectRegistro();
    _folderOut.clear();
    _stateChanged=true;
    emit estaActualizado(_stateChanged);
    _widgetCnps->connectRegistro();
}
