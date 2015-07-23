#ifndef REGISTROCREATEMET_H
#define REGISTROCREATEMET_H
#include "cnpmetortotp_global.h"
#include <QObject>
#include <QDebug>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <OpePcot/datazoneproject.h>
#include <ProyectoTP/aprotpsection.h>
#include <CnpMetOrtoTP/createmet.h>
class CreateMet;

class CNPMETORTOTPSHARED_EXPORT RegistroCreateMet : public AProTPSection
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit RegistroCreateMet(QObject *parent = 0);
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     *
     */
    RegistroCreateMet(QObject *parent,QString folderOut,DataZoneProject::Ambito ambitoOperacion,double tamanyoPixel,
                      DataZoneProject::sistemaCoor coordinateSystem,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada,
                      QString pathImageMet,QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask,
                      QString exeExtraction,QString exeResize,QString utmDefecto, QJsonArray listaEjecutables,DataZoneProject::Sensor selectSensor);

    void setWidget(CreateMet *widget);

    //Getter
    /*!
      Devuelve si la seccion esta o no activada
      */
    bool getMetEnabled() const;
    /*!
     * Mostrar el valors del directori de sortida.
     */
    QString getFolderOut();
    /*!
     * Mostrar el valor del Ambit de projecte.
     */
    DataZoneProject::Ambito getAmbitoOperacion();
    /*!
     * Mostrar el valor del sistema de coordenades.
     */
    DataZoneProject::sistemaCoor getCoordinateSystem();
    /*!
     * Mostrar el valor del sensor de vol.
     */
    DataZoneProject::Sensor getSelectSensor();
    /*!
     * Mostrar el valor de la mida de pixel.
     */
    double getTamanyPixel();
    /*!
     * Mostrar el valor del tamany de tall  del fitxer met.
     */
    int getTamanyoCorte();
    /*!
     * Mostrar el valor del número de canals.
     */
    int getNumeroCanales();
    /*!
     * Mostrar el valor de la amplada de passada de vol.
     */
    int getAnchoPasada();
    /*!
     * Mostrar el valor del offset de passada de vol.
     */
    int getOffsetPasada();
    /*!
     * Mostrar l'estat de cutDtm.
     */
    bool getCutDtm();
    /*!
     * Mostrar l'estat de foootprintmask.
     */
    bool getFootPrintMask();
    /*!
     * Mostrar el path de imatge met.
     */
    QString getPathImageMet();
    /*!
     * Mostrar el path de ExeSubScene.
     */
    QString getExeSubScene();
    /*!
     * Mostrar el path de ExeImaOpeGeo.
     */
    QString getExeImaOpeGeo();
    /*!
     * Mostrar el path de FootPrintMask.
     */
    QString getExeFootPrintMask();
    /*!
     * Mostrar imatge original del met.
     */
    QString getExeExtraction();
    /*!
     * Mostrar el path de Resize.
     */
    QString getExeResize();
    /*!
     * Mostrar el valor del utm per defecte.
     */
    QString getUtmDefecto();
    /*!
     * Mostrar el llistat d'executables.
     */
    QJsonArray getListaEjecutables();
    /*!
     * Crear l'objecte DataZoneProject.
     */
    void buildDataZoneProject(DataZoneProject *dataZP);
    /*!
     * Mostrar valor de l'executable.
     */
    QMap<QString, QString> getMapExe();

    //Metodos de interfaz AProTPSection

    virtual QString getNombreSection() const;
    virtual bool processSection(QJsonObject archivo);
    virtual QJsonObject writeSection();
    virtual void resetSection();

