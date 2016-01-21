#include "ambitjson.h"

QString AmbitJson::_errorStatic=QString();

AmbitJson::AmbitJson(QObject *parent, QFileInfo fileInfo) : QObject(parent)
{
    _dataFile=fileInfo;
    _ambitosArchivo.clear();
    _error=QString();
    prepararEvaluadores();
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
    if(!nTemplate.open(QFile::Text | QFile::ReadOnly))
    {
        _error=QStringLiteral("No se pudo abrir el archivo especificado.");
        return;
    }

    QByteArray json=nTemplate.readAll();
    QJsonDocument docJson=QJsonDocument::fromJson(json);

    if(docJson.isEmpty() || docJson.isNull())
    {
        _error=QStringLiteral("Formato de archivo no reconocido.");
        nTemplate.close();
        return;
    }

    if(!docJson.isArray())
    {
        _error=QStringLiteral("Formato JSON no compatible.");
        nTemplate.close();
        return;
    }


    if(!_ambitosArchivo.isEmpty()) {
        foreach(Ambito *amb,_ambitosArchivo)
            delete amb;
        _ambitosArchivo.clear();
    }

    QJsonArray arrayJson=docJson.array();
    QJsonArray::iterator it;
    for(it=arrayJson.begin();it!=arrayJson.end();it++)
    {
        _ambitosArchivo.append(Ambito::fromJson((*it).toObject()));
    }
    nTemplate.close();
}

bool AmbitJson::isLoaded() const
{
    return !_ambitosArchivo.isEmpty();
}

bool AmbitJson::isValid() const
{
    if(_ambitosArchivo.isEmpty())
    {
        return false;
    }
    foreach(Ambito *amb,_ambitosArchivo)
    {
        if(!amb->isValid())
        {
            return false;
        }
    }
    return true;
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

void AmbitJson::prepararEvaluadores()
{
//    //1.- Crear evaluadores
//    _evCatalunya=new AmbEvaluador(this);
//    _evEspa=new AmbEvaluador(this);
//    _evFrancia=new AmbEvaluador(this);

//    AmbEvExtractionTest *testExtraction=new AmbEvExtractionTest(this);
//    AmbEvImageRefTest *testImageRef=new AmbEvImageRefTest(this);
//    AmbEvaSizePixelTest *testSizePixel=new AmbEvaSizePixelTest(this);
//    AmbEvFootprintTest *testFootprint=new AmbEvFootprintTest(this);
//    AmbEvGeoTransformTest *testGeoTrans=new AmbEvGeoTransformTest(this);
//    AmbEvResizeTest *testResize=new AmbEvResizeTest(this);
//    AmbEvSubsceneTest *testSubscene=new AmbEvSubsceneTest(this);
//    AmbEvRangoUtmTest *testRangoUtm=new AmbEvRangoUtmTest(this);
//    AmbEvUtmFranciaTest *testFrancUtm=new AmbEvUtmFranciaTest(this);

//    //2.- Asignar tests a los evaluadores
//    _evCatalunya->addTest(testExtraction);
//    _evCatalunya->addTest(testImageRef);
//    _evCatalunya->addTest(testSizePixel);
//    _evCatalunya->addTest(testFootprint);
//    _evCatalunya->addTest(testGeoTrans);
//    _evCatalunya->addTest(testResize);
//    _evCatalunya->addTest(testSubscene);

//    _evEspa->addTest(testFootprint);
//    _evEspa->addTest(testImageRef);
//    _evEspa->addTest(testSizePixel);
//    _evEspa->addTest(testGeoTrans);
//    _evEspa->addTest(testResize);
//    _evEspa->addTest(testSubscene);

//    _evFrancia->addTest(testFootprint);
//    _evFrancia->addTest(testImageRef);
//    _evFrancia->addTest(testSizePixel);
//    _evFrancia->addTest(testResize);
//    _evFrancia->addTest(testSubscene);
//    _evFrancia->addTest(testFrancUtm);

//    //3.- Conectar
//    connect(testExtraction,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
//    connect(testImageRef,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
//    connect(testSizePixel,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
//    connect(testFootprint,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
//    connect(testResize,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
//    connect(testSubscene,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
//    connect(testGeoTrans,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
//    connect(testFrancUtm,SIGNAL(testResult(bool)),this,SLOT(resultadosTest(bool)));
}

void AmbitJson::resultadosTest(bool result)
{
    if(!result)
        _isCorrect=result;
}

bool AmbitJson::isCorrect()
{
    _isCorrect=true;

    if(_ambitosArchivo.isEmpty())
        return false;
    if(_ambitosArchivo.count()!=3)
        return false;

    foreach(Ambito *amb,_ambitosArchivo) {
        if(amb->nombre().contains("Catalunya"))
            _evCatalunya->check(amb);
        else if(amb->nombre().contains("Francia"))
            _evFrancia->check(amb);
        else if(amb->nombre().contains("Espanya"))
            _evEspa->check(amb);
    }

    return _isCorrect;
}



