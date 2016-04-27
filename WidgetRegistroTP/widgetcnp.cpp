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
    QString rutaCorrecta("/home/bardo/Workbench/Qt/ClasesQt/salidaToolspcot");
    if(directorio!=rutaCorrecta)
        cambiarCorreccion(ParcialCorrecto);
    else
        cambiarCorreccion(Correcto);

}

void WidgetCNP::connectRegistro()
{
    //Obtener el puntero de registro a partir del puntero de seccion (AProTPSection)
    RegistroCnp *registro = qobject_cast<RegistroCnp*>(_aproRegistro);

    connect(registro,SIGNAL(cnpsEnabled(bool)),this,SLOT(changeOnCnpsEnabled(bool)));
    connect(registro,SIGNAL(changeFolderOut(QString)),this,SLOT(changeOnFolderOut(QString)));
    connect(ui->toolButtonCnp,SIGNAL(clicked()),this,SLOT(selectOutFolder()));
    connect(ui->pushButtonDeleteDataCnp,SIGNAL(clicked()),this,SLOT(deleteData()));
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

void WidgetCNP::deleteData()
{
    ui->lineEditCnp->clear();
}







