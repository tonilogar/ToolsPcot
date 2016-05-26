#include "widgetcnp.h"
#include "ui_widgetcnp.h"

WidgetCNP::WidgetCNP(QWidget *parent) :
    WidgetRegistro(parent),
    ui(new Ui::WidgetCNP)
{
    ui->setupUi(this);
    ui->pushButtonDeleteDataCnp->setDisabled(true);
    ui->label->setDisabled(true);
    ui->lineEditCnp->setDisabled(true);
    ui->toolButtonCnp->setDisabled(true);

    //Conectar el checkbox con el slot para activar y desactivar la interface

    connect(ui->checkBoxCnp,SIGNAL(stateChanged(int)),this,SLOT(activarWidget(int)));
    connect(ui->checkBoxCnp,SIGNAL(stateChanged(int)),this,SLOT(setCnpsEnabled(int)));
}

WidgetCNP::~WidgetCNP()
{
    delete ui;
}

void WidgetCNP::conectarInterface()
{
    ui->checkBoxCnp->setEnabled(true);
}

void WidgetCNP::desconectarInterface()
{
    ui->checkBoxCnp->setChecked(false);
    ui->checkBoxCnp->setEnabled(false);
}

void WidgetCNP::activarInterface()
{
    ui->pushButtonDeleteDataCnp->setEnabled(true);
    ui->label->setEnabled(true);
    ui->lineEditCnp->setEnabled(true);
    ui->toolButtonCnp->setEnabled(true);
}

void WidgetCNP::desactivarInterface()
{
    ui->pushButtonDeleteDataCnp->setEnabled(false);
    ui->label->setEnabled(false);
    ui->lineEditCnp->setEnabled(false);
    ui->toolButtonCnp->setEnabled(false);
    deleteData();
}

void WidgetCNP::checkEstadoCorreccion()
{
        QString directorio=ui->lineEditCnp->text();
        QFileInfo infoDir(directorio);
        if(infoDir.isDir())
            cambiarCorreccion(Correcto);
        else cambiarCorreccion(ParcialCorrecto);
}

void WidgetCNP::connectRegistro()
{
    //Obtener el puntero de registro a partir del puntero de seccion (AProTPSection)
    registro = qobject_cast<RegistroCnp*>(_aproRegistro);

    connect(registro,SIGNAL(cnpsEnabled(bool)),this,SLOT(changeOnCnpsEnabled(bool)));
    connect(registro,SIGNAL(changeFolderOut(QString)),this,SLOT(changeOnFolderOut(QString)));

    connect(ui->lineEditCnp,SIGNAL(textChanged(QString)),registro,SLOT(setFolderOut(QString)));
    connect(ui->toolButtonCnp,SIGNAL(clicked()),this,SLOT(selectOutFolder()));
    connect(ui->pushButtonDeleteDataCnp,SIGNAL(clicked()),this,SLOT(deleteData()));
connect(registro,SIGNAL(recargaSeccion(QVariantMap)),this,SLOT(recargaRegistro(QVariantMap)));
}

void WidgetCNP::changeOnCnpsEnabled(bool b)
{
    checkEstadoCorreccion();
}

void WidgetCNP::changeOnFolderOut(QString fOut)
{
    checkEstadoCorreccion();
}
void WidgetCNP::selectOutFolder()
{
    QString path=QFileDialog::getExistingDirectory(this,tr("Select out folder"));
    if(path.isEmpty() || path.isNull())
        return;
    ui->lineEditCnp->setText(path);
}

void WidgetCNP::setCnpsEnabled(int s)
{
    if(s==Qt::Checked)
        registro->setCnpsEnabled(true);
    else registro->setCnpsEnabled(false);
}


void WidgetCNP::deleteData()
{
    ui->lineEditCnp->clear();
}


void WidgetCNP::loadRegistro(QVariantMap mapa)
{
    //reiniciarStateMachine();
//    bool conectado=mapa.value("isLoadedCoordenadas").toBool();
//    conectarWidget(conectado);
//    bool enabled=mapa.value("cnpsEnabled").toBool();
//    if(enabled) {
//        activarWidget(Qt::Checked);
//        ui->checkBoxCnp->setChecked(enabled);
//    }
//    else {
//        activarWidget(Qt::Unchecked);
//        ui->checkBoxCnp->setChecked(false);
//    }
//    ui->lineEditCnp->setText(mapa.value("folderOut").toString());
//    checkEstadoCorreccion();

    ui->checkBoxCnp->setChecked(mapa.value("cnpsEnabled").toBool());
    ui->lineEditCnp->setText(mapa.value("folderOut").toString());
}




