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
#include "createcnps.h"
#include "ui_createcnps.h"
#include <QDebug>
#include <QDateTime>
CreateCnps::CreateCnps(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateCnps)
{
    ui->setupUi(this);
    punteroRegistroCnps=new RegistroCnps(this);
 connect(ui->checkBoxCreaCnps,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableCreateCnp(int)));
 connect(ui->lineEditFolderOutCnps,SIGNAL(textChanged(QString)),this,SLOT(comprobarCorreccion(QString)));
 connect(ui->lineEditFolderOutCnps,SIGNAL(textChanged(QString)),punteroRegistroCnps,SLOT(setFolderOut(QString)));

}

CreateCnps::~CreateCnps()
{
    delete ui;
}

bool CreateCnps::comprobarChecFolderCnps()
{

 qDebug() << folderOut << "Directorio3";
 if(!folderOut.isNull() && !folderOut.isEmpty())
 {
     emit cambioEstadoCnps(true);
    qDebug() << folderOut << "Directorio4";
    return true;
 }
 else
 {
     emit cambioEstadoCnps(false);
     return false;
 }
 return false;
}

void CreateCnps::enableOrDisableCreateCnp (int chec)
{
    if (chec==0)
    {
     ui->pushButtonFolderOutCnps->setDisabled(1);
     ui->lineEditFolderOutCnps->setDisabled(1);

     comprobarChecFolderCnps();
     emit cambioEstadoCorreccionCnps(0);    ///Estado no seleccionado
    }
    if (chec==2)
    {
        ui->pushButtonFolderOutCnps->setEnabled(1);
        ui->lineEditFolderOutCnps->setEnabled(1);
        qDebug()<< "seleccionado";
        if(comprobarChecFolderCnps())
            emit cambioEstadoCorreccionCnps(1);
        else emit cambioEstadoCorreccionCnps(2);
    }
    qDebug()<< chec <<"chec";
}



void CreateCnps::on_pushButtonFolderOutCnps_clicked()
{
    folderOut=QString();
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    folderOut=QFileDialog::getExistingDirectory
    (0,("Triar carpeta sortida"),(pbSelectFolder));
    qDebug() << folderOut << "DirectorioMet1";
    if(!folderOut.isNull() && !folderOut.isEmpty())
    {
    ui->lineEditFolderOutCnps->setText(folderOut);
    }
}

void CreateCnps::setPunterotVCoordenadas(TableViewCoordinates *p)
{
  tVCoordenadas=p;
}
void CreateCnps::activateWidget(bool acti)
{
    if (acti==true)
    {
        ui->checkBoxCreaCnps->setEnabled(true);
        ui->pushButtonDeleteDatesCnps->setEnabled(true);
    }
    else
    {
        ui->checkBoxCreaCnps->setEnabled(false);
        ui->checkBoxCreaCnps->setChecked(false);
        ui->pushButtonDeleteDatesCnps->setEnabled(false);
    }
}



void CreateCnps::on_pushButtonDeleteDatesCnps_clicked()
{
    folderOut=QString();
ui->lineEditFolderOutCnps->clear();
emit cambioEstadoCnps(false);
}

void CreateCnps::comprobarCorreccion(QString dato)
{
    //Comprobar el estado de chequeo y comprobar checFolderCnps
    if(!ui->checkBoxCreaCnps->isChecked())
        emit cambioEstadoCorreccionCnps(0);
    else {
        if(comprobarChecFolderCnps())
            emit cambioEstadoCorreccionCnps(1);
        else emit cambioEstadoCorreccionCnps(2);
    }
}

RegistroCnps* CreateCnps::getObjetoRegistroCnps()
{
return punteroRegistroCnps;
}
