//    DepuPcot
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
#include "operacion.h"

Operacion::Operacion(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP) :
    QObject(parent)
{
    _wCoor=new WorkCoordinates(this,idCoor);
    _idCoor=idCoor;
    _dataZP=dataZP;
    contadorpasos=0;
    _totalPasos=0;
    _error=QString();
    fallida=false;
    completo=false;

}
//Getter


QString Operacion::getIdentificador()
{
    return _idCoor->getIdentificador();
}
double Operacion::getEste()
{
    if(_wCoor->getEste()==_wCoor->getOeste())
    {
        return _wCoor->getEste()+3000;
        qDebug()<< "getEste Operacion";
    }
    else
        return _wCoor->getEste();

}
double Operacion::getOeste()
{
    if(_wCoor->getOeste()==_wCoor->getEste())
    {
        return _wCoor->getOeste()-3000;
    }
    else
        return _wCoor->getOeste();
}
double Operacion::getNorte()
{
    if(_wCoor->getNorte()==_wCoor->getSur())
    {
        return _wCoor->getNorte()+3000;
    }
    else
        return _wCoor->getNorte();
}
double Operacion::getSur()
{
    if(_wCoor->getSur()==_wCoor->getNorte())
    {
        return _wCoor->getSur()-3000;
    }
    else
        return _wCoor->getSur();
}
QString Operacion::getFileOrigen()
{
    return QString();
}
QString Operacion::getFileDestino()
{
    return QString();
}
QString Operacion::getFileCnpOrigen()
{
    return QString();
}
int Operacion::totalPasos()
{
    return _totalPasos;
}
int Operacion::pasoActual()
{
    return contadorpasos;
}
/*!
 * incrementarPasos.
 * Sumo 1 a contadorpasos
 * emito la senyal pasoActualizado con el valor de contadorpasos, este SIGNAL esta connectado con el SLOT actualizarBarra
 * de la clase mainindows
 * Si contadorpasos>=_totalPasos el atributo completo es true y emito el SIGNAL operacionCompleta
 */
void Operacion::incrementarPasos()
{
    contadorpasos++;
    emit pasoActualizado(contadorpasos);
    if(contadorpasos>=_totalPasos)
    {
        completo=true;
        emit operacionCompleta();
    }
}
IdentificadorCoordenadas* Operacion::getidenCoor()
{
    return _idCoor;
}

/*!
 * setFallida.
 * Si la variable fallida es true creo una variable entera "pasos"
 * que es igual a la resta de _totalPasos-contadorpasos
 * Emito el SIGNAL operacionFallida con los parametros de QString error y un entero indicand el paso en que se creo el error
 * El SIGNAL operacionFallida esta conectado con el SLOT errorOperacion de la clase mainWindows
 */
void Operacion::setFallida(QString error)
{
    _error=error;
    fallida=true;
    int pasos=_totalPasos-contadorpasos;
    emit operacionFallida(_error, pasos);
}
bool Operacion::isFallida()
{
    return fallida;
}
bool Operacion::isCompleta()
{
    return completo;
}
/*!
 * resetOperation.
 * Doy valores por defecto a los atributos
 *
 */
void Operacion::resetOperation()
{
    contadorpasos=0;
    _error=QString();
    fallida=false;
    completo=false;
}
