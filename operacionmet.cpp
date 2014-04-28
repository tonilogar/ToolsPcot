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
#include "operacionmet.h"
#include <QDebug>
OperacionMet::OperacionMet(QObject *parent) :
    OperacionBase(parent)
{
    zProyecto=QString();
    aProyecto=QString();
    exeSScene=QString();
    exeImaOpeGeo=QString();
    exeFootPrintMask=QString();
    utmDefecto=0;
    fOut=QString();
    tabla=QVariantList();
    controlOperacion=false;
    pixel=0;
    utm=0;
    sCut=0;
    nCanals=0;
    aPasada=0;
    oPasada=0;
    footPrintMask=false;
    cutDtm=false;
    datosEjecucion=QList<OmetDatosEjecucion*>();
}
void OperacionMet::startOperacion()//virtual
{
    foreach (OmetDatosEjecucion *element,datosEjecucion)
    {
        delete element;
    }
    datosEjecucion.clear();
    contadorFilas=0;
    procesoQueToca=0;
    //qDebug() << registro << "registro---------------------------------";
    controlOperacion=true;
    zProyecto=registro.value("zonaProyecto").toString();
    qDebug()<< zProyecto << "zProyectopppppppppppppppppp";
    aProyecto=registro.value("ambitoProyecto").toString();
    fOut=registro.value("folderOut").toString();
    exeSScene=registro.value("exeSubScene").toString();
    exeImaOpeGeo=registro.value("exeImaOpeGeo").toString();
    exeFootPrintMask=registro.value("exeFootPrintMask").toString();
    pixel=registro.value("sizePixel").toDouble();
    utm=registro.value("uso").toInt();
    sCut=registro.value("sCut").toInt();
    nCanals=registro.value("nCanals").toInt();
    aPasada=registro.value("aPasada").toInt();
    oPasada=registro.value("oPasada").toInt();
    tabla=registro.value("datosTabla").toList();
    utmDefecto=registro.value("Utm").toInt();

    //recalcular coordenadas de tabla
    footPrintMask=registro.value("FootPrintMask",QVariant(false)).toBool();
    cutDtm=registro.value("CutDtm",QVariant(false)).toBool();

    int line=tabla.count();
    for (int i=0;i<line;i++)
    {
        OmetDatosEjecucion *_objetoDatos=new OmetDatosEjecucion(this);
        QVariantMap fila =tabla.at(i).toMap();
        QString identificador=fila.value("ID").toString();
        QString ficheroSalidaSub=fOut+"/"+identificador+"_SubScene.rf";
        ficheroSalidaSub=ficheroSalidaSub.replace("/","\\\\");
        _objetoDatos->setFileSubScene(ficheroSalidaSub);

        QString ficheroSalidaOpeGeo=fOut+"/"+identificador+"_ImageOpeGeo.rf";
        ficheroSalidaOpeGeo=ficheroSalidaOpeGeo.replace("/","\\\\");
        _objetoDatos->setFileOpegeo(ficheroSalidaOpeGeo);

        QString ficheroSalidaFootPrintMask=fOut+"/"+identificador+"_FootPrintMask.rf";
        ficheroSalidaFootPrintMask=ficheroSalidaFootPrintMask.replace("/","\\\\");
        _objetoDatos->setFileFootPrintMask(ficheroSalidaFootPrintMask);

        QString ficheroSalidaCutDtm=fOut+"/"+identificador+"_%1.rf";
        ficheroSalidaCutDtm=ficheroSalidaCutDtm.replace("/","\\\\");
        _objetoDatos->setFileCutDtm(ficheroSalidaCutDtm);
        datosEjecucion<<_objetoDatos;
    }

    if (footPrintMask)
    {
        totalPasos=tabla.count()*3;
        recalcularTablaFPM();
    }
    else
        totalPasos=tabla.count()*2;
    emit inicioProgreso(0,totalPasos+1);
    QString pixelString=QString::number(pixel);
    //    qDebug()<< pixelString+","+pixelString << "pixelpepe";
    proceso.start(exeSScene);
}
void OperacionMet::inicio()//virtual
{
    if (controlOperacion)
    {
        if (procesoQueToca==0)
        {
            QVariantMap fila=tabla.at(contadorFilas).toMap();
            QString identificador=fila.value("ID").toString();
            float este, oeste, norte, sur, xa ,ya ,xb ,yb;
            QString ficheroSalidaSubScene=datosEjecucion.at(contadorFilas)->getFileSubScene();
            //QString timeStamp=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
            xa=fila.value("Xa").toFloat();
            xb=fila.value("Xb").toFloat();
            ya=fila.value("Ya").toFloat();
            yb=fila.value("Yb").toFloat();
            if(xa==xb || xa>xb)
            {
                este=xa;
                oeste=xb;
            }
            else
            {
                oeste=xa;
                este=xb;
            }
            if(ya==yb || ya>yb)
            {
                norte=ya;
                sur=yb;
            }
            else
            {
                sur=ya;
                norte=yb;
            }
            flujo << aProyecto << endl;
            flujo << "s" << endl;
            flujo << "n" << endl;
            flujo << oeste << " " << este << " "<< norte << " "<< sur << " " << endl;
            flujo << "n" << endl;
            flujo << "n" << endl;
            flujo << ficheroSalidaSubScene << endl;
            flujo << endl;
            ++contador;
            emit actualizarProgreso(contador);
        }
        if (procesoQueToca==1)
        {

            QVariantMap fila=tabla.at(contadorFilas).toMap();
            QString identificador=fila.value("ID").toString();
            QString ficheroEntradaOpeGeo=datosEjecucion.at(contadorFilas)->getFileSubScene();
            QString ficheroSalidaImOpGe=datosEjecucion.at(contadorFilas)->getFileOpegeo();
            flujo << ficheroEntradaOpeGeo << endl;
            flujo << "1"<< endl;
            flujo << "n"<< endl;
            flujo << "a"<< endl;
            flujo << ficheroEntradaOpeGeo << endl;
            flujo << pixel << endl;
            flujo << pixel << endl;
            flujo << ficheroSalidaImOpGe << endl;
            ++contador;
            emit actualizarProgreso(contador);
        }
        if (procesoQueToca==2)
        {
            /*Si el utm cambia respecto al utm del proyecto por defecto tengo que cambiar las coordenadas
            con IcccoordinatesTransformation
            \\Empuries\PRODUCCIO\DFApplications\ICCGeoOperations\exe\ICCCoordinatesTransformation.exe
*/
            QVariantMap fila=tabla.at(contadorFilas).toMap();
            QString identificador=fila.value("ID").toString();
            QString ficheroEntradaFootPM=datosEjecucion.at(contadorFilas)->getFileOpegeo();
            QString ficheroSalidaFootPrintMask=datosEjecucion.at(contadorFilas)->getFileFootPrintMask();
            float xaOrigen ,yaOrigen ,xbOrigen ,ybOrigen;
            xaOrigen=fila.value("XaOrigen").toFloat();
            xbOrigen=fila.value("XbOrigen").toFloat();
            yaOrigen=fila.value("YaOrigen").toFloat();
            ybOrigen=fila.value("YbOrigen").toFloat();
            QString ficheroSalidaCnp=fOut+"/"+identificador+".cnp";
            QFileInfo folderOutQfileCnp(ficheroSalidaCnp);
            QFile ficheroCnp(ficheroSalidaCnp);
            ficheroCnp.open(QIODevice::Text | QIODevice::ReadWrite);
            QTextStream outPathCnp(&ficheroCnp);
            outPathCnp << "2,1"<< endl;
            outPathCnp << "1,1 "<< xaOrigen <<"  "<< yaOrigen <<"  "<< identificador+"_1" <<  endl;
            outPathCnp << "1,1 "<< xbOrigen <<"  "<< ybOrigen <<"  "<< identificador+"_2" <<  endl;
            ficheroCnp.close();
            flujo << ficheroEntradaFootPM << endl;
            flujo << ficheroSalidaCnp << endl;
            flujo << ficheroSalidaFootPrintMask << endl;
            flujo << "1" << endl;
            flujo << aPasada << endl;
            flujo << oPasada << endl;
            ++contador;
            emit actualizarProgreso(contador);
        }
        if (procesoQueToca==3)
        {

        }
    }
}

