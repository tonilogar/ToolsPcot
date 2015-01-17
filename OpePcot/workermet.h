#ifndef WORKERMET_H
#define WORKERMET_H
#include "operacionpcot_global.h"
#include "worker.h"

class OPERACIONPCOTSHARED_EXPORT WorkerMet : public Worker
{
    Q_OBJECT
public:
    explicit WorkerMet(QObject *parent = 0, QList < Proceso*> listaProcesos=QList < Proceso*>());

signals:

public slots:

    void siguienteProceso();

};

#endif // WORKERMET_H
