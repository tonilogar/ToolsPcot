#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "createcnps.h"
#include "createmet.h"
#include "createorto.h"
#include "lanzadoroperaciones.h"
#include "registrocnps.h"
#include "registromet.h"
#include "registroorto.h"
#include "dialogopreferencias.h"
#include <QSignalMapper>
#include <QSettings>
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
    void lanzarDialogoPreferencias();

private:
    Ui::MainWindow *ui;


    //Atributo de signal mapper
    QSignalMapper *mapeadorVistas;
    LanzadorOperaciones *_lanzadorOpe;
};

#endif // MAINWINDOW_H
