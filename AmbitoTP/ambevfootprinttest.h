#ifndef AMBEVFOOTPRINTTEST_H
#define AMBEVFOOTPRINTTEST_H

#include "ambitotp_global.h"

#include <QObject>

#include "ambito.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvFootprintTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvFootprintTest(QObject *parent = 0);

    void launchTest(Ambito *amb);

signals:


public slots:
};

#endif // AMBEVFOOTPRINTTEST_H
