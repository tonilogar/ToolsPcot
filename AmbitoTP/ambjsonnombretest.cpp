#include "ambjsonnombretest.h"

AmbJsonNombreTest::AmbJsonNombreTest(QObject *parent, QString nombre)
    : AmbJsonEvaluaTest(parent)
{
    _errorMessage=QString("No se ha encontrado el ambito ")+nombre;
    _nombre=nombre;
}

bool AmbJsonNombreTest::syncTest(AmbitJson *ambJson)
{
    _lastAmbitJson=ambJson;
    _result=false;
    QList<Ambito*> listaAmbitos=_lastAmbitJson->getAmbitos();
    foreach(Ambito *amb,listaAmbitos) {
        if(amb->nombre()==_nombre)
            _result=true;
    }

    return _result;
}

