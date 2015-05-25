#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <CnpMetOrtoTP/createcnps.h>
#include <CnpMetOrtoTP/createmet.h>
#include <CnpMetOrtoTP/createorto.h>
#include <ControlOpeTP/lanzadoroperaciones.h>
#include <CnpMetOrtoTP/registrocreatecnps.h>
#include <CnpMetOrtoTP/registrocreatemet.h>
#include <CnpMetOrtoTP/registrocreateorto.h>
#include "dialogopreferencias.h"
#include <QSignalMapper>
#include <QSettings>
#include "dialogprogresoope.h"
#include <ProyectoTP/archivoproyecto.h>
#include "newprojectdialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:


private slots:
    void on_pushButtonEmpezarOperacionesMetOrto_clicked();
    void on_pushButton_clicked();
    void lanzarDialogoPreferencias();
    void mostrarDialogoProgreso();
    void nuevoProyecto();

    void cambiosEnProyecto(bool estado);

private:
    Ui::MainWindow *ui;
    bool _estadoCreateCnps;
    bool _estadoCreateMets;
    bool _estadoCreateOrtos;

    //Atributo de signal mapper
    QSignalMapper *mapeadorVistas;
    LanzadorOperaciones *_lanzadorOpe;
    RegistroCreateMet  ObjetoRegistroCreateMet;
    DialogProgresoOpe *_dialogoProgreso;

    ArchivoProyecto *_archivoProyecto;
};

#endif // MAINWINDOW_H
