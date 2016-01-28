#include "ambevpixelsizetest.h"

AmbEvPixelSizeTest::AmbEvPixelSizeTest(QObject *parent)
    : AmbEvaluaTest(parent,QStringLiteral("El tamaño de pixel no está dentro del rango aceptable"))
{

}

bool AmbEvPixelSizeTest::syncLaunchTest(Ambito *amb)
{
    _ambito=amb;

    double pSize=_ambito->tamPixel();
    if(pSize<0 || pSize>100) {
        _isPassed=false;
    }
    else _isPassed=true;
    emit testResult(_isPassed);
    return _isPassed;
}

