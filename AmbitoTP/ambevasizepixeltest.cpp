#include "ambevasizepixeltest.h"

AmbEvaSizePixelTest::AmbEvaSizePixelTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("El tamaño de pixel esta fuera de rango"))
{
}

void AmbEvaSizePixelTest::launchTest(Ambito *amb)
{

    _ambito=amb;
    double sizePixel=_ambito->tamPixel();
    if(sizePixel<0 || sizePixel>100){
        _isPassed=false;
        emit testResult(false);
        return;
    }
     _isPassed=true;
     emit testResult(true);
     return;
}
