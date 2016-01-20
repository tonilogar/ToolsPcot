#ifndef AMBEVASIZEPIXELTEST_H
#define AMBEVASIZEPIXELTEST_H

#include "ambitotp_global.h"
#include <QObject>
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvaSizePixelTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvaSizePixelTest(QObject *parent = 0);

    void launchTest(Ambito *amb);
signals:

public slots:

};

#endif // AMBEVASIZEPIXELTEST_H
