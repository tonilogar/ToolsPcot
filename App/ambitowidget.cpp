#include "ambitowidget.h"
#include "ui_ambitowidget.h"

AmbitoWidget::AmbitoWidget(QWidget *parent, Ambito *amb) :
    QWidget(parent),
    ui(new Ui::AmbitoWidget)
{
    ui->setupUi(this);
    _ambito=amb;


    //Preparar los campos con datos iniciales
    ui->utmComboBox->addItem("No seleccionado",-1);
    for (int i=0; i< 3; i++)
    ui->utmComboBox->addItem(QString::number(i+29),i+29);
    ui->utmComboBox->setCurrentIndex(_ambito->utm()-28);



    ui->editName->setText(_ambito->nombre());
    ui->lineReference->setText(_ambito->imageRef().absoluteFilePath());
    ui->doubleSpinBoxTam->setValue(_ambito->tamPixel());






    //Establezco las conexiones pertinentes
    connect(ui->editName,SIGNAL(textChanged(QString)),_ambito,SLOT(setNombre(QString)));
    connect(ui->lineReference,SIGNAL(textChanged(QString)),_ambito,SLOT(setImageRef(QFileInfo)));
    connect(ui->doubleSpinBoxTam,SIGNAL(valueChanged(double)),_ambito,SLOT(setTamPixel(double)));
    connect(ui->utmComboBox,SIGNAL(valueChanged(int)),_ambito,SLOT(setUtm(int)));
}

AmbitoWidget::~AmbitoWidget()
{
    delete ui;
}
