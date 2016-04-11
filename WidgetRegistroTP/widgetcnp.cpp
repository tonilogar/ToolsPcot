#include "widgetcnp.h"
#include "ui_widgetcnp.h"

WidgetCNP::WidgetCNP(QWidget *parent) :
    WidgetRegistro(parent),
    ui(new Ui::WidgetCNP)
{
    ui->setupUi(this);
    setEstadoInterface(false);
}

WidgetCNP::~WidgetCNP()
{
    delete ui;
}

void WidgetCNP::activarInterface()
{
    ui->checkBoxCnp->setDisabled(0);
    ui->pushButtonDeleteDataCnp->setDisabled(0);
    ui->label->setDisabled(0);
    ui->lineEditCnp->setDisabled(0);
    ui->toolButtonCnp->setDisabled(0);
}

void WidgetCNP::desactivarInterface()
{
ui->checkBoxCnp->setDisabled(1);
ui->pushButtonDeleteDataCnp->setDisabled(1);
ui->label->setDisabled(1);
ui->lineEditCnp->setDisabled(1);
ui->toolButtonCnp->setDisabled(1);
}

void WidgetCNP::checkEstadoCorreccion()
{
    qDebug() << "CHEQUEANDO ESTADO DE CORRECCION";
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







