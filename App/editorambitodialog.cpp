#include "editorambitodialog.h"
#include "ui_editorambitodialog.h"


EditorAmbitoDialog::EditorAmbitoDialog(QWidget *parent, AmbitJson *archivoAmb) :
    QDialog(parent),
    ui(new Ui::EditorAmbitoDialog)
{
    ui->setupUi(this);
    _archivoAm=archivoAmb;
    connect(ui->lineEditExtraction,SIGNAL(textChanged(QString)),this,SLOT(setExtraction(QString)));
    connect(ui->lineEditFootPrintMask,SIGNAL(textChanged(QString)),this,SLOT(setFootPrintMask(QString)));
    connect(ui->lineEditGeoTransformation,SIGNAL(textChanged(QString)),this,SLOT(setImageOpeGeo(QString)));
    connect(ui->lineEditResize,SIGNAL(textChanged(QString)),this,SLOT(setResize(QString)));
    connect(ui->lineEditSubScene,SIGNAL(textChanged(QString)),this,SLOT(setSubScene(QString)));

    connect(ui->toolButtonExtraction,SIGNAL(clicked()),this,SLOT(selectExtraction()));
    connect(ui->toolButtonFootPrintMask,SIGNAL(clicked()),this,SLOT(selectFootPrintMask()));
    connect(ui->toolButtonGeoTransformation,SIGNAL(clicked()),this,SLOT(selectImageOpeGeo()));
    connect(ui->toolButtonResize,SIGNAL(clicked()),this,SLOT(selectResize()));
    connect(ui->toolButtonSubScene,SIGNAL(clicked()),this,SLOT(selectSubScene()));
    connect(ui->ambitosDefectoButton,SIGNAL(clicked(bool)),this,SLOT(crearAmbitosDefecto()));

    _evaluadorEspa=new AmbEvaluador(this);
    _evaluadorCat=new AmbEvaluador(this);
    _evaluadorFranc=new AmbEvaluador(this);

    AmbEvExtractionTest *testExtraction=new AmbEvExtractionTest(this);
    AmbEvImageRefTest *testImageRef=new AmbEvImageRefTest(this);
    AmbEvFootprintTest *testFootprint=new AmbEvFootprintTest(this);
    AmbEvGeoTransformTest *testGeoTrans=new AmbEvGeoTransformTest(this);
    AmbEvResizeTest *testResize=new AmbEvResizeTest(this);
    AmbEvSubsceneTest *testSubscene=new AmbEvSubsceneTest(this);
    AmbEvUtmFranciaTest *testFrancUtm=new AmbEvUtmFranciaTest(this);
    AmbEvPixelSizeTest *testPixelSize=new AmbEvPixelSizeTest(this);

    connect(testExtraction,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));   
    connect(testImageRef,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testFootprint,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testResize,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testSubscene,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testGeoTrans,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testFrancUtm,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testPixelSize,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));

    _evaluadorCat->addTest(testExtraction);
    _evaluadorCat->addTest(testImageRef);
    _evaluadorCat->addTest(testFootprint);
    _evaluadorCat->addTest(testGeoTrans);
    _evaluadorCat->addTest(testResize);
    _evaluadorCat->addTest(testSubscene);
    _evaluadorCat->addTest(testPixelSize);

    _evaluadorEspa->addTest(testFootprint);
    _evaluadorEspa->addTest(testImageRef);
    _evaluadorEspa->addTest(testGeoTrans);
    _evaluadorEspa->addTest(testResize);
    _evaluadorEspa->addTest(testSubscene);
    _evaluadorEspa->addTest(testPixelSize);

    _evaluadorFranc->addTest(testFootprint);
    _evaluadorFranc->addTest(testImageRef);
    _evaluadorFranc->addTest(testResize);
    _evaluadorFranc->addTest(testSubscene);
    _evaluadorFranc->addTest(testFrancUtm);
    _evaluadorFranc->addTest(testPixelSize);
}

EditorAmbitoDialog::~EditorAmbitoDialog()
{
    delete ui;
}

int EditorAmbitoDialog::exec()
{
    recargarAmbitos();

    return QDialog::exec();
}

