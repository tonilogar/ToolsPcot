#ifndef CREATEMET_H
#define CREATEMET_H
#include "cnpmetortotp_global.h"
#include <QWidget>
#include <QSettings>
#include "registrocreatemet.h"
#include "ficherodatosambitopro.h"
#include <OpePcot/datazoneproject.h>
#include <QMessageBox>

namespace Ui {
    class CreateMet;
}

//Posibles estados de correccion
// 0 - no seleccionado, 1 - correcto, 2 - parcialmente correcto
class CNPMETORTOTPSHARED_EXPORT CreateMet : public QWidget
{
    Q_OBJECT

public:

    explicit CreateMet(QWidget *parent = 0);
    ~CreateMet();
    RegistroCreateMet * getObjetoRegistroCreateMet();

signals:
   void cambioEstadoMet(bool state);
   void cambioEstadoCorreccionMet(int state);

public slots:
    void activateWidget(bool acti);
    void onCambioComboBoxAmbitoProyectoMet(int text);
    void calcularOffsetPasada(int offsetPasada);
    void enableOrDisableExtraerMet(int chec);
    void enableOrDisableFootPrintMaskMet(int chec);
    void enableOrDisableCortarMet(int chec);
    //Codigo nuevo
    void cambioestadoCheckBox(int estado);
    void cambioestadoComboBox(int estado );
    void cambioestadoLineEdit(QString directorio);

    void VigilarTamanyPixel(int tamanyoPixel);
    void VigilarCoorSysMet(int corSys);
    void VigilarSelectSensor(int sens);
    void VigilarTamanyoCorte(int tamanyoCorte);
    void VigilarNumeroCanales(int numeroCanales);
    void VigilarAnchoPasada(int anchoPasada);
    void VigilarOffsetPasada(int offsetPasada);
    void recargarModelosAmbito();
private slots:
    void on_pushButtonFolderOutMet_clicked();
    void on_pushButtonDeleteDatesMet_clicked();

private:
    Ui::CreateMet *ui;
    RegistroCreateMet *punteroRegistroCreateMet;
    QString folderOut;
    void evaluarEstadoWidgetMet();
    QString _ambitoOperacion;                          ///< Valor del ambito de la operación.
    int _coordinateSystem;                    ///< Valor del sistema de coordenadas.
    double tP;
};

#endif // CREATEMET_H
