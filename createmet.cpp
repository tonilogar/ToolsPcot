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
#include "createmet.h"
#include "ui_createmet.h"
#include <QLineEdit>
#include <QFileDialog>
#include <QDebug>

CreateMet::CreateMet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMet)
{
    ui->setupUi(this);

    punteroRegistroCreateMet=new RegistroCreateMet(this);

    //Cargamos desde settings
    QSettings settings("tologar","ToolsPCOT",this);
    QString pathMet=settings.value("variablesMET").toString();

    FicheroDatosAmbitoPro lectorModelos(this,pathMet);
    if (lectorModelos.fileExist())
    {
        ui->comboBoxAmbitoProyectoMet->setModel(lectorModelos.obtenerModelo());
    }
    else
    {
        qDebug() <<  "No existe el archivo";
        QMessageBox::StandardButton botonPulsado=QMessageBox::question(0,"Dades Ambit projecte met", "El fitxer de variables met no es troba,\nVols crear un fitxer per defecte");
        if(botonPulsado==QMessageBox::Yes)
        {
            //Crear un archivo Json por defecto
            lectorModelos.CreateJsonMetDefecto();
            //Paso la dirección por de fecto al valor de path de settings
            QSettings settings("tologar","ToolsPCOT",this);
            QString pathDefectoFileJson=qApp->applicationDirPath()+"/variablespcotMet.txt";
            FicheroDatosAmbitoPro lectorOuts(this,pathDefectoFileJson);
            settings.setValue("variablesMET",pathDefectoFileJson);
            ui->comboBoxAmbitoProyectoMet->setModel(lectorOuts.obtenerModelo());

        }
    }

    ui->comboBoxTamanoPixelMet->addItem("No seleccionado",-1);
    for (double i=0.00; i< 101; i+=0.10){
        ui->comboBoxTamanoPixelMet->addItem(QString::number(i),i);
    }



    ui->comboBoxCoordinateSystemMet->addItem("No seleccionado",3);
    ui->comboBoxCoordinateSystemMet->addItem("Etrs89",0);
    ui->comboBoxCoordinateSystemMet->addItem("Ed50",1);
    ui->comboBoxCoordinateSystemMet->addItem("Ntf",2);



    ui->comboBoxTamanyoCortarMet->addItem("No seleccionado",-1);
    for (int i=100; i< 1000; i+=10)
        ui->comboBoxTamanyoCortarMet->addItem(QString::number(i)+" MB",i);

    ui->comboBoxNumeroCanalesspasadaMet->addItem("No seleccionado",-1);
    for (int i=1; i< 601; i++)
        ui->comboBoxNumeroCanalesspasadaMet->addItem(QString::number(i),i);

    ui->comboBoxAnchoPasadaMet->addItem("No seleccionado",-1);
    for (int i=1; i< 20100; i++)
        ui->comboBoxAnchoPasadaMet->addItem(QString::number(i)+" Mts",i);

    ui->comboBoxOffsetPasadaMet->addItem("No seleccionado",-1);
    for (int i=10; i< 3010; i+=10)
        ui->comboBoxOffsetPasadaMet->addItem(QString::number(i)+" Mts",i);

    connect(ui->comboBoxAmbitoProyectoMet,SIGNAL(currentIndexChanged(int)),this,SLOT(onCambioComboBoxAmbitoProyectoMet(int)));
    connect(ui->comboBoxTamanoPixelMet,SIGNAL(currentIndexChanged(int)),this,SLOT(calcularOffsetPasada(int)));
    connect(ui->checkBoxExtraerMet,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableExtraerMet(int)));
    connect(ui->checkBoxCortarMet,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableCortarMet(int)));
    connect(ui->checkBoxFootPrintMaskMet,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableFootPrintMaskMet(int)));

    //nuevo  codigo
    connect(ui->checkBoxExtraerMet,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxAmbitoProyectoMet,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxTamanoPixelMet,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxCoordinateSystemMet,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->lineEditFolderOutMet,SIGNAL(textChanged(QString)),this,SLOT(cambioestadoLineEdit(QString)));

    connect(ui->checkBoxFootPrintMaskMet,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxAnchoPasadaMet,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxOffsetPasadaMet,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));


    connect(ui->checkBoxCortarMet,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxNumeroCanalesspasadaMet,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxTamanyoCortarMet,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));


    //Connectar el estado de los widgets a sus slots correspondientes para cambiar el valor
    connect(ui->lineEditFolderOutMet,SIGNAL(textChanged(QString)),punteroRegistroCreateMet,SLOT(setFolderOut(QString)));
    connect(ui->comboBoxAmbitoProyectoMet,SIGNAL(currentIndexChanged(QString)),punteroRegistroCreateMet,SLOT(setAmbitoOperacion(QString)));
    connect(ui->comboBoxTamanoPixelMet,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarTamanyPixel(int)));
    connect(ui->comboBoxCoordinateSystemMet,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarCoorSysMet(int)));
    connect(ui->comboBoxTamanyoCortarMet,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarTamanyoCorte(int)));
    connect(ui->comboBoxNumeroCanalesspasadaMet,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarNumeroCanales(int)));
    connect(ui->comboBoxAnchoPasadaMet,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarAnchoPasada(int)));
    connect(ui->comboBoxOffsetPasadaMet,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarOffsetPasada(int)));

    //Conectar los check con los metodos de registroCreateMet para comprobar el estado de selecionado o no seleccionado
    connect(ui->checkBoxCortarMet,SIGNAL(stateChanged(int)),punteroRegistroCreateMet,SLOT(setCutDtm(int)));
    connect(ui->checkBoxFootPrintMaskMet,SIGNAL(stateChanged(int)),punteroRegistroCreateMet,SLOT(setFootprintMask(int)));
}

