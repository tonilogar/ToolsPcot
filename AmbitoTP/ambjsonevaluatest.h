#ifndef AMBJSONEVALUATEST_H
#define AMBJSONEVALUATEST_H

#include <QObject>
#include "ambitotp_global.h"

class AmbitJson;

class AMBITOTPSHARED_EXPORT AmbJsonEvaluaTest : public QObject
{
    Q_OBJECT
public:
    explicit AmbJsonEvaluaTest(QObject *parent = 0,QString error=QString());

    virtual bool syncTest(AmbitJson *ambJson)=0;

    bool isPassed() const;

    QString errorMessage() const;

signals:

    void testResult(bool);

public slots:

    virtual void launchTest(AmbitJson *ambJson);

protected:

    bool _result;
    QString _errorMessage;
    AmbitJson *_lastAmbitJson;
};

#endif // AMBJSONEVALUATEST_H
