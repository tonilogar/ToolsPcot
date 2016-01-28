#ifndef AMBJSONNUMTEST_H
#define AMBJSONNUMTEST_H

#include <QObject>
#include "ambitotp_global.h"

#include "ambjsonevaluatest.h"
#include "ambitjson.h"

class AMBITOTPSHARED_EXPORT AmbJsonNumTest : public AmbJsonEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbJsonNumTest(QObject *parent = 0);

    virtual bool syncTest(AmbitJson *ambJson);

signals:

public slots:
};

#endif // AMBJSONNUMTEST_H
