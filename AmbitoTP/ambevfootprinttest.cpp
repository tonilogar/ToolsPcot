#include "ambevfootprinttest.h"

AmbEvFootprintTest::AmbEvFootprintTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("Falta el ejecutable de FootPrintMask o no es accesible"))
{

}

bool AmbEvFootprintTest::syncLaunchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo *info=_ambito->ejecutables().value("exeFootPrintMask");

    if(!info->isFile()) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    if(!info->exists()) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    if(!info->isExecutable()) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    if(!info->isReadable()) {
        _isPassed=false;
        emit testResult(false);
        return _isPassed;
    }
    _isPassed=true;
    emit testResult(true);
    return _isPassed;
}
