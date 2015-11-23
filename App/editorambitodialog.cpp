#include "editorambitodialog.h"
#include "ui_editorambitodialog.h"


EditorAmbitoDialog::EditorAmbitoDialog(QWidget *parent, AmbitJson *archivoAmb) :
    QDialog(parent),
    ui(new Ui::EditorAmbitoDialog)
{
    ui->setupUi(this);
    _archivoAm=archivoAmb;

    ui->tabWidget->addTab(new QWidget(this),QStringLiteral("Nuevo widget!!!"));
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
