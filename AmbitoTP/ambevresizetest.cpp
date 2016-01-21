#include "ambevresizetest.h"

AmbEvResizeTest::AmbEvResizeTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("Falta el ejecutable resize"))
{

}

bool AmbEvResizeTest::syncLaunchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo *info=_ambito->ejecutables().value("exeResize");

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
