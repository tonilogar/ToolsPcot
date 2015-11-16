#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setup();

    comprobarSettings();
    cargarAmbitos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup()
{
    _preferenciasAvanzadas=new PreferenciasAvanzadasDialog(this);

    connect(ui->actionOpciones_avanzadas,SIGNAL(triggered(bool)),_preferenciasAvanzadas,SLOT(reload()));

    _archivoAmbito=0;
}

void MainWindow::comprobarSettings()
{
    QSettings settingsToolsPcot(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));

    if(!settingsToolsPcot.contains(QStringLiteral("pathConfigAmbito")))
    {
        settingsToolsPcot.setValue(QStringLiteral("pathConfigAmbito"),qApp->applicationDirPath()+"/ambitConfig.json");
    }
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