CreateMet::~CreateMet()
{
    delete ui;
}
RegistroCreateMet * CreateMet::getObjetoRegistroCreateMet()
{
    return punteroRegistroCreateMet;
}
void CreateMet::on_pushButtonFolderOutMet_clicked()
{
    folderOut=QString();
    QString pbSelectFolder = "Q:\soft\Antonio";//el primer valor de el QStringList es donde se abrira la ventana
    folderOut=QFileDialog::getExistingDirectory
            (0,("Triar carpeta sortida"),(pbSelectFolder));
    qDebug() << folderOut << "DirectorioMet1";
    if(!folderOut.isNull() && !folderOut.isEmpty())
    {
        ui->lineEditFolderOutMet->setText(folderOut);
    }
}
void CreateMet::enableOrDisableExtraerMet(int chec)
{
    if (chec==0)
    {
        ui->checkBoxCortarMet->setDisabled(1);
        ui->checkBoxFootPrintMaskMet->setDisabled(1);
        ui->checkBoxCortarMet->setChecked(0);
        ui->checkBoxFootPrintMaskMet->setChecked(0);
        ui->comboBoxAmbitoProyectoMet->setDisabled(1);
        ui->comboBoxTamanoPixelMet->setDisabled(1);
        ui->comboBoxCoordinateSystemMet->setDisabled(1);
        ui->lineEditFolderOutMet->setDisabled(1);
        ui->pushButtonFolderOutMet->setDisabled(1);
        ui->labelAmbitoProyectoMet->setDisabled(1);
        ui->labelCoordinateSystemMet->setDisabled(1);
        ui->labelTamanoPixelMet->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->checkBoxCortarMet->setEnabled(1);
        ui->checkBoxFootPrintMaskMet->setEnabled(1);
        ui->comboBoxAmbitoProyectoMet->setEnabled(1);
        ui->comboBoxTamanoPixelMet->setEnabled(1);
        ui->comboBoxCoordinateSystemMet->setEnabled(1);
        ui->lineEditFolderOutMet->setEnabled(1);
        ui->pushButtonFolderOutMet->setEnabled(1);
        ui->labelAmbitoProyectoMet->setEnabled(1);
        ui->labelCoordinateSystemMet->setEnabled(1);
        ui->labelTamanoPixelMet->setEnabled(1);
        qDebug()<< "seleccionado";
    }
//    if(ui->comboBoxAmbitoProyectoMet->currentIndex()==3)
//    {
//        qDebug()<< "pepepepeooooooooo";
//        ui->comboBoxCoordinateSystemMet->setDisabled(1);
//    }

}

