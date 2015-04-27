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

//Secciones
#include "aprotpsection.h"
#include "aprocnpmetortosection.h"

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
    virtual bool read(QString pathProyectFile);

    // Seccion CNP MET ORTO
    bool CnpMetOrto_isCnpEnabled() const {
        return _seccionCnpMetOrto->isCnpEnabled();
    }

    bool CnpMetOrto_isMetEnabled() const {
        return _seccionCnpMetOrto->isMetEnabled();
    }

    bool CnpMetOrto_isOrtoEnabled() const {
        return _seccionCnpMetOrto->isOrtoEnabled();
    }

    QString CnpMetOrto_cnpFolderOut() {
        return _seccionCnpMetOrto->cnpFolderOut();
    }

public slots:
    void setnameFileProyect(QString nameFileProyect);
    void setnameProyect(QString nameProyect);
    void setdescriptionProyecte(QString descriptionProyecte);
    void setautorProyect(QString autorProyect);
    void setdateAcces(QDate dateAcces);
    void setdateCreate(QDate dateCreate);
    void setdateflight(QDate dateFlight);

    void CnpMetOrto_setCnpEnable(bool v) {
        _seccionCnpMetOrto->enableCNP(v);
    }

    void CnpMetOrto_setMetEnable(bool v) {
        _seccionCnpMetOrto->enableMet(v);
    }

    void CnpMetOrto_setOrtoEnable(bool v) {
        _seccionCnpMetOrto->enableOrto(v);
    }

    void CnpMetOrto_setCnpFolderOut(QString f) {
        _seccionCnpMetOrto->setCnpFolderOut(f);
    }

protected:
    QString _nameFileProyect;
    QString _nameProyect;
    QString _descriptionProyecte;
    QString _autorProyect;
    QDate _dateAcces;
    QDate _dateCreate;
    QDate _dateFlight;

    AProCnpMetOrtoSection *_seccionCnpMetOrto;

};


#endif // ARCHIVOPROYECTO_H
