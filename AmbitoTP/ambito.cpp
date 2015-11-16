#include "ambito.h"

Ambito::Ambito(QObject *parent) : QObject(parent)
{
    _nombre=QString();
    _tamPixel=0.0;
    _utm=0;
    _imageRef=QFileInfo();
    _ejecutables.clear();
}

void Ambito::setNombre(QString n)
{
    _nombre=n;
}

void Ambito::setImageRef(QFileInfo iR)
{
    _imageRef=iR;
}

void Ambito::setTamPixel(double tp)
{
    _tamPixel=tp;
}

void Ambito::setUtm(int u)
{
    _utm=u;
}

void Ambito::addEjecutable(QString n, QFileInfo *info)
{
    _ejecutables.insert(n,info);
}

void Ambito::removeEjecutable(QString n)
{
    _ejecutables.remove(n);
}

QJsonObject Ambito::toJson() const
{
    QJsonObject res;
    res.insert(QStringLiteral("Nombreambito"),_nombre);
    if(_imageRef.isFile())
        res.insert(QStringLiteral("Path"),_imageRef.absoluteFilePath());
    else res.insert(QStringLiteral("Path"),QStringLiteral(""));
    res.insert(QStringLiteral("TamanyoPixel"),_tamPixel);
    res.insert(QStringLiteral("Utm"),_utm);

    QJsonArray arrayExec;
    QList<QString> claves=_ejecutables.keys();
    foreach(QString nombre,claves) {
        QJsonObject exec;
        exec.insert(QStringLiteral("Nombre"),nombre);
        exec.insert(QStringLiteral("Path"),_ejecutables.value(nombre)->absoluteFilePath());
        arrayExec.append(exec);
    }
    res.insert(QStringLiteral("Ejecutables"),arrayExec);
    return res;
}

Ambito *Ambito::fromJson(QJsonObject obj)
{
    Ambito *res=new Ambito(0);

    res->setNombre(obj.value(QStringLiteral("Nombreambito")).toString());
    res->setImageRef(QFileInfo(obj.value(QStringLiteral("Path")).toString()));
    res->setTamPixel(obj.value(QStringLiteral("TamanyoPixel")).toDouble());
    res->setUtm(obj.value(QStringLiteral("Utm")).toInt());

    return res;
}

bool Ambito::isValid() const
{
    //EVALUA SI EL AMBITO ES O NO ES VALIDO
    //¡¡OJO!! 'VALIDO' NO SIGNIFICA CORRECTO!!
    //QFile imageRef(_imageRef.absolutePath());
    if(!_nombre.isEmpty() || !_nombre.isNull())
        return false;
    else if(!_imageRef.exists())
        return false;
    else if(_imageRef.isReadable())
        return false;
    else if(!_utm<=0)
        return false;
    else if(!_tamPixel<=0.0)
        return false;
    else if(!_ejecutables.isEmpty())
        return false;
        return true;
}

 bool Ambito::existImageRef(QFileInfo imageRef)
 {
  if(_imageRef.exists()) return true;
  return false;
 }
