#include "ambevaluador.h"

AmbEvaluador::AmbEvaluador(QObject *parent, Ambito *amb) : QObject(parent)
{
    _ambito=amb;
}

void AmbEvaluador::addTest(AmbEvaluaTest *test)
{
    _listaTests.append(test);
}

void AmbEvaluador::removeTest(AmbEvaluaTest *test)
{
    _listaTests.removeAll(test);
}

bool AmbEvaluador::isReadyToCheck() const
{
    return (_ambito!=0);
}

void AmbEvaluador::check(Ambito *amb)
{
    if(amb)
        _ambito=amb;

    foreach(AmbEvaluaTest *test,_listaTests) {
        test->launchTest(_ambito);
    }
}
