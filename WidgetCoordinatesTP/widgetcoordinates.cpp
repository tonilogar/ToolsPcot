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
}

WidgetCoordinates::~WidgetCoordinates()
{
    delete ui;
}
