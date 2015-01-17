#ifndef PROCESOSUBSCENE_H
#define PROCESOSUBSCENE_H
#include "operacionpcot_global.h"
#include "proceso.h"
#include "math.h"
class OPERACIONPCOTSHARED_EXPORT ProcesoSubScene : public Proceso
{
    Q_OBJECT
public:
    explicit ProcesoSubScene(QObject *parent,QString pathProceso);
    virtual void metodoMet(Operacion *op);
    virtual void metodoOrto(Operacion *op);
signals:

public slots:
void procesoIniciado();
void procesoTerminado(int fin);

private:

    TipoMetodo metodoInvocado;
};

#endif // PROCESOSUBSCENE_H
