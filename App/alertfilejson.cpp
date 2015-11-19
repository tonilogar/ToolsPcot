#include "alertfilejson.h"
#include "ui_alertfilejson.h"
AlertFileJson::AlertFileJson(QWidget *parent,AmbitJson *archivoAmbito) :
    QDialog(parent),
    ui(new Ui::AlertFileJson)
{
    ui->setupUi(this);

    _ambitoFile=archivoAmbito;
    _modoActual=FaltaArchivo;
    connect(ui->pushButtonSelectJson,SIGNAL(clicked()),this,SLOT(selectJson()));
    connect(ui->pushButtonCreateJson,SIGNAL(clicked()),this,SLOT(createJson()));
    connect(ui->pushButtonCancel,SIGNAL(clicked()),this,SLOT(cancel()));
}

void AlertFileJson::setModo(ModoAlerta m)
{
    _modoActual=m;
    switch(_modoActual) {
    case FaltaArchivo:
        ui->labelMensaje->setText(QStringLiteral("<html><head/><body><p><span style=\" color:#000000;\">¡No puedo encontrar el archivo de preferencias!</span></p><p><span style=\" color:#000000;\">Sin el archivo, no puedo trabajar. ¿Me ayudas?</span></p></body></html>"));
        break;
    case ArchivoNoValido:
        ui->labelMensaje->setText(QStringLiteral("<html><head/><body><p><span style=\" color:#000000;\">¡No entiendo el archivo de preferencias! Debe de estar mal</span></p><p><span style=\" color:#000000;\">Sin el archivo, no puedo trabajar. ¿Me ayudas?</span></p></body></html>"));
        break;
    default:
        break;
    }
}

AlertFileJson::~AlertFileJson()
{
    delete ui;
}

void AlertFileJson::selectJson()
{
    QString path=QFileDialog::getOpenFileName(this,"Seleccionar archivo de preferencias",
                                              qApp->applicationDirPath(),"Preferencias JSON (*.json)");
    if(path.isNull() || path.isEmpty())
        return;
    QFileInfo info(path);
    _ambitoFile->setFileInfo(path);
    _ambitoFile->load();
    bool state=_ambitoFile->isValid();
    if(_ambitoFile->exist() && _ambitoFile->isValid())
        this->accept();
    if(!_ambitoFile->exist())
        setModo(FaltaArchivo);
    if(!_ambitoFile->isValid())
        setModo(ArchivoNoValido);
    QList<Ambito*> ambitos=_ambitoFile->getAmbitos();
    foreach(Ambito *amb,ambitos) {
        if(!amb->isValid())
            qDebug() << "Ambito no valido: " <<amb->nombre();
    }
}

void AlertFileJson::createJson()
{
    emit lanzarAsistenteJson();
}

void AlertFileJson::cancel()
{
 this->close();
}
