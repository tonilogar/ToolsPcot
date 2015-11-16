#include "ambitjson.h"

QString AmbitJson::_errorStatic=QString();

AmbitJson::AmbitJson(QObject *parent, QFileInfo fileInfo) : QObject(parent)
{
    _dataFile=fileInfo;
    _ambitosArchivo.clear();
    _error=QString();
}

bool AmbitJson::exist() const
{
    return _dataFile.exists();
}

QFileInfo AmbitJson::getFileInfo() const
{
    return _dataFile;
}

void AmbitJson::setFileInfo(QFileInfo info)
{
    _dataFile=info;
}

bool AmbitJson::createStandardTemplate(QFileInfo info)
{
    QFile nTemplate(info.absoluteFilePath());

    if(!nTemplate.open(QFile::Text | QFile::WriteOnly)) {
        _errorStatic=QStringLiteral("No se pudo abrir el archivo para crear la plantilla.");
        return false;
    }

    //Genero el documento JSON y lo escribo en el template
    QJsonArray arrayJson;

    //Ambitos por defecto
    Ambito catalunya,espanya,francia;
    catalunya.setNombre(QStringLiteral("Catalunya lidar 2 metres"));
    espanya.setNombre(QStringLiteral("Espanya 5 metres"));
    francia.setNombre(QStringLiteral("Francia Farmstar"));

    catalunya.setTamPixel(1);
    espanya.setTamPixel(5);
    francia.setTamPixel(10);

    catalunya.setUtm(31);
    espanya.setUtm(30);
    francia.setUtm(1);

    QString pathImageCat;
    QString pathImageEsp;
    QString pathImageFra;
    catalunya.setImageRef(pathImageCat);
    espanya.setImageRef(pathImageEsp);
    francia.setImageRef(pathImageFra);

    //Rutas de referencia: EN BLANCO
    //Ejecutables: EN BLANCO
    catalunya.addEjecutable(QStringLiteral("exeExtraction"),new QFileInfo());
    catalunya.addEjecutable(QStringLiteral("exeResize"),new QFileInfo());
    catalunya.addEjecutable(QStringLiteral("exeFootPrintMask"),new QFileInfo());
    catalunya.addEjecutable(QStringLiteral("exeSubScene"),new QFileInfo());
    catalunya.addEjecutable(QStringLiteral("exeGeoTransform"),new QFileInfo());

    espanya.addEjecutable(QStringLiteral("exeFootPrintMask"),new QFileInfo());
    espanya.addEjecutable(QStringLiteral("exeResize"),new QFileInfo());
    espanya.addEjecutable(QStringLiteral("exeSubScene"),new QFileInfo());
    espanya.addEjecutable(QStringLiteral("exeGeoTransform"),new QFileInfo());

    francia.addEjecutable(QStringLiteral("exeFootPrintMask"),new QFileInfo());
    francia.addEjecutable(QStringLiteral("exeResize"),new QFileInfo());
    francia.addEjecutable(QStringLiteral("exeSubScene"),new QFileInfo());
    francia.addEjecutable(QStringLiteral("exeResize"),new QFileInfo());

    arrayJson.append(catalunya.toJson());
    arrayJson.append(espanya.toJson());
    arrayJson.append(francia.toJson());

    QJsonDocument doc(arrayJson);
    QByteArray jTemplate=doc.toJson();
    if((-1==nTemplate.write(jTemplate.data(),jTemplate.size()))) {
        _errorStatic=QStringLiteral("No se pudo escribir la plantilla en el archivo.");
        nTemplate.close();
        return false;
    }

    nTemplate.close();
    return true;
}

AmbitJson::~AmbitJson()
{
    if(!_ambitosArchivo.isEmpty()) {
        foreach (Ambito* amb, _ambitosArchivo) {
            delete amb;
        }
        _ambitosArchivo.clear();
    }
    this->~QObject();
}

void AmbitJson::load()
{
    QFile nTemplate(_dataFile.absoluteFilePath());

    if(!nTemplate.open(QFile::Text | QFile::ReadOnly)) {
        _error=QStringLiteral("No se pudo abrir el archivo especificado.");
        return;
    }

    QByteArray json=nTemplate.readAll();
    QJsonDocument docJson=QJsonDocument::fromJson(json);

    if(docJson.isEmpty() || docJson.isNull()) {
        _error=QStringLiteral("Formato de archivo no reconocido.");
        nTemplate.close();
        return;
    }

    if(!docJson.isArray()) {
        _error=QStringLiteral("Formato JSON no compatible.");
        nTemplate.close();
        return;
    }

    QJsonArray arrayJson=docJson.array();
    QJsonArray::iterator it;
    for(it=arrayJson.begin();it!=arrayJson.end();it++) {
        _ambitosArchivo.append(Ambito::fromJson((*it).toObject()));
    }

    nTemplate.close();
}

bool AmbitJson::isLoaded() const
{
    return !_ambitosArchivo.isEmpty();
}

void AmbitJson::save()
{
    QFile fJson(_dataFile.absoluteFilePath());

    fJson.open(QFile::Text | QFile::WriteOnly);

    QJsonArray jArray;
    foreach(Ambito *amb,_ambitosArchivo) {
        jArray.append(amb->toJson());
    }

    QJsonDocument jDoc(jArray);

    QByteArray jByte=jDoc.toJson();
    fJson.write(jByte.data(),jByte.size());

    fJson.close();
}

bool AmbitJson::isSaved() const
{
    ///@todo Falta implementar
    return true;
}

void AmbitJson::addAmbito(Ambito *amb)
{
    _ambitosArchivo.append(amb);
}

void AmbitJson::removeAmbito(Ambito *amb)
{
    _ambitosArchivo.removeAll(amb);
}

