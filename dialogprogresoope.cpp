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
#include "dialogprogresoope.h"
#include "ui_dialogprogresoope.h"

DialogProgresoOpe::DialogProgresoOpe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProgresoOpe)
{
    ui->setupUi(this);
    connect(ui->pushButtonClose,SIGNAL(clicked()),this,SLOT(close()));
    ui->progressBarCnp->setVisible(false);
    ui->labelCnp->setVisible(false);
    ui->pushButtonCancelCnp->setVisible(false);
    ui->progressBarMet->setVisible(false);
    ui->labelMet->setVisible(false);
    ui->pushButtonCancelMet->setVisible(false);
    ui->progressBarOrto->setVisible(false);
    ui->labelOrto->setVisible(false);
    ui->pushButtonCancelOrto->setVisible(false);
    ui->pushButtonSowErrors->setVisible(false);
    ui->textBrowserErrors->setVisible(false);
    ui->labelWarning->setVisible(false);
    ui->labelWarning->setText("<font color='blue'>Se ha producido un fallo</font>");
    ui->labelWarningIcon->setVisible(false);
    _cnpEnd=false;
    _metEnd=false;
    _ortoEnd=false;
    connect(ui->pushButtonCancelCnp,SIGNAL(clicked()),this,SLOT(disableCancelCnp()));
    connect(ui->pushButtonCancelMet,SIGNAL(clicked()),this,SLOT(disableCancelMet()));
    connect(ui->pushButtonCancelOrto,SIGNAL(clicked()),this,SLOT(disableCancelOrto()));



}

DialogProgresoOpe::~DialogProgresoOpe()
{
    delete ui;    
}

void DialogProgresoOpe::conectToControlCnp(ControlWorker *cWorker)
{
    connect(cWorker,SIGNAL(nuevoWorker(Worker*)),this,SLOT(nuevoWorkerCnp(Worker*)));
    connect(cWorker,SIGNAL(rangoOperaciones(int,int)),ui->progressBarCnp,SLOT(setRange(int,int)));
    connect(cWorker,SIGNAL(actualizarPaso(int)),ui->progressBarCnp,SLOT(setValue(int)));
    connect(cWorker,SIGNAL(enviarError(QString)),this,SLOT(errorCnp(QString)));
}
void DialogProgresoOpe::conectToControlMet(ControlWorker *cWorker)
{
    connect(cWorker,SIGNAL(nuevoWorker(Worker*)),this,SLOT(nuevoWorkerMet(Worker*)));
    connect(cWorker,SIGNAL(rangoOperaciones(int,int)),ui->progressBarMet,SLOT(setRange(int,int)));
    connect(cWorker,SIGNAL(actualizarPaso(int)),ui->progressBarMet,SLOT(setValue(int)));
    connect(cWorker,SIGNAL(enviarError(QString)),this,SLOT(errorMet(QString)));
}
void DialogProgresoOpe::conectToControlOrto(ControlWorker *cWorker)
{
    connect(cWorker,SIGNAL(nuevoWorker(Worker*)),this,SLOT(nuevoWorkerOrto(Worker*)));
    connect(cWorker,SIGNAL(rangoOperaciones(int,int)),ui->progressBarOrto,SLOT(setRange(int,int)));
    connect(cWorker,SIGNAL(actualizarPaso(int)),ui->progressBarOrto,SLOT(setValue(int)));
    connect(cWorker,SIGNAL(enviarError(QString)),this,SLOT(errorOrto(QString)));
}


void DialogProgresoOpe::nuevoWorkerCnp(Worker* w)
{
    connect(ui->pushButtonCancelCnp,SIGNAL(clicked()),w,SLOT(cancelar()));
}
void DialogProgresoOpe::nuevoWorkerMet(Worker* w)
{
    connect(ui->pushButtonCancelMet,SIGNAL(clicked()),w,SLOT(cancelar()));
}
void DialogProgresoOpe::nuevoWorkerOrto(Worker* w)
{
    connect(ui->pushButtonCancelOrto,SIGNAL(clicked()),w,SLOT(cancelar()));
}

void DialogProgresoOpe::errorCnp(QString error)
{
    qDebug()<< error << "error";
}
void DialogProgresoOpe::errorMet(QString error)
{
    qDebug()<< error << "error";
}
void DialogProgresoOpe::errorOrto(QString error)
{
    qDebug()<< error << "error";
}
void DialogProgresoOpe::visibleCnp(bool b)
{
 ui->labelCnp->setVisible(b);
 ui->progressBarCnp->setVisible(b);
 ui->pushButtonCancelCnp->setVisible(b);
}
void DialogProgresoOpe::visibleMet(bool b)
{
 ui->labelMet->setVisible(b);
 ui->progressBarMet->setVisible(b);
 ui->pushButtonCancelMet->setVisible(b);
}
void DialogProgresoOpe::visibleOrto(bool b)
{
 ui->labelOrto->setVisible(b);
 ui->progressBarOrto->setVisible(b);
 ui->pushButtonCancelOrto->setVisible(b);
}
void DialogProgresoOpe::visibleClose(bool b)
{

}
void DialogProgresoOpe::disableCancelCnp()
{
ui->pushButtonCancelCnp->setDisabled(true);
qDebug()<< "disablet CnpCancel";
}
void DialogProgresoOpe::disableCancelMet()
{
ui->pushButtonCancelMet->setDisabled(true);
qDebug()<< "disablet metCancel";
}
void DialogProgresoOpe::disableCancelOrto()
{
ui->pushButtonCancelOrto->setDisabled(true);
qDebug()<< "disablet OrtoCancel";
}
void DialogProgresoOpe::setCnpEnd()
{
  _cnpEnd=true;
  closeDisableEnable();
  qDebug()<< "setCnpEnd()";
}

void DialogProgresoOpe::setMetEnd()
{
   _metEnd=true;
   closeDisableEnable();
   qDebug()<< "setMetEnd()";
}

void DialogProgresoOpe::setOrtoEnd()
{
 _ortoEnd=true;
 closeDisableEnable();
 qDebug()<< "setOrtoEnd()";
}
void DialogProgresoOpe::cnpEnd()
{
  _cnpEnd=true;
  closeDisableEnable();
  qDebug()<< "setCnpEnd()";
}

void DialogProgresoOpe::metEnd()
{
   _metEnd=true;
   closeDisableEnable();
   qDebug()<< "setMetEnd()";
}

void DialogProgresoOpe::ortoEnd()
{
 _ortoEnd=true;
 closeDisableEnable();
 qDebug()<< "setOrtoEnd()";
}
void DialogProgresoOpe::closeDisableEnable()
{
    qDebug()<< _cnpEnd << "_cnpEnd";
    qDebug()<< _metEnd << "_metEnd ";
    qDebug()<< _ortoEnd << "_ortoEnd";
    qDebug()<< "closeDisableEnable()";
    if(_cnpEnd && _metEnd && _ortoEnd)
    {
        ui->pushButtonClose->setEnabled(true);
        qDebug()<< "ui->pushButtonClose->setEnabled(true);";
    }
}

void DialogProgresoOpe::sowErrors(QString error)
{

    ui->labelWarning->setVisible(true);
    ui->labelWarningIcon->setVisible(true);
    ui->pushButtonSowErrors->setVisible(true);
    ui->textBrowserErrors->insertPlainText(error);
}

void DialogProgresoOpe::on_pushButtonSowErrors_clicked()
{
    ui->textBrowserErrors->setVisible(true);
}
