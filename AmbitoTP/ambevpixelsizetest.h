#ifndef AMBEVPIXELSIZETEST_H
#define AMBEVPIXELSIZETEST_H

#include <QObject>
#include "ambitotp_global.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvPixelSizeTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvPixelSizeTest(QObject *parent = 0);

    bool syncLaunchTest(Ambito *amb);

signals:

public slots:
};

#endif // AMBEVPIXELSIZETEST_H
