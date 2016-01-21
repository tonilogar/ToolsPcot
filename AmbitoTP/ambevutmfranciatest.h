#ifndef AMBEVUTMFRANCIATEST_H
#define AMBEVUTMFRANCIATEST_H

#include <QObject>

#include "ambitotp_global.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvUtmFranciaTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvUtmFranciaTest(QObject *parent = 0);

    bool syncLaunchTest(Ambito *amb);

signals:

public slots:
};

#endif // AMBEVUTMFRANCIATEST_H
