#ifndef OPERACIONCNP_H
#define OPERACIONCNP_H
#include "operacionpcot_global.h"
#include "operacion.h"

class OPERACIONPCOTSHARED_EXPORT OperacionCnp : public Operacion
{
    Q_OBJECT
public:
    explicit OperacionCnp(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP);
    virtual void aceptarProceso(Proceso *p);
    virtual QString getFileDestino();
signals:

public slots:




};

#endif // OPERACIONCNP_H
