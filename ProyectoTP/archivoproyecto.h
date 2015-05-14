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
    AProCnpMetOrtoSection *_seccionCnpMetOrto;
    //Lista de punteros AProCnpMetOrtoSection.

};


#endif // ARCHIVOPROYECTO_H
