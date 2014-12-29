#include "readercoordinates.h"

ReaderCoordinates::ReaderCoordinates(QObject *parent) :
    QObject(parent)
{
    _error=QString();
    _listCoordinates.clear();
}
