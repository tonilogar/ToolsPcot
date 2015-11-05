#include "preferenciasavanzadasdialog.h"
#include "ui_preferenciasavanzadasdialog.h"

PreferenciasAvanzadasDialog::PreferenciasAvanzadasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferenciasAvanzadasDialog)
{
    ui->setupUi(this);
    setup();
}

void PreferenciasAvanzadasDialog::setup()
{
    connect(ui->browseAmbitoButton,SIGNAL(clicked(bool)),this,SLOT(selectAmbitoFile()));
}

void PreferenciasAvanzadasDialog::reload()
{
    //Cargar el settings
    QSettings settingsPcot(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));

    ui->pathAmbitoLine->setText(settingsPcot.value(QStringLiteral("pathConfigAmbito")).toString());

    this->show();
}

void PreferenciasAvanzadasDialog::selectAmbitoFile()
{
    QString path=QFileDialog::getOpenFileName(this,tr("Seleccionar archivo de ámbito"),qApp->applicationDirPath());

    if(path.isEmpty() || path.isNull())
        return;

    QSettings settingsPcot(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));

    settingsPcot.setValue(QStringLiteral("pathConfigAmbito"),path);

    ui->pathAmbitoLine->setText(path);
}

PreferenciasAvanzadasDialog::~PreferenciasAvanzadasDialog()
{
    delete ui;
}
