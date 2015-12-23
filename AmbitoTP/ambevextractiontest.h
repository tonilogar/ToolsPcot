#ifndef AMBEVEXTRACTIONTEST_H
#define AMBEVEXTRACTIONTEST_H

#include "ambitotp_global.h"

#include <QObject>
#include <QFileInfo>

#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvExtractionTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvExtractionTest(QObject *parent = 0);

    void launchTest(Ambito *amb);

signals:


public slots:
};

#endif // AMBEVEXTRACTIONTEST_H
