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
#include "armclasefilesout.h"

ARMClaseFilesOut::ARMClaseFilesOut(QObject *parent) :
    QObject(parent)
{
    //Inicializar la lista de procesos a 3 como maximo

    _argumentosAttPix << tr("-c") << tr("ARCHIVO_RAD") << tr("-o") << tr("SALIDA_PIX") << tr("-a") <<tr("SALIDA_ATT");
    _argumentosAttPix << tr("-i")<< tr("ARCHIVO_RAW") << tr("-f") << tr("1") << tr("-j") << tr("110") << tr("-g") << tr("-50");
    _argumentosAttPix << tr("-v") << tr("0") << tr("-s") << tr("300") << tr("-n") << tr("1000000") << tr("-r") << tr("Y") << tr("-R") << tr("Y") << tr("-A") << tr("11");
}

QString ARMClaseFilesOut::nombreArchivoEntrada(QString nombreEntrada, QString directorioEntrada)
{
    QString name=nombreEntrada;
    if(!directorioEntrada.isEmpty()) {
        if(!directorioEntrada.endsWith("/"))
            name=name.prepend(directorioEntrada.append("/"));
        else name=name.prepend(directorioEntrada);
    }

    //Reemplazar la direccion de las cadenas de salida

    name=name.replace(tr("/"),tr("\\"));
    return name;
}

QString ARMClaseFilesOut::nombreArchivoSalida(QString nombreSalida, QString directorioSalida)
{
    QString name=nombreSalida;
    if(!directorioSalida.isEmpty() && !directorioSalida.isNull()) {
        if(!directorioSalida.endsWith("/"))
            name=name.prepend(directorioSalida.append("/"));
        else name=name.prepend(directorioSalida);
    }

    name=name.replace(tr("/"),tr("\\"));
    return name;
}

void ARMClaseFilesOut::createFilesAttPix(QList<QPair<QString, QString> > listaPares, QString folderAtt, QString folderPix,QString radFile)
{
    _listaAtt=listaPares;
    _posicionAtt=0;
    _servidos=0;

    _radFile=radFile;

    _listaProcesosAttPix.clear();

    if(!folderPix.endsWith('/'))
        _folderPix=folderPix.append('/');
    else _folderPix=folderPix;

    if(!folderAtt.endsWith('/'))
        _folderAtt=folderAtt.append('/');
    else _folderAtt=folderAtt;

    _folderPix.replace(tr("/"),tr("\\"));
    _folderAtt.replace(tr("/"),tr("\\"));
    _radFile.replace(tr("/"),tr("\\"));

    _argumentosAttPix.replace(1,_radFile); //Sustituimos la entrada del archivo rad en los argumentos

    emit setProgressRank(0,_listaAtt.count());

    //Ahora debemos de iniciar los distintos procesos
    for(int i=0;i<3 && i<_listaAtt.count();i++) {
        startMulti(i);
    }
}

void ARMClaseFilesOut::nextAttPix(int exitCode)
{
    if(_servidos<_listaAtt.count()) {
        emit actualizaAvance(++_servidos);

        if(_posicionAtt<_listaAtt.count()) {    //Lanza un nuevo proceso
                    QStringList argumentos=_argumentosAttPix;
                    QProcess *procesoEmisor=0;
                    bool found=false;	    //<--- ¡¡CORRECTO!!
                    for(int i=0;i<3 && !found;i++) {
                        if(_listaProcesosAttPix.at(i)->state()==QProcess::NotRunning) {
                            found=true;
                            procesoEmisor=_listaProcesosAttPix.value(i);
                        }
                    }

            QString origenRaw=_listaAtt.value(_posicionAtt).first;
            QString destinoPix=_listaAtt.value(_posicionAtt++).second;
            QString destinoAtt=destinoPix;

            //Preparar los destinos
            destinoPix=destinoPix.prepend(_folderPix).append(".pix");
            destinoAtt=destinoAtt.prepend(_folderAtt).append(".att");
            origenRaw=origenRaw.append(",rb");  //Necesario para los argumentos de radcorr

            argumentos.replace(3,destinoPix);    // nombre y path del archivo de salida pix
            argumentos.replace(5,destinoAtt);    // nombre y path del archivo de salida att
            argumentos.replace(7,origenRaw);     // Archivo RAW

            procesoEmisor->start(tr("\\Pedros\public_CASI\soft\Soft_ITRES2013/Radcorr5.2.4.0.exe"),argumentos);
        }
    }

    if((_servidos>=_listaAtt.count())&&(_posicionAtt>=_listaAtt.count()))
        emit actualizaAvance(_listaAtt.count());
}

void ARMClaseFilesOut::startMulti(int id)
{
    if(_posicionAtt>=_listaAtt.count()) {
        return;
    }

    QProcess *proceso=new QProcess(this);
    connect(proceso,SIGNAL(finished(int)),this,SLOT(nextAttPix(int)));

    _listaProcesosAttPix.append(proceso);

    QStringList argumentos=_argumentosAttPix;

    QString origenRaw=_listaAtt.value(_posicionAtt).first;
    QString destinoPix=_listaAtt.value(_posicionAtt++).second;
    QString destinoAtt=destinoPix;

    //Preparar los destinos
    destinoPix=destinoPix.prepend(_folderPix).append(".pix");
    destinoAtt=destinoAtt.prepend(_folderAtt).append(".att");
    origenRaw=origenRaw.append(",rb");

    argumentos.replace(3,destinoPix);    // nombre y path del archivo de salida pix
    argumentos.replace(5,destinoAtt);    // nombre y path del archivo de salida att
    argumentos.replace(7,origenRaw);     // Archivo RAW
    proceso->start(tr("E:/Antonio/Documentos/programacion/QT/cursoQt/ficherosClase/Radcorr5.2.4.0.exe"),argumentos);
}

void ARMClaseFilesOut::cancelProgress()
{

}
