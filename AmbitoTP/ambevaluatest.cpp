#include "ambevaluatest.h"

AmbEvaluaTest::AmbEvaluaTest(QObject *parent, QString mensaje) : QObject(parent)
{
    _mensaje=mensaje;
    _ambito=0;
}

void AmbEvaluaTest::launchTest(Ambito *amb)
{
    syncLaunchTest(amb);
}