void CreateMet::activateWidget(bool acti)
{
    qDebug() << acti << "actiMet";
    if (acti==true)
    {
        ui->checkBoxExtraerMet->setEnabled(true);
        ui->pushButtonDeleteDatesMet->setEnabled(true);
    }
    else
    {
        ui->checkBoxExtraerMet->setEnabled(false);
        ui->checkBoxExtraerMet->setChecked(false);
        ui->pushButtonDeleteDatesMet->setEnabled(false);
    }
}
void CreateMet::setPunterotVCoordenadas(TableViewCoordinates *p)
{
    tVCoordenadas=p;
}
void CreateMet::calcularOffsetPasada(int offsetPasada)
{
    qDebug() << offsetPasada << "ofsetPasada";

    ui->comboBoxAnchoPasadaMet->setCurrentIndex((offsetPasada*800));
}
void CreateMet::enableOrDisableFootPrintMaskMet(int chec)
{
    if (chec==0)
    {
        ui->comboBoxAnchoPasadaMet->setDisabled(1);
        ui->comboBoxOffsetPasadaMet->setDisabled(1);
        ui->labelAnchoPasadaMet->setDisabled(1);
        ui->labelOffsetPasadaMet->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->comboBoxAnchoPasadaMet->setDisabled(0);
        ui->comboBoxOffsetPasadaMet->setDisabled(0);
        ui->labelAnchoPasadaMet->setDisabled(0);
        ui->labelOffsetPasadaMet->setDisabled(0);
        qDebug()<< "seleccionado";
    }
    qDebug()<< chec <<"chec";
}
void CreateMet::enableOrDisableCortarMet(int chec)
{
    if (chec==0)
    {
        ui->comboBoxTamanyoCortarMet->setDisabled(1);
        ui->comboBoxNumeroCanalesspasadaMet->setDisabled(1);
        ui->labelCortarMet->setDisabled(1);
        ui->labelNumeroCanalesspasadaMet->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->comboBoxTamanyoCortarMet->setDisabled(0);
        ui->comboBoxNumeroCanalesspasadaMet->setDisabled(0);
        ui->labelCortarMet->setDisabled(0);
        ui->labelNumeroCanalesspasadaMet->setDisabled(0);
        qDebug()<< "seleccionado";
    }
    qDebug()<< chec <<"chec";
}

void CreateMet::onCambioComboBoxAmbitoProyectoMet(int text)
{
    if(ui->comboBoxAmbitoProyectoMet->currentIndex()==2)
        {
        ui->comboBoxCoordinateSystemMet->setCurrentIndex(3);
    }
    if(ui->comboBoxAmbitoProyectoMet->currentIndex()==1 || ui->comboBoxAmbitoProyectoMet->currentIndex()==3)
        {
        if(ui->comboBoxCoordinateSystemMet->currentIndex()!=2)
        {
         ui->comboBoxCoordinateSystemMet->setCurrentIndex(1);
        }

    }



    //No creo que sea necesario obtener los datos de tamayo de pixel y utm del fichero obj
    //qDebug()<< ui->comboBoxAmbitoProyectoMet->currentText() <<"ui->comboBoxAmbitoProyectoMet->currentText()";
//    int utm;
//    int tPixel;
//    utm=ui->comboBoxAmbitoProyectoMet->itemData(text,Qt::UserRole+3).toInt();
//    tPixel=ui->comboBoxAmbitoProyectoMet->itemData(text,Qt::UserRole+2).toInt();
//    if (tPixel!=-1)
//    {
//        for(int i=0;i<ui->comboBoxTamanoPixelMet->count();i++)
//        {
//            if (ui->comboBoxTamanoPixelMet->itemData(i).toInt()==tPixel)
//            {
//                ui->comboBoxTamanoPixelMet->setCurrentIndex(i);
//            }
//        }
//    }
//    if (utm!=-1)
//    {
//        for(int i=0;i<ui->comboBoxCoordinateSystemMet->count();i++)
//        {
//            if (ui->comboBoxCoordinateSystemMet->itemData(i).toInt()==utm)
//            {
//                ui->comboBoxCoordinateSystemMet->setCurrentIndex(i);
//            }
//        }
//    }
    int valorAP = ui->comboBoxAmbitoProyectoMet->currentIndex();
    QString path = ui->comboBoxAmbitoProyectoMet->itemData(valorAP,Qt::UserRole+1).toString();
    punteroRegistroCreateMet->setPathImageMet(path);
    qDebug()<< path <<"pathitemData(valorAP,Qt::UserRole+1)";





    DataZoneProject::Ambito nombre = (DataZoneProject::Ambito)ui->comboBoxAmbitoProyectoMet->itemData(valorAP,Qt::UserRole+6).toInt();
    punteroRegistroCreateMet->setAmbitoOperacion(nombre);
    qDebug()<< nombre <<"nombreitemData(valorAP,Qt::UserRole+6)";

    QJsonArray listaExe=ui->comboBoxAmbitoProyectoMet->itemData(valorAP,Qt::UserRole+4).toJsonArray();
    punteroRegistroCreateMet->setListaEjecutables(listaExe);
    qDebug()<< listaExe.count() << listaExe <<"numero de elementos";
    qDebug()<< punteroRegistroCreateMet->getTamanyPixel() <<"tamanyo pixelonCambioComboBoxAmbitoProyectoMet";
    qDebug()<< punteroRegistroCreateMet->getCoordinateSystem() <<"sistema coordenadasonCambioComboBoxAmbitoProyectoMet";
    qDebug()<< punteroRegistroCreateMet->getAmbitoOperacion() <<"Ambito operaciononCambioComboBoxAmbitoProyectoMet";
}

