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
#include "identificadorcoordenadas.h"

IdentificadorCoordenadas::IdentificadorCoordenadas(QObject *parent) :
    QObject(parent)
{
    _identificador=QString();

    //Estos valores a -1, en realidad deben de ser valores
    //que no sean valores validos dentro del sistema
    _xa=-1;
    _ya=-1;
    _xb=-1;
    _yb=-1;
}
IdentificadorCoordenadas::IdentificadorCoordenadas(QObject *parent, QString identificador,double xa,
                                                   double ya,double xb, double yb)
{
    _identificador=identificador;
    _xa=xa;
    _ya=ya;
    _xb=xb;
    _yb=yb;
}

//Getter
QString IdentificadorCoordenadas::getIdentificador()
{
    return _identificador;
}
double IdentificadorCoordenadas::getXa()
{
    return _xa;
}
double IdentificadorCoordenadas::getYa()
{
    return _ya;
}
double IdentificadorCoordenadas::getXb()
{
    return _xb;
}
double IdentificadorCoordenadas::getYb()
{
    return _yb;
}

//Setter
void IdentificadorCoordenadas::setIdentificador(QString identificador)
{
    _identificador=identificador;
}
void IdentificadorCoordenadas::setXa(double xa)
{
    _xa=xa;
}
void IdentificadorCoordenadas::setYa(double ya)
{
    _ya=ya;
}
void IdentificadorCoordenadas::setXb(double xb)
{
    _xb=xb;
}
void IdentificadorCoordenadas::setYb(double yb)
{
    _yb=yb;
}
