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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PreferenciasAvanzadasDialog *_preferenciasAvanzadas;
    AmbitJson *_archivoAmbito;
    AlertFileJson *_objetoAlertFileJson;

    void setup();

    void comprobarSettings();
    void cargarAmbitos();
};

#endif // MAINWINDOW_H
