#include "ambevrangoutmtest.h"

AmbEvRangoUtmTest::AmbEvRangoUtmTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("El valor de UTM por defecto no esta dentro de rango"))
{

}

void AmbEvRangoUtmTest::launchTest(Ambito *amb)
{
    _ambito=amb;

    int utm=_ambito->utm();

    if((29 < utm) || (31 > utm)) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    _isPassed=true;
    emit testResult(true);
    return;
}
