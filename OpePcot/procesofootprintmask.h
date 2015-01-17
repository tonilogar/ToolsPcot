#ifndef PROCESOFOOTPRINTMASK_H
#define PROCESOFOOTPRINTMASK_H
#include "operacionpcot_global.h"
#include "proceso.h"
#include <QFile>
#include <QTextStream>

class OPERACIONPCOTSHARED_EXPORT ProcesoFootPrintMask : public Proceso
{
    Q_OBJECT
public:
    explicit ProcesoFootPrintMask(QObject *parent,QString pathProceso);
    virtual void metodoMet(Operacion *op);
    virtual void metodoOrto(Operacion *op);
signals:

public slots:
    void procesoIniciado();
    void procesoTerminado(int fin);

private:
     TipoMetodo metodoInvocado;
};

#endif // PROCESOFOOTPRINTMASK_H
