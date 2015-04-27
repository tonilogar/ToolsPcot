#ifndef ARCHIVOPROYECTO_H
#define ARCHIVOPROYECTO_H

#include "proyectotp_global.h"
#include <QObject>
#include <QFileInfo>
#include <QFile>
#include <QDate>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

class PROYECTOTPSHARED_EXPORT ArchivoProyecto:public QObject
{
    Q_OBJECT
public:
    explicit ArchivoProyecto(QObject *parent = 0, QString nameFileProyect=QString());
    ~ArchivoProyecto();
    QString getnameFileProyect();
    QString getnameProyect();
    QString getdescriptionProyecte();
    QString getautorProyect();
    QDate   getdateAcces();
    QDate   getdateCreate();
    QDate   getdateflight();
    virtual QString getnumberVersion();
    bool exist();
    virtual bool build(QString nameProyect,QString descriptionProyecte, QString autorProyect, QDate dateFlight);

public slots:
    void setnameFileProyect(QString nameFileProyect);
    void setnameProyect(QString nameProyect);
    void setdescriptionProyecte(QString descriptionProyecte);
    void setautorProyect(QString autorProyect);
    void setdateAcces(QDate dateAcces);
    void setdateCreate(QDate dateCreate);
    void setdateflight(QDate dateFlight);
protected:
    QString _nameFileProyect;
    QString _nameProyect;
    QString _descriptionProyecte;
    QString _autorProyect;
    QDate _dateAcces;
    QDate _dateCreate;
    QDate _dateFlight;
    QString _pathNameFileCoordinates;
    QString _nameFileCoordinates;

    bool _createMet;
    QString _folderOutCnp;
    QString _IncidentsCnp;

    bool _checkExtractMet;
    QString _folderOutMet;
    QString _zoneProjectMet;
    double _pixelSizeMet;
    QString _coordinateSystemMet;
    bool _checkCutMet;
    int _sizeCutMet;
    int _numberChanelsMet;
    bool checkFootPrintMaskMet;
    QString _selectSensorMet;
    int _offsetFlightMet;
    int _widthFlightMet;
    QString _IncidentsMet;

    bool _checkExtractOrto;
    QString _folderOutOrto;
    QString _zoneProjectOrto;
    double _pixelSizeOrto;
    QString _coordinateSystemOrto;
    bool _checkCutOrto;
    int _sizeCutOrto;
    int _numberChanelsOrto;
    bool checkFootPrintMaskOrto;
    QString _selectSensorOrto;
    int _offsetFlightOrto;
    int _widthFlightOrto;
    QString _IncidentsOrto;





};


#endif // ARCHIVOPROYECTO_H
