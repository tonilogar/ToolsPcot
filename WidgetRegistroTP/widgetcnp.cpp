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