void OperacionMet::fin(int end)//virtual
{
    //qDebug()<< registro.value("sizePixel").toInt() << "-----sizepixel";
    QVariantMap fila=tabla.at(contadorFilas).toMap();
    QString identificador;
    identificador=fila.value("ID").toString();
    if (end!=0)
    {
        //Si el mensaje que emite el iccimageSubscene al acabar es diferente de 0
        QString error=registro.value("ultimasalida").toString();
        if(procesoQueToca==0)
        {
            error.prepend("\n"+identificador+"\n----ERROR CutSubScene----\n"+identificador);
            error.append("\n"+identificador+"\n----ERROR CutSubScene----\n"+identificador+"\n\n");
        }
        if(procesoQueToca==1)
        {
            error.prepend("\n"+identificador+"\n----ERROR ImageOperaGeo----\n"+identificador);
            error.append("\n"+identificador+"\n----ERROR ImageOperaGeo----\n"+identificador+"\n\n");
        }
        if(procesoQueToca==2)
        {
            error.prepend("\n"+identificador+"\n----ERROR FootPrintMask----\n"+identificador);
            error.append("\n"+identificador+"\n----ERROR ImageOperaGeo----\n"+identificador+"\n\n");
        }
        emit errorProgreso(error);
        qDebug() << "ultimasalida---------------" << error << "ultimasalida---------------";
    }

    if (contador<totalPasos && controlOperacion)
    {
        if(end!=0)
        {
            contadorFilas++;
            procesoQueToca=0;
            if(proceso.state()!=QProcess::NotRunning) {
                qDebug() << "WARNING: Proceso anterior (-) funcionando, esperando a terminar...";
                proceso.waitForFinished();
                qDebug() << "TERMINADO!";
            }
            proceso.start(exeSScene);
            qDebug() << procesoQueToca << "procesoQueToca" << footPrintMask << "footPrintMask " << cutDtm << "cutDtm" << "exeSScene-Error";
        }
        else {

            switch(procesoQueToca) {
            case 0:
                procesoQueToca=1;
                if(proceso.state()!=QProcess::NotRunning) {
                    qDebug() << "WARNING: Proceso (0) funcionando, esperando a terminar...";
                    proceso.waitForFinished();
                    qDebug() << "TERMINADO!";
                }
                proceso.start(exeImaOpeGeo);
                qDebug() << procesoQueToca << "procesoQueToca" << footPrintMask << "footPrintMask " << cutDtm << "cutDtm" << "exeImaOpeGeo";
                break;
            case 1:
                if(!footPrintMask) {
                    procesoQueToca=0;
                    contadorFilas++;
                    if(proceso.state()!=QProcess::NotRunning) {
                        qDebug() << "WARNING: Proceso (1) funcionando, esperando a terminar...";
                        proceso.waitForFinished();
                        qDebug() << "TERMINADO!";
                    }
                    proceso.start(exeSScene);
                    qDebug() << procesoQueToca << "procesoQueToca" << footPrintMask << "footPrintMask " << cutDtm << "cutDtm" << "exeImaOpeGeo";

                }
                else {
                    procesoQueToca=2;
                    if(proceso.state()!=QProcess::NotRunning) {
                        qDebug() << "WARNING: Proceso (1) funcionando, esperando a terminar...";
                        proceso.waitForFinished();
                        qDebug() << "TERMINADO!";
                    }
                    proceso.start(exeFootPrintMask);
                    qDebug() << procesoQueToca << "procesoQueToca" << footPrintMask << "footPrintMask " << cutDtm << "cutDtm" << "exeImaOpeGeo";

                }
                break;
            case 2:
                procesoQueToca=0;
                contadorFilas++;
                if(proceso.state()!=QProcess::NotRunning) {
                    qDebug() << "WARNING: Proceso (2) funcionando, esperando a terminar...";
                    proceso.waitForFinished();
                    qDebug() << "TERMINADO!";
                }
                proceso.start(exeSScene);
                qDebug() << procesoQueToca << "procesoQueToca" << footPrintMask << "footPrintMask " << cutDtm << "cutDtm" << "exeImaOpeGeo";

                break;
            default:
                break;
            }
        }

    }
    else
    {
        controlOperacion=false;
        emit finProgreso();
    }

}
void OperacionMet::cancelarOperacion()//virtual
{
    if (controlOperacion)
    {

        controlOperacion=false;
        if(proceso.state()!=QProcess::NotRunning)
        {
            proceso.kill();
        }
    }
}

