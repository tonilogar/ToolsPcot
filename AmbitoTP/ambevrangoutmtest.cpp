#include "ambevrangoutmtest.h"

AmbEvRangoUtmTest::AmbEvRangoUtmTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("El valor de UTM por defecto no esta dentro de rango"))
{

}

bool AmbEvRangoUtmTest::syncLaunchTest(Ambito *amb)
{
    _ambito=amb;

    int utm=_ambito->utm();

    if((utm < 29) || (utm > 31)) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    _isPassed=true;
    emit testResult(true);
    return _isPassed;
}
