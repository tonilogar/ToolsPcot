#ifndef DIALOGPROGRESOOPE_H
#define DIALOGPROGRESOOPE_H

#include <QDialog>
#include <controlworker.h>
#include <QCloseEvent>
namespace Ui {
class DialogProgresoOpe;
}

class DialogProgresoOpe : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProgresoOpe(QWidget *parent = 0);
    ~DialogProgresoOpe();
    void conectToControlCnp(ControlWorker *cWorker);
    void conectToControlMet(ControlWorker *cWorker);
    void conectToControlOrto(ControlWorker *cWorker);
    void limpiarErrorLog();
    void resetDialog();


public slots :



private slots:
    void nuevoWorkerCnp(Worker *w);
    void nuevoWorkerMet(Worker *w);
    void nuevoWorkerOrto(Worker *w);
    void errorCnp(QString error);
    void errorMet(QString error);
    void errorOrto(QString error);
    void on_pushButtonSowErrors_clicked();
    void cnpTerminado();
    void metTerminado();
    void ortoTerminado();

private:
    Ui::DialogProgresoOpe *ui;
    void hideAll();
    void setVisibleCnp(bool b);
    void setVisibleMet(bool b);
    void setVisibleOrto(bool b);
    void setVisibleErrorLog(bool b);
    void setVisibleError(bool b);
    void compruebaOperacionesTerminadas();
    bool  _cnpTerminado;
    bool  _metTerminado;
    bool  _ortoTerminado;
};

#endif // DIALOGPROGRESOOPE_H
