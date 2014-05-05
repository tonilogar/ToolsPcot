//    ToolsPcot
//    Copyright (C) {2014}  {Antonio López García}
//    tologar@gmail.com

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "createorto.h"
#include "ui_createorto.h"
#include <QLineEdit>
#include <QFileDialog>
#include <QDebug>

CreateOrto::CreateOrto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOrto)
{
    ui->setupUi(this);
    punteroRegistroCreateOrto=new RegistroCreateOrto(this);

    //Cargamos desde settings
    QSettings settings("tologar","ToolsPCOT",this);
    QString pathOrto=settings.value("variablesORTO").toString();

    FicheroDatosAmbitoPro lectorModelos(this,pathOrto);
    if (lectorModelos.fileExist())
    {
        ui->comboBoxAmbitoProyectoOrto->setModel(lectorModelos.obtenerModelo());
    }
    else
    {
        qDebug() <<  "No existe el archivo";
        QMessageBox::StandardButton botonPulsado=QMessageBox::question(0,"Dades Ambit projecte orto", "El fitxer de variables orto no es troba,\nVols crear un fitxer per defecte");
        if(botonPulsado==QMessageBox::Yes)
        {
            //Crear un archivo Json por defecto
            lectorModelos.CreateJsonOrtoDefecto();
            //Paso la dirección por de fecto al valor de path de settings
            QSettings settings("tologar","ToolsPCOT",this);
            QString pathDefectoFileJson=qApp->applicationDirPath()+"/variablespcotMet.txt";
            FicheroDatosAmbitoPro lectorOuts(this,pathDefectoFileJson);
            settings.setValue("variablesORTO",pathDefectoFileJson);
            ui->comboBoxAmbitoProyectoOrto->setModel(lectorOuts.obtenerModelo());
        }
    }

    ui->comboBoxTamanoPixelOrto->addItem("No seleccionado",-1);
    for (int i=1; i< 1001; i++){
        ui->comboBoxTamanoPixelOrto->addItem(QString::number(i),i);
    }

    ui->comboBoxUtmOrto->addItem("No seleccionado",-1);
    ui->comboBoxUtmOrto->addItem("29",29);
    ui->comboBoxUtmOrto->addItem("30",30);
    ui->comboBoxUtmOrto->addItem("31",31);
    ui->comboBoxUtmOrto->addItem("França Farmstar",-2);

    ui->comboBoxAnchoPasadaOrto->addItem("No seleccionado",-1);
    for (int i=1; i< 20100; i++)
        ui->comboBoxAnchoPasadaOrto->addItem(QString::number(i)+" Mts",i);

    ui->comboBoxOffsetPasadaOrto->addItem("No seleccionado",-1);
    for (int i=10; i< 1010; i+=10)
        ui->comboBoxOffsetPasadaOrto->addItem(QString::number(i)+" Mts",i);

    connect(ui->comboBoxAmbitoProyectoOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(onCambioComboBoxAmbitoProyectoOrto(int)));
    connect(ui->comboBoxTamanoPixelOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(calcularOffsetPasada(int)));
    connect(ui->checkBoxExtraerOrto,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableExtraerOrto(int)));
    connect(ui->checkBoxFootPrintMaskOrto,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableFootPrintMaskOrto(int)));


    //nuevo  codigo
    connect(ui->checkBoxExtraerOrto,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxAmbitoProyectoOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxTamanoPixelOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxUtmOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->lineEditFolderOutOrto,SIGNAL(textChanged(QString)),this,SLOT(cambioestadoLineEdit(QString)));

    connect(ui->checkBoxFootPrintMaskOrto,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxAnchoPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxOffsetPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));

    //Connectar el estado de los widgets a sus slots correspondientes para cambiar el valor
    connect(ui->lineEditFolderOutOrto,SIGNAL(textChanged(QString)),punteroRegistroCreateOrto,SLOT(setFolderOut(QString)));
    connect(ui->comboBoxAmbitoProyectoOrto,SIGNAL(currentIndexChanged(QString)),punteroRegistroCreateOrto,SLOT(setAmbitoProyecto(QString)));
    connect(ui->comboBoxTamanoPixelOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarTamanyPixel(int)));
    connect(ui->comboBoxUtmOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarUtm(int)));
    connect(ui->comboBoxAnchoPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarAnchoPasada(int)));
    connect(ui->comboBoxOffsetPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarOffsetPasada(int)));

    //Conectar los check con los metodos de registroCreateMet para comprobar el estado de selecionado o no seleccionado
    connect(ui->checkBoxFootPrintMaskOrto,SIGNAL(stateChanged(int)),punteroRegistroCreateOrto,SLOT(setFootprintMask(int)));
}

