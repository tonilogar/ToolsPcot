#include "ambevutmfranciatest.h"

AmbEvUtmFranciaTest::AmbEvUtmFranciaTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("No se utiliza el valor de UTM para este ambito."))
{

}

void AmbEvUtmFranciaTest::launchTest(Ambito *amb)
{
    _ambito=amb;

    int utm=_ambito->utm();
    if(utm==-1) {
        _isPassed=true;
        emit testResult(true);
    }
    else {
        _isPassed=false;
        emit testResult(false);
    }
    return;

}