void OperacionMet::recalcularTablaFPM()
{
    QVariantList nuevaTabla;
    foreach (QVariant element, tabla)
    {
        qDebug()<< "metodo magico";
        QVariantMap fila=element.toMap();
        QVariantMap nuevaFila;

        QVariant id=fila.value("ID");
        nuevaFila.insert("ID",id);
        qDebug()<<id << "id";
        float esteF, oesteF, norteF, surF, xa ,ya ,xb ,yb, xaOrigen ,yaOrigen ,xbOrigen ,ybOrigen;
        xa=fila.value("Xa").toFloat();
        xb=fila.value("Xb").toFloat();
        ya=fila.value("Ya").toFloat();
        yb=fila.value("Yb").toFloat();
        xaOrigen=xa;
        yaOrigen=ya;
        xbOrigen=xb;
        ybOrigen=yb;
        if(xa==xb || xa>xb)
        {
            esteF=xa+(pixel*400);
            oesteF=xb-(pixel*400);
            xa=esteF;
            xb=oesteF;
        }
        else
        {
            oesteF=xa-(pixel*400);
            esteF=xb+(pixel*400);
            xa=oesteF;
            xb=esteF;
        }
        if(ya==yb || ya>yb)
        {
            norteF=ya+(pixel*400);
            surF=yb-(pixel*400);
            ya=norteF;
            yb=surF;
        }
        else
        {
            surF=ya-(pixel*400);
            norteF=yb+(pixel*400);
            ya=surF;
            yb=norteF;
        }

        qDebug()<< oesteF <<"oesteF";
        qDebug()<< esteF <<"esteF";
        qDebug()<< norteF <<"norteF";
        qDebug()<< surF <<"surF";

        nuevaFila.insert("Xa",xa);
        nuevaFila.insert("Ya",ya);
        nuevaFila.insert("Xb",xb);
        nuevaFila.insert("Yb",yb);
        nuevaFila.insert("XaOrigen",xaOrigen);
        nuevaFila.insert("YaOrigen",yaOrigen);
        nuevaFila.insert("XbOrigen",xbOrigen);
        nuevaFila.insert("YbOrigen",ybOrigen);

        QString oeste;
        oeste.setNum (oesteF, 'f');
        nuevaFila.insert("Oeste",oeste);


        QString este;
        este.setNum (esteF, 'f');
        nuevaFila.insert("Este",este);

        QString norte;
        norte.setNum (norteF, 'f');
        nuevaFila.insert(("Norte"),norte);

        QString sur;
        sur.setNum (surF, 'f');
        nuevaFila.insert("Sur",sur);

        nuevaTabla.append(nuevaFila);
    }
    tabla.clear();
    tabla=nuevaTabla;

}


