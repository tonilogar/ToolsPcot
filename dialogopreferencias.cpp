#include "dialogopreferencias.h"
#include "ui_dialogopreferencias.h"

DialogoPreferencias::DialogoPreferencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoPreferencias)
{
    ui->setupUi(this);

    //Conecto señales de los botones con los slots de busqueda
    connect(ui->metButton,SIGNAL(clicked()),this,SLOT(buscarArchivoMET()));
    connect(ui->ortoButton,SIGNAL(clicked()),this,SLOT(buscarArchivoORTO()));

    //Cargar datos de settings
    QSettings settings("tologar","ToolsPCOT",this);

    QString pathMet,pathOrto;

    pathMet=settings.value("variablesMET").toString();
    pathOrto=settings.value("variablesORTO").toString();
    qDebug()<< pathMet << "pathMet";
    ui->metEdit->setText(pathMet);
    ui->ortoEdit->setText(pathOrto);

    _isChanged=false;
}

DialogoPreferencias::~DialogoPreferencias()
{
    delete ui;
}

void DialogoPreferencias::buscarArchivoMET()
{
    QString path=QFileDialog::getOpenFileName(this,
                                              "Preferencias - Seleccionar archivo de ambito MET",
                                              qApp->applicationDirPath(),
                                              "Archivo JSON (*.txt)");

    if(path.isNull() || path.isEmpty())
        return;

    ui->metEdit->setText(path);
    _isChanged=true;
}

void DialogoPreferencias::buscarArchivoORTO()
{
    QString path=QFileDialog::getOpenFileName(this,
                                              "Preferencias - Seleccionar archivo de ambito ORTO",
                                              qApp->applicationDirPath(),
                                              "Archivo JSON (*.txt)");

    if(path.isNull() || path.isEmpty())
        return;

    ui->ortoEdit->setText(path);
    _isChanged=true;
}

void DialogoPreferencias::accept()
{
    QSettings settings("tologar","ToolsPCOT",this);

    settings.setValue("variablesMET",ui->metEdit->text());
    settings.setValue("variablesORTO",ui->ortoEdit->text());
    QString pathMet=settings.value("variablesMET").toString();
    qDebug() << pathMet << "pathmetDentroPreferencias";
    emit cambiosArchivoMet();
    emit cambiosArchivoOrto();
    QDialog::accept();

}
