#ifndef CREATECNPS_H
#define CREATECNPS_H
#include "widgetcnpmetortotp_global.h"
#include <QWidget>
#include <QFileDialog>
#include <RegistroTP/registrocnp.h>

class RegistroCnp;

namespace Ui {
    class CreateCnps;
}

//Posibles estados de correccion
// 0 - no seleccionado, 1 - correcto, 2 - parcialmente correcto
class WIDGETCNPMETORTOTP_EXPORT CreateCnps : public QWidget
{
    Q_OBJECT

public:
    explicit CreateCnps(QWidget *parent = 0);
    ~CreateCnps();
    RegistroCnp * getObjetoRegistroCreateCnps();
    bool comprobarChecFolderCnps();
    void disconnectRegistro();
    void connectRegistro();

signals:

    void cambioEstadoCnps(bool state);
    void cambioEstadoCorreccionCnps(int state);

public slots:
    void activateWidget(bool acti);
    void enableOrDisableCreateCnp(int chec);
    void comprobarCorreccion(QString dato);

private slots:
    void on_pushButtonFolderOutCnps_clicked();
    void on_pushButtonDeleteDatesCnps_clicked();



private:
    Ui::CreateCnps *ui;
    RegistroCnp *punteroRegistroCreateCnps;
    QString folderOut;

};

#endif // CREATECNPS_H