QList <QList<CorteMet *> > OperacionMet::calculoCorte()
{
    qDebug()<< tabla <<"empiezo el metodo calculocorte";
    QList <QList <CorteMet *> > res;
    int index=0;
    foreach (QVariant entrada, tabla)
    {
     qDebug()<< tabla.count() <<"tabla.count() empiezo el metodo calculocorte";
     qDebug()<< entrada <<"entrada empiezo el metodo calculocorte";
        QVariantMap fila=entrada.toMap();
        QString identificador=fila.value("ID").toString();
        float este, oeste, norte, sur, xa ,ya ,xb ,yb;
        qDebug()<< identificador << "empiezo el metodo calculocorte";
        xa=fila.value("Xa").toFloat();
        xb=fila.value("Xb").toFloat();
        ya=fila.value("Ya").toFloat();
        yb=fila.value("Yb").toFloat();
        if(xa==xb || xa>xb)
        {
            este=xa;
            oeste=xb;
        }
        else
        {
            oeste=xa;
            este=xb;
        }
        if(ya==yb || ya>yb)
        {
            norte=ya;
            sur=yb;
        }
        else
        {
            sur=ya;
            norte=yb;
        }

        QList<CorteMet *>  cortesFila=calculaCorteFila(identificador,este,oeste,norte,sur,datosEjecucion[index++]);
        res<<cortesFila;
    }
    return res;
}

