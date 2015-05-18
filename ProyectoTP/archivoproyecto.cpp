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

#include "archivoproyecto.h"


ArchivoProyecto::ArchivoProyecto(QObject *parent, QString nameFileProyect):
    QObject(parent)
{
    _nameFileProyect=nameFileProyect;
    _seccionCnpMetOrto=new AProCnpMetOrtoSection(this);
}
ArchivoProyecto::~ArchivoProyecto()
{
    if(_seccionCnpMetOrto)
        delete _seccionCnpMetOrto;
}

bool ArchivoProyecto::exist()
{
    return QFileInfo::exists(_nameFileProyect);
}
QString ArchivoProyecto::getnameFileProyect()
{
    return _nameFileProyect;
}

QString ArchivoProyecto::getnameProyect()
{
    return _nameProyect;
}
QString ArchivoProyecto::getdescriptionProyecte()
{
    return _descriptionProyecte;
}
QString ArchivoProyecto::getautorProyect()
{
    return _autorProyect;
}
QDate ArchivoProyecto::getdateAcces()
{
    return _dateAcces;
}
QDate ArchivoProyecto::getdateCreate()
{
    return _dateAcces;
}
QString ArchivoProyecto::getnumberVersion()
{
    return QString("0.0");
}
QDate ArchivoProyecto::getdateflight()
{
    return _dateFlight;
}
void ArchivoProyecto::setnameFileProyect(QString nameFileProyect)
{
    _nameFileProyect=nameFileProyect;
}
void ArchivoProyecto::setnameProyect(QString nameProyect)
{
    _nameProyect=nameProyect;
}
void ArchivoProyecto::setdescriptionProyecte(QString descriptionProyecte)
{
    _descriptionProyecte=descriptionProyecte;
}
void ArchivoProyecto::setautorProyect(QString autorProyect)
{
    _autorProyect=autorProyect;
}
void ArchivoProyecto::setdateAcces(QDate dateAcces)
{
    _dateAcces=dateAcces;
}
void ArchivoProyecto::setdateCreate(QDate dateCreate)
{
    _dateCreate=dateCreate;
}
void ArchivoProyecto::setdateflight(QDate dateFlight)
{
    _dateFlight=dateFlight;
}
bool ArchivoProyecto::build(QString nameProyect,QString descriptionProyecte, QString autorProyect, QDate dateFlight)
{
    QDate dateCreate=QDate::currentDate();

    if (nameProyect.isEmpty() || nameProyect.isNull())
    {
        return false;
    }
    QJsonObject proyecto;
    proyecto.insert("cabecera","PROYECTOTPC");
    proyecto.insert("version",getnumberVersion());
    proyecto.insert("proyecto",nameProyect);
    proyecto.insert("autor",autorProyect);
    proyecto.insert("descripcion",descriptionProyecte);
    proyecto.insert("fechavuelo",dateFlight.toString("dd-MM-yyyy"));
    proyecto.insert("fechacreacion",dateCreate.toString("dd-MM-yyyy"));
    proyecto.insert("fechaultimoacceso",dateCreate.toString("dd-MM-yyyy"));

    // ESCRIBIR INFORMACION DE SECCION CNP MET ORTO
    QJsonObject cnpMetOrto=_seccionCnpMetOrto->writeSection();
    proyecto.insert("cnpMetOrto",cnpMetOrto);
    // -------

    QJsonDocument documentProyecto;
    documentProyecto.setObject(proyecto);
    QFile ficheroProyecto(_nameFileProyect);
    if(!ficheroProyecto.open(QFile::Text | QFile::WriteOnly))
    {
        return false;
    }
    ficheroProyecto.write(documentProyecto.toJson());
    ficheroProyecto.close();
    _nameProyect=nameProyect;
    _autorProyect=autorProyect;
    _descriptionProyecte=descriptionProyecte;
    _dateCreate=dateCreate;
    _dateAcces=dateCreate;
    _dateFlight=dateFlight;

}

bool ArchivoProyecto::read(QString pathProyectFile)
{
    /// @todo Implementar el metodo read
    return false;
}












