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
