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
#include <QList>

//Secciones
#include "aprotpsection.h"

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
    bool estaActualizado() const {
        return _estadoProyecto;
    }

    virtual bool build(QString nameProyect,QString descriptionProyecte, QString autorProyect, QDate dateFlight);
    virtual bool build();
    virtual bool read(QString pathProyectFile);
    virtual bool save();

    void addSection(AProTPSection *section);
    void removeSection(AProTPSection *section);
    QList<AProTPSection*> getListaSections();

signals:

    void cambioActualizado(bool estado);

public slots:
    void setnameFileProyect(QString nameFileProyect);
    void setnameProyect(QString nameProyect);
    void setdescriptionProyecte(QString descriptionProyecte);
    void setautorProyect(QString autorProyect);
    void setdateAcces(QDate dateAcces);
    void setdateCreate(QDate dateCreate);
    void setdateflight(QDate dateFlight);

protected slots:

    /*!
      Alguna de las secciones ha aceptado cambios en su estado
      */

    void sectionHasChanged(bool estado);

protected:
    QString _nameFileProyect;
    QString _nameProyect;
    QString _descriptionProyecte;
    QString _autorProyect;
    QDate _dateAcces;
    QDate _dateCreate;
    QDate _dateFlight;

    bool _estadoProyecto;   ///< True: el proyecto esta actualizado, false: el proyecto ha cambiado

    //Lista de secciones
    QList<AProTPSection*> _listaSecciones;
};


#endif // ARCHIVOPROYECTO_H
