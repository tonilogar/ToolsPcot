#ifndef PROCESOCUTFILES_H
#define PROCESOCUTFILES_H
#include "operacionpcot_global.h"
#include "proceso.h"
class OPERACIONPCOTSHARED_EXPORT ProcesoCutFiles : public Proceso
{
    Q_OBJECT
public:
    explicit ProcesoCutFiles(QObject *parent,QString pathProceso);
    virtual void metodoMet(Operacion *op);
    virtual void metodoOrto(Operacion *op);
signals:

public slots:
    void procesoIniciado();
    void procesoTerminado(int fin);
private:

    TipoMetodo metodoInvocado;
};

#endif // PROCESOCUTFILES_H
