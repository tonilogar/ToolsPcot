#ifndef PROCESOEXTRACTION_H
#define PROCESOEXTRACTION_H
#include "operacionpcot_global.h"
#include "proceso.h"

class OPERACIONPCOTSHARED_EXPORT ProcesoExtraction : public Proceso
{
    Q_OBJECT
public:
    explicit ProcesoExtraction(QObject *parent,QString pathProceso);
    virtual void metodoMet(Operacion *op);
signals:

public slots:
    void procesoIniciado();
    void procesoTerminado(int fin);

};

#endif // PROCESOEXTRACTION_H