CreateOrto::~CreateOrto()
{
    delete ui;
}
RegistroCreateOrto * CreateOrto::getObjetoRegistroCreateOrto()
{
    return punteroRegistroCreateOrto;
}
void CreateOrto::on_pushButtonFolderOutOrto_clicked()
{
    folderOut=QString();
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    folderOut=QFileDialog::getExistingDirectory
            (0,("Triar carpeta sortida"),(pbSelectFolder));
    qDebug() << folderOut << "DirectorioOrto1";
    if(!folderOut.isNull() && !folderOut.isEmpty())
    {
        ui->lineEditFolderOutOrto->setText(folderOut);
    }
}
void CreateOrto::enableOrDisableExtraerOrto(int chec)
{
    if (chec==0)
    {
        ui->checkBoxFootPrintMaskOrto->setDisabled(1);
        ui->checkBoxFootPrintMaskOrto->setChecked(0);
        ui->comboBoxAmbitoProyectoOrto->setDisabled(1);
        ui->comboBoxTamanoPixelOrto->setDisabled(1);
        ui->comboBoxUtmOrto->setDisabled(1);
        ui->lineEditFolderOutOrto->setDisabled(1);
        ui->pushButtonFolderOutOrto->setDisabled(1);
        ui->labelAmbitoProyectoOrto->setDisabled(1);
        ui->labelUtmOrto->setDisabled(1);
        ui->labelTamanoPixelOrto->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->checkBoxFootPrintMaskOrto->setEnabled(1);
        ui->comboBoxAmbitoProyectoOrto->setEnabled(1);
        ui->comboBoxTamanoPixelOrto->setEnabled(1);
        ui->comboBoxUtmOrto->setEnabled(1);
        ui->lineEditFolderOutOrto->setEnabled(1);
        ui->pushButtonFolderOutOrto->setEnabled(1);
        ui->labelAmbitoProyectoOrto->setEnabled(1);
        ui->labelUtmOrto->setEnabled(1);
        ui->labelTamanoPixelOrto->setEnabled(1);
        qDebug()<< "seleccionado";
    }
    qDebug()<< chec <<"chec";
}

void CreateOrto::activateWidget(bool acti)
{
    qDebug() << acti << "actiOrto";
    if (acti==true)
    {
        ui->checkBoxExtraerOrto->setEnabled(true);
        ui->pushButtonDeleteDatesOrto->setEnabled(true);
    }
    else
    {
        ui->checkBoxExtraerOrto->setEnabled(false);
        ui->checkBoxExtraerOrto->setChecked(false);
        ui->pushButtonDeleteDatesOrto->setEnabled(false);
    }
}
void CreateOrto::setPunterotVCoordenadas(TableViewCoordinates *p)
{
    tVCoordenadas=p;
}
void CreateOrto::calcularOffsetPasada(int offsetPasada)
{
    qDebug() << offsetPasada << "ofsetPasada";

    ui->comboBoxAnchoPasadaOrto->setCurrentIndex((offsetPasada*800)/2);
}
void CreateOrto::enableOrDisableFootPrintMaskOrto(int chec)
{
    if (chec==0)
    {
        ui->comboBoxAnchoPasadaOrto->setDisabled(1);
        ui->comboBoxOffsetPasadaOrto->setDisabled(1);
        ui->labelAnchoPasadaOrto->setDisabled(1);
        ui->labelOffsetPasadaOrto->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->comboBoxAnchoPasadaOrto->setDisabled(0);
        ui->comboBoxOffsetPasadaOrto->setDisabled(0);
        ui->labelAnchoPasadaOrto->setDisabled(0);
        ui->labelOffsetPasadaOrto->setDisabled(0);
        qDebug()<< "seleccionado";
    }
    qDebug()<< chec <<"chec";
}
void CreateOrto::onCambioComboBoxAmbitoProyectoOrto(int text)
{
    int utm;
    int tPixel;
    utm=ui->comboBoxAmbitoProyectoOrto->itemData(text,Qt::UserRole+3).toInt();
    tPixel=ui->comboBoxAmbitoProyectoOrto->itemData(text,Qt::UserRole+2).toInt();
    if (tPixel!=-1)
    {
        for(int i=0;i<ui->comboBoxTamanoPixelOrto->count();i++)
        {
            if (ui->comboBoxTamanoPixelOrto->itemData(i).toInt()==tPixel)
            {
                ui->comboBoxTamanoPixelOrto->setCurrentIndex(i);
            }
        }
    }

    if (utm!=-1)
    {
        for(int i=0;i<ui->comboBoxUtmOrto->count();i++)
        {
            if (ui->comboBoxUtmOrto->itemData(i).toInt()==utm)
            {
                ui->comboBoxUtmOrto->setCurrentIndex(i);
            }
        }
    }
    int valorAP = ui->comboBoxAmbitoProyectoOrto->currentIndex();
    QString path = ui->comboBoxAmbitoProyectoOrto->itemData(valorAP,Qt::UserRole+1).toString();
    qDebug()<< valorAP <<"valorAP";
    qDebug()<< path <<"path";
    punteroRegistroCreateOrto->setPathImageOrto(path);
    QString pexe=ui->comboBoxAmbitoProyectoOrto->itemData(text,Qt::UserRole+4).toString();
    punteroRegistroCreateOrto->setExeSubScene(pexe);

    QString pepe=punteroRegistroCreateOrto->getPathImageOrto();
    //QString pepe=punteroRegistroCreateOrto->getPathImageOrto();
    //qDebug()<< pepe <<"pepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepe";
}

