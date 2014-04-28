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
#include "modeloraw.h"
#include <QDebug>
ModeloRaw::ModeloRaw(QObject *parent,QList<RegistroRaw*> lista) :
    QAbstractTableModel(parent)
{
    _listaRegistros=lista;  //Inicializando la lista de registros
   _flagStripNumber=false;
   _flagFilenumber=false;
   _flagSignoPasada=false;
   _flagCanalRed=false;
   _flagCanalGreen=false;
   _flagCanalBlue=false;

}
QString ModeloRaw::getFicheroRad()
{
    return _ficheroRad;
}
QString ModeloRaw::getFicheroRadCorr()
{
    return _ficheroRadCorr;
}
QString ModeloRaw::getDatosRadCorr()
{
    return _datosRadCorr;
}
QString ModeloRaw::getDatosAttsync()
{
    return _datosAttsync;
}
QString ModeloRaw::getFicheroAttsync()
{
    return _ficheroAttsync;
}
int ModeloRaw::rowCount(const QModelIndex &parent) const
{
    return _listaRegistros.count();
}
int ModeloRaw::columnCount(const QModelIndex &parent) const
{
    return 9;
}
QList<RegistroRaw*> ModeloRaw::getListaRegistro()
{
    return _listaRegistros;
}

QList< QPair< QString,QString> > ModeloRaw::getPares()
{
 QList< QPair< QString ,QString> > listaPares;

 foreach(RegistroRaw* element, _listaRegistros)
 {
  QString nombreOrigen;
  QString nombreDestino;
  nombreOrigen=element->getPathRaw()+"\\"+element->getNameRaw();
  nombreOrigen.replace("/","\\");
  nombreDestino=_prefix+QString::number(element->getStripNumber())+_nomAvio+_numeroVol+QString(element->getSignoPasada())+"_"+_codiSensor+"F"+QString::number(element->getFileNumber());
  nombreDestino.replace("/","\\");
  QPair <QString, QString> parDatos;
  parDatos.first=nombreOrigen;
  parDatos.second=nombreDestino;
  listaPares.append(parDatos);
 }

return  listaPares;
}

Qt::ItemFlags ModeloRaw::flags(const QModelIndex &index) const
{
    if(index.column()>2)
    return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    return (Qt::ItemIsEnabled | Qt::ItemIsSelectable );
}

QVariant ModeloRaw::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    QVariant resultado;
    RegistroRaw *registro = _listaRegistros.at(index.row());

    if(role==Qt::DisplayRole || role==Qt::EditRole) {
       QString canalRed;
       QString canalGreen;
       QString canalBlue;
       QString stripNumber;
       QString fileNumber;
       QString signo;
        switch(index.column()) {
        case 0:
            resultado=registro->getPathRaw();
            break;
        case 1:
            resultado=registro->getNameRaw();
            break;
        case 2:
            fileNumber=QString::number(registro->getFileNumber());
            if (registro->getFileNumber()<10)
            {
                fileNumber=fileNumber.prepend("0");
            }
            stripNumber=QString::number(registro->getStripNumber());
            if (registro->getStripNumber()<10)
            {
                stripNumber=stripNumber.prepend("0");
            }
            if(registro->getSignoPasada()==0)
                signo=QString();
            else if(registro->getSignoPasada()==1)
                signo=QString('N');
            else if(registro->getSignoPasada()==2)
                signo=QString('P');
            if(signo.isEmpty())
                resultado=_prefix+stripNumber+_nomAvio+_numeroVol+"_"+_codiSensor+"F"+fileNumber;
            else
                resultado=_prefix+stripNumber+_nomAvio+_numeroVol+signo+"_"+_codiSensor+"F"+fileNumber;
            break;
        case 3:
            resultado=registro->getStripNumber();
            break;

        case 4:
            if(role==Qt::DisplayRole){
                if(registro->getSignoPasada()==0)
                    resultado=QString("No seleccionado");
                else if(registro->getSignoPasada()==1)
                    resultado=QString("Negativo");
                else if(registro->getSignoPasada()==2)
                    resultado=QString("Positivo");
            }
            break;
        case 5:
            resultado=registro->getFileNumber();
            break;
        case 6:
            resultado=registro->getCanalRed();
            break;
        case 7:
            resultado=registro->getCanalGreen();
            break;
        case 8:
            resultado=registro->getCanalBlue();
            break;
            default:
            break;
        }
    }
    return resultado;
}

