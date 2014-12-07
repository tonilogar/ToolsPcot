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
#include "operacionprogresdialog.h"
#include "ui_operacionprogresdialog.h"
#include <QDebug>
operacionProgresdialog::operacionProgresdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::operacionProgresdialog)
{
    ui->setupUi(this);
    cnpTerminado=true;
    metTerminado=true;
    ortoTerminado=true;
    ui->progressBarCnp->setVisible(false);
    ui->labelCnp->setVisible(false);
    ui->pushButtonCancelCnp->setVisible(false);
    ui->progressBarMet->setVisible(false);
    ui->labelMet->setVisible(false);
    ui->pushButtonCancelMet->setVisible(false);
    ui->progressBarOrto->setVisible(false);
    ui->labelorto->setVisible(false);
    ui->pushButtonCancelOrto->setVisible(false);
    ui->labelAdvertenciaFallo->setVisible(false);
    ui->labelAdvertenciaFallo->setText("<font color='blue'>Se ha producido un fallo</font>");
    ui->labelIconoAdvertencia->setVisible(false);
    ui->pushButtonFallo->setVisible(false);
    ui->textBrowserFallo->setVisible(false);
    ui->labelCancelCnp->setVisible(false);
    ui->labelCancelMet->setVisible(false);
    ui->labelCancelOrto->setVisible(false);
    ui->pushButtonCancelCnp->setEnabled(true);
    ui->pushButtonCancelMet->setEnabled(true);
    ui->pushButtonCancelOrto->setEnabled(true);
    ui->pushButtonClose->setEnabled(false);
    connect(ui->pushButtonCancelCnp,SIGNAL(clicked()),this,SIGNAL(cancelarCnp()));
    connect(ui->pushButtonCancelMet,SIGNAL(clicked()),this,SIGNAL(cancelarMet()));
    connect(ui->pushButtonCancelOrto,SIGNAL(clicked()),this,SIGNAL(cancelarOrto()));
    connect(ui->pushButtonClose,SIGNAL(clicked()),this,SLOT(close()));
    resize(this->width(),20);
    setWindowFlags(Qt::WindowTitleHint);
    _WMet=0;
}

operacionProgresdialog::~operacionProgresdialog()
{
    delete ui;
}
void operacionProgresdialog::actualizarBarraCnp(int pos)
{
    ui->progressBarCnp->setValue(pos);
}
void operacionProgresdialog::actualizarBarraMet(int pos)
{
    qDebug() << "actualizarbarraMet" << pos << "pos";
    ui->progressBarMet->setValue(pos);
}
void operacionProgresdialog::actualizarBarraOrto(int pos)
{
    ui->progressBarOrto->setValue(pos);
}

void operacionProgresdialog::setCnpRange(int min, int max)
{
    cnpTerminado=false;
    ui->labelCancelCnp->setVisible(false);
    ui->progressBarCnp->setVisible(true);
    ui->labelCnp->setVisible(true);
    ui->pushButtonCancelCnp->setVisible(true);
    ui->progressBarCnp->setRange(min,max);
    checkCnpMetOrto();
}
void operacionProgresdialog::setMetRange(int min, int max)
{
    metTerminado=false;
    ui->labelCancelMet->setVisible(false);
    ui->progressBarMet->setVisible(true);
    ui->labelMet->setVisible(true);
    ui->pushButtonCancelMet->setVisible(true);
    ui->progressBarMet->setRange(min,max);
    checkCnpMetOrto();
}
void operacionProgresdialog::setOrtoRange(int min, int max)
{
    ortoTerminado=false;
    ui->labelCancelOrto->setVisible(false);
    ui->progressBarOrto->setVisible(true);
    ui->labelorto->setVisible(true);
    ui->pushButtonCancelOrto->setVisible(true);
    ui->progressBarOrto->setRange(min,max);
    checkCnpMetOrto();
}


bool operacionProgresdialog::isCnpTerminado()
{
 return cnpTerminado;
}
bool operacionProgresdialog::isMetTerminado()
{
 return metTerminado;
}
bool operacionProgresdialog::isOrtoTerminado()
{
return ortoTerminado;
}



//settersbool
void operacionProgresdialog::setCnpTerminado(bool estado )
{
 cnpTerminado=estado;
 checkCnpMetOrto();
 if(cnpTerminado)
 {
     disabledCancelCnp();
 }
 qDebug()<< cnpTerminado << "setCnpTerminado";
}
void operacionProgresdialog::setMetTerminado(bool estado )
{
 metTerminado=estado;
 checkCnpMetOrto();
 if(metTerminado)
 {
     disabledCancelMet();
 }
 qDebug()<< metTerminado << "setMetTerminado";
}
void operacionProgresdialog::setOrtoTerminado(bool estado)
{
  ortoTerminado=estado;
  checkCnpMetOrto();
  if(ortoTerminado)
  {
      disabledCancelOrto();
  }
  qDebug()<< ortoTerminado << "setOrtoTerminado";
}


