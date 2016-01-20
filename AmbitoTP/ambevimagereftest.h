#ifndef AMBEVIMAGEREFTEST_H
#define AMBEVIMAGEREFTEST_H

#include <QObject>
#include <QFileInfo>
#include "ambitotp_global.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvImageRefTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvImageRefTest(QObject *parent = 0);

    void launchTest(Ambito *amb);

signals:

public slots:

};

#endif // AMBEVIMAGEREFTEST_H
