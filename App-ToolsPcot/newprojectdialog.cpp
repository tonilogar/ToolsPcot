#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    connect(ui->lineEditProject,SIGNAL(textChanged(QString)),this,SLOT(generarNombreFicheroProyecto(QString)));
connect(ui->toolButtonDateFlight,SIGNAL(clicked()),this,SLOT(lanzarCalendario()));
connect(ui->dateEditDateFlight,SIGNAL(dateChanged(QDate)),this,SLOT(cambiarFechaFichero(QDate)));
connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(crearArchivoProyecto()));
ui->dateEditDateFlight->setDisplayFormat("dd/MM/yyyy");
ui->dateEditDateFlight->setDate(QDate::currentDate());
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
void NewProjectDialog::crearArchivoProyecto()
{
    QSettings settings("tologar","ToolsPCOT",this);
QString dirProyecto=settings.value("directorioProyectos").toString();
//Casos de la direccion en windows o linux barras inclinadas

QFileInfo archivo;
archivo.setFile(QDir(dirProyecto),ui->lineEditProjectFile->text());
_aProyecto.setnameFileProyect(archivo.filePath());
_aProyecto.build(ui->lineEditProject->text(), ui->textEditDescription->toPlainText(), ui->lineEditAutor->text(),
                 ui->dateEditDateFlight->date());


}
