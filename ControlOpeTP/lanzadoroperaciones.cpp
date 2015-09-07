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

LanzadorOperaciones::LanzadorOperaciones(QObject *parent, RegistroCreateCnps *_regCnp, RegistroCreateMet  *_regMet,
                                         RegistroCreateOrto *_regOrto, ModeloCoordenadas *_modeloCoor ) :
    QObject(parent)
{
    _registroCnp=_regCnp;
    _registroMet=_regMet;
    _registroOrto=_regOrto;
    _modeloCoordenadas=_modeloCoor;
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
void LanzadorOperaciones::setObjetoModeloCoordenadas(ModeloCoordenadas *_mCoor)
{
    _modeloCoordenadas=_mCoor;
}
void LanzadorOperaciones::createListadoOperacionCnp()
{    
    borrarListadoOperacion(_listadoOperacionCnp);
    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    {
        _listadoOperacionCnp.append(new OperacionCnp(this,qVa,_dataZoneCnp));
    }
}

void LanzadorOperaciones::createListadoOperacionMet()
{   
    borrarListadoOperacion(_listadoOperacionMet);

    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    {
        _listadoOperacionMet.append(new OperacionMet(this,qVa,_dataZoneMet));
    }
}

void LanzadorOperaciones::createListadoOperacionOrto()
{
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
        }
        if (_metActivo)
        {
            _registroMet->buildDataZoneProject(_dataZoneMet);
            QMap <QString, QString> _qMapEjecutables;
            _qMapEjecutables=_registroMet->getMapExe();
            FactoryProcesos *_factoryPro=new FactoryProcesos(this,_qMapEjecutables);
            QList <Proceso *> listaProcesoMet;
            listaProcesoMet= _factoryPro->buildListaProcesosMet(_dataZoneMet);
            if(_WMet!=0)
            {
                delete _WMet;
            }
            _WMet=new WorkerMet(this,listaProcesoMet);
            _controlMet->setWorker(_WMet);
            createListadoOperacionMet();
            _controlMet->setListaOperaciones(_listadoOperacionMet);

        }

        if (_ortoActivo)
        {
            _registroOrto->buildDataZoneProject(_dataZoneOrto);
            QMap <QString, QString> _qMapEjecutables;
            _qMapEjecutables=_registroOrto->getMapExe();
            FactoryProcesos *_factoryPro=new FactoryProcesos(this,_qMapEjecutables);
            QList <Proceso *> listaProcesoOrto;
            listaProcesoOrto= _factoryPro->buildListaProcesosOrto(_dataZoneOrto);
            if(_WOrto!=0)
            {
                delete _WOrto;
            }
            _WOrto=new WorkerOrto(this,listaProcesoOrto);
            _controlOrto->setWorker(_WOrto);
            createListadoOperacionOrto();
            _controlOrto->setListaOperaciones(_listadoOperacionOrto);

        }
        if(_cnpActivo)
        {
             _controlCnp->start();
        }
        if(_metActivo)
        {
             _controlMet->start();
        }
        if(_ortoActivo)
        {
             _controlOrto->start();
        }
      emit inicioOperaciones();
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
    int numFilas=modelo->rowCount();
    for(int i=0;i<numFilas;i++)
    {
        ide=new IdentificadorCoordenadas(this);
        ide->setIdentificador(_modeloCoordenadas->index(i,0).data().toString());
        ide->setXa(_modeloCoordenadas->index(i,1).data().toDouble());
        ide->setYa(_modeloCoordenadas->index(i,2).data().toDouble());
        ide->setXb(_modeloCoordenadas->index(i,3).data().toDouble());
        ide->setYb(_modeloCoordenadas->index(i,4).data().toDouble());
        _listaIdentificadores<<ide;
    }
}

ControlWorker *LanzadorOperaciones::getControlCnp()
{
  return _controlCnp;
}

ControlWorker *LanzadorOperaciones::getControlMet()
{
 return _controlMet;
}

ControlWorker *LanzadorOperaciones::getControlOrto()
{
 return _controlOrto;
}




