#ifndef POCESOCNP_H
#define POCESOCNP_H
#include "operacionpcot_global.h"
#include"proceso.h"
#include"operacioncnp.h"


class OPERACIONPCOTSHARED_EXPORT PocesoCnp : public Proceso
{
    Q_OBJECT
public:
    explicit PocesoCnp(QObject *parent,QString pathProceso);
    virtual void metodoCnp(Operacion *opCnp);


signals:

public slots:

};

#endif // POCESOCNP_H
