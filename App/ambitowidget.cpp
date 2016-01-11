#include "ambitowidget.h"
#include "ui_ambitowidget.h"

AmbitoWidget::AmbitoWidget(QWidget *parent, Ambito *amb) :
    QWidget(parent),
    ui(new Ui::AmbitoWidget)
{
    ui->setupUi(this);
    _ambito=amb;
    _evaluador=new AmbEvaluador(this);

    AmbEvRangoUtmTest *testUtm=new AmbEvRangoUtmTest(this);
    _evaluador->addTest(testUtm);

    //conectar mensajes de test
    connect(testUtm,SIGNAL(testResult(bool)),this,SLOT(depuracionSalidaEvaluador(bool)));


    //Preparar los campos con datos iniciales
    ui->utmComboBox->addItem("No seleccionado",-1);
    for (int i=0; i< 3; i++)
        ui->utmComboBox->addItem(QString::number(i+29),i+29);
    if(_ambito->utm()==-1)
        ui->utmComboBox->setCurrentIndex(0);
    else
        ui->utmComboBox->setCurrentIndex(_ambito->utm()-28);

    ui->editName->setText(_ambito->nombre());
    ui->lineReference->setText(_ambito->imageRef().absoluteFilePath());
    ui->doubleSpinBoxTam->setValue(_ambito->tamPixel());

    //Establezco las conexiones pertinentes
    connect(ui->editName,SIGNAL(textChanged(QString)),_ambito,SLOT(setNombre(QString)));
    connect(ui->lineReference,SIGNAL(textChanged(QString)),_ambito,SLOT(setImageRef(QFileInfo)));
    connect(ui->doubleSpinBoxTam,SIGNAL(valueChanged(double)),_ambito,SLOT(setTamPixel(double)));
    connect(ui->utmComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioUtm(int)));

    _evaluador->check(_ambito);
}

AmbitoWidget::~AmbitoWidget()
{
    delete ui;
}

void AmbitoWidget::depuracionSalidaEvaluador(bool data)
{
    if(!data)
        qDebug() << "TEST UTM PASADO";
    else qDebug() << "TEST UTM NO HA PASADO";
}

void AmbitoWidget::cambioUtm(int index)
{
    _ambito->setUtm(ui->utmComboBox->itemData(index).toInt());
}
