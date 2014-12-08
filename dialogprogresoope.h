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
    void visibleCnp(bool b);
    void visibleMet(bool b);
    void visibleOrto(bool b);
    void visibleClose(bool b);
    void closeDisableEnable();
    void cnpEnd();
    void metEnd();
    void ortoEnd();


private slots:
    void nuevoWorkerCnp(Worker *w);
    void nuevoWorkerMet(Worker *w);
    void nuevoWorkerOrto(Worker *w);
    void errorCnp(QString error);
    void errorMet(QString error);
    void errorOrto(QString error);
    void disableCancelCnp();
    void disableCancelMet();
    void disableCancelOrto();
    void setCnpEnd();
    void setMetEnd();
    void setOrtoEnd();
private:
    Ui::DialogProgresoOpe *ui;
    bool _cnpEnd;
    bool _metEnd;
    bool _ortoEnd;

};

#endif // DIALOGPROGRESOOPE_H
