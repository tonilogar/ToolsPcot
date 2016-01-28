#ifndef AMBEVRESIZETEST_H
#define AMBEVRESIZETEST_H

#include <QObject>
#include <QFileInfo>

#include "ambitotp_global.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvResizeTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvResizeTest(QObject *parent = 0);

    bool syncLaunchTest(Ambito *amb);

signals:

public slots:
};

#endif // AMBEVRESIZETEST_H
