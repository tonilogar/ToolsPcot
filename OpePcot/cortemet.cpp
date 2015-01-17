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
#include "cortemet.h"

CorteMet::CorteMet(QObject *parent,QString nFileIn, QString nFileOut, int fSup, int fInf,
                   int cIz, int cDer, int ind) :
    QObject(parent)
{
}
QString CorteMet::getNombreFileIn()
{
  return nombreFileIn;
}

QString CorteMet::getNombreFileOut()
{
 return nombreFileOut;
}
int CorteMet::getFilaSup()
{
 return filaSup;
}
int CorteMet::getFilaInf()
{
 return filaInf;
}
int CorteMet::getColumnIz()
{
 return columnIz;
}
int CorteMet::getColumnDer()
{
 return columnDer;
}
int CorteMet::getIndice()
{
 return indice;
}
//Setters
void CorteMet::setNombreFileIn(QString nFileIn)
{
 nombreFileIn=nFileIn;
}
void CorteMet::setNombreFileOut(QString nFileOut)
{
nombreFileOut=nFileOut;
}
void CorteMet::setFilaSup(int fSup)
{
 filaSup=fSup;
}
void CorteMet::setFilaInf(int fInf)
{
 filaInf=fInf;
}
void CorteMet::setColumnIz(int cIz)
{
 columnIz=cIz;
}
void CorteMet::setColumnDer(int cDer)
{
  columnDer=cDer;
}
void CorteMet::setIndice(int ind)
{
  indice=ind;
}
