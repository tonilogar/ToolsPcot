#include "editorambitodialog.h"
#include "ui_editorambitodialog.h"
#include <QDebug>
EditorAmbitoDialog::EditorAmbitoDialog(QWidget *parent, AmbitJson *archivoAmb) :
    QDialog(parent),
    ui(new Ui::EditorAmbitoDialog)
{
    ui->setupUi(this);
    _archivoAmbito=archivoAmb;

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
void EditorAmbitoDialog::showDialog()
{
    qDebug() <<"llega el signal";
}
