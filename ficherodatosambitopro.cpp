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
#include "ficherodatosambitopro.h"

FicheroDatosAmbitoPro::FicheroDatosAmbitoPro(QObject *parent, QString nFichero) :
    QObject(parent)
{
    nombreFichero=nFichero;
}

void FicheroDatosAmbitoPro::setNombreFichero(QString nFichero)
{
    nombreFichero=nFichero;
}

QString FicheroDatosAmbitoPro::getNombreFichero()
{
    return nombreFichero;
}

bool FicheroDatosAmbitoPro::fileExist()
{
    return QFile::exists(nombreFichero);
}

QStandardItemModel*  FicheroDatosAmbitoPro::obtenerModelo()
{

    //1-Abrir archivo
    //2-Leer archivo
    //3-Crear modelo
    //4-procesar contenido leido de larchivo.
    //5-Rellenar modelo
    //6-Devolver modelo

    QStandardItemModel *modelo=new QStandardItemModel(0);
    QFile archivo(nombreFichero);
    archivo.open(QFile::ReadOnly | QFile::Text);
    //QString contenido=archivo.readAll();
    //QJsonDocument fileJson=QJsonDocument::fromJson(contenido.toUtf8());
    QByteArray contenido;
    contenido=archivo.readAll();
    QJsonDocument fileJson;
    fileJson=QJsonDocument::fromJson(contenido);
    if(fileJson.isArray())
    {
        qDebug() <<"tengo elementos";

    }
    else
        qDebug() <<"no tengo elementos";

    QStandardItem *itemNulo;
    itemNulo=new QStandardItem("No seleccionado");
    itemNulo->setData(QString(),Qt::UserRole+1);
    itemNulo->setData(-1,Qt::UserRole+2);
    itemNulo->setData(-1,Qt::UserRole+3);
    modelo->appendRow(itemNulo);
    QJsonArray listaAmbitos;
    listaAmbitos=fileJson.array();
    foreach (QJsonValue registro,listaAmbitos)
    {
        QStandardItem *item;//creo puntero QStandartItem para almacenar un elemento al modelo.
        if(registro.isObject())
        {
            QJsonObject ambito=registro.toObject();
            QString nombre=ambito.value("Nombreambito").toString();
            QString path=ambito.value("Path").toString();
            int tPixel=ambito.value("TamanyoPixel").toVariant().toInt();
            int utmDefecto=ambito.value("Utm").toVariant().toInt();
            QJsonArray listaExe=ambito.value("Ejecutables").toArray();
            qDebug()<< listaExe <<"listaExelllllllllll";
            item=new QStandardItem(nombre);
            item->setData(path,Qt::UserRole+1);
            item->setData(tPixel,Qt::UserRole+2);
            item->setData(utmDefecto,Qt::UserRole+3);
            item->setData(listaExe,Qt::UserRole+4);
            item->setData(nombre,Qt::UserRole+5);
            modelo->appendRow(item);
        }
    }
    return modelo;
}

