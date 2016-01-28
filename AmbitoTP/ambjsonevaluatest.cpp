#include "ambjsonevaluatest.h"
#include "ambitjson.h"

AmbJsonEvaluaTest::AmbJsonEvaluaTest(QObject *parent, QString error)
    : QObject(parent)
{
    _errorMessage=error;
    _lastAmbitJson=0;
    _result=false;
}

void AmbJsonEvaluaTest::launchTest(AmbitJson *ambJson)
{
    syncTest(ambJson);
}

bool AmbJsonEvaluaTest::isPassed() const
{
    return _result;
}

QString AmbJsonEvaluaTest::errorMessage() const
{
    return _errorMessage;
}
