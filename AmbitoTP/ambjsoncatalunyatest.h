#ifndef AMBJSONCATALUNYATEST_H
#define AMBJSONCATALUNYATEST_H

#include <QObject>
#include "ambitotp_global.h"
#include "ambitjson.h"
#include "ambjsonevaluatest.h"
#include "ambito.h"

#include "ambevextractiontest.h"
#include "ambevimagereftest.h"
#include "ambevfootprinttest.h"
#include "ambevgeotransformtest.h"
#include "ambevresizetest.h"
#include "ambevsubscenetest.h"
#include "ambevpixelsizetest.h"
#include "ambevrangoutmtest.h"

class AMBITOTPSHARED_EXPORT AmbJsonCatalunyaTest : public AmbJsonEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbJsonCatalunyaTest(QObject *parent = 0);

    bool syncTest(AmbitJson *ambJson);

signals:

public slots:

protected:

    QList<AmbEvaluaTest*> _listaTests;
};

#endif // AMBJSONCATALUNYATEST_H