void operacionProgresdialog::restCnpTerminado()
{
  cnpTerminado=true;
  qDebug()<< cnpTerminado << "restCnpTerminado";
}
void operacionProgresdialog::restMetTerminado()
{
  metTerminado=true;
  qDebug()<< metTerminado << "restMetTerminado";
}
void operacionProgresdialog::restOrtoTerminado()
{
  ortoTerminado=true;
  qDebug()<< ortoTerminado << "restOrtoTerminado";
}
void operacionProgresdialog::closeEvent(QCloseEvent *e)
{
 cnpTerminado=true;
 metTerminado=true;
 ortoTerminado=true;
 ui->progressBarCnp->setValue(0);
 ui->progressBarMet->setValue(0);
 ui->progressBarOrto->setValue(0);
 ui->progressBarCnp->setVisible(false);
 ui->labelCnp->setVisible(false);
 ui->pushButtonCancelCnp->setVisible(false);
 ui->progressBarMet->setVisible(false);
 ui->labelMet->setVisible(false);
 ui->pushButtonCancelMet->setVisible(false);
 ui->progressBarOrto->setVisible(false);
 ui->labelorto->setVisible(false);
 ui->pushButtonCancelOrto->setVisible(false);
 ui->labelAdvertenciaFallo->setVisible(false);
 ui->labelIconoAdvertencia->setVisible(false);
 ui->pushButtonFallo->setVisible(false);
 ui->textBrowserFallo->setVisible(false);
 ui->textBrowserFallo->clear();
 ui->pushButtonClose->setEnabled(false);
 resize(this->width(),20);
 QDialog::closeEvent(e);

}

void operacionProgresdialog::tratarErrores(QString error)
{

    ui->labelAdvertenciaFallo->setVisible(true);
    ui->labelIconoAdvertencia->setVisible(true);
    ui->pushButtonFallo->setVisible(true);
    ui->textBrowserFallo->insertPlainText(error);
}

void operacionProgresdialog::on_pushButtonFallo_clicked()
{
    ui->textBrowserFallo->setVisible(true);
}
void operacionProgresdialog::on_pushButtonCancelCnp_clicked()
{
    ui->progressBarCnp->setVisible(false);
    ui->labelCancelCnp->setVisible(true);
    ui->labelCancelCnp->setText("<font color='red'>Operacion Cancelada</font>");
}
void operacionProgresdialog::on_pushButtonCancelMet_clicked()
{
    ui->progressBarMet->setVisible(false);
    ui->labelCancelMet->setVisible(true);
    ui->labelCancelMet->setText("<font color='red'>Operacion Cancelada</font>");
}
void operacionProgresdialog::on_pushButtonCancelOrto_clicked()
{
    ui->progressBarOrto->setVisible(false);
    ui->labelCancelOrto->setVisible(true);
    ui->labelCancelOrto->setText("<font color='red'>Operacion Cancelada</font>");
}

void operacionProgresdialog::enableCancelCnp()
{
  ui->pushButtonCancelCnp->setEnabled(true);
}
void operacionProgresdialog::enableCancelMet()
{
  ui->pushButtonCancelMet->setEnabled(true);
}
void operacionProgresdialog::enableCancelOrto()
{
  ui->pushButtonCancelOrto->setEnabled(true);
}

void operacionProgresdialog::disabledCancelCnp()
{
  int maxMet=ui->progressBarCnp->maximum();
  cnpTerminado=true;
  ui->progressBarCnp->setValue(maxMet);
  ui->pushButtonCancelCnp->setDisabled(true);
  checkCnpMetOrto();
  qDebug()<< "disableCnp";
}
void operacionProgresdialog::disabledCancelMet()
{
  int maxMet=ui->progressBarMet->maximum();
  metTerminado=true;
  ui->progressBarMet->setValue(maxMet);
  ui->pushButtonCancelMet->setDisabled(true);
  checkCnpMetOrto();
  qDebug()<< "disableMet";
}
void operacionProgresdialog::disabledCancelOrto()
{
  int maxMet=ui->progressBarOrto->maximum();
  ortoTerminado=true;
  ui->pushButtonCancelOrto->setDisabled(true);
  ui->progressBarOrto->setValue(maxMet);
  checkCnpMetOrto();
  qDebug()<< "disableOrto";
}
void operacionProgresdialog::checkCnpMetOrto()
{
    qDebug()<< cnpTerminado << "cnpTerminado=true";
    qDebug()<< metTerminado << "metTerminado=true";
    qDebug()<< ortoTerminado << "ortoTerminado=true";
          if (cnpTerminado && metTerminado && ortoTerminado)
          {
             ui->pushButtonClose->setEnabled(true);
             qDebug()<< cnpTerminado << "if true checkCnpMetOrto";
          }
          else ui->pushButtonClose->setEnabled(false);
    }



