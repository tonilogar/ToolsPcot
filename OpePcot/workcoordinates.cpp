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
#include "workcoordinates.h"

WorkCoordinates::WorkCoordinates(QObject *parent, IdentificadorCoordenadas *idecoor) :
    QObject(parent)
{
    _idecoo=idecoor;
    oeste=getCoordenadasOeste(_idecoo);
    este=getCoordenadasEste(_idecoo);
    norte=getCoordenadasNorte(_idecoo);
    sur=getCoordenadasSur(_idecoo);
}

double WorkCoordinates::getCoordenadasEste(IdentificadorCoordenadas *coordenadas)
{
    double xa=coordenadas->getXa();
    double xb=coordenadas->getXb();
    double este;
    if(xa>=xb)
    {
        este=xa;
    }
    else
        este=xb;
    return este;
}

double WorkCoordinates::getCoordenadasOeste(IdentificadorCoordenadas *coordenadas)
{
    double xa=coordenadas->getXa();
    double xb=coordenadas->getXb();
    double oeste;
    if(xa>=xb)
    {
        oeste=xb;
    }
    else
        oeste=xa;
    return oeste;
}

double WorkCoordinates::getCoordenadasNorte(IdentificadorCoordenadas *coordenadas)
{
    double ya=coordenadas->getYa();
    double yb=coordenadas->getYb();
    double norte;
    if(ya>=yb)
    {
        norte=ya;
    }
    else
        norte=yb;
    return norte;
}

double WorkCoordinates::getCoordenadasSur(IdentificadorCoordenadas *coordenadas)
{
    double ya=coordenadas->getYa();
    double yb=coordenadas->getYb();
    double sur;
    if(ya>=yb)
    {
        sur=yb;
    }
    else
        sur=ya;
    return sur;
}

void WorkCoordinates::setIdentificadorCoordenadas(IdentificadorCoordenadas *idecoor)
{
    _idecoo=idecoor;
    oeste=getCoordenadasOeste(_idecoo);
    este=getCoordenadasEste(_idecoo);
    norte=getCoordenadasNorte(_idecoo);
    sur=getCoordenadasSur(_idecoo);
}
