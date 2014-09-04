#ifndef REGISTROCREATEMET_H
#define REGISTROCREATEMET_H

#include <QObject>
#include <QDebug>
#include <QJsonArray>
#include <OperacionPcot/datazoneproject.h>

class RegistroCreateMet : public QObject
{
    Q_OBJECT
public:
    explicit RegistroCreateMet(QObject *parent = 0);
    RegistroCreateMet(QObject *parent,QString folderOut,QString ambitoProyecto,int tamanyoPixel,
                      int utm,int tamanyoCorte,int numeroCanales,int anchoPasada,int offsetPasada, QString pathImageMet
                      , QString exeSubScene, QString exeImaOpeGeo, QString exeFootPrintMask, QString exeExtraction,
                      QString exeResize,QString utmDefecto, QJsonArray listaEjecutables);

    //Getter
    QString getFolderOut();
    QString getAmbitoProyecto();
    int getTamanyPixel();
    int getUtm();
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

public slots:
    //setters
    void setFolderOut(QString folderOut);
    void setAmbitoProyecto(QString ambitoProyecto);
    void setTamanyPixel(int tamanyoPixel);
    void setUtm(int utm);
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
    QString _ambitoProyecto;
    int _tamanyoPixel;
    int _utm;
    int _tamanyoCorte;
    int _numeroCanales;
    int _anchoPasada;
    int _offsetPasada;
    bool _dtm;
    bool _fprintM;
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
