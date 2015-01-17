#ifndef WORKER_H
#define WORKER_H
#include "operacionpcot_global.h"
#include <QObject>
#include "proceso.h"
#include "operacion.h"
#include "operacionmet.h"

class OPERACIONPCOTSHARED_EXPORT Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0, QList < Proceso*> listaProcesos=QList < Proceso*>());
    Operacion* getOperacionActual();
    void trabajarEn(Operacion *operacionActual);
    bool isLibre();
    bool isCancelado();
signals:

    void workerLibre();
    void workerOcupado();

public slots:
    virtual void siguienteProceso();
    void cancelar();
    void reset();

protected:
    Operacion *_operacionActual;
    QList < Proceso*> _listaProcesos;
    int contadorProceso;
    bool libre;
    bool cancelado;
};

#endif // WORKER_H
