#include "ambevsubscenetest.h"

AmbEvSubsceneTest::AmbEvSubsceneTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("Falta el ejecutable subscene"))
{

}

bool AmbEvSubsceneTest::syncLaunchTest(Ambito *amb)
{
    _ambito=amb;

    QFileInfo *info=_ambito->ejecutables().value("exeSubScene");

    if(!info->isFile()) {
        _isPassed=false;
        _mensaje=QStringLiteral("El ejecutable exeSubScene no es un archivo");
        emit testResult(false);
        return _isPassed;
    }
    if(!info->exists()) {
        _isPassed=false;
        _mensaje=QStringLiteral("El ejecutable exeSubScene no existe");
        emit testResult(false);
        return _isPassed;
    }
    if(!info->isExecutable()) {
        _isPassed=false;
        _mensaje=QStringLiteral("El ejecutable exeSubScene no es ejecutable");
        emit testResult(false);
        return _isPassed;
    }
    if(!info->isReadable()) {
        _isPassed=false;
        _mensaje=QStringLiteral("El ejecutable exeSubScene no es accesible");
        emit testResult(false);
        return _isPassed;
    }
    _isPassed=true;
    emit testResult(true);
    return _isPassed;
}

