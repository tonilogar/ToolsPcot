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

    _evaluador=new AmbEvaluador(this);

    AmbEvExtractionTest *testExtraction=new AmbEvExtractionTest(this);
    AmbEvFootprintTest *testFootprint=new AmbEvFootprintTest(this);
    AmbEvGeoTransformTest *testGeoTrans=new AmbEvGeoTransformTest(this);
    AmbEvResizeTest *testResize=new AmbEvResizeTest(this);
    AmbEvSubsceneTest *testSubscene=new AmbEvSubsceneTest(this);

    connect(testExtraction,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testFootprint,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testResize,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testSubscene,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));
    connect(testGeoTrans,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));

    _evaluador->addTest(testExtraction);
    _evaluador->addTest(testFootprint);
    _evaluador->addTest(testGeoTrans);
    _evaluador->addTest(testResize);
    _evaluador->addTest(testSubscene);
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
    for(int i=0;i<numTabs;i++) {
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

    //lanzamos los test

    Ambito *falsoAmbito=new Ambito(this);

    QStringList listaNombres=mapaEjecutables.keys();

    foreach(QString nombre,listaNombres)
        falsoAmbito->addEjecutable(nombre,mapaEjecutables.value(nombre));

    _evaluador->check(falsoAmbito);

    //Otra forma de comprobar el resultados de los test
    QList<AmbEvaluaTest*> listaTest=_evaluador->getTestList();

    foreach(AmbEvaluaTest *test,listaTest) {
        if(test->isPassed())
            qDebug() << "PASSED";
        else qDebug() << "FAILED";
    }
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
