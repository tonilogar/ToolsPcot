#ifndef PROCESOGEOTRANS_H
#define PROCESOGEOTRANS_H
#include "operacionpcot_global.h"
#include "proceso.h"

class OPERACIONPCOTSHARED_EXPORT ProcesoGeoTrans : public Proceso
{
    Q_OBJECT
public:
    explicit ProcesoGeoTrans(QObject *parent,QString pathProceso);
    virtual void metodoMet(Operacion *op);
    virtual void metodoOrto(Operacion *op);
signals:

public slots:
    void procesoIniciado();
    void procesoTerminado(int fin);

private:

    TipoMetodo metodoInvocado;
};

#endif // PROCESOGEOTRANS_H
