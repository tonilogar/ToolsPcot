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
#include "lanzadoroperaciones.h"
#include <QDateTime>

LanzadorOperaciones::LanzadorOperaciones(QObject *parent, RegistroCreateCnps *_regCnp,RegistroCreateMet  *_regMet,
                                         RegistroCreateOrto *_regOrto,TableViewCoordinates *_tableCoor ) :
    QObject(parent)
{
    _registroCnp=_regCnp;
    _registroMet=_regMet;
    _registroOrto=_regOrto;
    _tableCoordinates=_tableCoor;
    _opeMet=new OperacionMet();
    _opeOrto=new OperacionOrto();
    _tablaproceso=new operacionProgresdialog();
    //Conexiones cnp met orto

    //connect(ope,SIGNAL(pasoActualizado(int)),_tablaproceso,SLOT(actualizarBarraMet(int)));
    connect(_opeOrto,SIGNAL(actualizarProgreso(int)),_tablaproceso,SLOT(actualizarBarraOrto(int)));

    connect(_opeMet,SIGNAL(inicioProgreso(int,int)),_tablaproceso,SLOT(setMetRange(int,int)));
    connect(_opeOrto,SIGNAL(inicioProgreso(int,int)),_tablaproceso,SLOT(setOrtoRange(int,int)));


    connect(_opeMet,SIGNAL(errorProgreso(QString)),_tablaproceso,SLOT(tratarErrores(QString)));
    connect(_opeOrto,SIGNAL(errorProgreso(QString)),_tablaproceso,SLOT(tratarErrores(QString)));


    connect(_tablaproceso,SIGNAL(cancelarMet()),_opeMet,SLOT(cancelarOperacion()));
    connect(_tablaproceso,SIGNAL(cancelarOrto()),_opeOrto,SLOT(cancelarOperacion()));


    connect(_opeMet,SIGNAL(finProgreso()),_tablaproceso,SLOT(disabledCancelMet()));
    connect(_opeOrto,SIGNAL(finProgreso()),_tablaproceso,SLOT(disabledCancelOrto()));


    //Codigo nuevo
    _dataZoneCnp=new DataZoneProject(this);
    _dataZoneMet=new DataZoneProject(this);
    _dataZoneOrto=new DataZoneProject(this);


}
void LanzadorOperaciones::operacionCnps()
{

    _tablaproceso->enableCancelCnp();
    QVariantMap datosOperacionCnp;
    QFileInfo folderOutQfileCnp(_registroCnp->getFolderOut());

    if(!folderOutQfileCnp.exists())
    {
        QMessageBox::warning(0,"error directorio salida cnp", "Cnp, el directorio de salida no existe");
        return;
    }
    if (!folderOutQfileCnp.isDir())
    {
        QMessageBox::warning(0,"error directorio salida Cnp", "Cnp, el path indicado no se corresponde con un directorio");
        return;
    }

    if (!folderOutQfileCnp.isReadable())
    {
        QMessageBox::warning(0,"error de lectura Cnp ", "Cnp, el directorio indicado no tiene permisos de lectura");
        return;
    }

    if (!folderOutQfileCnp.isWritable())
    {
        QMessageBox::warning(0,"error de escritura", "el directorio indicado no tiene permisos de escritura");
        return;
    }
    _registroCnp->buildDataZoneProject(_dataZoneCnp);
    IdeCor=createIDC();
    OperacionCnp *operCnp;
    foreach (IdentificadorCoordenadas *ide,IdeCor)
    {
        operCnp=new OperacionCnp(this,ide,_dataZoneCnp);

        _listadoOperacionCnp<<new OperacionCnp(this,ide,_dataZoneCnp);

    }
    _tablaproceso->setModal(true);//para que la ventana sea modal y no deje seleccionar las ventanas inferiores
    QRect tam=_tablaproceso->geometry();
    QPoint centro = QApplication::activeWindow()->geometry().center();
    tam.moveCenter(centro);
    _tablaproceso->setGeometry(tam);
    _tablaproceso->show();
    QVariantList datosModelo=obtenerDatosModelo(_tableCoordinates->getModeloCoordenadas());

    //qDebug() << "setDatosRegistroCnp";

    //qDebug() << "startOperacionCnp";

}

