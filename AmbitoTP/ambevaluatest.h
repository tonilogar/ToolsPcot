#ifndef AMBEVALUATEST_H
#define AMBEVALUATEST_H

#include "ambitotp_global.h"

#include <QObject>

#include "ambito.h"

class AMBITOTPSHARED_EXPORT AmbEvaluaTest : public QObject
{
    Q_OBJECT
public:
    explicit AmbEvaluaTest(QObject *parent = 0,QString mensaje=QString());

    bool isPassed() const
    { return _isPassed; }

    Ambito *lastAmbitoChecked() const
    { return _ambito; }

    QString mensaje() const
    { return _mensaje; }

    virtual void launchTest(Ambito *amb)=0;

signals:

public slots:

protected:

    QString _mensaje;
    bool _isPassed;
    Ambito *_ambito;

};

#endif // AMBEVALUATEST_H
