#ifndef DATAJSON_H
#define DATAJSON_H

#include "ambitotp_global.h"

#include <QObject>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

#include "ambito.h"


class AMBITOTPSHARED_EXPORT AmbitJson : public QObject
{
    Q_OBJECT
public:
    explicit AmbitJson(QObject *parent = 0,QFileInfo fileInfo=QFileInfo());
    ~AmbitJson();

    bool exist() const;

    QFileInfo getFileInfo() const;

    static bool createStandardTemplate(QFileInfo info);

    bool isLoaded() const;

    bool isSaved() const;

    bool isValid() const;

    QString lastError() const
    { return _error; }

    QList<Ambito*> getAmbitos() const
    { return _ambitosArchivo; }

    static QString staticLastError()
    { return AmbitJson::_errorStatic; }

signals:

public slots:

    void setFileInfo(QFileInfo info);
    void load();
    void save();

    void addAmbito(Ambito *amb);
    void removeAmbito(Ambito *amb);

private:

    QFileInfo _dataFile;    ///< Archivo que contiene la informacion en JSON
    QList<Ambito*> _ambitosArchivo;

    QString _error;
    static QString _errorStatic;
};

#endif // DATAJSON_H
