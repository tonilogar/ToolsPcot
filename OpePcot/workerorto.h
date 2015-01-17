#ifndef WORKERORTO_H
#define WORKERORTO_H
#include "operacionpcot_global.h"
#include "worker.h"

class OPERACIONPCOTSHARED_EXPORT WorkerOrto : public Worker
{
    Q_OBJECT
public:
    explicit WorkerOrto(QObject *parent = 0, QList < Proceso*> listaProcesos=QList < Proceso*>());

signals:

public slots:

    void siguienteProceso();

};


#endif // WORKERORTO_H