void CreateMet::on_pushButtonDeleteDatesMet_clicked()
{
    ui->lineEditFolderOutMet->clear();
    ui->comboBoxAmbitoProyectoMet->setCurrentIndex(0);
    ui->comboBoxAnchoPasadaMet->setCurrentIndex(0);
    ui->comboBoxNumeroCanalesspasadaMet->setCurrentIndex(0);
    ui->comboBoxOffsetPasadaMet->setCurrentIndex(0);
    ui->comboBoxTamanoPixelMet->setCurrentIndex(0);
    ui->comboBoxTamanyoCortarMet->setCurrentIndex(0);
    ui->comboBoxCoordinateSystemMet->setCurrentIndex(0);
}

//Codigo nuevo////////////

void CreateMet::evaluarEstadoWidgetMet()
{
    //Si el checkExtreureMwet esta deseleccionadop return sin icono
    if(!ui->checkBoxExtraerMet->isChecked())
    {
        emit cambioEstadoCorreccionMet(0);
        qDebug() <<  "Icono 0";
        return;
    }
    //SI checkExtreureMet esta activo y checcutMet y checkFootprintMet desactivados
    if(!ui->checkBoxCortarMet->isChecked() && !ui->checkBoxFootPrintMaskMet->isChecked())
    {
        if(!ui->lineEditFolderOutMet->text().isEmpty() && ui->comboBoxAmbitoProyectoMet->currentIndex()!=0
                && ui->comboBoxTamanoPixelMet->currentIndex()!=0 && ui->comboBoxCoordinateSystemMet->currentIndex()!=0)
        {
            qDebug() <<  "Icono 1";
            emit cambioEstadoCorreccionMet(1);
        }
        else
        {
            qDebug() <<  "Icono 2";
            emit cambioEstadoCorreccionMet(2);
        }
        return;
    }
    //Si checkBoxCortarMet esta activo y CheckFootPrintmask desactivado
    if(ui->checkBoxCortarMet->isChecked() && !ui->checkBoxFootPrintMaskMet->isChecked())
    {
        //Si todos los datos de checkBoxExtraerMet y checkBoxCortarMet son correctos
        if(!ui->lineEditFolderOutMet->text().isEmpty() && ui->comboBoxAmbitoProyectoMet->currentIndex()!=0
                && ui->comboBoxTamanoPixelMet->currentIndex()!=0 && ui->comboBoxCoordinateSystemMet->currentIndex()!=0
                && ui->comboBoxTamanyoCortarMet->currentIndex()!=0 && ui->comboBoxNumeroCanalesspasadaMet->currentIndex()!=0 )
        {
            qDebug() <<  "Icono 1";
            emit cambioEstadoCorreccionMet(1);
        }
        else
        {
            //Si los datos no son correctos
            qDebug() <<  "Icono 2";
            emit cambioEstadoCorreccionMet(2);
        }
        return;
    }
    //Si checkBoxFootPrintMask esta activo ycheckBoxCortarMet desactivado
    if(!ui->checkBoxCortarMet->isChecked() && ui->checkBoxFootPrintMaskMet->isChecked())
    {
        //Si todos los datos de checkBoxExtraerMet y checkBoxFootPrintMask son correctos
        if(!ui->lineEditFolderOutMet->text().isEmpty() && ui->comboBoxAmbitoProyectoMet->currentIndex()!=0
                && ui->comboBoxTamanoPixelMet->currentIndex()!=0 && ui->comboBoxCoordinateSystemMet->currentIndex()!=0
                && ui->comboBoxAnchoPasadaMet->currentIndex()!=0 && ui->comboBoxOffsetPasadaMet->currentIndex()!=0 )
        {
            qDebug() <<  "Icono 1";
            emit cambioEstadoCorreccionMet(1);
        }
        else
        {
            //Si los datos no son correctos
            qDebug() <<  "Icono 2";
            emit cambioEstadoCorreccionMet(2);
        }
        return;
    }

    //Si todos los datos de checkBoxExtraerMet y checkBoxFootPrintMask son correctos
    if(!ui->lineEditFolderOutMet->text().isEmpty() && ui->comboBoxAmbitoProyectoMet->currentIndex()!=0
            && ui->comboBoxTamanoPixelMet->currentIndex()!=0 && ui->comboBoxCoordinateSystemMet->currentIndex()!=0
            && ui->comboBoxAnchoPasadaMet->currentIndex()!=0 && ui->comboBoxOffsetPasadaMet->currentIndex()!=0
            && ui->comboBoxTamanyoCortarMet->currentIndex()!=0 && ui->comboBoxNumeroCanalesspasadaMet->currentIndex()!=0)
    {
        qDebug() <<  "Icono 1";
        emit cambioEstadoCorreccionMet(1);
    }
    else
    {
        //Si los datos no son correctos
        qDebug() <<  "Icono 2";
        emit cambioEstadoCorreccionMet(2);
    }
    return;
}

