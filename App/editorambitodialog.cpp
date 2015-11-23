#include "editorambitodialog.h"
#include "ui_editorambitodialog.h"


EditorAmbitoDialog::EditorAmbitoDialog(QWidget *parent, AmbitJson *archivoAmb) :
    QDialog(parent),
    ui(new Ui::EditorAmbitoDialog)
{
    ui->setupUi(this);
    _archivoAm=archivoAmb;

    ui->comboBoxUtmCatalunya->addItem("No seleccionado",-1);
    ui->comboBoxUtmCatalunya->addItem("29",29);
    ui->comboBoxUtmCatalunya->addItem("30",30);
    ui->comboBoxUtmCatalunya->addItem("31",31);

    ui->comboBoxUtmEspanya->addItem("No seleccionado",-1);
    ui->comboBoxUtmEspanya->addItem("29",29);
    ui->comboBoxUtmEspanya->addItem("30",30);
    ui->comboBoxUtmEspanya->addItem("31",31);

    ui->comboBoxUtmFrancia->addItem("No seleccionado",-1);
    ui->comboBoxUtmFrancia->addItem("Fran�a Farmstar",-2);

}

EditorAmbitoDialog::~EditorAmbitoDialog()
{
    delete ui;
}
 void EditorAmbitoDialog::showDataAmbito()
 {
     _qlistAmbitos=_archivoAm->getAmbitos();
  foreach (Ambito* ambito, _qlistAmbitos)
  {
      ambito->toJson();
    if(ambito->nombre()=="Catalunya lidar 2 metres")
    {
        ui->lineEditNameCatalunya->setText(ambito->nombre());
        ui->lineEditImageRefCatalunya->setText(ambito->imageRef().absoluteFilePath());
        ui->doubleSpinBoxSizePixelCatalunya->setValue(ambito->tamPixel());
        ui->comboBoxUtmCatalunya->setCurrentIndex(3);
        _ejecutables=ambito->ejecutables();

//        if (_ejecutables.value())
//        {
//            ui->lineEditExtraction->setText("catalunyajjjj");
//        }
    }
    else if (ambito->nombre()=="Espanya 5 metres")
    {
        ui->lineEditNameEspanya->setText(ambito->nombre());
        ui->lineEditImageRefEspanya->setText(ambito->imageRef().absoluteFilePath());
        ui->doubleSpinBoxSizePixelEspanya->setValue(ambito->tamPixel());
        ui->comboBoxUtmEspanya->setCurrentIndex(2);

    }
    else
    {
        ui->lineEditNameFrancia->setText(ambito->nombre());
        ui->lineEditImageRefFrancia->setText(ambito->imageRef().absoluteFilePath());
        ui->doubleSpinBoxSizePixelFrancia->setValue(ambito->tamPixel());
        ui->comboBoxUtmFrancia->setCurrentIndex(1);

    }
     qDebug() << "otros";
  }
 }
