#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _preferenciasAvanzadas=new PreferenciasAvanzadasDialog(this);
    connect(ui->actionOpciones_avanzadas,SIGNAL(triggered(bool)),_preferenciasAvanzadas,SLOT(reload()));
    connect(ui->actionAbrir_proyecto,SIGNAL(triggered()),this,SLOT(abrirProyecto()));
    connect(ui->actionGuardar_proyecto,SIGNAL(triggered()),this,SLOT(guardarProyecto()));

    connect(ui->widgetCoordinates,SIGNAL(loadedModelo(bool)),this,SIGNAL(activarWidgetsRegistro(bool)));
    connect(this,SIGNAL(activarWidgetsRegistro(bool)),ui->cnp,SLOT(conectarWidget(bool)));
    _registroCnp=new RegistroCnp(this);

    ui->cnp->setRegistro(_registroCnp);

    //DEPURACION
    connect(ui->cnp,SIGNAL(correccion(CorreccionRegistro)),this,SLOT(depurarWidgetRegistro(CorreccionRegistro)));
    setup();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::nuevoproyecto()
{
    NewProjectDialog dialogo;
    if(dialogo.exec())
    {

        ArchivoProyecto *aProyecto=dialogo.getArchivoProyecto();
        if(!_proyectoActual)
        {
            aProyecto->addSection(ui->widgetCoordinates->getSectionCoordinates());
        }
        else
        {

            QList <AProTPSection*> aproSecction=_proyectoActual->getListaSections();

            foreach(AProTPSection * seccion,aproSecction)
            {
                aProyecto->addSection(seccion);

            }
            delete _proyectoActual;
        }
        _proyectoActual=aProyecto;
        connect(_proyectoActual,SIGNAL(cambioActualizado(bool)),this,SLOT(cambiosEnProyecto(bool)));
        emit activarWidgetsRegistro(true);
    }
}

void MainWindow::setup()
{    
    QSettings settingsToolsPcot(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));
    QFileInfo rutaFileObj=settingsToolsPcot.value(QStringLiteral("pathConfigAmbito")).toString();

    _archivoAmbito=new AmbitJson(this,rutaFileObj);
    _objetoAlertFileJson=new AlertFileJson(this,_archivoAmbito);
    _objetoEditorAmbitoDialog=new EditorAmbitoDialog(this,_archivoAmbito);

    connect(_objetoAlertFileJson,SIGNAL(lanzarAsistenteJson()),_objetoEditorAmbitoDialog,SLOT(exec()));
    connect(_preferenciasAvanzadas,SIGNAL(signalEditAmbito()),_objetoEditorAmbitoDialog,SLOT(exec()));
    connect(_objetoEditorAmbitoDialog,SIGNAL(rejected()),_objetoAlertFileJson,SLOT(accept()));
    connect(_objetoEditorAmbitoDialog,SIGNAL(accepted()),_objetoAlertFileJson,SLOT(accept()));
    connect(_preferenciasAvanzadas,SIGNAL(accepted()),this,SLOT(setup()));

    if(!_archivoAmbito->exist()) {
        AmbitJson::createStandardTemplate(rutaFileObj);
        _objetoAlertFileJson->setModo(AlertFileJson::FaltaArchivo);
    }
    else _objetoAlertFileJson->setModo(AlertFileJson::ArchivoNoValido);

    _archivoAmbito->load();

    //Crear un evaluador de ambito json y poblarlo de test
    AmbJsonEvaluador *evaluaJson=new AmbJsonEvaluador(this,_archivoAmbito);

    evaluaJson->addTest(new AmbJsonNumTest(this));
    evaluaJson->addTest(new AmbJsonNombreTest(this,QStringLiteral("Francia Farmstar")));
    evaluaJson->addTest(new AmbJsonNombreTest(this,QStringLiteral("Catalunya lidar 2 metres")));
    evaluaJson->addTest(new AmbJsonNombreTest(this,QStringLiteral("Espanya 5 metres")));
    evaluaJson->addTest(new AmbJsonCatalunyaTest(this));
    evaluaJson->addTest(new AmbJsonEspanyaTest(this));
    evaluaJson->addTest(new AmbJsonFranciaTest(this));


    _archivoAmbito->setEvaluador(evaluaJson);

    while(!_archivoAmbito->isCorrect()) {
        if(_objetoAlertFileJson->exec()==QFileDialog::Rejected)
            exit(1);
    }

    //Crear dialogo de nuevo proyecto

    connect(ui->actionNuevo_proyecto,SIGNAL(triggered(bool)),this,SLOT(nuevoproyecto()));

    _proyectoActual=0;

    //Conectamos las señales de coordenadas
    connect(ui->actionAyuda_coordenadas,SIGNAL(triggered(bool)),ui->widgetCoordinates,SLOT(ayudaCoordenadas()));
    connect(ui->actionLimpiar_coordenadas,SIGNAL(triggered(bool)),ui->widgetCoordinates,SLOT(limpiarModeloCoordenadas()));
    connect(ui->actionSelect_coordenadas,SIGNAL(triggered(bool)),this,SLOT(selectFileCoor()));
    // Conectamos la señal de salida
    connect(ui->actionSalir,SIGNAL(triggered(bool)),this,SLOT(close()));
}

