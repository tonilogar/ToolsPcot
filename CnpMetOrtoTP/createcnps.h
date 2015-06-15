#ifndef CREATECNPS_H
#define CREATECNPS_H
#include "cnpmetortotp_global.h"
#include <QWidget>
#include <QFileDialog>
#include "registrocreatecnps.h"

class RegistroCreateCnps;

namespace Ui {
    class CreateCnps;
}

//Posibles estados de correccion
// 0 - no seleccionado, 1 - correcto, 2 - parcialmente correcto
class CNPMETORTOTPSHARED_EXPORT CreateCnps : public QWidget
{
    Q_OBJECT

public:
    explicit CreateCnps(QWidget *parent = 0);
    ~CreateCnps();
    RegistroCreateCnps * getObjetoRegistroCreateCnps();   
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
    RegistroCreateCnps *punteroRegistroCreateCnps;
    QString folderOut;

};

#endif // CREATECNPS_H
