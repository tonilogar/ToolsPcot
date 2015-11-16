#include "dialogpre.h"
#include "ui_dialogpre.h"

DialogPre::DialogPre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPre)
{

    ui->setupUi(this);
    _openDirImage=qApp->applicationDirPath();
    _openDirExe="//nas03/geoproces/DFApplications";
    _objetoAmbito=new Ambito(this);
    connect(ui->pushButtonCatalunya,SIGNAL(clicked()),this,SLOT(selectMetCat()));
    connect(ui->pushButtonExtractionCatalunya,SIGNAL(clicked()),this,SLOT(selectExeExtra()));
    connect(ui->pushButtonResizeCatalunya,SIGNAL(clicked()),this,SLOT(selectExeResi()));
    connect(ui->pushButtonFootPrintMaskCatalunya,SIGNAL(clicked()),this,SLOT(selectExeFootP()));
    connect(ui->pushButtonSubesceneCatalunya,SIGNAL(clicked()),this,SLOT(selectExeSub()));
    connect(ui->pushButtonGeoTransformationCatalunya,SIGNAL(clicked()),this,SLOT(selectExeImaOpe()));

    connect(ui->pushButtonEspanya,SIGNAL(clicked()),this,SLOT(selectMetEsp()));
    connect(ui->pushButtonFootPrintMaskEspanya,SIGNAL(clicked()),this,SLOT(selectExeFootP()));
    connect(ui->pushButtonResizeEspanya,SIGNAL(clicked()),this,SLOT(selectExeResi()));
    connect(ui->pushButtonSubesceneEspanya,SIGNAL(clicked()),this,SLOT(selectExeSub()));
    connect(ui->pushButtonGeoTransformationEspanya,SIGNAL(clicked()),this,SLOT(selectExeImaOpe()));

    connect(ui->pushButtonFrancia,SIGNAL(clicked()),this,SLOT(selectMetFra()));
    connect(ui->pushButtonFootPrintMaskFrancia,SIGNAL(clicked()),this,SLOT(selectExeFootP()));
    connect(ui->pushButtonResizeFrancia,SIGNAL(clicked()),this,SLOT(selectExeResi()));
    connect(ui->pushButtonSubesceneFrancia,SIGNAL(clicked()),this,SLOT(selectExeSub()));
    connect(ui->pushButtonResizeFrancia_2,SIGNAL(clicked()),this,SLOT(selectExeResi()));
    connect(ui->pushButtonOk,SIGNAL(clicked()),this,SLOT(selectOk()));
    connect(ui->pushButtonCancel,SIGNAL(clicked()),this,SLOT(selectCancel()));
    check=false;
}

DialogPre::~DialogPre()
{
    delete ui;
}

void DialogPre::selectMetCat()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona archivo met de Cataluña",
                                              _openDirImage,"Archivo (*.rf)");
    if(path.isNull() || path.isEmpty())
    {
        check=false;
        return;
    }
    ui->lineEditCatlunya->setText(path);
    _openDirImage=path;
}
void DialogPre::selectMetEsp()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona archivo met de España",
                                              _openDirImage,"Archivo (*.rf)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditEspanya->setText(path);
    _openDirImage=path;
}
void DialogPre::selectMetFra()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona archivo met de Francia",
                                              _openDirImage,"Archivo (*.rf)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditFrancia->setText(path);
    _openDirImage=path;
}
void DialogPre::selectExeSub()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageSubescenes.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditSubesceneCatalunya->setText(path);
    _openDirExe=path;
}
void DialogPre::selectExeImaOpe()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageGeoTransformation.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditGeoTransformationCatalunya->setText(path);
    _openDirExe=path;
}
void DialogPre::selectExeFootP()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageFootPrintMask.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditFootPrintMaskCatalunya->setText(path);
    _openDirExe=path;
}
void DialogPre::selectExeExtra()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCADBDTMEXTRACTIONCONSOLEVERSION.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditExtractionCatalunya->setText(path);
    _openDirExe=path;
}
void DialogPre::selectExeResi()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageresize.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditResizeCatalunya->setText(path);
    _openDirExe=path;
}
void DialogPre::EditFileJson()
{
    //_objetoAmbito->setImageRef(QFileInfo(ui->lineEditCatlunya->text()));
    //_objetoAmbito->setImageRef((QFileInfo(ui->lineEditEspanya->text()));
    //_objetoAmbito->setPathImageFraSett((QFileInfo(ui->lineEditFrancia->text()));
    //_objetoAmbito->setExeExtraSett(ui->lineEditExtraction->text());
    //_objetoAmbito->setExeFootPSett(ui->lineEditFootPrintMask->text());
    //_objetoAmbito->setExeImaOpeoSett(ui->lineEditGeoTransformation->text());
    //_objetoAmbito->setExeResiSett(ui->lineEditResize->text());
    //_objetoAmbito->setExeSubeSett(ui->lineEditSubescene->text());
    QDialog::accept();
}

