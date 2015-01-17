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
#include "proceso.h"
#include "operacion.h"
Proceso::Proceso(QObject *parent,QString pathProceso) :
    QObject(parent)
{
    _libre=true;
    _pathProceso=pathProceso;
    _flujo.setDevice(&_proceso);
    connect(&_proceso,SIGNAL(started()),this,SLOT(procesoIniciado()));
    connect(&_proceso,SIGNAL(finished(int)),this,SLOT(procesoTerminado(int)));
}
void Proceso::procesoIniciado()
{
    qDebug()<< "procesoIniciado";
}

void Proceso::procesoTerminado(int fin)
{

qDebug()<< "procesoTerminado";
}
bool Proceso::isLibre()
{
    return _libre;
}
void Proceso::kill()
{
    if(_proceso.state()!=QProcess::NotRunning)
    {
       _proceso.kill();

    }

}
