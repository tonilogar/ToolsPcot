#ifndef DIALOGPROGRESOOPE_H
#define DIALOGPROGRESOOPE_H

#include <QDialog>
#include <controlworker.h>
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

private slots:
    void nuevoWorkerCnp(Worker *w);
    void nuevoWorkerMet(Worker *w);
    void nuevoWorkerOrto(Worker *w);
    void errorCnp(QString error);
    void errorMet(QString error);
    void errorOrto(QString error);


private:
    Ui::DialogProgresoOpe *ui;

};

#endif // DIALOGPROGRESOOPE_H