public slots:
    //setters
    /*!
     * Canvia el nom del directori de sortida.
     * @param nou valor del fitxer de sortida.
     */
    void setFolderOut(QString folderOut);
    /*!
     * Canvia valor de Ambit de projecte.
     * @param nou valor de Ambit de projecte.
     */
    void setAmbitoOperacion(DataZoneProject::Ambito ambitoProyecto);
    /*!
     * Canvia valor de la mida de pixel.
     * @param nou valor de la mida de pixel.
     */
    void setTamanyPixel(double tamanyoPixel);
    /*!
     * Canvia valor del sistema de coordenades.
     * @param nou valor del sistema de coordenades.
     */
    void setCoordinateSystem(DataZoneProject::sistemaCoor coordinateSystem);
    /*!
     * Canvia valor del sensor de vol.
     * @param nou valor del sensor de vol.
     */
    void setSelectSensor(DataZoneProject::Sensor selectSensor);
    /*!
     * Canvia valor del tamany de tall  del fitxer met.
     * @param nou valor del tamany de tall  del fitxer met.
     */
    void setTamanyoCorte(int tamanyoCorte);
    /*!
     * Canvia valor de la amplada de passada de vol.
     * @param nou valor de la amplada de passada de vol.
     */
    void setNumeroCanales(int numeroCanales);
    /*!
     * Canvia valor de la amplada de passada de vol.
     * @param nou valor de la amplada de passada de vol.
     */
    void setAnchoPasada(int anchoPasada);
    /*!
     * Canvia valor del offset de passada de vol.
     * @param nou valor del offset de passada de vol.
     */
    void setOffsetPasada(int offsetPasada);
    /*!
     * Canvia l'estat de cutDtm.
     * @param nou estat de cutDtm.
     */
    void setCutDtm(int dtm);
    /*!
     * Canvia l'estat de foootprintmask.
     * @param nou estat de foootprintmask.
     */
    void setFootprintMask(int fprintM);
    /*!
     * Canvia el path de imatge met.
     * @param nou path de imatge met.
     */
    void setPathImageMet(QString pathImageMet);
    /*!
     * Canvia valor path de SubScene.
     * @param nou path de SubScene.
     */
    void setExeSubScene(QString exeSubScene);
    /*!
     * Canvia valor path de ImaOpeGeo.
     * @param nou path de ImaOpeGeo.
     */
    void setExeImaOpeGeo(QString exeImaOpeGeo);
    /*!
     * Canvia valor path de FootPrintMask.
     * @param nou path de FootPrintMask.
     */
    void setExeFootPrintMask(QString exeFootPrintMask);
    /*!
     * Canvia valor path de Extraction.
     * @param nou path de Extraction.
     */
    void setExeExtraction(QString exeExtraction);
    /*!
     * Canvia valor path de Resize.
     * @param nou path de Resize.
     */
    void setExeResize(QString exeResize);
    /*!
     * Canvia valor del utm per defecte.
     * @param nou valor del utm per defecte.
     */
    void setUtmDefecto(QString utmDefecto);
    /*!
     * Canvia valor del llistat del executables.
     * @param nou valor del llistat del executables.
     */
    void setListaEjecutables(QJsonArray listaEjecutables);

    void setMetEnabled(bool enabled);

signals:

private:


    QString _folderOut;   ///< Nom del directori de sortida.
    double _tamanyoPixel; ///< Nom del valor de la mida de pixel.
    bool _dtm;            ///< Valor de la mida de pixel.
    int _tamanyoCorte;    ///< Valor de la mida de tall.
    int _numeroCanales;   ///< Valor número de canals.
    bool _fprintM;        ///< Valor estat footPrintMask.
    int _anchoPasada;     ///< Valor amplada de passada.
    int _offsetPasada;    ///< Valor offset de passada.
    DataZoneProject::sistemaCoor _coordinateSystem; ///< Valor sistema de coordenades.
    DataZoneProject::Ambito _ambitoOperacion;       ///< Valor ambit de projecte.
    DataZoneProject::Sensor _selectSensor;          ///< Valor sensor de vol.
    QString _pathImageMet;       ///< Valor de la imatge met inicial.
    QString _exeSubScene;         ///< Valor path SubScene.
    QString _exeImaOpeGeo;        ///< Valor path ImaOpeGeo.
    QString _exeFootPrintMask;    ///< Valor path FootPrintMask.
    QString _exeExtraction;       ///< Valor path Extraction.
    QString _exeResize;           ///< Valor path Resize.
    QString _utmDefecto;          ///< Valor utm per defecte .
    QJsonArray _listaEjecutables; ///< Llistat de executables .
    bool _metEnabled;  ///< Seccion CNPS activada
    CreateMet *_widgetMet;    ///< Widget grafico asociado

};

#endif // REGISTROCREATEMET_H
