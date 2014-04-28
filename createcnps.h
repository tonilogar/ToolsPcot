#ifndef CREATECNPS_H
#define CREATECNPS_H

#include <QWidget>
#include "tableviewcoordinates.h"
#include "registrocreatecnps.h"

namespace Ui {
    class CreateCnps;
}

//Posibles estados de correccion
// 0 - no seleccionado, 1 - correcto, 2 - parcialmente correcto
class CreateCnps : public QWidget
{
    Q_OBJECT

public:
    explicit CreateCnps(QWidget *parent = 0);
    ~CreateCnps();
    RegistroCreateCnps * getObjetoRegistroCreateCnps();   
    void setPunterotVCoordenadas(TableViewCoordinates *puntero);
    bool comprobarChecFolderCnps();
    //void createCnp();

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
    TableViewCoordinates *tVCoordenadas;
    QString folderOut;

};

#endif // CREATECNPS_H
