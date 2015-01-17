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
#include "operacioncnp.h"
#include "proceso.h"
#include <QDebug>
OperacionCnp::OperacionCnp(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP) :
    Operacion(parent,idCoor,dataZP)
{
    _totalPasos=1;

}

void OperacionCnp::aceptarProceso(Proceso *p)
{
 p->metodoCnp(this);
}

QString OperacionCnp::getFileDestino()
{
    QString path= _dataZP->getFolderOut();
    QString nameFile=_idCoor->getIdentificador();
    QString fileDestino=path+"\\"+nameFile+".cnp";
    return fileDestino;
}

