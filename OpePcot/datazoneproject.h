#ifndef DATAZONEPROJECT_H
#define DATAZONEPROJECT_H
#include "operacionpcot_global.h"
#include <QObject>
#include <QVariantMap>

/*!
 * @class DataZoneProject
 * @brief DataZoneProject valores necesarios para las caracteristicas del met
 *
 * Cada objeto nos proporciona los datos necesarios para cortar el met.
 * Ambito de proyecto.
 * Image base.
 * Tamaño de pixel.
 * Sistema de coordenadas.
 * Numero de canales.
 * Ancho de pasada.
 * Offsset de pasada.
 * metodo footPrintMask on off
 * corte de met on off
 */
class OPERACIONPCOTSHARED_EXPORT DataZoneProject : public QObject
{
    Q_OBJECT
public:

    /*!
     * Crea e inicializa la variable enum Ambito.
     *
     */
    enum Ambito{
        Catalunya, Espanya, Francia, Otro
    };

    /*!
     * Crea e inicializa la variable enum sistemaCoor.
     *
     */
    enum sistemaCoor{
        Etrs89, Ed50, Ntf, vacio
    };
    /*!
     * Crea e inicializa la variable enum sistemaCoor.
     *
     */
    enum Sensor{
        Casi, Tasi, Aisa, Aisa_BE, Vacio
    };

    /*!
     * Constructor explicito por defecto, solo necesita un puntero nulo
     *
     */
    explicit DataZoneProject(QObject *parent = 0);
    /*!
     * Constructor necesita un puntero nulo,y los valores de los atributos de la clase
     *
     */
    DataZoneProject(QObject *parent,QString zoneProject, QString imageProject, double sizePixel, sistemaCoor coordinateSystem, bool cutDtm,
                        int sizeCut, int numberCanals, bool footPrintMask, int anchoPasada, int offsetPasada, QString folderOut, Ambito ambitoOperacion,
                        Sensor selectSensor);

    /*!
    * Cambia la zona del ambito de la operación.
    * @param Ambito nuevo valor para el indicador Ambito .
    *
    */
    void setAmbitoOperacion(Ambito ambitoOperacion);

    /*!
     * Cambia el valor del sistema de coordenadas.
     * @param coordinateSystem nuevo valor del sistema de coordenadas.
     *
     */
    void setCoordinateSystem(sistemaCoor coordinateSystem);
    /*!
     * Cambia el valor del sensor.
     * @param coordinateSystem nuevo valor de sensor.
     *
     */
    void setSelectSensor(Sensor selectSensor);

    //Getter

    /*!
     * Muestra el ambito de proyecto .
     *
     */
    DataZoneProject::Ambito getAmbitoOperacion();


    /*!
     * Muestra el ambito de proyecto .
     *
     */
    DataZoneProject::sistemaCoor getCoordinateSystem();

    /*!
     * Muestra el sensor seleccionado .
     *
     */
    DataZoneProject::Sensor getSelectSensor();

    /*!
     * Muestra el nombre de la zona del proyecto.
     *
     */
    QString getZoneProject();

    /*!
     * Muestra el nombre de la imagen original.
     *
     */
    QString getImageProject();

    /*!
     * Muestra el tamanyo de pixel.
     *
     */
    double getSizePixel();

    /*!
     * Muestra si es necesario cortar la imagen.
     *
     */
    bool getCutDtm();

    /*!
     * Muestra el tamanyo maximo que tiene que pesar una imagen.
     *
     */
    int getSizeCut();

    /*!
     * Muestra el numero de canales de la imagen.
     *
     */
    int getNumberCanals();

    /*!
     * Muestra si es necesario aplicar el ejecutable ICCImageFootPrintMask.exe.
     *
     */
    bool getFootPrintMask();

    /*!
     * Muestra el valor de ancho de pasada que utiliza el ejecutable ICCImageFootPrintMask.exe.
     *
     */
    int getAnchoPasada();

