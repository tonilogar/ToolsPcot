#include "ambevfootprinttest.h"

AmbEvFootprintTest::AmbEvFootprintTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("Falta el ejecutable de FootPrintMask o no es accesible"))
{

}

void AmbEvFootprintTest::launchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo *info=_ambito->ejecutables().value("exeFootPrintMask");

    if(!info->isFile()) {
        _isPassed=false;
        emit errorOnFootprint(true);
        return;
    }
    if(!info->exists()) {
        _isPassed=false;
        emit errorOnFootprint(true);
        return;
    }
    if(!info->isExecutable()) {
        _isPassed=false;
        emit errorOnFootprint(true);
        return;
    }
    if(!info->isReadable()) {
        _isPassed=false;
        emit errorOnFootprint(true);
        return;
    }
    _isPassed=true;
    emit errorOnFootprint(false);
    return;
}
