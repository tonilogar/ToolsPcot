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
    _estadoProyecto=true;

}
ArchivoProyecto::~ArchivoProyecto()
{
    foreach(AProTPSection *seccion,_listaSecciones)
        delete seccion;
    _listaSecciones.clear();
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
    _estadoProyecto=false;
    emit cambioActualizado(_estadoProyecto);
}
void ArchivoProyecto::setnameProyect(QString nameProyect)
{
    _nameProyect=nameProyect;
    _estadoProyecto=false;
    emit cambioActualizado(_estadoProyecto);
}
void ArchivoProyecto::setdescriptionProyecte(QString descriptionProyecte)
{
    _descriptionProyecte=descriptionProyecte;
    _estadoProyecto=false;
    emit cambioActualizado(_estadoProyecto);
}
void ArchivoProyecto::setautorProyect(QString autorProyect)
{
    _autorProyect=autorProyect;
    _estadoProyecto=false;
    emit cambioActualizado(_estadoProyecto);
}
void ArchivoProyecto::setdateAcces(QDate dateAcces)
{
    _dateAcces=dateAcces;
    _estadoProyecto=false;
    emit cambioActualizado(_estadoProyecto);
}
void ArchivoProyecto::setdateCreate(QDate dateCreate)
{
    _dateCreate=dateCreate;
    _estadoProyecto=false;
    emit cambioActualizado(_estadoProyecto);
}
void ArchivoProyecto::setdateflight(QDate dateFlight)
{
    _dateFlight=dateFlight;
    _estadoProyecto=false;
    emit cambioActualizado(_estadoProyecto);
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

    // ESCRIBIR INFORMACION DE SECCIONES
    foreach(AProTPSection *section,_listaSecciones) {
        QJsonObject sectionObject=section->writeSection();
        proyecto.insert(section->getNombreSection(),sectionObject);
    }

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
    _estadoProyecto=true;
    emit cambioActualizado(_estadoProyecto);
    return true;
}

bool ArchivoProyecto::build()
{
    _dateCreate=QDate::currentDate();

    if (_nameProyect.isEmpty() || _nameProyect.isNull())
    {
        return false;
    }
    QJsonObject proyecto;
    proyecto.insert("cabecera","PROYECTOTPC");
    proyecto.insert("version",getnumberVersion());
    proyecto.insert("proyecto",_nameProyect);
    proyecto.insert("autor",_autorProyect);
    proyecto.insert("descripcion",_descriptionProyecte);
    proyecto.insert("fechavuelo",_dateFlight.toString("dd-MM-yyyy"));
    proyecto.insert("fechacreacion",_dateCreate.toString("dd-MM-yyyy"));
    proyecto.insert("fechaultimoacceso",_dateCreate.toString("dd-MM-yyyy"));

    // ESCRIBIR INFORMACION DE SECCIONES
    foreach(AProTPSection *section,_listaSecciones) {
        QJsonObject sectionObject=section->writeSection();
        proyecto.insert(section->getNombreSection(),sectionObject);
    }

    QJsonDocument documentProyecto;
    documentProyecto.setObject(proyecto);
    QFile ficheroProyecto(_nameFileProyect);
    if(!ficheroProyecto.open(QFile::Text | QFile::WriteOnly))
    {
        return false;
    }
    ficheroProyecto.write(documentProyecto.toJson());
    ficheroProyecto.close();
    _estadoProyecto=true;
    emit cambioActualizado(_estadoProyecto);
    return true;
}

bool ArchivoProyecto::save()
{
    _dateAcces=QDate::currentDate();

    if (_nameProyect.isEmpty() || _nameProyect.isNull())
    {
        return false;
    }
    QJsonObject proyecto;
    proyecto.insert("cabecera","PROYECTOTPC");
    proyecto.insert("version",getnumberVersion());
    proyecto.insert("proyecto",_nameProyect);
    proyecto.insert("autor",_autorProyect);
    proyecto.insert("descripcion",_descriptionProyecte);
    proyecto.insert("fechavuelo",_dateFlight.toString("dd-MM-yyyy"));
    proyecto.insert("fechacreacion",_dateCreate.toString("dd-MM-yyyy"));
    proyecto.insert("fechaultimoacceso",_dateAcces.toString("dd-MM-yyyy"));

    // ESCRIBIR INFORMACION DE SECCIONES
    foreach(AProTPSection *section,_listaSecciones) {
        QJsonObject sectionObject=section->writeSection();
        proyecto.insert(section->getNombreSection(),sectionObject);
    }

    QJsonDocument documentProyecto;
    documentProyecto.setObject(proyecto);
    QFile ficheroProyecto(_nameFileProyect);
    if(!ficheroProyecto.open(QFile::Text | QFile::WriteOnly))
    {
        return false;
    }
    ficheroProyecto.write(documentProyecto.toJson());
    ficheroProyecto.close();
    _estadoProyecto=true;
    emit cambioActualizado(_estadoProyecto);
    return true;
}
bool ArchivoProyecto::saveAs()
{


}

void ArchivoProyecto::sectionHasChanged(bool estado)
{
    if(!estado) {
        _estadoProyecto=estado;
        emit this->cambioActualizado(_estadoProyecto);
    }
}

void ArchivoProyecto::addSection(AProTPSection *section)
{
    if(!_listaSecciones.contains(section)) {
        _listaSecciones.append(section);
        connect(section,SIGNAL(estaActualizado(bool)),this,SLOT(sectionHasChanged(bool)));
    }
}

void ArchivoProyecto::removeSection(AProTPSection *section)
{
    if(_listaSecciones.contains(section)) {
        this->disconnect(section);
        _listaSecciones.removeAll(section);
    }
}

QList<AProTPSection*> ArchivoProyecto::getListaSections()
{
    return _listaSecciones;
}

bool ArchivoProyecto::read(QString pathProyectFile)
{
    /// @todo Implementar el metodo read
    QFile archivo(pathProyectFile);
    //Abrir archivo proyecto QFile
    archivo.open(QFile::Text | QFile::ReadOnly);
    //leerlo
    QByteArray lecturaArchivo=archivo.readAll();
    //Pasar la informacion a objeto Json
    QJsonDocument archivoJsonDoc=QJsonDocument::fromJson(lecturaArchivo);
      //procesar objeto Json
    QJsonObject objetoProyecto=archivoJsonDoc.object();
    //Extraer los datos para sustituir el archivo de proyecto antiguo por los nuevos datos
    _nameProyect=objetoProyecto.value("proyecto").toString();
    _autorProyect=objetoProyecto.value("autor").toString();
    _descriptionProyecte=objetoProyecto.value("descripcion").toString();
    _dateFlight=QDate::fromString(objetoProyecto.value("fechavuelo").toString(),"dd-MM-yyyy");
    _dateCreate=QDate::fromString(objetoProyecto.value("fechacreacion").toString(),"dd-MM-yyyy");
    _dateAcces=QDate::fromString(objetoProyecto.value("fechaultimoacceso").toString(),"dd-MM-yyyy");
    foreach(AProTPSection *section,_listaSecciones)
    {
        section->processSection(objetoProyecto);
    }
    _estadoProyecto=true;
    emit cambioActualizado(_estadoProyecto);
    return true;
}












