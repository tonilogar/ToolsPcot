#ifndef OPERACIONPROGRESDIALOG_H
#define OPERACIONPROGRESDIALOG_H
#include <QCloseEvent>
#include <QDialog>

namespace Ui {
class operacionProgresdialog;
}

class operacionProgresdialog : public QDialog
{
    Q_OBJECT

public:
    explicit operacionProgresdialog(QWidget *parent = 0);
    ~operacionProgresdialog();

    //getter
    bool isCnpTerminado();
    bool isMetTerminado();
    bool isOrtoTerminado();
    //settersbool

    void restCnpTerminado();
    void restMetTerminado();
    void restOrtoTerminado();
signals:
    void cancelarCnp();
    void cancelarMet();
    void cancelarOrto();
public slots:
    void setCnpTerminado(bool estado);
    void setMetTerminado(bool estado);
    void setOrtoTerminado(bool estado);
    void actualizarBarraCnp(int pos);
    void actualizarBarraMet(int pos);
    void actualizarBarraOrto(int pos);
    void setCnpRange(int min, int max);
    void setMetRange(int min, int max);
    void setOrtoRange(int min, int max);
    void tratarErrores(QString error);
    void enableCancelCnp();
    void enableCancelMet();
    void enableCancelOrto();
    void disabledCancelCnp();
    void disabledCancelMet();
    void disabledCancelOrto();
    void checkCnpMetOrto();
private:
    Ui::operacionProgresdialog *ui;
    bool metTerminado;
    bool ortoTerminado;
    bool cnpTerminado;

protected:
    void closeEvent(QCloseEvent *e);
private slots:
    void on_pushButtonFallo_clicked();
    void on_pushButtonCancelMet_clicked();

    void on_pushButtonCancelOrto_clicked();
    void on_pushButtonCancelCnp_clicked();
};

#endif // OPERACIONPROGRESDIALOG_H
