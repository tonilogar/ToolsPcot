#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    connect(ui->lineEditProject,SIGNAL(textChanged(QString)),this,SLOT(generarNombreFicheroProyecto(QString)));
    connect(ui->toolButtonDateFlight,SIGNAL(clicked()),this,SLOT(lanzarCalendario()));
    connect(ui->toolButtonFolderProject,SIGNAL(clicked()),this,SLOT(cambiarFolderProject()));
    connect(ui->dateEditDateFlight,SIGNAL(dateChanged(QDate)),this,SLOT(cambiarFechaFichero(QDate)));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(crearArchivoProyecto()));
    QSettings settings("tologar","ToolsPCOT",this);
    QString dirProyecto=settings.value("directorioProyectos").toString();
    ui->lineEditFolderProject->setText(dirProyecto);
    ui->dateEditDateFlight->setDisplayFormat("dd/MM/yyyy");
    ui->dateEditDateFlight->setDate(QDate::currentDate());

    _aProyecto=0;
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

void NewProjectDialog::generarNombreFicheroProyecto(QString valor)
{
    if(valor.isEmpty() || valor.isNull())
    {
        ui->lineEditProjectFile->setText(valor);
        return;
    }
    QString fecha=ui->dateEditDateFlight->date().toString("ddMMyyyy");
    ui->lineEditProjectFile->setText(valor+"_"+fecha+".tpc");

}
void NewProjectDialog::lanzarCalendario()
{
    CalendarDialog calendario;
    calendario.setSelectDate(ui->dateEditDateFlight->date());
    calendario.exec();
    ui->dateEditDateFlight->setDate(calendario.getSelectDate());
}
void NewProjectDialog::cambiarFechaFichero(QDate fecha)
{
    if(ui->lineEditProject->text().isEmpty() || ui->lineEditProject->text().isNull())
    {
        return;
    }
    QString fechaText=fecha.toString("ddMMyyyy");
    ui->lineEditProjectFile->setText(ui->lineEditProject->text()+"_"+fechaText+".tpc");
}
void NewProjectDialog::cambiarFolderProject()
{
    QString newFolderProject=QFileDialog::getExistingDirectory(this,tr("select folder project"),ui->lineEditFolderProject->text());
    if(newFolderProject.isEmpty())
    {
        return;
    }
    ui->lineEditFolderProject->setText(newFolderProject);
}

void NewProjectDialog::crearArchivoProyecto()
{
    if(!checkDates())
    {
        QMessageBox::warning(this,tr("ToolsPCot - New projecto"),tr("write de name of project"));
        return;
    }

    QString dirProyecto=ui->lineEditFolderProject->text();
    //Casos de la direccion en windows o linux barras inclinadas

    QFileInfo archivo;
    archivo.setFile(QDir(dirProyecto),ui->lineEditProjectFile->text());

    _aProyecto=new ArchivoProyecto(this,archivo.filePath());
    _aProyecto->setnameProyect(ui->lineEditProject->text());
    _aProyecto->setdescriptionProyecte(ui->textEditDescription->toPlainText());
    _aProyecto->setautorProyect(ui->lineEditAutor->text());
    _aProyecto->setdateflight(ui->dateEditDateFlight->date());
}
bool NewProjectDialog::checkDates()
{
    if(ui->lineEditProject->text().isEmpty() || ui->lineEditProject->text().isNull() )
    {
        return false;
    }
    return true;
}
