#ifndef AMBEVRANGOUTMTEST_H
#define AMBEVRANGOUTMTEST_H

#include "ambitotp_global.h"

#include <QObject>

#include "ambito.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvRangoUtmTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvRangoUtmTest(QObject *parent = 0);

    void launchTest(Ambito *amb);

signals:

    void errorOnUtm(bool);

public slots:
};

#endif // AMBEVRANGOUTMTEST_H
