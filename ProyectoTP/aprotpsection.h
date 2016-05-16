#ifndef APROTPSECTION_H
#define APROTPSECTION_H

#include "proyectotp_global.h"

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QVariantMap>

class PROYECTOTPSHARED_EXPORT AProTPSection : public QObject
{
    Q_OBJECT
public:
    explicit AProTPSection(QObject *parent = 0);
    ~AProTPSection();

    virtual QString getNombreSection() const=0;
    virtual bool processSection(QJsonObject archivo)=0;
    virtual QJsonObject writeSection() =0;
    virtual void resetSection()=0;

signals:

    void estaActualizado(bool state);
    void recargaSeccion(QVariantMap);
public slots:

protected:

    bool _stateChanged;    ///< Estado de la seccion, true: esta actualizado, false: esta desactualizado
};

#endif // APROTPSECTION_H
