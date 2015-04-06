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
    connect(ui->buttonDirectorioProyectos,SIGNAL(clicked()),this,SLOT(buscarDirectorioProyectos()));
    //Cargar datos de settings
    QSettings settings("tologar","ToolsPCOT",this);

    QString pathMet,pathOrto,pathDirectorioProyectos;

    pathMet=settings.value("variablesMET").toString();
    pathOrto=settings.value("variablesORTO").toString();
    pathDirectorioProyectos=settings.value("directorioProyectos").toString();
    qDebug()<< pathMet << "pathMet";
    ui->metEdit->setText(pathMet);
    ui->ortoEdit->setText(pathOrto);
    ui->editDirectorioProyectos->setText(pathDirectorioProyectos);

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
void DialogoPreferencias::buscarDirectorioProyectos()
{
    QString path=QFileDialog::getExistingDirectory(this,
                                              "Preferencias - Seleccionar directorio de proyectos",
                                              qApp->applicationDirPath());
    if(path.isNull() || path.isEmpty())
        return;
    ui->editDirectorioProyectos->setText(path);
    _isChanged=true;
}

void DialogoPreferencias::accept()
{
    QSettings settings("tologar","ToolsPCOT",this);

    settings.setValue("variablesMET",ui->metEdit->text());
    settings.setValue("variablesORTO",ui->ortoEdit->text());
    settings.setValue("directorioProyectos",ui->editDirectorioProyectos->text());
    emit cambiosArchivoMet();
    emit cambiosArchivoOrto();
    emit cambiosDirectorioProyecto();
    QDialog::accept();

}
