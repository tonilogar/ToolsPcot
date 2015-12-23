#include "ambevresizetest.h"

AmbEvResizeTest::AmbEvResizeTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("Falta el ejecutable resize"))
{

}

void AmbEvResizeTest::launchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo *info=_ambito->ejecutables().value("exeResize");

    if(!info->isFile()) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    if(!info->exists()) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    if(!info->isExecutable()) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    if(!info->isReadable()) {
        _isPassed=false;
        emit testResult(false);
        return;
    }
    _isPassed=true;
    emit testResult(true);
    return;


}

