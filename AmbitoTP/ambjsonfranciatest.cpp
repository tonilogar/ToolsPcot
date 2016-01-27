#include "ambjsonfranciatest.h"

AmbJsonFranciaTest::AmbJsonFranciaTest(QObject *parent)
    : AmbJsonEvaluaTest(parent,QStringLiteral("Errores en el ambito de Francia Farmstar"))
{
    _listaTests.append(new AmbEvImageRefTest(this));
    _listaTests.append(new AmbEvFootprintTest(this));
    _listaTests.append(new AmbEvResizeTest(this));
    _listaTests.append(new AmbEvSubsceneTest(this));
    _listaTests.append(new AmbEvPixelSizeTest(this));
    _listaTests.append(new AmbEvUtmFranciaTest(this));

}

bool AmbJsonFranciaTest::syncTest(AmbitJson *ambJson)
{
    _lastAmbitJson=ambJson;
    _result=true;
    Ambito *ambFrancia=0;

    foreach(Ambito *amb,_lastAmbitJson->getAmbitos()) {
        if(amb->nombre()==QStringLiteral("Francia Farmstar"))
            ambFrancia=amb;
    }

    if(!ambFrancia) {
        _result=false;
        return false;
    }

    foreach(AmbEvaluaTest *test,_listaTests) {
        if(!test->syncLaunchTest(ambFrancia))
            _result=false;
    }

    return _result;
}

