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
    _dialogoProgreso=new operacionProgresdialog();
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
    QList <Proceso *> listaProcesoCnp;
    listaProcesoCnp<< new PocesoCnp(this,QString());
    _Wcnp=new Worker(this,listaProcesoCnp);
    _controlCnp->setWorker(_Wcnp);


    connect(_controlCnp,SIGNAL(rangoOperaciones(int,int)),_dialogoProgreso,SLOT(setCnpRange(int,int)));
    connect(_controlCnp,SIGNAL(actualizarPaso(int)),_dialogoProgreso,SLOT(actualizarBarraCnp(int)));
    connect(_controlCnp,SIGNAL(enviarError(QString)),_dialogoProgreso,SLOT(tratarErrores(QString)));
    connect(_controlCnp,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(setCnpTerminado(bool)));

    connect(_controlMet,SIGNAL(rangoOperaciones(int,int)),_dialogoProgreso,SLOT(setMetRange(int,int)));
    connect(_controlMet,SIGNAL(actualizarPaso(int)),_dialogoProgreso,SLOT(actualizarBarraMet(int)));
    connect(_controlMet,SIGNAL(enviarError(QString)),_dialogoProgreso,SLOT(tratarErrores(QString)));
    connect(_controlMet,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(setMetTerminado(bool)));

    connect(_controlOrto,SIGNAL(rangoOperaciones(int,int)),_dialogoProgreso,SLOT(setOrtoRange(int,int)));
    connect(_controlOrto,SIGNAL(actualizarPaso(int)),_dialogoProgreso,SLOT(actualizarBarraOrto(int)));
    connect(_controlOrto,SIGNAL(enviarError(QString)),_dialogoProgreso,SLOT(tratarErrores(QString)));
    connect(_controlOrto,SIGNAL(operacionesTerminadas(bool)),_dialogoProgreso,SLOT(setOrtoTerminado(bool)));
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
    foreach (Operacion *ope,_listadoOperacionCnp)
    {
        delete ope;
    }
    _listadoOperacionCnp.clear();

    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    {
        _listadoOperacionCnp.append(new OperacionCnp(this,qVa,_dataZoneCnp));
    }
}

void LanzadorOperaciones::createListadoOperacionMet()
{
    foreach (Operacion *ope,_listadoOperacionMet)
    {
        delete ope;
    }
    _listadoOperacionMet.clear();

    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    {
        _listadoOperacionMet.append(new OperacionMet(this,qVa,_dataZoneMet));
    }
}

void LanzadorOperaciones::createListadoOperacionOrto()
{
    //    foreach (Operacion *ope,_listadoOperacionOrto)
    //    {
    //        delete ope;
    //    }
    //    _listadoOperacionOrto.clear();

    //    foreach (IdentificadorCoordenadas *qVa,_listaIdentificadores)
    //    {
    //        _listadoOperacionOrto.append(new Oper(this,qVa,_dataZoneOrto));
    //    }
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
            _registroCnp->buildDataZoneProject(_dataZoneCnp);
            borrarListadoOperacion(_listadoOperacionCnp);
            createListadoOperacionCnp();
            _controlCnp->setListaOperaciones(_listadoOperacionCnp);
            _controlCnp->start();
        }
        if (_metActivo)
        {
            _registroMet->buildDataZoneProject(_dataZoneMet);
            borrarListadoOperacion(_listadoOperacionMet);

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
        _dialogoProgreso->show();
    }
}

void LanzadorOperaciones::borrarListadoOperacion(QList <Operacion *> lista)
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






