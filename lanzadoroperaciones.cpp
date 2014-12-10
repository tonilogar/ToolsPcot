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
#include "lanzadoroperaciones.h"
#include <QDateTime>

LanzadorOperaciones::LanzadorOperaciones(QObject *parent, RegistroCreateCnps *_regCnp,RegistroCreateMet  *_regMet,
                                         RegistroCreateOrto *_regOrto,TableViewCoordinates *_tableCoor ) :
    QObject(parent)
{
    _registroCnp=_regCnp;
    _registroMet=_regMet;
    _registroOrto=_regOrto;
    _tableCoordinates=_tableCoor;
    _dialogoProgreso=new DialogProgresoOpe();
    _cnpActivo=false;
    _metActivo=false;
    _ortoActivo=false;
    _Wcnp=0;
    _WMet=0;
    _WOrto=0;
    _dataZoneCnp=new DataZoneProject(this);
    _dataZoneMet=new DataZoneProject(this);
    _dataZoneOrto=new DataZoneProject(this);
    _controlCnp=new ControlWorker(this);
    _controlMet=new ControlWorker(this);
    _controlOrto=new ControlWorker(this);    
   _dialogoProgreso->conectToControlCnp(_controlCnp);
   _dialogoProgreso->conectToControlMet(_controlMet);
   _dialogoProgreso->conectToControlOrto(_controlOrto);
   _dialogoProgreso->visibleClose(false);
   connect(_controlCnp,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(disableCancelCnp()));
   connect(_controlMet,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(disableCancelMet()));
   connect(_controlOrto,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(disableCancelOrto()));
   connect(_controlCnp,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(setCnpEnd()));
   connect(_controlMet,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(setMetEnd()));
   connect(_controlOrto,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(setOrtoEnd()));

   connect(_controlCnp,SIGNAL(enviarError(QString)),_dialogoProgreso,SLOT(sowErrors(QString)));
   connect(_controlMet,SIGNAL(enviarError(QString)),_dialogoProgreso,SLOT(sowErrors(QString)));
   connect(_controlOrto,SIGNAL(enviarError(QString)),_dialogoProgreso,SLOT(sowErrors(QString)));


}

void LanzadorOperaciones::setObjetoRegistroCnp(RegistroCreateCnps *_regCnp)
{
    _registroCnp=_regCnp;
}

void LanzadorOperaciones::setObjetoRegistroMet(RegistroCreateMet *_regMet)
{
    _registroMet=_regMet;
}
void LanzadorOperaciones::setObjetoRegistroOrto(RegistroCreateOrto *_regOrto)
{
    _registroOrto=_regOrto;
}
void LanzadorOperaciones::setObjetotableCoordinates(TableViewCoordinates *_tableCoor)
{
    _tableCoordinates=_tableCoor;
}
void LanzadorOperaciones::createListadoOperacionCnp()
{
     _dialogoProgreso->visibleCnp(true);
    borrarListadoOperacion(_listadoOperacionCnp);
    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    {
        _listadoOperacionCnp.append(new OperacionCnp(this,qVa,_dataZoneCnp));
    }
}

void LanzadorOperaciones::createListadoOperacionMet()
{
    _dialogoProgreso->visibleMet(true);
    borrarListadoOperacion(_listadoOperacionMet);

    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    {
        _listadoOperacionMet.append(new OperacionMet(this,qVa,_dataZoneMet));
    }
}

void LanzadorOperaciones::createListadoOperacionOrto()
{
    _dialogoProgreso->visibleOrto(true);
    borrarListadoOperacion(_listadoOperacionOrto);
    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    {
        _listadoOperacionOrto.append(new OperacionOrto(this,qVa,_dataZoneOrto));
    }
}

void LanzadorOperaciones::setCnpActivo(bool cnpActivo)
{
    _cnpActivo=cnpActivo;
}

void LanzadorOperaciones::setMetActivo(bool metActivo)
{
    _metActivo=metActivo;
}

void LanzadorOperaciones::setOrtoActivo(bool ortoActivo)
{
    _ortoActivo=ortoActivo;
}

