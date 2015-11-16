#include "alertfilejson.h"
#include "ui_alertfilejson.h"
AlertFileJson::AlertFileJson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlertFileJson)
{
    ui->setupUi(this);

    connect(ui->pushButtonSelectJson,SIGNAL(clicked()),this,SLOT(selectJson()));
    connect(ui->pushButtonCreateJson,SIGNAL(clicked()),this,SLOT(createJson()));
    connect(ui->pushButtonCancel,SIGNAL(clicked()),this,SLOT(cancel()));
}

AlertFileJson::~AlertFileJson()
{
    delete ui;
}
void AlertFileJson::selectJson()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona archivo met de Francia",
                                              qApp->applicationDirPath(),"Archivo (*.obj)");
    if(path.isNull() || path.isEmpty())return;
    QSettings settingsPcotPathObj(QStringLiteral("tonilogar"),QStringLiteral("ToolsPCot"));
    settingsPcotPathObj.setValue(QStringLiteral("pathConfigAmbito"),path);
    this->close();
}
void AlertFileJson::createJson()
{
  _objetoDialogoPr=new DialogPre(0);
  _objetoDialogoPr->exec();
  this->close();
}

void AlertFileJson::cancel()
{
 this->close();

}
