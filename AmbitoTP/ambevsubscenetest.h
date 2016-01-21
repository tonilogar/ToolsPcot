#ifndef AMBEVSUBSCENETEST_H
#define AMBEVSUBSCENETEST_H

#include <QObject>
#include <QFileInfo>

#include "ambitotp_global.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvSubsceneTest : public AmbEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbEvSubsceneTest(QObject *parent = 0);

    bool syncLaunchTest(Ambito *amb);

signals:

public slots:
};

#endif // AMBEVSUBSCENETEST_H
