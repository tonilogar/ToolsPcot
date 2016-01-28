#include "ambjsoncatalunyatest.h"

AmbJsonCatalunyaTest::AmbJsonCatalunyaTest(QObject *parent)
    : AmbJsonEvaluaTest(parent,QStringLiteral("Errores en el ambito de Catalunya"))
{
    _listaTests.append(new AmbEvExtractionTest(this));
    _listaTests.append(new AmbEvImageRefTest(this));
    _listaTests.append(new AmbEvFootprintTest(this));
    _listaTests.append(new AmbEvGeoTransformTest(this));
    _listaTests.append(new AmbEvResizeTest(this));
    _listaTests.append(new AmbEvSubsceneTest(this));
    _listaTests.append(new AmbEvPixelSizeTest(this));
    _listaTests.append(new AmbEvRangoUtmTest(this));
}

bool AmbJsonCatalunyaTest::syncTest(AmbitJson *ambJson)
{
    _lastAmbitJson=ambJson;
    _result=true;
    Ambito *ambCatalunya=0;

    foreach(Ambito *amb,_lastAmbitJson->getAmbitos()) {
        if(amb->nombre()==QStringLiteral("Catalunya lidar 2 metres"))
            ambCatalunya=amb;
    }

    if(!ambCatalunya) {
        _result=false;
        return _result;
    }

    foreach(AmbEvaluaTest *test,_listaTests) {
        if(!test->syncLaunchTest(ambCatalunya))
            _result=false;
    }

    return _result;
}

