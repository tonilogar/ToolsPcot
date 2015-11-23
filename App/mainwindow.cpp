#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _preferenciasAvanzadas=new PreferenciasAvanzadasDialog(this);
    connect(ui->actionOpciones_avanzadas,SIGNAL(triggered(bool)),_preferenciasAvanzadas,SLOT(reload()));
    setup();
    //comprobarSettings();//Leo la direccion donde se encuentra el fichero de preferencias del setting
    //compruebo que se pueda leer el fichero
    //Si no se puede leer aparece una ventada de alerta de la clase AlertFileJson
    //cargarAmbitos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup()
{    
    QSettings settingsToolsPcot(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));
    QFileInfo rutaFileObj=settingsToolsPcot.value(QStringLiteral("pathConfigAmbito")).toString();
    _archivoAmbito=new AmbitJson(this,rutaFileObj);
    _objetoAlertFileJson=new AlertFileJson(this,_archivoAmbito);
    _objetoEditorAmbitoDialog=new EditorAmbitoDialog(this,_archivoAmbito);
    connect(_objetoAlertFileJson,SIGNAL(lanzarAsistenteJson()),_objetoEditorAmbitoDialog,SLOT(exec()));
    connect(_preferenciasAvanzadas,SIGNAL(signalEditAmbito()),_objetoEditorAmbitoDialog,SLOT(showDataAmbito()));
    connect(_preferenciasAvanzadas,SIGNAL(signalEditAmbito()),_objetoEditorAmbitoDialog,SLOT(exec()));
    connect(_objetoEditorAmbitoDialog,SIGNAL(rejected()),_objetoAlertFileJson,SLOT(accept()));
    connect(_objetoEditorAmbitoDialog,SIGNAL(accepted()),_objetoAlertFileJson,SLOT(accept()));
    connect(_preferenciasAvanzadas,SIGNAL(accepted()),this,SLOT(setup()));

    if(!_archivoAmbito->exist()) {
        //AmbitJson::createStandardTemplate(rutaFileObj);
        _objetoAlertFileJson->setModo(AlertFileJson::FaltaArchivo);
    }
    else _objetoAlertFileJson->setModo(AlertFileJson::ArchivoNoValido);

    _archivoAmbito->load();
    while(!_archivoAmbito->isValid()) {
        if(_objetoAlertFileJson->exec()==QFileDialog::Rejected)
            exit(1);
    }
}

void MainWindow::comprobarSettings()
{
    qDebug() << "comprobando setting";

//    QSettings settingsToolsPcot(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));
//    QFileInfo rutaFileObj=settingsToolsPcot.value(QStringLiteral("pathConfigAmbito")).toString();
//    _archivoAmbito=new AmbitJson(this,rutaFileObj);
//    if(!_archivoAmbito->exist())
//    {
//        AmbitJson::createStandardTemplate(rutaFileObj);
//    }
//    _archivoAmbito->load();
//    if(!_archivoAmbito->isValid()) {
//        _objetoAlertFileJson=new AlertFileJson(this,_archivoAmbito);
//        if(_objetoAlertFileJson->exec()==QDialog::Rejected)
//            exit(0);
//    }
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
void MainWindow::pepe()
{
   qDebug() << "pepe";
}


