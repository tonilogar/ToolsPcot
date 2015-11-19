#include "editorambitodialog.h"
#include "ui_editorambitodialog.h"

EditorAmbitoDialog::EditorAmbitoDialog(QWidget *parent, AmbitJson *archivoAmb) :
    QDialog(parent),
    ui(new Ui::EditorAmbitoDialog)
{
    ui->setupUi(this);
    _archivoAmbito=archivoAmb;
}

EditorAmbitoDialog::~EditorAmbitoDialog()
{
    delete ui;
}
