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
#include "opemetfrancia.h"

OpeMetFrancia::OpeMetFrancia(QObject *parent) :
    OperacionMet(parent)
{
    exeResize=QString();
}
void OpeMetFrancia::startOperacion()//virtual
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
    aProyecto=registro.value("ambitoProyecto").toString();
    fOut=registro.value("folderOut").toString();
    exeSScene=registro.value("exeSubScene").toString();
    exeFootPrintMask=registro.value("exeFootPrintMask").toString();
    exeResize=registro.value("exeResize").toString();
    pixel=registro.value("sizePixel").toDouble();
    utm=registro.value("uso").toInt();
    sCut=registro.value("sCut").toInt();
    nCanals=registro.value("nCanals").toInt();
    aPasada=registro.value("aPasada").toInt();
    oPasada=registro.value("oPasada").toInt();
    tabla=registro.value("datosTabla").toList();
    utmDefecto=registro.value("Utm").toInt();
    qDebug()<< sCut << "sCut";
    qDebug()<< nCanals << "nCanals";
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
        QString ficheroSalidaResize=fOut+"/"+identificador+"_Resize.rf";
        ficheroSalidaResize=ficheroSalidaResize.replace("/","\\\\");
        _objetoDatos->setFileResize(ficheroSalidaResize);
        QString ficheroSalidaFootPrintMask=fOut+"/"+identificador+"_FootPrintMask.rf";
        ficheroSalidaFootPrintMask=ficheroSalidaFootPrintMask.replace("/","\\\\");
        _objetoDatos->setFileFootPrintMask(ficheroSalidaFootPrintMask);
        datosEjecucion<<_objetoDatos;

    }

    if (footPrintMask)
    {
        totalPasos=tabla.count()*3;
        recalcularTablaFPM();
        qDebug()<< totalPasos<<"totalPasosFootprintMak";
    }
    else
    {
        totalPasos=tabla.count()*2;
    qDebug()<< totalPasos<<"totalPasos---NO----FootprintMak";
}
    if (cutDtm)
        {
        if (!resDef.isEmpty())
        {
            foreach( QList <CorteMet *> element, resDef)
            {
                foreach(CorteMet * corte,element)
                {
                  delete corte;
                }
            }
}
            resDef=calculoCorte();

            foreach(QList <CorteMet *> element,resDef)
            {
             totalPasos=totalPasos+element.count();
            }

            //calcular los cortes  y sumarlo a total de pasdos
            //lamando al metodo calcular cortes
            qDebug()<< totalPasos<<"totalPasosCutDtm";
        }

    emit inicioProgreso(0,totalPasos+1);
    QString pixelString=QString::number(pixel);
    //    qDebug()<< pixelString+","+pixelString << "pixelpepe";

    proceso.start(exeSScene);
}
void OpeMetFrancia::inicio()//virtual
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
            QString ficheroEntradaResize=datosEjecucion.at(contadorFilas)->getFileSubScene();
            qDebug()<< ficheroEntradaResize <<"ficheroEntradaResize";
            QString ficheroSalidaResize=datosEjecucion.at(contadorFilas)->getFileResize();
            qDebug()<< ficheroSalidaResize <<"ficheroSalidaResize";
            flujo << "1" << endl;
            flujo << "n" << endl;
            flujo << "a" << endl;
            flujo << ficheroEntradaResize << endl;
            flujo << pixel << endl;
            flujo << pixel << endl;
            flujo << ficheroSalidaResize << endl;
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
            QString ficheroEntradaFootPrintMask=datosEjecucion.at(contadorFilas)->getFileResize();
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
            flujo << ficheroEntradaFootPrintMask << endl;
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
            QVariantMap fila=tabla.at(contadorFilas).toMap();
            QString identificador=fila.value("ID").toString();
//            QString ficheroEntradaFootPrintMask=datosEjecucion.at(contadorFilas)->getFileResize();
//            QString ficheroSalidaFootPrintMask=datosEjecucion.at(contadorFilas)->getFileFootPrintMask();
            float este, oeste, norte, sur, xa ,ya ,xb ,yb;
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
            int numeroColumTotal=(este-oeste)/pixel+1;
            qDebug()<< numeroColumTotal << "numeroColumTotal";
            int numeroFilaTotal=(norte-sur)/pixel+1;
            qDebug()<< numeroFilaTotal << "numeroColumTotal";

            qDebug()<< sCut << "sCut";
            qDebug()<< nCanals << "nCanals";
            int filaSup;
            int filaInf;
            int ColumnIz;
            int ColumnDe;
            if(numeroColumTotal < numeroFilaTotal)
            {
                int verticalSize=(sCut*1024*1024)/(4*nCanals*numeroColumTotal);
                float numeroTall=(float)numeroColumTotal/verticalSize;
                numeroTall=(int)ceil(numeroTall);
                int verticalSizeDef=numeroColumTotal/numeroTall;

             int solape=0;
             int incremento=0;
            for(int i=1;i<numeroFilaTotal;i++)
            {
                filaSup=i+incremento-1-solape;
                solape=-10;
                incremento=verticalSizeDef;
                filaInf=verticalSizeDef*i;
                ColumnIz=1;
                ColumnDe=numeroColumTotal;
            }
            }
            if(numeroFilaTotal < numeroColumTotal)
            {
                int horizontalSize=(sCut*1024*1024)/(4*nCanals*numeroFilaTotal);
                int numeroTall= numeroFilaTotal/horizontalSize;
                numeroTall=(int)ceil(numeroTall);
                int horizontalSizeDef=numeroColumTotal/numeroTall;
                filaSup=1;
                filaInf=222222222;
                ColumnIz=1;
                ColumnDe=2222222222222;
            }


            ++contador;
            emit actualizarProgreso(contador);
        }
    }
}


void OpeMetFrancia::fin(int end)//virtual
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
            error.prepend("\n"+identificador+"\n----ERROR ImageResize----\n"+identificador);
            error.append("\n"+identificador+"\n----ERROR ImageResize----\n"+identificador+"\n\n");
        }
        if(procesoQueToca==2)
        {
            error.prepend("\n"+identificador+"\n----ERROR FootPrintMask----\n"+identificador);
            error.append("\n"+identificador+"\n----ERROR FootPrintMask----\n"+identificador+"\n\n");
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
                proceso.start(exeResize);
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
