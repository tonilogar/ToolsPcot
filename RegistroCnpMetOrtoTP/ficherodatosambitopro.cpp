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
            if(nombre.toUpper().contains("CATALUNYA"))
                item->setData(0,Qt::UserRole+6);
            else if (nombre.toUpper().contains("ESPANYA"))
                item->setData(1,Qt::UserRole+6);
            else if (nombre.toUpper().contains("FRANCIA"))
                item->setData(2,Qt::UserRole+6);
            else
                item->setData(3,Qt::UserRole+6);
            modelo->appendRow(item);
        }
    }
    return modelo;
}
void FicheroDatosAmbitoPro::CreateJsonMetDefecto()
{
    //  QString directorioExe;
    //  directorioExe=qApp->applicationDirPath();
    QJsonObject ambitCat, ambitEsp, ambitFran;
    QJsonObject ejeCat, ejeEsp,ejeFran;
    QJsonArray ejecutablesCat,ejecutablesEsp,ejecutablesFran;

    //Crear QJsonObject ambitCat
    ambitCat.insert("Nombreambito",QJsonValue(QString("Catalunya lidar 2 metres")));
    ambitCat.insert("Path",QJsonValue(QString("//nas02/treballcompartit/dtmdbdad/BD_CAT2MLID_ET.RF")));
    ambitCat.insert("TamanyoPixel",QJsonValue(int(1)));
    ambitCat.insert("Utm",QJsonValue(int(31)));
    ejeCat.insert("Nombre",QJsonValue(QString("exeExtraction")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCDTMOperations/exe/ICCADBDTMEXTRACTIONCONSOLEVERSION.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperationsGeocorrection/exe_Backup_Empuries_130115/exe/ICCImageGeoTransformation.exe")));
    ejecutablesCat.append(ejeCat);
    ambitCat.insert("Ejecutables",ejecutablesCat);

    //Crear QJsonObject ambitEsp
    ambitEsp.insert("Nombreambito",QJsonValue(QString("Espanya 5 metres")));
    ambitEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/nas02-treballcompartit-dtmdbdad/dtmdbdad/mosaicMetEspanya.rf")));
    ambitEsp.insert("TamanyoPixel",QJsonValue(int(5)));
    ambitEsp.insert("Utm",QJsonValue(int(30)));
    ejeEsp.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperationsGeocorrection/exe_Backup_Empuries_130115/exe/ICCImageGeoTransformation.exe")));
    ejecutablesEsp.append(ejeEsp);
    ambitEsp.insert("Ejecutables",ejecutablesEsp);

    //Crear QJsonObject ambitFran
    ambitFran.insert("Nombreambito",QJsonValue(QString("Francia Farmstar")));
    ambitFran.insert("Path",QJsonValue(QString("//Pedros/Disc_E/Antonio/MosaicMetFarmstar_NTF_ELIP.rf")));
    ambitFran.insert("TamanyoPixel",QJsonValue(int(10)));
    ambitFran.insert("Utm",QJsonValue(int(-2)));
    ejeFran.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesFran.append(ejeFran);
    ambitFran.insert("Ejecutables",ejecutablesFran);

    QJsonArray array;
    array.prepend((ambitCat));
    array.prepend((ambitFran));
    array.prepend((ambitEsp));
    QJsonDocument documento;
    documento.setArray(array);
    QFile documentoTexto;
    QTextStream value;
    QString PathFileJsonDefecto=qApp->applicationDirPath()+"/variablespcotMet.txt";
    documentoTexto.setFileName(PathFileJsonDefecto);
    documentoTexto.open(QFile::WriteOnly | QFile::Text);
    value.setDevice(&documentoTexto);
    value << documento.toJson();
}
void FicheroDatosAmbitoPro::CreateJsonOrtoDefecto()
{
    //  QString directorioExe;
    //  directorioExe=qApp->applicationDirPath();
    QJsonObject ambitCat, ambitEsp, ambitFran;
    QJsonObject ejeCat, ejeEsp,ejeFran;
    QJsonArray ejecutablesCat,ejecutablesEsp,ejecutablesFran;
    //Crear QJsonObject ambitCat
    ambitCat.insert("Nombreambito",QJsonValue(QString("Catalunya lidar 2 metres")));
    ambitCat.insert("Path",QJsonValue(QString("//nas02/treballcompartit/dtmdbdad/BD_CAT2MLID_ET.RF")));
    ambitCat.insert("TamanyoPixel",QJsonValue(int(1)));
    ambitCat.insert("Utm",QJsonValue(int(31)));
    ejeCat.insert("Nombre",QJsonValue(QString("exeExtraction")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCDTMOperations/exe/ICCADBDTMEXTRACTIONCONSOLEVERSION.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    ejeCat.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperationsGeocorrection/exe_Backup_Empuries_130115/exe/ICCImageGeoTransformation.exe")));
    ejecutablesCat.append(ejeCat);
    ambitCat.insert("Ejecutables",ejecutablesCat);

    //Crear QJsonObject ambitEsp
    ambitEsp.insert("Nombreambito",QJsonValue(QString("Espanya 5 metres")));
    ambitEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/nas02-treballcompartit-dtmdbdad/dtmdbdad/mosaicMetEspanya.rf")));
    ambitEsp.insert("TamanyoPixel",QJsonValue(int(5)));
    ambitEsp.insert("Utm",QJsonValue(int(30)));
    ejeEsp.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    ejeEsp.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperationsGeocorrection/exe_Backup_Empuries_130115/exe/ICCImageGeoTransformation.exe")));
    ejecutablesEsp.append(ejeEsp);
    ambitEsp.insert("Ejecutables",ejecutablesEsp);

    //Crear QJsonObject ambitFran
    ambitFran.insert("Nombreambito",QJsonValue(QString("Francia Farmstar")));
    ambitFran.insert("Path",QJsonValue(QString("//Pedros/Disc_E/Antonio/MosaicMetFarmstar_NTF_ELIP.rf")));
    ambitFran.insert("TamanyoPixel",QJsonValue(int(10)));
    ambitFran.insert("Utm",QJsonValue(int(-2)));
    ejeFran.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeFran.insert("Path",QJsonValue(QString("D:/antonio/trabajos/programacion/vEntorno/variables/empuries-produccio/ICCImageOperations/exe/ICCImageResize.exe")));
    ejecutablesFran.append(ejeFran);
    ambitFran.insert("Ejecutables",ejecutablesFran);


    QJsonArray array;
    array.prepend((ambitCat));
    array.prepend((ambitFran));
    array.prepend((ambitEsp));
    QJsonDocument documento;
    documento.setArray(array);
    QFile documentoTexto;
    QTextStream value;
    QString PathFileJsonDefecto=qApp->applicationDirPath()+"/variablespcotOrto.txt";
    documentoTexto.setFileName(PathFileJsonDefecto);
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























