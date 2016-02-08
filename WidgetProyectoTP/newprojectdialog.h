#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include "widgetproyectotp_global.h"

#include <QDialog>
#include <QSettings>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include "calendardialog.h"
#include <ProyectoTP/archivoproyecto.h>

namespace Ui {
class NewProjectDialog;
}

class WIDGETPROYECTOTPSHARED_EXPORT NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();
    bool checkDates();
    ArchivoProyecto *getArchivoProyecto();
private slots:
    void generarNombreFicheroProyecto(QString valor);
    void lanzarCalendario();
    void cambiarFechaFichero(QDate fecha);
    void cambiarFolderProject();
    void crearArchivoProyecto();


private:
    Ui::NewProjectDialog *ui;
    ArchivoProyecto *_aProyecto;
};

#endif // NEWPROJECTDIALOG_H
