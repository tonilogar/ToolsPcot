#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include "calendardialog.h"
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


private:
    Ui::NewProjectDialog *ui;
};

#endif // NEWPROJECTDIALOG_H
