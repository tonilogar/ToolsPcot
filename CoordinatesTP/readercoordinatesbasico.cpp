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
    IdentificadorCoordenadas *identiCoor=0;
    do
    {
      flujo >> ide >> xa >> ya >> xb >> yb;
      identiCoor=new IdentificadorCoordenadas(0,ide,xa,ya,xb,yb);
      _listCoordinates << identiCoor;
      ide.clear();
      xa=xb=ya=yb=0;
    }
    while (!flujo.atEnd());
    return checkListaIdentificadores();
}

bool ReaderCoordinatesBasico::checkListaIdentificadores()
{
    bool resultado=true;
    foreach(IdentificadorCoordenadas *ide,_listCoordinates)
    {
        //COMPRUEBA CADA IDENTIFICADOR;
    }

    //    bool error=false;
    //    bool ideError=false;
    //    //Expresio regular per comprobar el valor de identificador
    //    QRegExp expre("^*\w*$",Qt::CaseInsensitive);
    //    if(!expre.isValid())
    //    {
    //     _error="La expresion regular no es correcta";
    //     return false;
    ///@todo IMPLEMENTAR EVALUACION DE LISTA DE IDENTIFICADORES
    return resultado;
}
