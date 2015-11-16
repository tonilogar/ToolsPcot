#ifndef AMBITO_H
#define AMBITO_H

#include "ambitotp_global.h"

#include <QObject>
#include <QFileInfo>
#include <QMap>
#include <QJsonArray>
#include <QJsonObject>

class AMBITOTPSHARED_EXPORT Ambito : public QObject
{
    Q_OBJECT
public:
    explicit Ambito(QObject *parent = 0);

    QString nombre() const
    { return _nombre; }

    QFileInfo imageRef() const
    { return _imageRef; }

    double tamPixel() const
    { return _tamPixel; }

    int utm() const
    { return _utm; }

    QMap<QString,QFileInfo*> ejecutables() const
    { return _ejecutables; }

    QJsonObject toJson() const;

    static Ambito *fromJson(QJsonObject obj);

    bool isValid() const;

    bool existImageRef(QFileInfo imageRef);



signals:

public slots:

    void setNombre(QString n);
    void setImageRef(QFileInfo iR);
    void setTamPixel(double tp);
    void setUtm(int u);

    void addEjecutable(QString n,QFileInfo *info);
    void removeEjecutable(QString n);

private:

    QString _nombre;
    QFileInfo _imageRef;
    double _tamPixel;
    int _utm;

    QMap<QString,QFileInfo*> _ejecutables;
};

#endif // AMBITO_H
