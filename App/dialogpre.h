#ifndef DIALOGPRE_H
#define DIALOGPRE_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <AmbitoTP/ambito.h>
#include "alertfilejson.h"

namespace Ui {
class DialogPre;

}

class DialogPre : public QDialog
{
    Q_OBJECT

public:
    /*!
     * Constructor explicito, necesita un puntero nulo.
     */
    explicit DialogPre(QWidget *parent = 0);
    ~DialogPre();
    /*!
     * Obtiene los datos de los lineEdit y los utiliza para modificar los datos del Json.
     */
    void EditFileJson();


    /*!
     * Desactiva o activa los widgets relacionados con la imagen met de Catalunya.
     */
    void disableImageCat(bool disaOrEna);   
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCADBDTMEXTRACTIONCONSOLEVERSION.exe.
     */
    void disableExeExtraCat(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageresize.exe.
     */
    void disableExeResiCat(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageFootPrintMask.exe.
     */
    void disableExeFootPCat(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageSubescenes.exe.
     */
    void disableExeSubCat(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageGeoTransformation.exe.
     */
    void disableExeImaOpeCat(bool disaOrEna);


    /*!
     * Desactiva o activa los widgets relacionados con la imagen met de España.
     */
    void disableImageEsp(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageFootPrintMask.exe.
     */
    void disableExeFootPEsp(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageresize.exe.
     */
    void disableExeResiEsp(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageSubescenes.exe.
     */
    void disableExeSubEsp(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageGeoTransformation.exe.
     */
    void disableExeImaOpeEsp(bool disaOrEna);


    /*!
     * Desactiva o activa los widgets relacionados con la imagen met de Francia.
     */
    void disableImageFra(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageFootPrintMask.exe.
     */
    void disableExeFootPFra(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageresize.exe.
     */
    void disableExeResiFra(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageSubescenes.exe.
     */
    void disableExeSubFra(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageresize.exe.
     */
    void disableExeResiFra01(bool disaOrEna);





private:
    Ui::DialogPre *ui;
    QString _openDirImage;///< Variable que se utiliza como direccion para seleccionar las imagenes met.
    QString _openDirExe;///< Variable que se utiliza como direccion para seleccionar los ejecutables.
    Ambito *_objetoAmbito; ///< Puntero a objeto SettingPreferencias.
    AlertFileJson *_alert;///< Puntero del la clase AlertFileJson para mostrar el mensaje de alerta si no se seleccionan todos los ficheros necesarios
    bool check;
private slots:
    /*!
     * Lanza una ventana para seleccionar la imagen met de Catalunya.
     */
    void selectMetCat();
    /*!
     * Lanza una ventana para seleccionar la imagen met de España.
     */
    void selectMetEsp();
    /*!
     * Lanza una ventana para seleccionar la imagen met de Francia.
     */
    void selectMetFra();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageSubescenes.exe.
     */
    void selectExeSub();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageGeoTransformation.exe.
     */
    void selectExeImaOpe();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageFootPrintMask.exe.
     */
    void selectExeFootP();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCADBDTMEXTRACTIONCONSOLEVERSION.exe.
     */
    void selectExeExtra();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageresize.exe.
     */
    void selectExeResi();

    void selectOk();
    void selectCancel();
};

#endif // DIALOGPRE_H