void LanzadorOperaciones::operacionMet()
{
    _tablaproceso->enableCancelMet();
    QVariantMap datosOperacionMet;
    QString aProyecto;
    QString zProyecto;
    int resize;
    int utm;
    int sizeCut;
    int numeroCanals;
    int ampladaPasada;
    int ofsetPasada;
    bool footPrintMask;
    bool cutDtm;
    //    QString exeSScene;
    //    QString exeImaOpeGeo;
    //    QString exeFootPrintMask;
    QString utmDefecto;
    QJsonArray ejecutables;
    QFileInfo fileAProyecto;
    zProyecto=_registroMet->getAmbitoProyecto();
    aProyecto=_registroMet->getPathImageMet();
    ejecutables=_registroMet->getListaEjecutables();
    //    exeSScene=_registroMet->getExeSubScene();
    //    exeImaOpeGeo=_registroMet->getExeImaOpeGeo();
    //    exeFootPrintMask=_registroMet->getExeFootPrintMask();
    utmDefecto=_registroMet->getUtmDefecto();
    resize=_registroMet->getTamanyPixel();
    //qDebug()<< resize << "resize";
    utm=_registroMet->getUtm();
    sizeCut=_registroMet->getTamanyoCorte();
    numeroCanals=_registroMet->getNumeroCanales();
    ampladaPasada=_registroMet->getAnchoPasada();
    ofsetPasada=_registroMet->getOffsetPasada();
    footPrintMask=_registroMet->getFootPrintMask();
    cutDtm=_registroMet->getCutDtm();
    fileAProyecto.setFile(_registroMet->getPathImageMet());
    QJsonObject elementoExe;
    foreach (QJsonValue elemento, ejecutables)
    {
        elementoExe=elemento.toObject();
        datosOperacionMet.insert(elementoExe.value("nombre").toString(),elementoExe.value("path").toString());
    }
    if(!fileAProyecto.exists())
    {
        QMessageBox::warning(0,"error met", _registroMet->getPathImageMet()+ " no se encuentra seleccione la imagen en el dialogo de preferencias, " +QString::number(_registroMet->getPathImageMet().count()));
        return;
    }
    datosOperacionMet.insert("zonaProyecto",zProyecto);
    datosOperacionMet.insert("ambitoProyecto",aProyecto);
    datosOperacionMet.insert("utmDefecto",utmDefecto);
    datosOperacionMet.insert("sizePixel",resize);
    datosOperacionMet.insert("sCut",sizeCut);
    datosOperacionMet.insert("uso",utm);
    datosOperacionMet.insert("nCanals",numeroCanals);
    datosOperacionMet.insert("aPasada",ampladaPasada);
    datosOperacionMet.insert("oPasada",ofsetPasada);
    datosOperacionMet.insert("FootPrintMask",footPrintMask);
    datosOperacionMet.insert("CutDtm",cutDtm);

    QFileInfo folderOutQfile(_registroMet->getFolderOut());

    if(!folderOutQfile.exists())
    {
        QMessageBox::warning(0,"error directorio salida met", "Met, el directorio de salida no existe");
        return;
    }
    if (!folderOutQfile.isDir())
    {
        QMessageBox::warning(0,"error directorio salida met", "Met, el path indicado no se corresponde con un directorio");
        return;
    }

    if (!folderOutQfile.isReadable())
    {
        QMessageBox::warning(0,"error de lectura met ", "Met, el directorio indicado no tiene permisos de lectura");
        return;
    }

    if (!folderOutQfile.isWritable())
    {
        QMessageBox::warning(0,"error de escritura", "el directorio indicado no tiene permisos de escritura");
        return;
    }
    datosOperacionMet.insert("folderOut",_registroMet->getFolderOut());

    //_opeMet->resetOperacion();
    _tablaproceso->setModal(true);//para que la ventana sea modal y no deje seleccionar las ventanas inferiores
    QRect tam=_tablaproceso->geometry();
    QPoint centro = QApplication::activeWindow()->geometry().center();
    tam.moveCenter(centro);
    _tablaproceso->setGeometry(tam);
    QVariantList datosModelo=obtenerDatosModelo(_tableCoordinates->getModeloCoordenadas());
    datosOperacionMet.insert("datosTabla",datosModelo);
    qDebug()<< zProyecto <<"zProyecto---------------";
    _tablaproceso->show();
    if(zProyecto=="Catalunya lidar 1 metre")
    {
        _opeMet->resetOperacion();
        _opeMet->setDatosRegistro(datosOperacionMet);
        _opeMet->startOperacion();
        qDebug()<< zProyecto <<"Create met Catalunya";

    }
    if(zProyecto=="Espanya 5 metres")
    {
        _opeMet->setDatosRegistro(datosOperacionMet);
        _opeMet->startOperacion();
        qDebug()<< zProyecto <<"Create met España";

    }
    if(zProyecto=="Francia Farmstar")
    {
        qDebug()<< zProyecto <<"Create met Francia";
    }



}

