#include "ambjsonespanyatest.h"

AmbJsonEspanyaTest::AmbJsonEspanyaTest(QObject *parent)
    : AmbJsonEvaluaTest(parent,QStringLiteral("Errores en ambito de Espanya 5 metres"))
{
    _listaTests.append(new AmbEvImageRefTest(this));
    _listaTests.append(new AmbEvFootprintTest(this));
    _listaTests.append(new AmbEvGeoTransformTest(this));
    _listaTests.append(new AmbEvResizeTest(this));
    _listaTests.append(new AmbEvSubsceneTest(this));
    _listaTests.append(new AmbEvPixelSizeTest(this));
    _listaTests.append(new AmbEvRangoUtmTest(this));
}

bool AmbJsonEspanyaTest::syncTest(AmbitJson *ambJson)
{
    _lastAmbitJson=ambJson;
    _result=true;
    Ambito *ambEspanya=0;

    foreach(Ambito *amb,_lastAmbitJson->getAmbitos()) {
        if(amb->nombre()==QStringLiteral("Espanya 5 metres"))
            ambEspanya=amb;
    }

    if(!ambEspanya) {
        _result=false;
        return _result;
    }

    foreach(AmbEvaluaTest *test,_listaTests) {
        if(!test->syncLaunchTest(ambEspanya))
            _result=false;
    }

    return _result;
}



