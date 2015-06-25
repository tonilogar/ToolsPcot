#ifndef SECTIONCOORDINATES_H
#define SECTIONCOORDINATES_H

#include "coordinatestp_global.h"

#include "modelocoordenadas.h"

#include <ProyectoTP/aprotpsection.h>

#include <QDebug>

class  COORDINATESTPSHARED_EXPORT SectionCoordinates : public AProTPSection
{
    Q_OBJECT
public:
    explicit SectionCoordinates(QObject *parent = 0);
    ~SectionCoordinates();

    void setModeloCoordenadas(ModeloCoordenadas *m);
    ModeloCoordenadas *getModeloCoordenadas();

    virtual QString getNombreSection() const;
    virtual bool processSection(QJsonObject archivo);
    virtual QJsonObject writeSection();
    virtual void resetSection();

protected:

    ModeloCoordenadas *_modeloCoordenadas;

protected slots:

    void modeloResetado();

};

#endif // SECTIONCOORDINATES_H
