#include "ambevextractiontest.h"

AmbEvExtractionTest::AmbEvExtractionTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("Falta el ejecutable de Extraction o no es accesible"))
{

}

void AmbEvExtractionTest::launchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo *info=_ambito->ejecutables().value("exeExtraction");

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

