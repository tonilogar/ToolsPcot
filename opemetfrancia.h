#ifndef OPEMETFRANCIA_H
#define OPEMETFRANCIA_H
#include "operacionmet.h"
#include <math.h>
class OpeMetFrancia : public OperacionMet
{
    Q_OBJECT
public:
    explicit OpeMetFrancia(QObject *parent = 0);

public slots:
    virtual void inicio();//virtual
    virtual void fin(int end);//virtual
    virtual void startOperacion();//virtual

signals:

public slots:

protected:
    QString exeResize;

};

#endif // OPEMETFRANCIA_H
