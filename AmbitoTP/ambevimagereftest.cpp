#include "ambevimagereftest.h"

AmbEvImageRefTest::AmbEvImageRefTest(QObject *parent)
     : AmbEvaluaTest(parent,QStringLiteral("Falta la imagen de referencia"))
{
}

void AmbEvImageRefTest::launchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo info=_ambito->imageRef();

    if(!info.isFile()) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    if(!info.exists()) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    if(!info.isReadable()) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    _isPassed=true;
    emit testResult(true);
    return;
}
