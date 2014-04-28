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
#include "operacionbase.h"

OperacionBase::OperacionBase(QObject *parent) :
    QObject(parent)
{
    /*El QVariantMap  tiene que estar formado por los datos de registroCnp o registroMet o registroOrto mas los datos de
    TableViewCoordinates, directorio de salida nombre de salida etc*/
    registro=QVariantMap();
    contador=0;
    //Conexiones
    flujo.setDevice(&proceso);
    connect(&proceso,SIGNAL(started()),this,SLOT(inicio()));
    connect(&proceso,SIGNAL(finished(int)),this,SLOT(fin(int)));
    connect(&proceso,SIGNAL(readyRead()),this,SLOT(datosSalida()));

}

QVariantMap OperacionBase::getDatosRegistro()
{
 return registro;
}

void OperacionBase::setDatosRegistro(QVariantMap datos)
{
    qDebug ()<< "---------------------setDatosRegistro-------------------";
 registro=datos;
}

void OperacionBase::datosSalida()
{
QString datosSalida=flujo.readAll();
registro.insert("ultimasalida",datosSalida);
}

void OperacionBase::resetOperacion()
{
    contador=0;
    registro.clear();
}

void OperacionBase::obStartOperacion()
{
    proceso.start(registro.value("pathArchivoEjecutable").toString());
}
