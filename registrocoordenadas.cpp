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
#include "registrocoordenadas.h"

RegistroCoordenadas::RegistroCoordenadas(QObject *parent) :
    QObject(parent)
{
    _identificador=QString();

    //Estos valores a -1, en realidad deben de ser valores
    //que no sean valores validos dentro del sistema
    _xA=-1;
    _yA=-1;
    _xB=-1;
    _yB=-1;
}

RegistroCoordenadas::RegistroCoordenadas(QObject *parent, QString id, double xA, double yA, double xB, double yB)
    : QObject(parent)
{
    _identificador=id;
    _xA=xA;
    _yA=yA;
    _xB=xB;
    _yB=yB;
}
void RegistroCoordenadas::ordenarCoordenadas()
{
  //elegir a que coordenadas corresponden los datos de registrocoordenadas.


}