void EditorAmbitoDialog::recargarAmbitos()
{
    //Limpiar todos los widgets que no sean la lista de ejecutables
    int numTabs=ui->tabWidget->count();

    QWidget *tab;
    for(int i=numTabs;i>0;i--) {
        if(ui->tabWidget->tabText(i)!=QStringLiteral("Ejecutables")) {
            tab=ui->tabWidget->widget(i);
            ui->tabWidget->removeTab(i);
            delete tab;
        }
    }

    //Creo un nuevo widget por cada ambito del archivo
    AmbitoWidget* ambitoW;
    QList<Ambito*> listaAmbitos=_archivoAm->getAmbitos();
    foreach(Ambito *amb,listaAmbitos) {
        ambitoW=new AmbitoWidget(this,amb);
        ui->tabWidget->addTab(ambitoW,amb->nombre());
    }

    //Revisar los ambitos, seleccionar los ejecutables, escribir los line edit
    QMap<QString,QFileInfo*> mapaEjecutables;
    foreach(Ambito *amb,listaAmbitos) {
        QMap<QString,QFileInfo*> ambEjecutables=amb->ejecutables();
        QStringList listaClaves=ambEjecutables.keys();
        foreach(QString clave,listaClaves) {
            if(!mapaEjecutables.contains(clave))
                mapaEjecutables.insert(clave,ambEjecutables.value(clave));
        }
    }

    if(!mapaEjecutables.contains("exeExtraction") || !mapaEjecutables.value("exeExtraction")->isFile())
        ui->lineEditExtraction->setText(QString());
    else ui->lineEditExtraction->setText(mapaEjecutables.value("exeExtraction")->absoluteFilePath());
    _exeExtraction.setFile(ui->lineEditExtraction->text());

    if(!mapaEjecutables.contains("exeFootPrintMask") || !mapaEjecutables.value("exeFootPrintMask")->isFile())
        ui->lineEditFootPrintMask->setText(QString());
    else ui->lineEditFootPrintMask->setText(mapaEjecutables.value("exeFootPrintMask")->absoluteFilePath());
    _exeFootPrintMask.setFile(ui->lineEditFootPrintMask->text());

    if(!mapaEjecutables.contains("exeResize") || !mapaEjecutables.value("exeResize")->isFile())
        ui->lineEditResize->setText(QString());
    else ui->lineEditResize->setText(mapaEjecutables.value("exeResize")->absoluteFilePath());
    _exeResize.setFile(ui->lineEditResize->text());

    if(!mapaEjecutables.contains("exeSubScene") || !mapaEjecutables.value("exeSubScene")->isFile())
        ui->lineEditSubScene->setText(QString());
    else ui->lineEditSubScene->setText(mapaEjecutables.value("exeSubScene")->absoluteFilePath());
    _exeSubScene.setFile(ui->lineEditSubScene->text());

    if(!mapaEjecutables.contains("exeGeoTransform") || !mapaEjecutables.value("exeGeoTransform")->isFile())
        ui->lineEditGeoTransformation->setText(QString());
    else ui->lineEditGeoTransformation->setText(mapaEjecutables.value("exeGeoTransform")->absoluteFilePath());
    _exeImageOpeGeo.setFile(ui->lineEditGeoTransformation->text());

    //lanzamos los test

    foreach(Ambito *amb,listaAmbitos) {
        if(amb->nombre().contains("Catalunya"))
            _evaluadorCat->check(amb);
        if(amb->nombre().contains("Espanya"))
            _evaluadorEspa->check(amb);
        if(amb->nombre().contains("Francia"))
            _evaluadorFranc->check(amb);
    }

    //Otra forma de comprobar el resultados de los test
}


QFileInfo EditorAmbitoDialog::getExtraction()
{
    return _exeExtraction;
}

QFileInfo EditorAmbitoDialog::getSubScene()
{
    return _exeSubScene;
}
QFileInfo EditorAmbitoDialog::getFootPrintMask()
{
    return _exeFootPrintMask;
}
QFileInfo EditorAmbitoDialog::getResize()
{
    return _exeResize;
}
QFileInfo EditorAmbitoDialog::getImageOpeGeo()
{
    return _exeImageOpeGeo;
}


void EditorAmbitoDialog::setExtraction(QString file)
{
    _exeExtraction.setFile(file);
}