QVariant ModeloRaw::headerData(int section, Qt::Orientation orientation, int role) const
{
    QVariant res;
    if(orientation==Qt::Horizontal && role==Qt::DisplayRole) {
        switch(section) {
        case 0:
            res=tr("Path");
            break;
        case 1:
            res=tr("Name");
            break;
        case 2:
            res=tr("File output");
            break;
        case 3:
            res=tr("Strip number");
            break;
        case 4:
            res=tr("Signe pase");
            break;
        case 5:
            res=tr("Number file");
            break;
        case 6:
            res=tr("Canal Red");
            break;
        case 7:
            res=tr("Canal Green");
            break;
        case 8:
            res=tr("Canal Blue");
            break;
        default:
            break;
        }
    }
    else if(orientation==Qt::Vertical && role==Qt::DisplayRole)
        res=section+1;
    return res;
}

bool ModeloRaw::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool _auxSignoPas,_auxStripNum,_auxFileNum,_auxCanalRed,_auxCanalGreen,_auxCanalBlue;
    if(!index.isValid())
        return false;

    if(role==Qt::EditRole) {
        RegistroRaw *registro = _listaRegistros.value(index.row());

        switch(index.column()) {
        case 0:
            registro->setNameRaw(value.toString());
            break;
        case 1:
            registro->setPathRaw(value.toString());
            break;
        case 3:
            registro->setStripNumber(value.toUInt());
            _auxStripNum=evaluaColumnaStripNunber();
            if(_auxStripNum!=_flagStripNumber) {
                _flagStripNumber=_auxStripNum;
                evaluacionGeneral();
            }
            break;
        case 4:
            registro->setSignoPasada(value.toUInt());
            _auxSignoPas=evaluaColumnaSignoPasada();
            if(_auxSignoPas!=_flagSignoPasada){
                _flagSignoPasada=_auxSignoPas;
                evaluacionGeneral();
            }
            break;
        case 5:
            registro->setFileNumber(value.toUInt());
            _auxFileNum=evaluaColumnaFileNumber();
            if(_auxFileNum!=_flagFilenumber) {
                _flagFilenumber=_auxFileNum;
                evaluacionGeneral();
            }
            break;
        case 6:
            registro->setCanalRed(value.toUInt());
            _auxCanalRed=evaluaColumnaCanalRed();
            if(_auxCanalRed!=_flagCanalRed){
                _flagCanalRed=_auxCanalRed;
                evaluacionGeneral();
            }
            break;
        case 7:
            registro->setCanalGreen(value.toUInt());
            _auxCanalGreen=evaluaColumnaCanalGreen();
            if(_auxCanalGreen!=_flagCanalGreen){
                _flagCanalGreen=_auxCanalGreen;
                evaluacionGeneral();
            }
            break;
        case 8:
            registro->setCanalBlue(value.toUInt());
            _auxCanalBlue=evaluaColumnaCanalBlue();
            if(_auxCanalBlue!=_flagCanalBlue){
                _flagCanalBlue=_auxCanalBlue;
                evaluacionGeneral();
            }
            break;
        default:
            break;
        }
    }

    emit dataChanged(index,index);
    if(index.column()>2)
        emit dataChanged(this->index(index.row(),2),this->index(index.row(),2));
    return true;
}

void ModeloRaw::setPrefix(QString prefijo)
{
_prefix=prefijo;
int numFilas=_listaRegistros.count();
for(int i=0; i<numFilas;i++)
{
    emit dataChanged(index(i,2),index(i,2));
}
qDebug() << _prefix;
}

void ModeloRaw::setCodiSensor(QString codiSensor)
{
_codiSensor=codiSensor;
int numFilas=_listaRegistros.count();
for(int i=0; i<numFilas;i++)
{

    emit dataChanged(index(i,2),index(i,2));
}
qDebug() << _codiSensor;

}

void ModeloRaw::setNomAvio(QString nomAvio)
{
    _nomAvio=nomAvio;

  if (nomAvio=="Select airplane name") _nomAvio="";
  if (nomAvio=="Caravan") _nomAvio="_K";
  if (nomAvio=="Partenavia") _nomAvio="_P";
  if (nomAvio=="Beechcraft") _nomAvio="_B";
  int numFilas=_listaRegistros.count();
  for(int i=0; i<numFilas;i++)
  {

      emit dataChanged(index(i,2),index(i,2));
  }
  qDebug() << _nomAvio;
}
void ModeloRaw::setNumeroVol(QString numeroVol)
{
_numeroVol=numeroVol;

if (numeroVol=="Select fly number") _numeroVol="";
int numFilas=_listaRegistros.count();
for(int i=0; i<numFilas;i++)
{

    emit dataChanged(index(i,2),index(i,2));
}
qDebug() << _numeroVol;

}

