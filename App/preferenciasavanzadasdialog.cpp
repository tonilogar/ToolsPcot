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
    connect(ui->editAmbitoButton,SIGNAL(clicked(bool)),this,SLOT(editPreferences()));
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
    QString path=QFileDialog::getOpenFileName(this,tr("Seleccionar archivo de ámbito"),qApp->applicationDirPath(),"Archivo (*.obj)");

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
void PreferenciasAvanzadasDialog::editPreferences()
{
_objetoDialogoPrefe=new DialogPre(0);
//_objetoDialogoPrefe->disableImageEsp(_objetoSettingPre->existPathImageEspSett());
//_objetoDialogoPrefe->disableExeImaOpe(_objetoSettingPre->existExeImaOpeoSett());
//_objetoDialogoPrefe->disableExeExtra(_objetoSettingPre->existExeExtraSett());
//_objetoDialogoPrefe->disableExeFootP(_objetoSettingPre->existExeFootPSett());
//_objetoDialogoPrefe->disableExeResi(_objetoSettingPre->existExeResiSett());
//_objetoDialogoPrefe->disableExeSub(_objetoSettingPre->existExeSubeSett());
//_objetoDialogoPrefe->disableImageCat(_objetoSettingPre->existPathImageCatSett());
//_objetoDialogoPrefe->disableImageFra(_objetoSettingPre->existPathImageFraSett());
_objetoDialogoPrefe->exec();
}
