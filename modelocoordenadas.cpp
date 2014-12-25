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
#include "modelocoordenadas.h"

ModeloCoordenadas::ModeloCoordenadas(QObject *parent,QList<IdentificadorCoordenadas*> lista) :
    QAbstractTableModel(parent)
{
    _listaRegistros=lista;  //Inicializando la lista de registros
}

int ModeloCoordenadas::rowCount(const QModelIndex &parent) const
{
    return _listaRegistros.count();
}

int ModeloCoordenadas::columnCount(const QModelIndex &parent) const
{
    return 5;
}

Qt::ItemFlags ModeloCoordenadas::flags(const QModelIndex &index) const
{
    return (Qt::ItemIsEnabled | Qt::ItemIsSelectable );
}

QVariant ModeloCoordenadas::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    QVariant resultado;
    IdentificadorCoordenadas *registro = _listaRegistros.at(index.row());

    /*
     * Al trabajar con los datos de un archivo de coordenadas, me he dado
     * cuenta de que la vista cambia de forma automatica el formato
     * de presentacion de algunos datos para presentarlos de manera exponencial
     * ( p.e 4.01392e5), asi que he modificado la forma de enviar los datos...
     */

    //Distinguimos entre los datos que enviamos para PRESENTAR y los que enviamos para EDITAR
    if(role==Qt::DisplayRole) { //Datos para PRESENTAR (display)

        switch(index.column()) {
        case 0:
            resultado=registro->getIdentificador();
            break;
        case 1:
            resultado=QString::number(registro->getXa(),'f',2); //Formato f, numero tal cual (p.e 401392)
                                                                //El numero 2 representa el total de decimales que queremos mostrar
            break;
        case 2:
            resultado=QString::number(registro->getYa(),'f',2);
            break;
        case 3:
            resultado=QString::number(registro->getXb(),'f',2);
            break;
        case 4:
            resultado=QString::number(registro->getYb(),'f',2);
            break;
        default:
            break;
        }
    }


    if(role==Qt::EditRole) { //Datos para EDITAR (edit), son los que enviamos cuando hacemos doble click en una casilla

        switch(index.column()) {
        case 0:
            resultado=registro->getIdentificador();
            break;
        case 1:
            resultado=registro->getXa();
            break;
        case 2:
            resultado=registro->getYa();
            break;
        case 3:
            resultado=registro->getXb();
            break;
        case 4:
            resultado=registro->getYb();
            break;
        default:
            break;
        }

    }

    return resultado;
}

QVariant ModeloCoordenadas::headerData(int section, Qt::Orientation orientation, int role) const
{
    QVariant res;
    if(orientation==Qt::Horizontal && role==Qt::DisplayRole) {
        switch(section) {
        case 0:
            res=tr("ID");
            break;
        case 1:
            res=tr("Xa");
            break;
        case 2:
            res=tr("Ya");
            break;
        case 3:
            res=tr("Xb");
            break;
        case 4:
            res=tr("Yb");
            break;
        default:
            break;
        }
    }
    else if(orientation==Qt::Vertical && role==Qt::DisplayRole)
        res=section+1;
    return res;
}

bool ModeloCoordenadas::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    if(role==Qt::EditRole) {
        IdentificadorCoordenadas *registro = _listaRegistros.value(index.row());

        switch(index.column()) {
        case 0:
            registro->setIdentificador(value.toString());
            break;
        case 1:
            registro->setXa(value.toDouble());
            break;
        case 2:
            registro->setYa(value.toDouble());
            break;
        case 3:
            registro->setXb(value.toDouble());
            break;
        case 4:
            registro->setYb(value.toDouble());
            break;
        default:
            break;
        }
    }

    emit dataChanged(index,index);
    return true;
}

void ModeloCoordenadas::clear()
{
    beginResetModel();
    _listaRegistros.clear();
    endResetModel();
}

void ModeloCoordenadas::setListaRegistro(QList<IdentificadorCoordenadas *> nuevaLista)
{
    beginResetModel();
    _listaRegistros.clear();
    _listaRegistros=nuevaLista;
    endResetModel();
}
QList <IdentificadorCoordenadas*> ModeloCoordenadas::getListaRegistro()
{
  return _listaRegistros;
}
