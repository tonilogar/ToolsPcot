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
#include "debugqprocess.h"

DebugQprocess::DebugQprocess(QObject *parent, QIODevice *dis) :
    QObject(parent)
{
    dispositivo=dis;
    stream=new QTextStream(dispositivo);
    connect(dispositivo,SIGNAL(readyRead()),this,SLOT(mensajeListo()));
}

void DebugQprocess::mensageListo()
{
    QString  mensaje=stream->readAll();
    qDebug() << mensaje << "hay mensaje";
}