void CreateOrto::on_pushButtonDeleteDatesOrto_clicked()
{
    ui->lineEditFolderOutOrto->clear();
    ui->comboBoxAmbitoProyectoOrto->setCurrentIndex(0);
    ui->comboBoxAnchoPasadaOrto->setCurrentIndex(0);
    ui->comboBoxOffsetPasadaOrto->setCurrentIndex(0);
    ui->comboBoxTamanoPixelOrto->setCurrentIndex(0);
    ui->comboBoxUtmOrto->setCurrentIndex(0);
}

//Codigo nuevo////////////

void CreateOrto::evaluarEstadoWidgetOrto()
{
    qDebug()<< "evaluando estado widget orto";
    //Si checkBoxExtraerOrto esta deseleccionado icono 0
    if(!ui->checkBoxExtraerOrto->isChecked())
    {
        emit cambioEstadoCorreccionOrto(0);
        return;
    }
    //Si checkBoxExtraerOrto y footprintMask esta seleccionado
    if(ui->checkBoxFootPrintMaskOrto->isChecked())
    {
        //si falta algún dato de  checkBoxExtraerOrto o footPrintMask icono 2 alerta
        if(ui->lineEditFolderOutOrto->text().isEmpty() || ui->lineEditFolderOutOrto->text().isNull() || ui->comboBoxAmbitoProyectoOrto->currentIndex()==0
                || ui->comboBoxAnchoPasadaOrto->currentIndex()==0 || ui->comboBoxOffsetPasadaOrto->currentIndex()==0
                ||ui->comboBoxTamanoPixelOrto->currentIndex()==0
                || ui->comboBoxUtmOrto->currentIndex()==0)
        {
            emit cambioEstadoCorreccionOrto(2);
            return;
        }
        //Si todos los datos son correctos icono 1 Ok
        else
            emit cambioEstadoCorreccionOrto(1);
        return;
    }
    else
    {
        if(ui->lineEditFolderOutOrto->text().isEmpty() || ui->lineEditFolderOutOrto->text().isNull() || ui->comboBoxAmbitoProyectoOrto->currentIndex()==0
                ||ui->comboBoxTamanoPixelOrto->currentIndex()==0
                || ui->comboBoxUtmOrto->currentIndex()==0)
        {
            emit cambioEstadoCorreccionOrto(2);
            return;
        }
        else
            emit cambioEstadoCorreccionOrto(1);
        return;
    }
    return;
}

void CreateOrto::cambioestadoCheckBox(int estado)
{
    evaluarEstadoWidgetOrto();
}
void CreateOrto::cambioestadoComboBox(int estado)
{
    evaluarEstadoWidgetOrto();
}

void CreateOrto::cambioestadoLineEdit(QString directorio)
{
    evaluarEstadoWidgetOrto();
}

void CreateOrto::VigilarTamanyPixel(int tamanyoPixel)
{
    int tPixel;
    tPixel=ui->comboBoxTamanoPixelOrto->itemData(tamanyoPixel).toInt();
    punteroRegistroCreateOrto->setTamanyPixel(tPixel);
}
void CreateOrto::VigilarUtm(int utm)
{
    int utmOrto;
    utmOrto=ui->comboBoxUtmOrto->itemData(utm).toInt();
    punteroRegistroCreateOrto->setUtm(utmOrto);
}
void CreateOrto::VigilarAnchoPasada(int anchoPasada)
{
    int aPassada;
    aPassada=ui->comboBoxAnchoPasadaOrto->itemData(anchoPasada).toInt();
    punteroRegistroCreateOrto->setAnchoPasada(aPassada);
}
void CreateOrto::VigilarOffsetPasada(int offsetPasada)
{
    int oPassada;
    oPassada=ui->comboBoxTamanoPixelOrto->itemData(offsetPasada).toInt();
    punteroRegistroCreateOrto->setOffsetPasada(oPassada);
}
void CreateOrto::recargarModelosAmbito()
{
    QSettings settings("tologar","ToolsPCOT",this);
    QString pathOrto=settings.value("variablesORTO").toString();
    FicheroDatosAmbitoPro lectorRecargarModelos(this,pathOrto);
    ui->comboBoxAmbitoProyectoOrto->setModel(lectorRecargarModelos.obtenerModelo());
}