//CATALUNYA
void DialogPre::disableImageCat(bool disaOrEna)
{
    ui->pushButtonCatalunya->setDisabled(disaOrEna);
    ui->labelCatalunya->setDisabled(disaOrEna);
    ui->lineEditCatlunya->setDisabled(disaOrEna);
}
void DialogPre::disableExeExtraCat(bool disaOrEna)
{
    ui->pushButtonExtractionCatalunya->setDisabled(disaOrEna);
    ui->labelExtractionCatalunya->setDisabled(disaOrEna);
    ui->lineEditExtractionCatalunya->setDisabled(disaOrEna);
}
void DialogPre::disableExeResiCat(bool disaOrEna)
{
    ui->pushButtonResizeCatalunya->setDisabled(disaOrEna);
    ui->labelResizeCatalunya->setDisabled(disaOrEna);
    ui->lineEditResizeCatalunya->setDisabled(disaOrEna);
}
void DialogPre::disableExeFootPCat(bool disaOrEna)
{
    ui->pushButtonFootPrintMaskCatalunya->setDisabled(disaOrEna);
    ui->labelFootPrintMaskCatalunya->setDisabled(disaOrEna);
    ui->lineEditFootPrintMaskCatalunya->setDisabled(disaOrEna);
}
void DialogPre::disableExeSubCat(bool disaOrEna)
{
    ui->pushButtonSubesceneCatalunya->setDisabled(disaOrEna);
    ui->labelSubesceneCatalunya->setDisabled(disaOrEna);
    ui->lineEditSubesceneCatalunya->setDisabled(disaOrEna);
}
void DialogPre::disableExeImaOpeCat(bool disaOrEna)
{
    ui->pushButtonGeoTransformationCatalunya->setDisabled(disaOrEna);
    ui->labelGeoTransformationCatalunya->setDisabled(disaOrEna);
    ui->lineEditGeoTransformationCatalunya->setDisabled(disaOrEna);
}

//ESPANYA
void DialogPre::disableImageEsp(bool disaOrEna)
{
    ui->pushButtonEspanya->setDisabled(disaOrEna);
    ui->labelEspanya->setDisabled(disaOrEna);
    ui->lineEditEspanya->setDisabled(disaOrEna);
}
void DialogPre::disableExeFootPEsp(bool disaOrEna)
{
    ui->pushButtonFootPrintMaskEspanya->setDisabled(disaOrEna);
    ui->labelFootPrintMaskEspanya->setDisabled(disaOrEna);
    ui->lineEditFootPrintMaskEspanya->setDisabled(disaOrEna);
}
void DialogPre::disableExeResiEsp(bool disaOrEna)
{
    ui->pushButtonResizeEspanya->setDisabled(disaOrEna);
    ui->labelResizeEspanya->setDisabled(disaOrEna);
    ui->lineEditResizeEspanya->setDisabled(disaOrEna);
}
void DialogPre::disableExeSubEsp(bool disaOrEna)
{
    ui->pushButtonSubesceneEspanya->setDisabled(disaOrEna);
    ui->labelSubesceneEspanya->setDisabled(disaOrEna);
    ui->lineEditSubesceneEspanya->setDisabled(disaOrEna);
}
void DialogPre::disableExeImaOpeEsp(bool disaOrEna)
{
    ui->pushButtonGeoTransformationEspanya->setDisabled(disaOrEna);
    ui->labelGeoTransformationEspanya->setDisabled(disaOrEna);
    ui->lineEditGeoTransformationEspanya->setDisabled(disaOrEna);
}

//FRANCIA
void DialogPre::disableImageFra(bool disaOrEna)
{
    ui->pushButtonFrancia->setDisabled(disaOrEna);
    ui->labelFrancia->setDisabled(disaOrEna);
    ui->lineEditFrancia->setDisabled(disaOrEna);
}
void DialogPre::disableExeFootPFra(bool disaOrEna)
{
    ui->pushButtonFootPrintMaskFrancia->setDisabled(disaOrEna);
    ui->labelFootPrintMaskFrancia->setDisabled(disaOrEna);
    ui->lineEditFootPrintMaskFrancia->setDisabled(disaOrEna);
}
void DialogPre::disableExeResiFra(bool disaOrEna)
{
    ui->pushButtonResizeFrancia->setDisabled(disaOrEna);
    ui->labelResizeFrancia->setDisabled(disaOrEna);
    ui->lineEditResizeFrancia->setDisabled(disaOrEna);
}
void DialogPre::disableExeSubFra(bool disaOrEna)
{
    ui->pushButtonSubesceneFrancia->setDisabled(disaOrEna);
    ui->labelSubesceneFrancia->setDisabled(disaOrEna);
    ui->lineEditSubesceneFrancia->setDisabled(disaOrEna);
}
void DialogPre::disableExeResiFra01(bool disaOrEna)
{
    ui->pushButtonResizeFrancia_2->setDisabled(disaOrEna);
    ui->labelResizeFrancia_2->setDisabled(disaOrEna);
    ui->lineEditResizeFrancia_2->setDisabled(disaOrEna);
}
void DialogPre::selectOk()
{
 if (!check)
 {

 }

}

void DialogPre::selectCancel()
{
this->close();
}

