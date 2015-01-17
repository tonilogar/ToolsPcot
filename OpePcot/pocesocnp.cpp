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
#include "pocesocnp.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
PocesoCnp::PocesoCnp(QObject *parent,QString pathProceso) :
    Proceso(parent,pathProceso)
{
}
void PocesoCnp::metodoCnp(Operacion *opCnp )
{
    _libre=false;
    emit procesoOcupado();
    QFile fileCnp(opCnp->getFileDestino());
    QTextStream flujo;
    flujo.setDevice(&fileCnp);
    if(!fileCnp.open(QFile::Text | QFile::WriteOnly))
    {
        opCnp->setFallida("No tienes permisos para crear el cnp");
        _libre=true;
        emit procesoLibre();
        return;
    }
    flujo<< "2,1" << endl;
    flujo<< "1,1 " << opCnp->getidenCoor()->getXa() << " " << opCnp->getidenCoor()->getYa()<< " " << opCnp->getIdentificador() << "_1" << endl;
    flujo<< "1,1 " << opCnp->getidenCoor()->getXb() << " " << opCnp->getidenCoor()->getYb()<< " " << opCnp->getIdentificador() << "_2" << endl;
    fileCnp.close();
    opCnp->incrementarPasos();
    _libre=true;
    emit procesoLibre();
}


