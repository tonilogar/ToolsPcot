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







