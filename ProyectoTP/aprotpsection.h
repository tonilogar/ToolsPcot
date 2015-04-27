#ifndef APROTPSECTION_H
#define APROTPSECTION_H

#include "proyectotp_global.h"

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

class PROYECTOTPSHARED_EXPORT AProTPSection : public QObject
{
    Q_OBJECT
public:
    explicit AProTPSection(QObject *parent = 0);
    ~AProTPSection();

    virtual bool processSection(QJsonObject archivo)=0;
    virtual QJsonObject writeSection() =0;

signals:

public slots:
};

#endif // APROTPSECTION_H
