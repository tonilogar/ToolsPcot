#ifndef CREATEORTO_H
#define CREATEORTO_H

#include <QWidget>
#include <QSettings>
#include "tableviewcoordinates.h"
#include "registrocreateorto.h"
#include "ficherodatosambitopro.h"
#include <OperacionPcot/datazoneproject.h>

namespace Ui {
    class CreateOrto;
}

//Posibles estados de correccion
// 0 - no seleccionado, 1 - correcto, 2 - parcialmente correcto
class CreateOrto : public QWidget
{
    Q_OBJECT

public:

    explicit CreateOrto(QWidget *parent = 0);
    ~CreateOrto();
    RegistroCreateOrto * getObjetoRegistroCreateOrto();
    void setPunterotVCoordenadas(TableViewCoordinates *puntero);

signals:
   void cambioEstadoOrto(bool state);
   void cambioEstadoCorreccionOrto(int state);

public slots:
    void activateWidget(bool acti);
    void onCambioComboBoxAmbitoProyectoOrto(int text);
    void calcularOffsetPasada(int offsetPasada);
    void enableOrDisableExtraerOrto(int chec);
    void enableOrDisableFootPrintMaskOrto(int chec);
    void enableOrDisableCortarOrto(int chec);
    //Codigo nuevo
    void cambioestadoCheckBox(int estado);
    void cambioestadoComboBox(int estado );
    void cambioestadoLineEdit(QString directorio);

    void VigilarTamanyPixel(int tamanyoPixel);
    void VigilarCoorSysOrto(int corSys);
    void VigilarSelectSensor(int sens);
    void VigilarTamanyoCorte(int tamanyoCorte);
    void VigilarNumeroCanales(int numeroCanales);
    void VigilarAnchoPasada(int anchoPasada);
    void VigilarOffsetPasada(int offsetPasada);
    void recargarModelosAmbito();
private slots:
    void on_pushButtonFolderOutOrto_clicked();
    void on_pushButtonDeleteDatesOrto_clicked();

private:
    Ui::CreateOrto *ui;
    RegistroCreateOrto *punteroRegistroCreateOrto;
    TableViewCoordinates *tVCoordenadas;
    QString folderOut;
    void evaluarEstadoWidgetOrto();
    QString _ambitoOperacion;                          ///< Valor del ambito de la operación.
    int _coordinateSystem;                    ///< Valor del sistema de coordenadas.
    double tP;
};

#endif // CREATEORTO_H

