#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QDir>
#include <QFileInfo>
#include "calendardialog.h"
#include <ProyectoTP/archivoproyecto.h>
namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();
private slots:
    void generarNombreFicheroProyecto(QString valor);
    void lanzarCalendario();
    void cambiarFechaFichero(QDate fecha);
    void crearArchivoProyecto();


private:
    Ui::NewProjectDialog *ui;
    ArchivoProyecto _aProyecto;
};

#endif // NEWPROJECTDIALOG_H
