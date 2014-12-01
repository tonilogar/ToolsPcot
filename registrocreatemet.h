#ifndef REGISTROCREATEMET_H
#define REGISTROCREATEMET_H

#include <QObject>
#include <QDebug>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <OperacionPcot/datazoneproject.h>

class RegistroCreateMet : public QObject
{
    Q_OBJECT
public:
    enum Ambito{
        Catalunya, Espanya, Francia, Otro
    };

    enum sistemaCoor{
        Etrs89, Ed50, Ntf, vacio
    };

    explicit RegistroCreateMet(QObject *parent = 0);
    RegistroCreateMet(QObject *parent,QString folderOut,QString ambitoOperacion,double tamanyoPixel,
                      QString coordinateSystem,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada,
                      QString pathImageMet,QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask,
                      QString exeExtraction,QString exeResize,QString utmDefecto, QJsonArray listaEjecutables);




    //Getter
    QString getFolderOut();
    QString getAmbitoOperacion();
    QString getCoordinateSystem();
    double getTamanyPixel();
    int getTamanyoCorte();
    int getNumeroCanales();
    int getAnchoPasada();
    int getOffsetPasada();
    bool getCutDtm();
    bool getFootPrintMask();
    QString getPathImageMet();
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
    void setAmbitoOperacion(QString ambitoProyecto);
    void setTamanyPixel(double tamanyoPixel);
    void setCoordinateSystem(QString coordinateSystem);
    void setTamanyoCorte(int tamanyoCorte);
    void setNumeroCanales(int numeroCanales);
    void setAnchoPasada(int anchoPasada);
    void setOffsetPasada(int offsetPasada);
    void setCutDtm(int dtm);
    void setFootprintMask(int fprintM);
    void setPathImageMet(QString pathImageMet);
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
    QString _coordinateSystem;
    QString _ambitoOperacion;
    QString _pathImageMet;
    QString _exeSubScene;
    QString _exeImaOpeGeo;
    QString _exeFootPrintMask;
    QString _exeExtraction;
    QString _exeResize;
    QString _utmDefecto;

    QJsonArray _listaEjecutables;

};

#endif // REGISTROCREATEMET_H