QList <CorteMet *> OperacionMet::calculaCorteFila(QString ident,int este,int oeste,int norte,int sur,OmetDatosEjecucion* datosEje)
{
    QList <CorteMet *>  datosCorte;

    int numeroColumTotal=(este-oeste)/pixel+1;
    qDebug()<< numeroColumTotal << "numeroColumTotal";
    int numeroFilaTotal=(norte-sur)/pixel+1;
    qDebug()<< numeroFilaTotal << "numeroFilaTotal";

    qDebug()<< sCut << "sCut";
    qDebug()<< nCanals << "nCanals";
    int filaSup;
    int filaInf;
    int ColumnIz;
    int ColumnDe;
    if(numeroColumTotal < numeroFilaTotal)
    {
        int verticalSize=(sCut*1024*1024)/(4*nCanals*numeroColumTotal);
        float numeroTall=(float)numeroFilaTotal/verticalSize;
        numeroTall=(int)ceil(numeroTall);
        int verticalSizeDef=numeroFilaTotal/numeroTall;
        qDebug()<< numeroColumTotal << "numeroColumTotal";
        qDebug()<< verticalSize << "verticalSize";
        qDebug()<< numeroTall << "numeroTall int ceil";
        qDebug()<< verticalSizeDef << "verticalSizeDef";
        int solape=0;
        int incremento=0;
        int resta=0;
        int x=0;
        for(int i=1;i <= numeroTall;i++)
        {
            CorteMet *_datos=new CorteMet();
            qDebug()<< incremento << "incremento";
            qDebug()<< i << "iiiiiiiiiiiiiiiiiiiii";
            filaSup=incremento*x+1-solape-resta;
            qDebug()<< filaSup << "filaSup01";
            qDebug()<< incremento << "incremento";
            x++;
            solape=10;
            resta=1;
            incremento=verticalSizeDef;
            if(i==numeroTall)
            {
             qDebug()<< "i==numeroTall";
            filaInf=numeroFilaTotal;
            }
            else
            {
                qDebug()<< "i!=numeroTall";
            filaInf=verticalSizeDef*i;
            }
            qDebug()<< filaInf << "filaInf";
            ColumnIz=1;
            ColumnDe=numeroColumTotal;
            _datos->setFilaSup(filaSup);
            _datos->setFilaInf(filaInf);
            _datos->setColumnIz(ColumnIz);
            _datos->setColumnDer(ColumnDe);
            if (footPrintMask)
            {
                _datos->setNombreFileIn(datosEje->getFileFootPrintMask());
                _datos->setNombreFileOut(datosEje->getFileCutDtm());
            }
            else
            {
                _datos->setNombreFileIn(datosEje->getFileResize());
                _datos->setNombreFileOut(datosEje->getFileCutDtm());
            }
            datosCorte<<_datos;
        }
        return datosCorte;
    }
    if(numeroFilaTotal < numeroColumTotal)
    {
        int horizontalSize=(sCut*1024*1024)/(4*nCanals*numeroFilaTotal);
        float numeroTall=(float)numeroColumTotal/horizontalSize;
        numeroTall=(int)ceil(numeroTall);
        int horizontalSizeDef=numeroColumTotal/numeroTall;
        qDebug()<< numeroFilaTotal << "numeroFilaTotal";
        qDebug()<< horizontalSize << "horizontalSize";
        qDebug()<< numeroTall << "numeroTall";
        qDebug()<< horizontalSizeDef << "horizontalSizeDef";
        int solape=0;
        int incremento=0;
        int resta=0;
        int x=0;
        for(int i=1;i <= numeroTall;i++)
        {
            CorteMet *_datos=new CorteMet();
            qDebug()<< incremento << "incremento";
            qDebug()<< i << "iiiiiiiiiiiiiiiiiiiii";
            ColumnIz=incremento*x+1-solape-resta;
            qDebug()<< ColumnIz << "ColumnIz";
            qDebug()<< incremento << "incremento";

            x++;
            solape=10;
            resta=1;
            incremento=horizontalSizeDef;

            if(i==numeroTall)
            {
             qDebug()<< "i==numeroTall";
            ColumnDe=numeroColumTotal;
            }
            else
            {
                qDebug()<< "i!=numeroTall";
            ColumnDe=horizontalSizeDef*i;
            }
            qDebug()<< ColumnIz << "ColumnIz";
            qDebug()<< ColumnDe << "ColumnDe";
            filaSup=1;
            filaInf=numeroFilaTotal;
            _datos->setFilaSup(filaSup);
            _datos->setFilaInf(filaInf);
            _datos->setColumnIz(ColumnIz);
            _datos->setColumnDer(ColumnDe);
            if (footPrintMask)
            {
                _datos->setNombreFileIn(datosEje->getFileFootPrintMask());
                _datos->setNombreFileOut(datosEje->getFileCutDtm());
            }
            else
            {
                _datos->setNombreFileIn(datosEje->getFileResize());
                _datos->setNombreFileOut(datosEje->getFileCutDtm());
            }
             datosCorte<<_datos;
        }
        return datosCorte;

    }
}



