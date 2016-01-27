#ifndef AMBJSONNOMBRETEST_H
#define AMBJSONNOMBRETEST_H

#include <QObject>
#include "ambitotp_global.h"
#include "ambitjson.h"
#include "ambjsonevaluatest.h"
#include "ambito.h"

class AMBITOTPSHARED_EXPORT AmbJsonNombreTest : public AmbJsonEvaluaTest
{
    Q_OBJECT
public:
    explicit AmbJsonNombreTest(QObject *parent = 0,QString nombre=QString());

    bool syncTest(AmbitJson *ambJson);

signals:

public slots:

private:

    QString _nombre;
};

#endif // AMBJSONNOMBRETEST_H
