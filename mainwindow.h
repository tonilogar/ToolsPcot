#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "createcnps.h"
#include "createmet.h"
#include "createorto.h"
#include "lanzadoroperaciones.h"
#include "registrocreatecnps.h"
#include "registrocreatemet.h"
#include "registrocreateorto.h"
#include "dialogopreferencias.h"
#include <QSignalMapper>

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
    //void setEstadoCnps(bool estado);
    //void setEstadoMets(bool estado);
    //void setEstadoOrtos(bool estado);

private slots:
    void on_pushButtonEmpezarOperacionesMetOrto_clicked();
    //void evaluacionCnpsMetsOrtos();
    void on_pushButton_clicked();
    void lanzarDialogoPreferencias();

private:
    Ui::MainWindow *ui;
    bool _estadoCreateCnps;
    bool _estadoCreateMets;
    bool _estadoCreateOrtos;

    //Atributo de signal mapper
    QSignalMapper *mapeadorVistas;
    LanzadorOperaciones *_lanzadorOpe;


RegistroCreateMet  ObjetoRegistroCreateMet;
};

#endif // MAINWINDOW_H
