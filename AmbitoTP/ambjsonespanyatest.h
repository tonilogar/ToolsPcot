#ifndef AMBJSONESPANYATEST_H
#define AMBJSONESPANYATEST_H

#include <QObject>
#include "ambitotp_global.h"
#include "ambitjson.h"
#include "ambjsonevaluatest.h"
#include "ambito.h"

#include "ambevimagereftest.h"
#include "ambevfootprinttest.h"
#include "ambevgeotransformtest.h"
#include "ambevresizetest.h"
#include "ambevsubscenetest.h"
#include "ambevpixelsizetest.h"
#include "ambevrangoutmtest.h"

class AMBITOTPSHARED_EXPORT AmbJsonEspanyaTest : public AmbJsonEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbJsonEspanyaTest(QObject *parent = 0);

    bool syncTest(AmbitJson *ambJson);
signals:

public slots:

protected:

    QList<AmbEvaluaTest*> _listaTests;
};

#endif // AMBJSONESPANYATEST_H
