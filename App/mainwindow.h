#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <AmbitoTP/ambitjson.h>
#include <AmbitoTP/ambito.h>

#include <RegistroTP/registrocnp.h>
#include <RegistroTP/registromet.h>
#include <RegistroTP/registroorto.h>
#include <QSettings>
#include <QDebug>
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
private slots:
    void pepe();
    void comprobarSettings();
    void setup();


private:
    Ui::MainWindow *ui;
    PreferenciasAvanzadasDialog *_preferenciasAvanzadas;
    AmbitJson *_archivoAmbito;
    AlertFileJson *_objetoAlertFileJson;
    EditorAmbitoDialog *_objetoEditorAmbitoDialog;



    void cargarAmbitos();
};

#endif // MAINWINDOW_H