bool LanzadorOperaciones::getCnpActivo()
{
    return _cnpActivo;
}

bool LanzadorOperaciones::getMetActivo()
{
    return _metActivo;
}

bool LanzadorOperaciones::getOrtoActivo()
{
    return _ortoActivo;
}
void LanzadorOperaciones::launch()
{
    if(_cnpActivo || _metActivo || _ortoActivo)
    {
        foreach (IdentificadorCoordenadas *ide, _listaIdentificadores)
        {
            delete ide;
        }
        _listaIdentificadores.clear();
        crearListaIdentificadores();
        if(_cnpActivo)
        {
            //Mantener el orden de creacion de nuevoWorker porque
            //el metodo setWorker intenta desconectar el worker antiguo.
            QList <Proceso *> p;
            p<< new PocesoCnp(this,QString());
            Worker *nuevoWorker=new Worker(this,p);
            _controlCnp->setWorker(nuevoWorker);
            if(_Wcnp)
            delete _Wcnp;
            _Wcnp=nuevoWorker;
            _registroCnp->buildDataZoneProject(_dataZoneCnp);
            createListadoOperacionCnp();
            _controlCnp->setListaOperaciones(_listadoOperacionCnp);
            _controlCnp->start();
        }
        else
            _dialogoProgreso->cnpEnd();
        if (_metActivo)
        {
            _registroMet->buildDataZoneProject(_dataZoneMet);
                QMap <QString, QString> _qMapEjecutables;
                _qMapEjecutables=_registroMet->getMapExe();
                ListaProcesos *_listPro;
                _listPro=new ListaProcesos(this,_qMapEjecutables);
                QList <Proceso *> listaProcesoMet;
                listaProcesoMet= _listPro->getListaProcesosMet(_dataZoneMet);
                if(_WMet!=0)
                {
                    delete _WMet;
                }
                _WMet=new WorkerMet(this,listaProcesoMet);
                _controlMet->setWorker(_WMet);
                createListadoOperacionMet();
                _controlMet->setListaOperaciones(_listadoOperacionMet);
                _controlMet->start();
        }
        else
            _dialogoProgreso->metEnd();
        if (_ortoActivo)
        {
            _registroOrto->buildDataZoneProject(_dataZoneOrto);
                QMap <QString, QString> _qMapEjecutables;
                _qMapEjecutables=_registroOrto->getMapExe();
                ListaProcesos *_listPro;
                _listPro=new ListaProcesos(this,_qMapEjecutables);
                QList <Proceso *> listaProcesoOrto;
                listaProcesoOrto= _listPro->getListaProcesosOrto(_dataZoneOrto);
                if(_WOrto!=0)
                {
                    delete _WOrto;
                }
                _WOrto=new WorkerOrto(this,listaProcesoOrto);
                _controlOrto->setWorker(_WOrto);
                createListadoOperacionOrto();
                _controlOrto->setListaOperaciones(_listadoOperacionOrto);
                _controlOrto->start();
        }
                else
                _dialogoProgreso->ortoEnd();
        _dialogoProgreso->show();
    }
}

void LanzadorOperaciones::borrarListadoOperacion(QList<Operacion *> &lista)
{
    foreach (Operacion *ope,lista)
    {
        delete ope;
    }
    lista.clear();
}
void LanzadorOperaciones::crearListaIdentificadores()
{
    IdentificadorCoordenadas *ide=0;
    ModeloCoordenadas *modelo=_tableCoordinates->getModeloCoordenadas();
    int numFilas=modelo->rowCount();
    for(int i=0;i<numFilas;i++)
    {
        ide=new IdentificadorCoordenadas(this);
        ide->setIdentificador(modelo->index(i,0).data().toString());
        ide->setXa(modelo->index(i,1).data().toDouble());
        ide->setYa(modelo->index(i,2).data().toDouble());
        ide->setXb(modelo->index(i,3).data().toDouble());
        ide->setYb(modelo->index(i,4).data().toDouble());
        _listaIdentificadores<<ide;
    }
}