void ModeloRaw::setRangoPasada(QString rangoPasada)
{
_rangoPasada=rangoPasada;
int numFilas=_listaRegistros.count();
for(int i=0; i<numFilas;i++)
{

    emit dataChanged(index(i,2),index(i,2));
}
qDebug() << _rangoPasada;

}

void ModeloRaw::setOberturaPasada(QString oberturaPasada)
{
_oberturaPasada=oberturaPasada;
int numFilas=_listaRegistros.count();
for(int i=0; i<numFilas;i++)
{

    emit dataChanged(index(i,2),index(i,2));
}
qDebug() << _oberturaPasada;

}

void ModeloRaw::setFicheroRad(QString ficheroRad)
{
  _ficheroRad=ficheroRad;
}
void ModeloRaw::setDatosRadCorr(QString datosRadCorr)
{
  _datosRadCorr=datosRadCorr;
}
void ModeloRaw::setDatosAttsync(QString datosAttsync)
{
  _datosAttsync=datosAttsync;
}
void ModeloRaw::setFicheroAttsync(QString ficheroAttsync)
{
  _ficheroAttsync=ficheroAttsync;
}
void ModeloRaw::setFicheroRadCorr(QString ficheroRadCorr)
{
  _ficheroRadCorr=ficheroRadCorr;
}


void ModeloRaw::clear()
{
    beginResetModel();
    _listaRegistros.clear();
    endResetModel();
}

void ModeloRaw::setListaRegistro(QList<RegistroRaw *> nuevaLista)
{
    beginResetModel();
    _listaRegistros.clear();
    _listaRegistros=nuevaLista;
    endResetModel();
}

bool ModeloRaw::evaluaColumnaFileNumber()
{
    bool found=false;
    for(int i=0;i<_listaRegistros.count()&& !found;i++){
        if(_listaRegistros.at(i)->getFileNumber()==0)
            found=true;
    }
    return !found;
}
bool ModeloRaw:: evaluaColumnaStripNunber()
{
    bool found=false;
    for(int i=0;i<_listaRegistros.count()&& !found;i++){
        if(_listaRegistros.at(i)->getStripNumber()==0)
            found=true;
    }
    return !found;
}

bool ModeloRaw:: evaluaColumnaCanalRed()
{
    bool found=false;
    for(int i=0;i<_listaRegistros.count()&& !found;i++){
        if(_listaRegistros.at(i)->getCanalRed()==0)
            found=true;
    }
    return !found;
}

bool ModeloRaw:: evaluaColumnaCanalGreen()
{
    bool found=false;
    for(int i=0;i<_listaRegistros.count()&& !found;i++){
        if(_listaRegistros.at(i)->getCanalGreen()==0)
            found=true;
    }
    return !found;
}

bool ModeloRaw:: evaluaColumnaCanalBlue()
{
    bool found=false;
    for(int i=0;i<_listaRegistros.count()&& !found;i++){
        if(_listaRegistros.at(i)->getCanalBlue()==0)
            found=true;
    }
    return !found;
}



bool ModeloRaw::evaluacionGeneral()
{

    if(_flagStripNumber  && _flagFilenumber && _flagSignoPasada && _flagCanalRed && _flagCanalGreen && _flagCanalBlue)
    {
         emit cambioEstado(true);
         qDebug()<< "cambioEstado true";
         return  true;
    }
    else
    {
        emit cambioEstado(false);
        qDebug()<< "cambioEstado false";
        return false;
    }

}

bool ModeloRaw::comprobarEstadoRaw()
{
    if (_flagStripNumber &&  _flagFilenumber && _flagSignoPasada && _flagCanalRed && _flagCanalGreen && _flagCanalBlue)
    {
        return true;
    }
    return false;
}

bool ModeloRaw::evaluaColumnaSignoPasada()
{
    bool found=false;
    for(int i=0;i<_listaRegistros.count()&& !found;i++){
        if(_listaRegistros.at(i)->getSignoPasada()==0)
            found=true;
    }
    return !found;
}