    /*!
     * Muestra el valor de offset que utiliza el ejecutable ICCImageFootPrintMask.exe.
     *
     */
    int getOffsetPasada();

    /*!
     * Muestra el valor del directorio de salida.
     *
     */
    QString getFolderOut();




signals:

public slots:
    //Setter
    /*!
     * Cambia el nombre de la zona del proyecto.
     * @param zoneProject nuevo valor del fichero de entrada.
     *
     */
    void setZoneProject(QString zoneProject);

    /*!
     * Cambia el nombre de la imagen original.
     * @param imageProject nuevo valor de la imagen original.
     *
     */
    void setImageProject(QString imageProject);
    /*!
     * Cambia el valor del tamanyo de pixel.
     * @param sizePixel nuevo valor del tamanyo de pixel.
     *
     */
    void setSizePixel(double sizePixel);



    /*!
     * Cambia el valor de la opción de corte de la imagen.
     * @param cutDtm nuevo valor de la opción de corte de la imagen.
     *
     */
    void setCutDtm(bool cutDtm);

    /*!
     * Cambia el valor del tamanyo maximo del corte de la imagen.
     * @param sizeCut nuevo valor maximo del corte de la imagen.
     *
     */
    void setSizeCut(int sizeCut);

    /*!
     * Cambia el valor del número de canales.
     * @param numberCanals nuevo valor del número de canales.
     *
     */
    void setNumberCanals(int numberCanals);

    /*!
     * Cambia el valor de la opcion footPrintMask.
     * @param footPrintMask nuevo valor de la opcion footPrintMask.
     *
     */
    void setFootPrintMask(bool footPrintMask);

    /*!
     * Cambia el valor de ancho de pasada que utiliza el ejecutable ICCImageFootPrintMask.exe.
     * @param anchoPasada nuevo valor de ancho de pasada que utiliza el ejecutable ICCImageFootPrintMask.exe.
     *
     */
    void setAnchoPasada(int anchoPasada);

    /*!
     * Cambia el valor de offset de pasada que utiliza el ejecutable ICCImageFootPrintMask.exe.
     * @param anchoPasada nuevo valor de offset de pasada que utiliza el ejecutable ICCImageFootPrintMask.exe.
     *
     */
    void setOffsetPasada(int offsetPasada);

    /*!
     * Cambia el path del directorio de salida.
     * @param folderOut nuevo valor del directorio de salida.
     *
     */
    void setFolderOut(QString folderOut);



private:

    QString _zoneProject;
    QString _imageProject;             ///< Valor de la imagen original.
    double _sizePixel;                 ///< Valor del tamanyo de pixel.
    bool _cutDtm;                      ///< Valor de opción de corte.
    int _sizeCut;                      ///< Valor de tamanyo maximo de corte.
    int _numberCanals;                 ///< Valor de número de canales.
    bool _footPrintMask;               ///< Valor de opción de footPrintMask.
    int _anchoPasada;                  ///< Valor de ancho de pasada que utiliza el ejecutable ICCImageFootPrintMask.exe.
    int _offsetPasada;                 ///< Valor de offset de pasada que utiliza el ejecutable ICCImageFootPrintMask.exe.
    int _numberCuts;                   ///< Valor de número de canales.
    QString _folderOut;                ///< Nombre de directorio de salida.
    QString _subSceneIn;               ///< Valor imagen de entrada para el ejecutable ICCImageSubescenes.exe.
    QString _subSceneOut;              ///< Valor imagen de salida para el ejecutable ICCImageSubescenes.exe.
    QString _reSizeOut;                ///< Valor imagen de salida para el ejecutable ICCImageResize.exe.
    QString _footPrintMaskOut;         ///< Valor imagen de salida para el ejecutable ICCImageFootPrintMask.exe.
    Ambito _ambitoOperacion;           ///< Valor del ambito de la operación.
    sistemaCoor _coordinateSystem;     ///< Valor del sistema de coordenadas.
    Sensor _selectSensor;               ///< Valor de sensor utilizado.




};

#endif // DATAZONEPROJECT_H
