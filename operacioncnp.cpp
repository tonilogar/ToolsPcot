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
#include "operacioncnp.h"
#include <QDebug>
OperacionCnp::OperacionCnp(QObject *parent):
    OperacionBase(parent)
{
    fOut=QString();
    tabla=QVariantList();
    controlOperacion=false;
}

void OperacionCnp::inicio()//virtual
{
}

void OperacionCnp::fin(int end)//virtual
{

}
void OperacionCnp::startOperacion()//virtual
{
    fOut=registro.value("folderOut").toString();
    tabla=registro.value("datosTabla").toList();
    emit inicioProgreso(0,tabla.count());
    QString ficheroSalida;
    QString identificador;
    float xa,ya,xb,yb;
    QString timeStamp=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    QString ficheroTotal=fOut+"/allWpoints"+timeStamp+".cnp";
    QFileInfo folderAllQfileCnp(ficheroTotal);
    QFile ficheroAllCnp(ficheroTotal);
    ficheroAllCnp.open(QIODevice::Text | QIODevice::ReadWrite);
    QTextStream outPathAllCnp(&ficheroAllCnp);
    //int numberWPoints=tabla.count()
    outPathAllCnp << (tabla.count())*2 <<",1"<< endl;
    foreach (QVariant line, tabla)
    {
        QVariantMap fila=tabla.at(contador).toMap();
        identificador=fila.value("ID").toString();
        xa=fila.value("Xa").toFloat();
        ya=fila.value("Ya").toFloat();
        xb=fila.value("Xb").toFloat();
        yb=fila.value("Yb").toFloat();
        ficheroSalida=fOut+"/"+identificador+".cnp";
        QFileInfo folderOutQfileCnp(ficheroSalida);
        QFile ficheroCnp(ficheroSalida);
        ficheroCnp.open(QIODevice::Text | QIODevice::ReadWrite);
        QTextStream outPathCnp(&ficheroCnp);
        outPathAllCnp << "1,1 "<< xa <<"  "<< ya <<"  "<< identificador+"_1" <<  endl;
        outPathAllCnp << "1,1 "<< xb <<"  "<< yb <<"  "<< identificador+"_2" <<  endl;
        outPathCnp << "2,1"<< endl;
        outPathCnp << "1,1 "<< xa <<"  "<< ya <<"  "<< identificador+"_1" <<  endl;
        outPathCnp << "1,1 "<< xb <<"  "<< yb <<"  "<< identificador+"_2" <<  endl;
        ficheroCnp.close();
        ++contador;
        emit actualizarProgreso(contador);
    }
    ficheroAllCnp.close();
    controlOperacion=false;
    emit finProgreso();
    qDebug()<< "finProceso";
}

void OperacionCnp::cancelarOperacion()//virtual
{
    if (controlOperacion)
    {//colocar
        controlOperacion=false;
        if(proceso.state()!=QProcess::NotRunning)
        {
            proceso.kill();
        }
        tabla.clear();
        fOut.clear();
        registro.clear();
        contador=0;

    }
}




