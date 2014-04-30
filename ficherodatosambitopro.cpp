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




 QJsonObject FicheroDatosAmbitoPro::CreateJsonDefecto()
 {
//  QString directorioExe;
//  directorioExe=qApp->applicationDirPath();
  QJsonObject ambitCat, ambitEsp, ambitFran;
  QJsonObject ejecutable;
  QJsonArray ejecutablesCat,ejecutablesEsp,ejecutablesFran;
  ejecutable.insert("Nombre",QJsonValue(QString("exeExtraction")));
  ejecutable.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCDTMOperations/exe/ICCADBDTMEXTRACTIONCONSOLEVERSION.exe")));
  ejecutablesCat.append(ejecutable);
  ejecutable.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
  ejecutable.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
  ejecutablesCat.append(ejecutable);
  ejecutable.insert("Nombre",QJsonValue(QString("exeSubScene")));
  ejecutable.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageSubescenes.exe")));
  ejecutablesCat.append(ejecutable);
  ejecutable.insert("Nombre",QJsonValue(QString("exeImaOpeGeo")));
  ejecutable.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperationsGeocorrection/exe/ICCImageGeoTransformation.exe")));
  ejecutablesCat.append(ejecutable);
  ambitCat.insert("Nombreambito",QJsonValue(QString("Catalunya lidar 1 metre")));
  ambitCat.insert("Path",QJsonValue(QString("//nas02/treballcompartit/dtmdbdad/BD_CAT2MLID_ET.RF")));
  ambitCat.insert("TamanyoPixel",QJsonValue(int(1)));
  ambitCat.insert("Utm",QJsonValue(int(31)));
  ambitCat.insert("Ejecutables",ejecutablesCat);




  ambitEsp.insert("Nombreambito",QJsonValue(QString("Espanya 5 metres")));
  ambitEsp.insert("Path",QJsonValue(QString("//Pedros/Disc_E/Antonio/mosaicMetEspanya.rf")));
  ambitEsp.insert("TamanyoPixel",QJsonValue(int(5)));
  ambitEsp.insert("Utm",QJsonValue(int(30)));
  ambitEsp.insert("Ejecutables",QJsonValue(QString("//Nas03/geoproces/DFApplications/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));


  ambitFran.insert("Nombreambito",QJsonValue(QString("Francia Farmstar")));
  ambitFran.insert("Path",QJsonValue(QString("//Pedros/Disc_E/Antonio/MosaicMetFarmstar_NTF_ELIP.rf")));
  ambitFran.insert("TamanyoPixel",QJsonValue(int(10)));
  ambitFran.insert("Utm",QJsonValue(int(-2)));
  ambitFran.insert("Ejecutables",QJsonValue(QString("//Nas03/geoproces/DFApplications/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));


  QJsonArray array;
  array.prepend((ambitCat));
  array.prepend((ambitFran));
  array.prepend((ambitEsp));
  QJsonDocument documento;
  documento.setArray(array);
  QFile documentoTexto;
  QTextStream value;
  documentoTexto.setFileName("E:/public/TrabajosQT/git/toolsPcot/branchDev-setting/variablespcotMet.txt");
  documentoTexto.open(QFile::WriteOnly | QFile::Text);
  value.setDevice(&documentoTexto);
  value << documento.toJson();
 }

 QString FicheroDatosAmbitoPro::getPathImageMetCat()
 {
  return _pathImageMetCat;
 }

 QString FicheroDatosAmbitoPro::getPathImageMetEsp()
 {
   return _pathImageMetEsp;
 }

 QString FicheroDatosAmbitoPro::getPathImageMetFran()
 {
  return _pathImageMetFran;
 }

 QString FicheroDatosAmbitoPro::getExeSubScene()
 {
   return _exeSubScene;
 }

 QString FicheroDatosAmbitoPro::getExeImaOpeGeo()
 {
  return _exeImaOpeGeo;
 }

 QString FicheroDatosAmbitoPro::getExeFootPrintMask()
 {
    return _exeFootPrintMask;
 }

 QString FicheroDatosAmbitoPro::getExeExtraction()
 {
  return _exeExtraction;
 }

 QString FicheroDatosAmbitoPro::getExeResize()
 {
  return _exeResize;
 }


 void FicheroDatosAmbitoPro::setPathImageMetCat(QString pathImageMetCat)
 {
   _pathImageMetCat=pathImageMetCat;
 }

 void FicheroDatosAmbitoPro::setPathImageMetEsp(QString pathImageMetEsp)
 {
  _pathImageMetEsp=pathImageMetEsp;
 }

 void FicheroDatosAmbitoPro::setPathImageMetFran(QString pathImageMetFran)
 {
  _pathImageMetFran=pathImageMetFran;
 }

 void FicheroDatosAmbitoPro::setExeSubScene(QString exeSubScene)
 {
  _exeSubScene=exeSubScene;
 }

 void FicheroDatosAmbitoPro::setExeImaOpeGeo(QString exeImaOpeGeo)
 {
  _exeImaOpeGeo=exeImaOpeGeo;
 }

 void FicheroDatosAmbitoPro::setExeFootPrintMask(QString exeFootPrintMask)
 {
  _exeFootPrintMask=exeFootPrintMask;
 }

 void FicheroDatosAmbitoPro::setExeExtraction(QString exeExtraction)
 {
 _exeExtraction=exeExtraction;
 }

 void FicheroDatosAmbitoPro::setExeResize(QString exeResize)
 {
 _exeResize=exeResize;
 }























