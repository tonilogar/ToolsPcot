#include "ambjsonnumtest.h"

AmbJsonNumTest::AmbJsonNumTest(QObject *parent)
    : AmbJsonEvaluaTest(parent,QStringLiteral("El número de ambitos no es correcto"))
{

}

bool AmbJsonNumTest::syncTest(AmbitJson *ambJson)
{
    _lastAmbitJson=ambJson;
    if(_lastAmbitJson->getAmbitos().size()!=3)
        _result=false;
    else _result=true;

    return _result;
}

