#include "ambevimagereftest.h"

AmbEvImageRefTest::AmbEvImageRefTest(QObject *parent)
     : AmbEvaluaTest(parent,QStringLiteral("Falta la imagen de referencia"))
{
}

bool AmbEvImageRefTest::syncLaunchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo info=_ambito->imageRef();

    if(!info.isFile()) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    if(!info.exists()) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    if(!info.isReadable()) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    _isPassed=true;
    emit testResult(true);
    return _isPassed;
}