void LanzadorOperaciones::operacionOrto()
{
    _tablaproceso->enableCancelOrto();
    QVariantMap datosOperacionOrto;
    QString aProyecto;
    QString exeSScene;
    QFileInfo fileAProyecto;
    aProyecto=_registroOrto->getPathImageOrto();
    exeSScene=_registroMet->getExeSubScene();

    fileAProyecto.setFile(_registroOrto->getPathImageOrto());
    if(!fileAProyecto.exists())
    {
        QMessageBox::warning(0,"error Orto", _registroOrto->getPathImageOrto()+ " no se encuentra seleccione la imagen en el dialogo de preferencias, " +QString::number(_registroOrto->getPathImageOrto().count()));
        return;
    }
    datosOperacionOrto.insert("ambitoProyecto",aProyecto);
    datosOperacionOrto.insert("exeSubScene",exeSScene);
    QFileInfo folderOutQfile(_registroOrto->getFolderOut());

    if(!folderOutQfile.exists())
    {
        QMessageBox::warning(0,"error directorio salida Orto", "Orto, el directorio de salida no existe");
        return;
    }
    if (!folderOutQfile.isDir())
    {
        QMessageBox::warning(0,"error directorio salida Orto", "Orto, el path indicado no se corresponde con un directorio");
        return;
    }

    if (!folderOutQfile.isReadable())
    {
        QMessageBox::warning(0,"error de lectura Orto ", "Orto, el directorio indicado no tiene permisos de lectura");
        return;
    }

    if (!folderOutQfile.isWritable())
    {
        QMessageBox::warning(0,"error de escritura", "el directorio indicado no tiene permisos de escritura");
        return;
    }
    datosOperacionOrto.insert("folderOut",_registroOrto->getFolderOut());
    _opeOrto->resetOperacion();


    _tablaproceso->setModal(true);//para que la ventana sea modal y no deje seleccionar las ventanas inferiores
    QRect tam=_tablaproceso->geometry();
    QPoint centro = QApplication::activeWindow()->geometry().center();
    tam.moveCenter(centro);
    _tablaproceso->setGeometry(tam);
    _tablaproceso->show();
    QVariantList datosModelo=obtenerDatosModelo(_tableCoordinates->getModeloCoordenadas());
    datosOperacionOrto.insert("datosTabla",datosModelo);
    _opeOrto->setDatosRegistro(datosOperacionOrto);
    _opeOrto->startOperacion();
}

QVariantList LanzadorOperaciones::obtenerDatosModelo(ModeloCoordenadas *_modeloC)
{
    QVariantList listaIdCoordenadas;
    int filasModelo=0;
    int columnasModelo=0;
    filasModelo=_modeloC->rowCount();
    columnasModelo=_modeloC->columnCount();

    for(int i=0;i<filasModelo;i++)
    {
        QVariantMap datosFila;
        for(int j=0;j<columnasModelo;j++)
        {
            datosFila.insert(_modeloC->headerData(j,Qt::Horizontal,Qt::DisplayRole).toString(),_modeloC->index(i,j).data());

        }
        listaIdCoordenadas.append(datosFila);
    }
    return listaIdCoordenadas;
}
void LanzadorOperaciones::setObjetoRegistroCnp(RegistroCreateCnps *_regCnp)
{
    _registroCnp=_regCnp;
}

void LanzadorOperaciones::setObjetoRegistroMet(RegistroCreateMet *_regMet)
{
    _registroMet=_regMet;
}
void LanzadorOperaciones::setObjetoRegistroOrto(RegistroCreateOrto *_regOrto)
{
    _registroOrto=_regOrto;
}
void LanzadorOperaciones::setObjetotableCoordinates(TableViewCoordinates *_tableCoor)
{
    _tableCoordinates=_tableCoor;
}

QList <IdentificadorCoordenadas *> LanzadorOperaciones::createIDC()
{
    ModeloCoordenadas *modeloCoor=_tableCoordinates->getModeloCoordenadas();
    IdentificadorCoordenadas *ideOut;
    QList <IdentificadorCoordenadas *> listCoor;
    for(int i=0;i<modeloCoor->rowCount();i++)
    {
        ideOut=new IdentificadorCoordenadas(this);
        ideOut->setIdentificador(modeloCoor->index(i,0).data().toString());
        ideOut->setXa(modeloCoor->index(i,1).data().toFloat());
        ideOut->setXb(modeloCoor->index(i,2).data().toFloat());
        ideOut->setYa(modeloCoor->index(i,3).data().toFloat());
        ideOut->setYb(modeloCoor->index(i,4).data().toFloat());
        listCoor<<ideOut;
    }
    return listCoor;
}

void LanzadorOperaciones::siguienteProceso()
{

}
QList <Operacion *> LanzadorOperaciones::createListadoOperacion()
{
//    QList <IdentificadorCoordenadas *> listCoor= createIDC();
//    foreach (IdentificadorCoordenadas *qVa,listCoor)
//    {
//        //_listadoOperacion.append(new OperacionMet(this,qVa,_dataZone));
//    }
//    foreach (Operacion *ope, _listadoOperacion)
//    {
//        connect(ope,SIGNAL(pasoActualizado(int)),this,SLOT(actualizarBarra(int)));
//        connect(ope,SIGNAL(operacionFallida(QString,int)),this,SLOT(errorOperacion(QString,int)));
//    }

}
QList <Proceso *>  LanzadorOperaciones::createListadoProcesos()
{
    QList <Proceso *> listaProcesos;
    QJsonArray ejecutables;
    ejecutables=_registroMet->getListaEjecutables();
    QJsonObject elementoExe;
    foreach (QJsonValue elemento, ejecutables)
    {
        elementoExe=elemento.toObject();
        //listaProcesos.insert(elementoExe.value("nombre").toString(),elementoExe.value("path").toString());
    }
    return listaProcesos;
}

void LanzadorOperaciones::pasoCnp(int paso)
{
contadorCnp++;
emit pasoCnpActual(contadorCnp);
}

void LanzadorOperaciones::errorCnp(QString error, int paso)
{
 contadorCnp++;
 emit pasoCnpActual(contadorCnp);
 emit sendError(error);
}



