#include "widgetmet.h"
#include "ui_widgetmet.h"

WidgetMet::WidgetMet(QWidget *parent) :
    WidgetRegistro(parent),
    ui(new Ui::WidgetMet)
{
    ui->setupUi(this);
    ui->pushButtonDeleteDataMet->setDisabled(true);
    ui->labelAmbitoProyectoMet->setDisabled(true);
    ui->labelAnchoPasadaMet->setDisabled(true);
    ui->labelCoordinateSystemMet->setDisabled(true);
    ui->labelCortarMet->setDisabled(true);
    ui->labelNumeroCanalesspasadaMet->setDisabled(true);
    ui->labelOffsetPasadaMet->setDisabled(true);
    ui->labelOutFolderMet->setDisabled(true);
    ui->labelSelectSensor->setDisabled(true);
    ui->labelTamanyoPixelMet->setDisabled(true);      
    ui->lineEditMet->setDisabled(true);
    ui->toolButtonMet->setDisabled(true);
    ui->doubleSpinBoxTamanyoPixelMet->setDisabled(true);
    ui->comboBoxCoordinateSystemMet->setDisabled(true);
    ui->comboBoxMet->setDisabled(true);
    ui->comboBoxSelectSensor->setDisabled(true);
    ui->spinBoxAnchoPasadaMet->setDisabled(true);
    ui->spinBoxCortarMet->setDisabled(true);
    ui->spinBoxNumeroCanalesspasadaMet->setDisabled(true);
    ui->spinBoxOffsetPasadaMet->setDisabled(true);



    connect(ui->checkBoxMet,SIGNAL(stateChanged(int)),this,SLOT(activarWidget(int)));
    connect(ui->checkBoxMet,SIGNAL(stateChanged(int)),this,SLOT(setMetEnabled(int)));
}

WidgetMet::~WidgetMet()
{
    delete ui;
}

void WidgetMet::conectarInterface()
{
  ui->checkBoxCortarMet->setEnabled(true);
  ui->checkBoxFootPrintMaskMet->setEnabled(true);
  ui->checkBoxMet->setEnabled(true);
}
void WidgetMet::desconectarInterface()
{
    ui->checkBoxMet->setChecked(false);
    ui->checkBoxMet->setEnabled(false);
    ui->checkBoxCortarMet->setChecked(false);
    ui->checkBoxCortarMet->setEnabled(false);
    ui->checkBoxFootPrintMaskMet->setChecked(false);
    ui->checkBoxFootPrintMaskMet->setEnabled(false);
}
void WidgetMet::activarInterface()
{
ui->pushButtonDeleteDataMet->setEnabled(true);
ui->labelOutFolderMet->setEnabled(true);
ui->labelAmbitoProyectoMet->setEnabled(true);
ui->labelTamanyoPixelMet->setEnabled(true);
ui->labelCoordinateSystemMet->setEnabled(true);
ui->toolButtonMet->setEnabled(true);
ui->doubleSpinBoxTamanyoPixelMet->setEnabled(true);
ui->comboBoxCoordinateSystemMet->setEnabled(true);
ui->comboBoxMet->setEnabled(true);
}

void WidgetMet::desactivarInterface()
{
    ui->pushButtonDeleteDataMet->setEnabled(false);
    ui->labelOutFolderMet->setEnabled(false);
    ui->labelAmbitoProyectoMet->setEnabled(false);
    ui->labelTamanyoPixelMet->setEnabled(false);
    ui->labelCoordinateSystemMet->setEnabled(false);
    ui->toolButtonMet->setEnabled(false);
    ui->doubleSpinBoxTamanyoPixelMet->setEnabled(false);
    ui->comboBoxCoordinateSystemMet->setEnabled(false);
    ui->comboBoxMet->setEnabled(false);
    deleteData();
}

void WidgetMet::checkEstadoCorreccion()
{

}
void WidgetMet::connectRegistro()
{
    //Obtener el puntero de registro a partir del puntero de seccion (AProTPSection)
    registro = qobject_cast<RegistroMet*>(_aproRegistro);

    connect(registro,SIGNAL(metEnabled(bool)),this,SLOT(changeOnMetEnabled(bool)));
    connect(registro,SIGNAL(changeFolderOut(QString)),this,SLOT(changeOnFolderOut(QString)));


}
void WidgetMet::setMetEnabled(int s)
{
    if(s==Qt::Checked)
        registro->setMetEnabled(true);
    else registro->setMetEnabled(false);
}
void WidgetMet::changeOnMetEnabled(bool b)
{

}
void WidgetMet::changeOnFolderOut(QString fOut)
{
    checkEstadoCorreccion();
}
void WidgetMet::selectOutFolder()
{
    QString path=QFileDialog::getExistingDirectory(this,tr("Select out folder"));
    if(path.isEmpty() || path.isNull())
        return;
    ui->lineEditMet->setText(path);
}
void WidgetMet::deleteData()
{
ui->lineEditMet->clear();
}
void WidgetMet::loadRegistro(QVariantMap mapa)
{
//    ui->lineEditCnp->setText(mapa.value("folderOut").toString());
//    ui->checkBoxCnp->setEnabled(mapa.value("cnpsEnable").toBool());
}
