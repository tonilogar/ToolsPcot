#ifndef PROCESORESIZE_H
#define PROCESORESIZE_H
#include "operacionpcot_global.h"
#include "proceso.h"

class OPERACIONPCOTSHARED_EXPORT ProcesoResize : public Proceso
{
    Q_OBJECT
public:
    explicit ProcesoResize(QObject *parent,QString pathProceso);
    virtual void metodoMet(Operacion *op);
    virtual void metodoOrto(Operacion *op);
signals:

public slots:
    void procesoIniciado();
    void procesoTerminado(int fin);

private:

    TipoMetodo metodoInvocado;
};

#endif // PROCESORESIZE_H
