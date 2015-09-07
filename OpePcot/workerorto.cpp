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
#include "workerorto.h"

WorkerOrto::WorkerOrto(QObject *parent, QList < Proceso*> listaProcesos) :
    Worker(parent, listaProcesos)
{

}
void WorkerOrto::siguienteProceso()
{
    if(_operacionActual->isCompleta() || _operacionActual->isFallida())
    {
        libre=true;
        emit workerLibre();
        return;
    }
    if(contadorProceso<_listaProcesos.count())
    {
        if(contadorProceso==1 && !_operacionActual->getDataZoneProyect()->getFootPrintMask() && _operacionActual->getDataZoneProyect()->getCutDtm())
        {
            _operacionActual->aceptarProceso(_listaProcesos.at(contadorProceso));
            contadorProceso++;
            return;
        }
        if(contadorProceso==1 && !_operacionActual->getDataZoneProyect()->getFootPrintMask())
        {
            _operacionActual->aceptarProceso(_listaProcesos.last());
            contadorProceso++;
            return;
        }

        _operacionActual->aceptarProceso(_listaProcesos.at(contadorProceso));

        contadorProceso++;
    }
    else
        _operacionActual->aceptarProceso(_listaProcesos.last());
}
