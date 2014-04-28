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
#include "operacionorto.h"

OperacionOrto::OperacionOrto(QObject *parent) :
    OperacionBase(parent)
{
    aProyecto=QString();
    exeSScene=QString();
    fOut=QString();
    tabla=QVariantList();
    controlOperacion=false;
}

void OperacionOrto::inicio()//virtual
{
    if (controlOperacion)
    {
QString ficheroSalida;
QVariantMap fila=tabla.at(contador).toMap();
QString identificador;
float oeste, este, norte, sur;
QString timeStamp=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");

identificador=fila.value("Id").toString();
oeste=fila.value("Oeste").toFloat();
este=fila.value("Este").toFloat();
norte=fila.value("Norte").toFloat();
sur=fila.value("Sur").toFloat();
flujo << aProyecto << endl;
//    flujo << "s" << endl;
//    flujo << "n" << endl;
flujo << oeste << " " << este << " "<< norte << " "<< sur << " " << endl;
//    flujo << "n" << endl;
//    flujo << "n" << endl;
ficheroSalida=fOut+"/"+identificador+timeStamp+"_Orto.rf";
flujo << ficheroSalida.replace("/","\\\\") << endl;
flujo << endl;
++contador;
emit actualizarProgreso(contador);
    }
}

void OperacionOrto::fin(int end)//virtual
{
    if (end!=0 && controlOperacion)
    {
        //Si el mensaje que emite el iccimageSubscene al acabar es diferente de 0
        //Se emite el signal errorProgreso que ejecuta el slot tratarErrores

        QString errorOrto=registro.value("ultimasalida").toString();

        errorOrto.prepend("\n----ERROR ORTO----\n");
        errorOrto.append("\n----ERROR ORTO----\n");

        emit errorProgreso(errorOrto);
        qDebug() << "ultimasalida---------------" << errorOrto << "ultimasalida---------------";
    }

    if (contador<tabla.count() && controlOperacion)
    {
        proceso.start(exeSScene);
        qDebug() << exeSScene << "exeSScene---------------------------------";
    }
    else
    {
        controlOperacion=false;
        emit finProgreso();
    }

}
void OperacionOrto::startOperacion()//virtual
{
    controlOperacion=true;
    aProyecto=registro.value("ambitoProyecto").toString();
    fOut=registro.value("folderOut").toString();
    exeSScene=registro.value("exeSubScene").toString();
    tabla=registro.value("datosTabla").toList();
    emit inicioProgreso(0,tabla.count());
    qDebug() << exeSScene << "exeSScene---------------------------------";
    proceso.start(exeSScene);
}
void OperacionOrto::cancelarOperacion()//virtual
{
    if (controlOperacion)
    {
        controlOperacion=false;
        if(proceso.state()!=QProcess::NotRunning)
        {
         proceso.kill();
        }
       tabla.clear();
       aProyecto.clear();
       fOut.clear();
       registro.clear();
       contador=0;
    }
}