void CreateMet::cambioestadoCheckBox(int estado)
{
    qDebug() <<  "cambioestadoCheckBox";
    evaluarEstadoWidgetMet();
}
void CreateMet::cambioestadoComboBox(int estado)
{
    qDebug() <<  "cambioestadoComboBox";
    evaluarEstadoWidgetMet();
}

void CreateMet::cambioestadoLineEdit(QString directorio)
{
    qDebug() <<  "cambioestadoLineEdit";
    evaluarEstadoWidgetMet();
}

void CreateMet::VigilarTamanyPixel(int tamanyoPixel)
{
    double tPixel;
    tPixel=ui->comboBoxTamanoPixelMet->itemData(tamanyoPixel).toDouble();
    punteroRegistroCreateMet->setTamanyPixel(tPixel);
}
void CreateMet::VigilarCoorSysMet(int corSys)
{
    DataZoneProject::sistemaCoor coordinateS;
    coordinateS=(DataZoneProject::sistemaCoor)ui->comboBoxCoordinateSystemMet->itemData(corSys).toInt();
    punteroRegistroCreateMet->setCoordinateSystem(coordinateS);
}
void CreateMet::VigilarTamanyoCorte(int tamanyoCorte)
{
    int tCorte;
    tCorte=ui->comboBoxTamanyoCortarMet->itemData(tamanyoCorte).toInt();
    punteroRegistroCreateMet->setTamanyoCorte(tCorte);
}
void CreateMet::VigilarNumeroCanales(int numeroCanales)
{
    int nCanales;
    nCanales=ui->comboBoxNumeroCanalesspasadaMet->itemData(numeroCanales).toInt();
    punteroRegistroCreateMet->setNumeroCanales(nCanales);
}
void CreateMet::VigilarAnchoPasada(int anchoPasada)
{
    int aPassada;
    aPassada=ui->comboBoxAnchoPasadaMet->itemData(anchoPasada).toInt();
    punteroRegistroCreateMet->setAnchoPasada(aPassada);
}
void CreateMet::VigilarOffsetPasada(int offsetPasada)
{
    int oPassada;
    oPassada=ui->comboBoxOffsetPasadaMet->itemData(offsetPasada).toInt();
    punteroRegistroCreateMet->setOffsetPasada(oPassada);
}

void CreateMet::recargarModelosAmbito()
{
    QSettings settings("tologar","ToolsPCOT",this);
    QString pathMet=settings.value("variablesMET").toString();
    FicheroDatosAmbitoPro lectorRecargarModelos(this,pathMet);
    ui->comboBoxAmbitoProyectoMet->setModel(lectorRecargarModelos.obtenerModelo());
}


