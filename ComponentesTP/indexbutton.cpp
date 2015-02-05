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
#include "indexbutton.h"

IndexButton::IndexButton(QWidget *parent,int indice) :
    QPushButton(parent),
    index(indice)
{
    connect(this,SIGNAL(clicked()),this,SLOT(botonPulsado()));
    _estadoActual=0;
}

void IndexButton::setIndiceButton(int indice)
{
    index=indice;
}

int IndexButton::getIndiceButton()
{
    return index;
}

void IndexButton::botonPulsado()
{
  emit clicked(index);
}

void IndexButton::setEstadoBoton(int estado)
{
    if(mapaEstados.contains(estado)) {
        _estadoActual=estado;
        setIcon(*mapaEstados.value(estado));
    }
}

int IndexButton::getEstadoBoton() const
{
    return this->_estadoActual;
}

QMap<int,QIcon*> IndexButton::getMapaEstados() const
{
    return mapaEstados;
}

QList<int> IndexButton::getListaEstados() const
{
    return mapaEstados.keys();
}

void IndexButton::addEstado(int numEstado, QIcon *iconoEstado)
{
    if(!mapaEstados.contains(numEstado))
        mapaEstados.insert(numEstado,iconoEstado);
}

void IndexButton::removeEstado(int numEstado)
{
    if(mapaEstados.contains(numEstado)) {
        //1.- comprueba que el estado actual no es el estado que queremos eliminar
        if(_estadoActual!=numEstado)
            mapaEstados.remove(numEstado);
        else { //En caso de que el estado actual sea el que queremos eliminar
            QList<int> lEstados=mapaEstados.keys();
            lEstados.removeAll(numEstado);
            if(!lEstados.isEmpty()) {   //si hay otro estado al que podamos cambiar
                _estadoActual=lEstados.first();
                setIcon(*mapaEstados.value(_estadoActual));
                mapaEstados.remove(numEstado);
            }
            else {
                _estadoActual=-1;
                setIcon(QIcon());
                mapaEstados.remove(numEstado);
            }
        }
    }
}