void EditorAmbitoDialog::setSubScene(QString file)
{
    _exeSubScene.setFile(file);
}
void EditorAmbitoDialog::setFootPrintMask(QString file)
{
    _exeFootPrintMask.setFile(file);
}

void EditorAmbitoDialog::setResize(QString file)
{
    _exeResize.setFile(file);
}
void EditorAmbitoDialog::setImageOpeGeo(QString file)
{
    _exeImageOpeGeo.setFile(file);
}



void EditorAmbitoDialog::selectExtraction()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Seleccionar ejecutable extraction"),qApp->applicationDirPath(),"Ejecutable (*.exe)");
    if(path.isEmpty() || path.isNull())
        return;
    ui->lineEditExtraction->setText(path);
    setExtraction(path);
}

void EditorAmbitoDialog::selectSubScene()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Seleccionar ejecutable subscene"),qApp->applicationDirPath(),"Ejecutable (*.exe)");
    if(path.isEmpty() || path.isNull())
        return;
    ui->lineEditSubScene->setText(path);
}
void EditorAmbitoDialog::selectFootPrintMask()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Seleccionar ejecutable footprintmask"),qApp->applicationDirPath(),"Ejecutable (*.exe)");
    if(path.isEmpty() || path.isNull())
        return;
    ui->lineEditFootPrintMask->setText(path);
    setFootPrintMask(path);
}
void EditorAmbitoDialog::selectResize()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Seleccionar ejecutable resize"),qApp->applicationDirPath(),"Ejecutable (*.exe)");
    if(path.isEmpty() || path.isNull())
        return;
    ui->lineEditResize->setText(path);
}
void EditorAmbitoDialog::selectImageOpeGeo()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Seleccionar ejecutable imageopegeo"),qApp->applicationDirPath(),"Ejecutable (*.exe)");
    if(path.isEmpty() || path.isNull())
        return;
    ui->lineEditGeoTransformation->setText(path);
}

void EditorAmbitoDialog::accept()
{
    //Aceptar implica reescribir la informacion de los ambitos
    QList<Ambito*> listaAmbitos=_archivoAm->getAmbitos();

    foreach(Ambito *amb,listaAmbitos) {
        QMap<QString,QFileInfo*> mapaEjecutables=amb->ejecutables();
        if(mapaEjecutables.contains("exeExtraction")) {
            amb->removeEjecutable("exeExtraction");
            amb->addEjecutable("exeExtraction",new QFileInfo(_exeExtraction));
        }
        if(mapaEjecutables.contains("exeFootPrintMask")) {
            amb->removeEjecutable("exeFootPrintMask");
            amb->addEjecutable("exeFootPrintMask",new QFileInfo(_exeFootPrintMask));
        }
        if(mapaEjecutables.contains("exeResize")) {
            amb->removeEjecutable("exeResize");
            amb->addEjecutable("exeResize",new QFileInfo(_exeResize));
        }
        if(mapaEjecutables.contains("exeGeoTransform")) {
            amb->removeEjecutable("exeGeoTransform");
            amb->addEjecutable("exeGeoTransform",new QFileInfo(_exeImageOpeGeo));
        }
        if(mapaEjecutables.contains("exeSubScene")) {
            amb->removeEjecutable("exeSubScene");
            amb->addEjecutable("exeSubScene",new QFileInfo(_exeSubScene));
        }
    }

    _archivoAm->save();
    QDialog::accept();
}

void EditorAmbitoDialog::depuracionSalidaEvaluador(bool data)
{
    AmbEvaluaTest *test=qobject_cast<AmbEvaluaTest*>(sender());

    if(data)
        qDebug() << "TEST PASSED";
    else
        qDebug() << test->mensaje();
}

void EditorAmbitoDialog::crearAmbitosDefecto()
{
    int conformidad=QMessageBox::warning(this, tr("Crear ambitos por defecto"),tr("ADVERTENCIA: Esta operación sobreescribirá el contenido del archivo de ambitos en uso. ¿Está seguro de que quiere hacerlo?"),QMessageBox::No,QMessageBox::Yes,QMessageBox::Cancel);
    if((conformidad==QMessageBox::Cancel) || (conformidad==QMessageBox::No))
            return;

    QFileInfo archivo=_archivoAm->getFileInfo();

    AmbitJson::createStandardTemplate(archivo);

    _archivoAm->load();
    recargarAmbitos();
}
