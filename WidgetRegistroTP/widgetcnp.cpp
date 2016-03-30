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

}

void WidgetCNP::desactivarInterface()
{

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
}

void WidgetCNP::changeOnCnpsEnabled(bool b)
{
    checkEstadoCorreccion();
}

void WidgetCNP::changeOnFolderOut(QString fOut)
{
    checkEstadoCorreccion();
}
