#ifndef AMBEVGEOTRANSFORMTEST_H
#define AMBEVGEOTRANSFORMTEST_H

#include <QObject>
#include <QFileInfo>

#include "ambitotp_global.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvGeoTransformTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvGeoTransformTest(QObject *parent = 0);

    bool syncLaunchTest(Ambito *amb);

signals:

public slots:
};

#endif // AMBEVGEOTRANSFORMTEST_H
