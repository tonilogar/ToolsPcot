#include "ambitowidget.h"
#include "ui_ambitowidget.h"

AmbitoWidget::AmbitoWidget(QWidget *parent, Ambito *amb) :
    QWidget(parent),
    ui(new Ui::AmbitoWidget)
{
    ui->setupUi(this);
    _ambito=amb;

    //Preparar los campos con datos iniciales
    ui->editName->setText(_ambito->nombre());

    //Establezco las conexiones pertinentes
    connect(ui->editName,SIGNAL(textChanged(QString)),_ambito,SLOT(setNombre(QString)));
}

AmbitoWidget::~AmbitoWidget()
{
    delete ui;
}
