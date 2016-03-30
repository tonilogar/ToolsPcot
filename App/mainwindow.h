#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QDebug>
#include <QSettings>
#include <QFileDialog>
#include <AmbitoTP/ambitjson.h>
#include <AmbitoTP/ambito.h>
#include <AmbitoTP/ambjsonevaluador.h>
#include <AmbitoTP/ambjsonnumtest.h>
#include <AmbitoTP/ambjsonnombretest.h>
#include <AmbitoTP/ambjsoncatalunyatest.h>
#include <AmbitoTP/ambjsonespanyatest.h>
#include <AmbitoTP/ambjsonfranciatest.h>
#include <RegistroTP/registrocnp.h>
#include <RegistroTP/registromet.h>
#include <RegistroTP/registroorto.h>
#include <WidgetProyectoTP/calendardialog.h>
#include <WidgetProyectoTP/newprojectdialog.h>
#include <ProyectoTP/archivoproyecto.h>
#include <ProyectoTP/aprotpsection.h>
#include "preferenciasavanzadasdialog.h"
#include "alertfilejson.h"
#include "editorambitodialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);

private slots:

    void setup();
    void selectFileCoor();
    void nuevoproyecto();
    void abrirProyecto();
    void cambiosEnProyecto(bool estado);
    void guardarProyecto();

signals:

    void activarWidgetsRegistro(bool data);

private:
    Ui::MainWindow *ui;
    PreferenciasAvanzadasDialog *_preferenciasAvanzadas;
    AmbitJson *_archivoAmbito;
    AlertFileJson *_objetoAlertFileJson;
    EditorAmbitoDialog *_objetoEditorAmbitoDialog;
    RegistroCnp *_registroCnp;

    ArchivoProyecto *_proyectoActual;


    void cargarAmbitos();
};

#endif // MAINWINDOW_H
