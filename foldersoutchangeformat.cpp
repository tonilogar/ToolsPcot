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
#include "foldersoutchangeformat.h"
#include "ui_foldersoutchangeformat.h"
#include <QLineEdit>
#include <QFileDialog>
#include <QDebug>
FoldersOutChangeFormat::FoldersOutChangeFormat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FoldersOutChangeFormat)
{
    ui->setupUi(this);
    punteroRegistroFolderOut=new RegistroFolderOutChangeFormat (this);
    connect(ui->lineEditAtp,SIGNAL(textChanged(QString)),punteroRegistroFolderOut,SLOT(setFolderAtp(QString)));
    connect(ui->lineEditPix,SIGNAL(textChanged(QString)),punteroRegistroFolderOut,SLOT(setFolderPix(QString)));
    connect(ui->lineEditRf,SIGNAL(textChanged(QString)),punteroRegistroFolderOut,SLOT(setFolderRf(QString)));
    connect(ui->lineEditJpg,SIGNAL(textChanged(QString)),punteroRegistroFolderOut,SLOT(setFolderJpg(QString)));
}

FoldersOutChangeFormat::~FoldersOutChangeFormat()
{
    delete ui;
}
RegistroFolderOutChangeFormat * FoldersOutChangeFormat::getObjetoRegistroFolOut()
{
return punteroRegistroFolderOut;
}

void FoldersOutChangeFormat::comprobarEstado()
{
    if(punteroRegistroFolderOut->getFolderAtt().isNull() && punteroRegistroFolderOut->getFolderAtt().isEmpty()
            )
    {
      cambioEstadoFoldersOut(false);
      qDebug()<< "comprobar estado false";
    }
    else
    {
     cambioEstadoFoldersOut(true);
     qDebug()<< "comprobar estado true";
    }
}


void FoldersOutChangeFormat::on_pushButtonAtt_clicked()
{
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    QString pbfolderOut=QFileDialog::getExistingDirectory
    (0,("Triar carpeta sortida"),(pbSelectFolder));
    //qDebug() << pbfolderOut << "Directorio";
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())
    {
        ui->lineEditAtt->setText(pbfolderOut);
    //Si no se selecciona directorio no se cambian los paths
    if(punteroRegistroFolderOut->getFolderPix().isNull() && punteroRegistroFolderOut->getFolderPix().isEmpty())ui->lineEditPix->setText(pbfolderOut);
    if(punteroRegistroFolderOut->getFolderAtp().isNull() && punteroRegistroFolderOut->getFolderAtp().isEmpty())ui->lineEditAtp->setText(pbfolderOut);
    if(punteroRegistroFolderOut->getFolderRf().isNull() && punteroRegistroFolderOut->getFolderRf().isEmpty())ui->lineEditRf->setText(pbfolderOut);
    if(punteroRegistroFolderOut->getFolderJpg().isNull() && punteroRegistroFolderOut->getFolderJpg().isEmpty())ui->lineEditJpg->setText(pbfolderOut);
    punteroRegistroFolderOut->setFolderAtt(pbfolderOut);
    punteroRegistroFolderOut->getFolderAtt();

        cambioEstadoFoldersOut(true);
    }
    else
        cambioEstadoFoldersOut(false);





}

void FoldersOutChangeFormat::on_pushButtonPix_clicked()
{
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    QString pbfolderOut=QFileDialog::getExistingDirectory
    (0,("Triar carpeta sortida"),(pbSelectFolder));
    qDebug() << pbfolderOut; "Directorio";
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())ui->lineEditPix->setText(pbfolderOut);
    punteroRegistroFolderOut->setFolderPix(pbfolderOut);
    punteroRegistroFolderOut->getFolderPix();
}

void FoldersOutChangeFormat::on_pushButtonAtp_clicked()
{
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    QString pbfolderOut=QFileDialog::getExistingDirectory
    (0,("Triar carpeta sortida"),(pbSelectFolder));
    qDebug() << pbfolderOut; "Directorio";
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())ui->lineEditAtp->setText(pbfolderOut);
    punteroRegistroFolderOut->setFolderAtp(pbfolderOut);
    punteroRegistroFolderOut->getFolderAtp();
}

void FoldersOutChangeFormat::on_pushButtonRf_clicked()
{
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    QString pbfolderOut=QFileDialog::getExistingDirectory
    (0,("Triar carpeta sortida"),(pbSelectFolder));
    qDebug() << pbfolderOut; "Directorio";
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())ui->lineEditRf->setText(pbfolderOut);
    punteroRegistroFolderOut->setFolderRf(pbfolderOut);
    punteroRegistroFolderOut->getFolderRf();
}

void FoldersOutChangeFormat::on_pushButtonJpg_clicked()
{
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    QString pbfolderOut=QFileDialog::getExistingDirectory
    (0,("Triar carpeta sortida"),(pbSelectFolder));
    qDebug() << pbfolderOut; "Directorio";
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())ui->lineEditJpg->setText(pbfolderOut);
    punteroRegistroFolderOut->setFolderJpg(pbfolderOut);
    punteroRegistroFolderOut->getFolderJpg();
}


