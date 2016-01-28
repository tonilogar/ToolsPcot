#ifndef AMBJSONFRANCIATEST_H
#define AMBJSONFRANCIATEST_H

#include <QObject>
#include "ambitotp_global.h"
#include "ambitjson.h"
#include "ambjsonevaluatest.h"
#include "ambito.h"

#include "ambevimagereftest.h"
#include "ambevfootprinttest.h"
#include "ambevresizetest.h"
#include "ambevsubscenetest.h"
#include "ambevpixelsizetest.h"
#include "ambevutmfranciatest.h"

class AMBITOTPSHARED_EXPORT AmbJsonFranciaTest : public AmbJsonEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbJsonFranciaTest(QObject *parent = 0);

    bool syncTest(AmbitJson *ambJson);

signals:

public slots:

protected:

    QList<AmbEvaluaTest*> _listaTests;
};

#endif // AMBJSONFRANCIATEST_H
