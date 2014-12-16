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
    ui->pushButtonClose->setEnabled(false);
    _cnpTerminado=true;
    _metTerminado=true;
    _ortoTerminado=true;
    resize(this->width(),20);
    setWindowFlags(Qt::WindowTitleHint);
    setModal(true);

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
    connect(cWorker,SIGNAL(operacionesTerminadas(bool)),ui->pushButtonCancelCnp,SLOT(setDisabled(bool)));
    connect(cWorker,SIGNAL(operacionesTerminadas(bool)),this,SLOT(cnpTerminado()));
}
void DialogProgresoOpe::conectToControlMet(ControlWorker *cWorker)
{
    connect(cWorker,SIGNAL(nuevoWorker(Worker*)),this,SLOT(nuevoWorkerMet(Worker*)));
    connect(cWorker,SIGNAL(rangoOperaciones(int,int)),ui->progressBarMet,SLOT(setRange(int,int)));
    connect(cWorker,SIGNAL(actualizarPaso(int)),ui->progressBarMet,SLOT(setValue(int)));
    connect(cWorker,SIGNAL(enviarError(QString)),this,SLOT(errorMet(QString)));
    connect(cWorker,SIGNAL(operacionesTerminadas(bool)),ui->pushButtonCancelMet,SLOT(setDisabled(bool)));
    connect(cWorker,SIGNAL(operacionesTerminadas(bool)),this,SLOT(metTerminado()));
}
void DialogProgresoOpe::conectToControlOrto(ControlWorker *cWorker)
{
    connect(cWorker,SIGNAL(nuevoWorker(Worker*)),this,SLOT(nuevoWorkerOrto(Worker*)));
    connect(cWorker,SIGNAL(rangoOperaciones(int,int)),ui->progressBarOrto,SLOT(setRange(int,int)));
    connect(cWorker,SIGNAL(actualizarPaso(int)),ui->progressBarOrto,SLOT(setValue(int)));
    connect(cWorker,SIGNAL(enviarError(QString)),this,SLOT(errorOrto(QString)));
    connect(cWorker,SIGNAL(operacionesTerminadas(bool)),ui->pushButtonCancelOrto,SLOT(setDisabled(bool)));
    connect(cWorker,SIGNAL(operacionesTerminadas(bool)),this,SLOT(ortoTerminado()));
}


void DialogProgresoOpe::nuevoWorkerCnp(Worker* w)
{
    setVisibleCnp(true);
    _cnpTerminado=false;
    connect(ui->pushButtonCancelCnp,SIGNAL(clicked()),w,SLOT(cancelar()));
}
void DialogProgresoOpe::nuevoWorkerMet(Worker* w)
{
    setVisibleMet(true);
    _metTerminado=false;
    connect(ui->pushButtonCancelMet,SIGNAL(clicked()),w,SLOT(cancelar()));
}
void DialogProgresoOpe::nuevoWorkerOrto(Worker* w)
{
    setVisibleOrto(true);
    _ortoTerminado=false;
    connect(ui->pushButtonCancelOrto,SIGNAL(clicked()),w,SLOT(cancelar()));
}

void DialogProgresoOpe::errorCnp(QString error)
{
    ui->labelWarning->setVisible(true);
    ui->labelWarningIcon->setVisible(true);
    ui->pushButtonSowErrors->setVisible(true);
    ui->textBrowserErrors->setTextColor(QColor("darkred"));
    ui->textBrowserErrors->insertPlainText("[Se ha producido un error en una operación cnp]");
    ui->textBrowserErrors->setTextColor(QColor("dimgray"));
    ui->textBrowserErrors->insertPlainText(error);
}
void DialogProgresoOpe::errorMet(QString error)
{
    ui->labelWarning->setVisible(true);
    ui->labelWarningIcon->setVisible(true);
    ui->pushButtonSowErrors->setVisible(true);
    ui->textBrowserErrors->setTextColor(QColor("darkred"));
    ui->textBrowserErrors->insertPlainText("[Se ha producido un error en una operación met]");
    ui->textBrowserErrors->setTextColor(QColor("dimgray"));
    ui->textBrowserErrors->insertPlainText(error);
}
void DialogProgresoOpe::errorOrto(QString error)
{
    ui->labelWarning->setVisible(true);
    ui->labelWarningIcon->setVisible(true);
    ui->pushButtonSowErrors->setVisible(true);
    ui->textBrowserErrors->setTextColor(QColor("darkred"));
    ui->textBrowserErrors->insertPlainText("[Se ha producido un error en una operación orto]");
    ui->textBrowserErrors->setTextColor(QColor("dimgray"));
    ui->textBrowserErrors->insertPlainText(error);
}
void DialogProgresoOpe::setVisibleCnp(bool b)
{
    ui->labelCnp->setVisible(b);
    ui->progressBarCnp->setVisible(b);
    ui->pushButtonCancelCnp->setVisible(b);
}
void DialogProgresoOpe::setVisibleMet(bool b)
{
    ui->labelMet->setVisible(b);
    ui->progressBarMet->setVisible(b);
    ui->pushButtonCancelMet->setVisible(b);
}
void DialogProgresoOpe::setVisibleOrto(bool b)
{
    ui->labelOrto->setVisible(b);
    ui->progressBarOrto->setVisible(b);
    ui->pushButtonCancelOrto->setVisible(b);
}
void DialogProgresoOpe::on_pushButtonSowErrors_clicked()
{
    ui->textBrowserErrors->setVisible(true);
}

void DialogProgresoOpe::limpiarErrorLog()
{
    ui->textBrowserErrors->clear();
}

void DialogProgresoOpe::resetDialog()
{
    ui->progressBarCnp->setValue(0);
    ui->progressBarMet->setValue(0);
    ui->progressBarOrto->setValue(0);
    limpiarErrorLog();
    hideAll();
    ui->pushButtonClose->setEnabled(false);
    ui->pushButtonCancelCnp->setEnabled(true);
    ui->pushButtonCancelMet->setEnabled(true);
    ui->pushButtonCancelOrto->setEnabled(true);
    _cnpTerminado=true;
    _metTerminado=true;
    _ortoTerminado=true;
    resize(this->width(),20);
}

void DialogProgresoOpe::hideAll()
{
    setVisibleCnp(false);
    setVisibleMet(false);
    setVisibleOrto(false);
    setVisibleErrorLog(false);
    setVisibleError(false);
}
void DialogProgresoOpe::setVisibleErrorLog(bool b)
{
    ui->textBrowserErrors->setVisible(b);
}

void DialogProgresoOpe::setVisibleError(bool b)
{
    ui->labelWarning->setVisible(b);
    ui->labelWarningIcon->setVisible(b);
    ui->pushButtonSowErrors->setVisible(b);
}
void DialogProgresoOpe::cnpTerminado()
{
    _cnpTerminado=true;
    compruebaOperacionesTerminadas();
}

void DialogProgresoOpe::metTerminado()
{
    _metTerminado=true;
    compruebaOperacionesTerminadas();
}

void DialogProgresoOpe::ortoTerminado()
{
    _ortoTerminado=true;
    compruebaOperacionesTerminadas();
}
void DialogProgresoOpe::compruebaOperacionesTerminadas()
{
    if(_cnpTerminado && _metTerminado && _ortoTerminado)
    {
        ui->pushButtonClose->setEnabled(true);
    }
}









