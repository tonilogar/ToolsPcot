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
         qDebug()<< "false Canred" ;
        return false;

    }
    if(info.suffix()!="txt")
    {
         qDebug()<< "false Canred" ;
        return false;

    }
    qDebug()<< "true Canred" ;
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
    double xa=0, ya=0, xb=0, yb=0;
    bool error=false;
    bool ideError=false;
    IdentificadorCoordenadas *identiCoor=0;
    //Expresio regular per comprobar el valor de identificador
    QRegExp expre("^*\w*$",Qt::CaseInsensitive);
    if(!expre.isValid())
    {
     _error="La expresion regular no es correcta";
     return false;
    }
    while (!flujo.atEnd() && !error)
    {
      flujo >> ide >> xa >> ya >> xb >> yb;
      ideError=ide.contains(expre);
      if (!ideError) error=true;
      if (xa==0 || ya==0 || xb==0 || yb==0)
      {
          error=true;
      }
      if (!error)
      {
          identiCoor=new IdentificadorCoordenadas(0,ide, xa, ya, xb, yb);
          _listCoordinates << identiCoor;
      }
      xa=0; ya=0; xb=0; yb=0;
      ide.clear();
    }
    if (error)
    {
     _listCoordinates.clear();
     _error="El format del fitxer coordenades no es correcte";
     qDebug()<< "false Ctryred" ;
     return false;
    }
    qDebug()<< "true Ctryred" ;
    return true;
}
