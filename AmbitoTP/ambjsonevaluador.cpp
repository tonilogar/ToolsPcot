#include "ambjsonevaluador.h"
#include "ambitjson.h"
#include "ambjsonevaluatest.h"

AmbJsonEvaluador::AmbJsonEvaluador(QObject *parent, AmbitJson *ambJson) : QObject(parent)
{
    _ambitJson=ambJson;
    _isCorrect=false;
}

AmbitJson *AmbJsonEvaluador::getAmbitJson() const
{
    return _ambitJson;
}

void AmbJsonEvaluador::setAmbitJson(AmbitJson *ambJson)
{
    _ambitJson=ambJson;
}

void AmbJsonEvaluador::addTest(AmbJsonEvaluaTest *test)
{
    _testList.append(test);
}

void AmbJsonEvaluador::removeTest(AmbJsonEvaluaTest *test)
{
    _testList.removeAll(test);
}

bool AmbJsonEvaluador::checkAmbitJson(AmbitJson *ambJson)
{
    _ambitJson=ambJson;
    _isCorrect=true;
    foreach(AmbJsonEvaluaTest *test,_testList) {
        if(!test->syncTest(_ambitJson))
            _isCorrect=false;
    }

    return _isCorrect;
}

bool AmbJsonEvaluador::isCorrect() const
{
    return _isCorrect;
}

QList<AmbJsonEvaluaTest*> AmbJsonEvaluador::failedTest()
{
    QList<AmbJsonEvaluaTest*> failedTestList;

    foreach(AmbJsonEvaluaTest* test,_testList) {
        if(!test->isPassed())
            failedTestList.append(test);
    }
    return failedTestList;
}
