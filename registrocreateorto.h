#ifndef REGISTROCREATEORTO_H
#define REGISTROCREATEORTO_H

#include <QObject>
#include <QDebug>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <OperacionPcot/datazoneproject.h>

class RegistroCreateOrto : public QObject
{
    Q_OBJECT
public:


    explicit RegistroCreateOrto(QObject *parent = 0);
    RegistroCreateOrto(QObject *parent,QString folderOut,DataZoneProject::Ambito ambitoOperacion,double tamanyoPixel,
                      DataZoneProject::sistemaCoor coordinateSystem,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada,
                      QString pathImageOrto,QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask,
                      QString exeExtraction,QString exeResize,QString utmDefecto, QJsonArray listaEjecutables,DataZoneProject::Sensor selectSensor);




    //Getter
    QString getFolderOut();
    DataZoneProject::Ambito getAmbitoOperacion();
    DataZoneProject::sistemaCoor getCoordinateSystem();
    DataZoneProject::Sensor getSelectSensor();
    double getTamanyPixel();
    int getTamanyoCorte();
    int getNumeroCanales();
    int getAnchoPasada();
    int getOffsetPasada();
    bool getCutDtm();
    bool getFootPrintMask();
    QString getPathImageOrto();
    QString getExeSubScene();
    QString getExeImaOpeGeo();
    QString getExeFootPrintMask();
    QString getExeExtraction();
    QString getExeResize();
    QString getUtmDefecto();
    QJsonArray getListaEjecutables();
    void buildDataZoneProject(DataZoneProject *dataZP);
    QMap<QString, QString> getMapExe();
public slots:
    //setters
    void setFolderOut(QString folderOut);
    void setAmbitoOperacion(DataZoneProject::Ambito ambitoProyecto);
    void setTamanyPixel(double tamanyoPixel);
    void setCoordinateSystem(DataZoneProject::sistemaCoor coordinateSystem);
    void setSelectSensor(DataZoneProject::Sensor selectSensor);
    void setTamanyoCorte(int tamanyoCorte);
    void setNumeroCanales(int numeroCanales);
    void setAnchoPasada(int anchoPasada);
    void setOffsetPasada(int offsetPasada);
    void setCutDtm(int dtm);
    void setFootprintMask(int fprintM);
    void setPathImageOrto(QString pathImageOrto);
    void setExeSubScene(QString exeSubScene);
    void setExeImaOpeGeo(QString exeImaOpeGeo);
    void setExeFootPrintMask(QString exeFootPrintMask);
    void setExeExtraction(QString exeExtraction);
    void setExeResize(QString exeResize);
    void setUtmDefecto(QString utmDefecto);
    void setListaEjecutables(QJsonArray listaEjecutables);

signals:

private:


    QString _folderOut;
    double _tamanyoPixel;
    bool _dtm;
    int _tamanyoCorte;
    int _numeroCanales;
    bool _fprintM;
    int _anchoPasada;
    int _offsetPasada;
    DataZoneProject::sistemaCoor _coordinateSystem;
    DataZoneProject::Ambito _ambitoOperacion;
    DataZoneProject::Sensor _selectSensor;
    QString _pathImageOrto;
    QString _exeSubScene;
    QString _exeImaOpeGeo;
    QString _exeFootPrintMask;
    QString _exeExtraction;
    QString _exeResize;
    QString _utmDefecto;

    QJsonArray _listaEjecutables;

};

#endif // REGISTROCREATEORTO_H