void MainWindow::selectFileCoor()
{
    QString path;
    path=QFileDialog::getOpenFileName(this,QString("select file coordinates"));
    if(path.isEmpty() || path.isNull())
    {
        return;
    }
    ui->widgetCoordinates->openArchivoCoordenadas(path);
}

void MainWindow::cargarAmbitos()
{
    QSettings settingsTPCot(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));

    QString rutaAmbito=settingsTPCot.value(QStringLiteral("pathConfigAmbito")).toString();
    if(!_archivoAmbito)
        _archivoAmbito=new AmbitJson(this,QFileInfo(rutaAmbito));
    else {
        if(_archivoAmbito->isLoaded())
            _archivoAmbito->save();
    }
    _archivoAmbito->setFileInfo(QFileInfo(rutaAmbito));

    if(!_archivoAmbito->exist())
        AmbitJson::createStandardTemplate(QFileInfo(rutaAmbito));

    _archivoAmbito->load();
    QList<Ambito*> listaAmbitos=_archivoAmbito->getAmbitos();

    foreach(Ambito *amb,listaAmbitos) {
        qDebug() << amb->nombre();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void MainWindow::abrirProyecto()
{
    QString archivoProyecto=QFileDialog::getOpenFileName(this,"select file project");
    if(archivoProyecto.isNull() || archivoProyecto.isEmpty())
    {
        return;
    }
    if (_proyectoActual)
    {
        _proyectoActual->read(archivoProyecto);
    }
    else
    {
        _proyectoActual=new ArchivoProyecto(this);
        _proyectoActual->addSection(ui->widgetCoordinates->getSectionCoordinates());
        connect(_proyectoActual,SIGNAL(cambioActualizado(bool)),this,SLOT(cambiosEnProyecto(bool)));
        _proyectoActual->read(archivoProyecto);
    }
    emit activarWidgetsRegistro(true);

    _registroCnp->setFolderOut(QString("HOLA QUE TAL!"));
}

void MainWindow::cambiosEnProyecto(bool estado)
{
    if(!estado)
    {
        this->setWindowTitle(_proyectoActual->getnameProyect()+tr("*")+tr(" - ToolsPcot"));
    }
    else
        this->setWindowTitle(_proyectoActual->getnameProyect()+tr(" - ToolsPcot"));
}

void MainWindow::guardarProyecto()
{
    if(_proyectoActual)
    {
        _proyectoActual->save();
    }
}

void MainWindow::depurarWidgetRegistro(CorreccionRegistro c)
{
    qDebug() << "ESTADO CNP: "<<c;
}
