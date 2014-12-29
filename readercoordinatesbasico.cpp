#include "readercoordinatesbasico.h"

ReaderCoordinatesBasico::ReaderCoordinatesBasico(QObject *parent) :
    ReaderCoordinates(parent)
{
}
bool ReaderCoordinatesBasico::canRead(QString pathFile)
{
    QFileInfo info(pathFile);
    if(!info.exists() || !info.isReadable() || !info.isFile())
    {
        return false;
    }
    if(!info.suffix()=="txt")
    {
        return false;
    }
    return true;
}

bool ReaderCoordinatesBasico::tryRead(QString pathFile)
{
    QFile file(pathFile);
    if(!file.open(QFile::Text | QFile::ReadOnly))
    {
        _error="Aquest fitxer no es pot obrir";
        return false;
    }
    QTextStream flujo(&file);
    flujo.setRealNumberPrecision(6);
    QString ide=QString();
    double xa=-1, ya=-1, xb=-1, yb=-1;
    bool error=false;
    bool ideError=false;
    IdentificadorCoordenadas *identiCoor=0;
    while (!flujo.atEnd() && !error)
    {
      flujo >> ide >> xa >> ya >> xb >> yb;
      ide.toDouble(&ideError);
      if (!ideError) error=true;
      if (xa==-1 || ya==-1 || xb==-1 || yb==-1)
      {
          error=true;
      }
      if (!error)
      {
          identiCoor=new IdentificadorCoordenadas(0,ide, xa, ya, xb, yb);
          _listCoordinates << identiCoor;
      }
      xa=-1; ya=-1; xb=-1; yb=-1;
      ide.clear();
    }
    if (error)
    {
     _listCoordinates.clear();
     _error="El format del fitxer coordenades no es correcte";
     return false;
    }
    return true;
}
