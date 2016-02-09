#include "widgetcoordinates.h"
#include "ui_widgetcoordinates.h"

WidgetCoordinates::WidgetCoordinates(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetCoordinates)
{
    ui->setupUi(this);
    _modeloCoordenadas=new ModeloCoordenadas(this);
    _sectionCoordenadas=new SectionCoordinates(this);

    _sectionCoordenadas->setModeloCoordenadas(_modeloCoordenadas);

    ui->tableView->setModel(_modeloCoordenadas);

    connect(_modeloCoordenadas,SIGNAL(loadedModelo(bool)),this,SIGNAL(loadedModelo(bool)));
}

WidgetCoordinates::~WidgetCoordinates()
{
    delete ui;
}

void WidgetCoordinates::openArchivoCoordenadas(QString archivo)
{
    ReaderCoordinatesBasico readCoor;
    if(readCoor.canRead(archivo))
    {
        if(readCoor.tryRead(archivo))
            _modeloCoordenadas->setListaRegistro(readCoor.getListCoordinates());
        else
            QMessageBox::warning(this, "File coordinates - error",readCoor.lastError());
    }
    else
        QMessageBox::warning(this, "File coordinates - error","el fitxer de coordenades no es un format valid");
}

void WidgetCoordinates::limpiarModeloCoordenadas()
{
    _modeloCoordenadas->clear();
}

void WidgetCoordinates::ayudaCoordenadas()
{
    DialogHelpFilecoordinates helpCoordinates;
    helpCoordinates.exec();
}
