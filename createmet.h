#ifndef CREATEMET_H
#define CREATEMET_H

#include <QWidget>
#include <QSettings>
#include "tableviewcoordinates.h"
#include "registrocreatemet.h"
#include "ficherodatosambitopro.h"

namespace Ui {
    class CreateMet;
}

//Posibles estados de correccion
// 0 - no seleccionado, 1 - correcto, 2 - parcialmente correcto
class CreateMet : public QWidget
{
    Q_OBJECT

public:
//    /*!
//     * Crea e inicializa la variable enum Ambito.
//     *
//     */
//    enum Ambito{
//        Catalunya, Espanya, Francia, Zone
//    };

//    /*!
//     * Crea e inicializa la variable enum sistemaCoor.
//     *
//     */
//    enum sistemaCoor{
//        Etrs89, Ed50, Ntf, Coordinates
//    };

    explicit CreateMet(QWidget *parent = 0);
    ~CreateMet();
    RegistroCreateMet * getObjetoRegistroCreateMet();
    void setPunterotVCoordenadas(TableViewCoordinates *puntero);

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

    void VigilarTamanyPixel(double tamanyoPixel);
    void VigilarCoorSysMet(QString corSys);
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
    TableViewCoordinates *tVCoordenadas;
    QString folderOut;
    void evaluarEstadoWidgetMet();
    QString _ambitoOperacion;                          ///< Valor del ambito de la operación.
    int _coordinateSystem;                    ///< Valor del sistema de coordenadas.
};

#endif // CREATEMET_H
