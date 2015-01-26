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
    QString pathOrto=settings.value("variablesOrto").toString();

    FicheroDatosAmbitoPro lectorModelos(this,pathOrto);
    if (lectorModelos.fileExist())
    {
        ui->comboBoxAmbitoProyectoOrto->setModel(lectorModelos.obtenerModelo());
    }
    else
    {
        qDebug() <<  "No existe el archivo";
        QMessageBox::StandardButton botonPulsado=QMessageBox::question(0,"Dades Ambit projecte Orto", "El fitxer de variables Orto no es troba,\nVols crear un fitxer per defecte");
        if(botonPulsado==QMessageBox::Yes)
        {
            //Crear un archivo Json por defecto
            lectorModelos.CreateJsonOrtoDefecto();
            //Paso la dirección por de fecto al valor de path de settings
            QSettings settings("tologar","ToolsPCOT",this);
            QString pathDefectoFileJson=qApp->applicationDirPath()+"/variablespcotOrto.txt";
            FicheroDatosAmbitoPro lectorOuts(this,pathDefectoFileJson);
            settings.setValue("variablesOrto",pathDefectoFileJson);
            ui->comboBoxAmbitoProyectoOrto->setModel(lectorOuts.obtenerModelo());

        }
    }

    ui->comboBoxTamanoPixelOrto->addItem("No seleccionado",-1);
    for (double i=0.10; i< 20; i+=0.10){
        ui->comboBoxTamanoPixelOrto->addItem(QString::number(i),i);
    }



    ui->comboBoxCoordinateSystemOrto->addItem("No seleccionado",3);
    ui->comboBoxCoordinateSystemOrto->addItem("Etrs89",0);
    ui->comboBoxCoordinateSystemOrto->addItem("Ed50",1);
    ui->comboBoxCoordinateSystemOrto->addItem("Ntf",2);

    ui->comboBoxSelectSensor->addItem("No seleccionado",4);
    ui->comboBoxSelectSensor->addItem("Casi",0);
    ui->comboBoxSelectSensor->addItem("Tasi",1);
    ui->comboBoxSelectSensor->addItem("Aisa",2);
    ui->comboBoxSelectSensor->addItem("Aisa_BE",3);


    ui->comboBoxTamanyoCortarOrto->addItem("No seleccionado",-1);
    for (int i=100; i< 1000; i+=10)
        ui->comboBoxTamanyoCortarOrto->addItem(QString::number(i)+" MB",i);

    ui->comboBoxNumeroCanalesspasadaOrto->addItem("No seleccionado",-1);
    for (int i=1; i< 601; i++)
        ui->comboBoxNumeroCanalesspasadaOrto->addItem(QString::number(i),i);

    ui->comboBoxAnchoPasadaOrto->addItem("No seleccionado",-1);
    for (int i=10; i< 20100; i++)
        ui->comboBoxAnchoPasadaOrto->addItem(QString::number(i)+" Mts",i);

    ui->comboBoxOffsetPasadaOrto->addItem("No seleccionado",-1);
    for (int i=10; i< 510; i+=10)
        ui->comboBoxOffsetPasadaOrto->addItem(QString::number(i)+" Mts",i);

    connect(ui->comboBoxAmbitoProyectoOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(onCambioComboBoxAmbitoProyectoOrto(int)));
    connect(ui->comboBoxTamanoPixelOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(calcularOffsetPasada(int)));
    connect(ui->comboBoxSelectSensor,SIGNAL(currentIndexChanged(int)),this,SLOT(calcularOffsetPasada(int)));
    connect(ui->checkBoxExtraerOrto,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableExtraerOrto(int)));
    connect(ui->checkBoxCortarOrto,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableCortarOrto(int)));
    connect(ui->checkBoxFootPrintMaskOrto,SIGNAL(stateChanged(int)),this,SLOT(enableOrDisableFootPrintMaskOrto(int)));

    //nuevo  codigo
    connect(ui->checkBoxExtraerOrto,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxAmbitoProyectoOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxTamanoPixelOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxCoordinateSystemOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxSelectSensor,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->lineEditFolderOutOrto,SIGNAL(textChanged(QString)),this,SLOT(cambioestadoLineEdit(QString)));

    connect(ui->checkBoxFootPrintMaskOrto,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxAnchoPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxOffsetPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));


    connect(ui->checkBoxCortarOrto,SIGNAL(stateChanged(int)),this,SLOT(cambioestadoCheckBox(int)));
    connect(ui->comboBoxNumeroCanalesspasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));
    connect(ui->comboBoxTamanyoCortarOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(cambioestadoComboBox(int)));


    //Connectar el estado de los widgets a sus slots correspondientes para cambiar el valor
    connect(ui->lineEditFolderOutOrto,SIGNAL(textChanged(QString)),punteroRegistroCreateOrto,SLOT(setFolderOut(QString)));
    connect(ui->comboBoxAmbitoProyectoOrto,SIGNAL(currentIndexChanged(QString)),punteroRegistroCreateOrto,SLOT(setAmbitoOperacion(QString)));
    connect(ui->comboBoxTamanoPixelOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarTamanyPixel(int)));
    connect(ui->comboBoxCoordinateSystemOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarCoorSysOrto(int)));
    connect(ui->comboBoxSelectSensor,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarSelectSensor(int)));

    connect(ui->comboBoxTamanyoCortarOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarTamanyoCorte(int)));
    connect(ui->comboBoxNumeroCanalesspasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarNumeroCanales(int)));
    connect(ui->comboBoxAnchoPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarAnchoPasada(int)));
    connect(ui->comboBoxOffsetPasadaOrto,SIGNAL(currentIndexChanged(int)),this,SLOT(VigilarOffsetPasada(int)));

    //Conectar los check con los Ortoodos de registroCreateOrto para comprobar el estado de selecionado o no seleccionado
    connect(ui->checkBoxCortarOrto,SIGNAL(stateChanged(int)),punteroRegistroCreateOrto,SLOT(setCutDtm(int)));
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
        ui->checkBoxCortarOrto->setDisabled(1);
        ui->checkBoxFootPrintMaskOrto->setDisabled(1);
        ui->checkBoxCortarOrto->setChecked(0);
        ui->checkBoxFootPrintMaskOrto->setChecked(0);
        ui->comboBoxAmbitoProyectoOrto->setDisabled(1);
        ui->comboBoxTamanoPixelOrto->setDisabled(1);
        ui->comboBoxCoordinateSystemOrto->setDisabled(1);
        ui->lineEditFolderOutOrto->setDisabled(1);
        ui->pushButtonFolderOutOrto->setDisabled(1);
        ui->labelAmbitoProyectoOrto->setDisabled(1);
        ui->labelCoordinateSystemOrto->setDisabled(1);
        ui->labelTamanoPixelOrto->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->checkBoxCortarOrto->setEnabled(1);
        ui->checkBoxFootPrintMaskOrto->setEnabled(1);
        ui->comboBoxAmbitoProyectoOrto->setEnabled(1);
        ui->comboBoxTamanoPixelOrto->setEnabled(1);
        ui->comboBoxCoordinateSystemOrto->setEnabled(1);
        ui->lineEditFolderOutOrto->setEnabled(1);
        ui->pushButtonFolderOutOrto->setEnabled(1);
        ui->labelAmbitoProyectoOrto->setEnabled(1);
        ui->labelCoordinateSystemOrto->setEnabled(1);
        ui->labelTamanoPixelOrto->setEnabled(1);
        qDebug()<< "seleccionado";
    }
    //    if(ui->comboBoxAmbitoProyectoOrto->currentIndex()==3)
    //    {
    //        qDebug()<< "pepepepeooooooooo";
    //        ui->comboBoxCoordinateSystemOrto->setDisabled(1);
    //    }

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
void CreateOrto::calcularOffsetPasada(int offsetPasada)
{
    int _numberPixelsSensor=0;
    if(ui->comboBoxSelectSensor->currentText()=="Casi")
            _numberPixelsSensor=550;
        if(punteroRegistroCreateOrto->getSelectSensor()==DataZoneProject::Tasi)
            _numberPixelsSensor=600;
        if(punteroRegistroCreateOrto->getSelectSensor()==DataZoneProject::Aisa)
            _numberPixelsSensor=1024;
        if(punteroRegistroCreateOrto->getSelectSensor()==DataZoneProject::Aisa_BE)
            _numberPixelsSensor=512;


        QString textoTamanyPixel=ui->comboBoxTamanoPixelOrto->currentText();
        double doubleTamanyPixel=textoTamanyPixel.toDouble();
        double anchoPasada;
        anchoPasada=doubleTamanyPixel*_numberPixelsSensor*1.5;
        int anchoPasadaInt=anchoPasada*1;
        qDebug()<< punteroRegistroCreateOrto->getSelectSensor() <<"punteroRegistroCreateOrtotttttttttt";
        qDebug()<<  anchoPasada <<  " anchoPasada";
        qDebug()<<  _numberPixelsSensor<<  " _numberPixelsSensor";
        qDebug()<< textoTamanyPixel <<  "text";
        qDebug()<< doubleTamanyPixel <<  "doubleTamanyPixel";
        qDebug()<< anchoPasadaInt <<  "anchoPasadaInt";
        ui->comboBoxAnchoPasadaOrto->setCurrentText(QString::number(anchoPasadaInt)+" Mts");
}
void CreateOrto::enableOrDisableFootPrintMaskOrto(int chec)
{
    if (chec==0)
    {
        ui->comboBoxAnchoPasadaOrto->setDisabled(1);
        ui->comboBoxOffsetPasadaOrto->setDisabled(1);
        ui->comboBoxSelectSensor->setDisabled(1);
        ui->labelSelectSensor->setDisabled(1);
        ui->labelAnchoPasadaOrto->setDisabled(1);
        ui->labelOffsetPasadaOrto->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->comboBoxAnchoPasadaOrto->setDisabled(0);
        ui->comboBoxOffsetPasadaOrto->setDisabled(0);
        ui->comboBoxSelectSensor->setDisabled(0);
        ui->labelSelectSensor->setDisabled(0);
        ui->labelAnchoPasadaOrto->setDisabled(0);
        ui->labelOffsetPasadaOrto->setDisabled(0);
        qDebug()<< "seleccionado";
    }
    qDebug()<< chec <<"chec";
}
void CreateOrto::enableOrDisableCortarOrto(int chec)
{
    if (chec==0)
    {
        ui->comboBoxTamanyoCortarOrto->setDisabled(1);
        ui->comboBoxNumeroCanalesspasadaOrto->setDisabled(1);
        ui->labelCortarOrto->setDisabled(1);
        ui->labelNumeroCanalesspasadaOrto->setDisabled(1);
        qDebug()<< "deseleccionado";
    }
    if (chec==2)
    {
        ui->comboBoxTamanyoCortarOrto->setDisabled(0);
        ui->comboBoxNumeroCanalesspasadaOrto->setDisabled(0);
        ui->labelCortarOrto->setDisabled(0);
        ui->labelNumeroCanalesspasadaOrto->setDisabled(0);
        qDebug()<< "seleccionado";
    }
    qDebug()<< chec <<"chec";
}

void CreateOrto::onCambioComboBoxAmbitoProyectoOrto(int text)
{
    if(ui->comboBoxAmbitoProyectoOrto->currentIndex()==2)
    {
        ui->comboBoxCoordinateSystemOrto->setCurrentIndex(3);
    }
    if(ui->comboBoxAmbitoProyectoOrto->currentIndex()==1 || ui->comboBoxAmbitoProyectoOrto->currentIndex()==3)
    {
        if(ui->comboBoxCoordinateSystemOrto->currentIndex()!=2)
        {
            ui->comboBoxCoordinateSystemOrto->setCurrentIndex(1);
        }

    }



    //No creo que sea necesario obtener los datos de tamayo de pixel y utm del fichero obj
    //qDebug()<< ui->comboBoxAmbitoProyectoOrto->currentText() <<"ui->comboBoxAmbitoProyectoOrto->currentText()";
    //    int utm;
    //    int tPixel;
    //    utm=ui->comboBoxAmbitoProyectoOrto->itemData(text,Qt::UserRole+3).toInt();
    //    tPixel=ui->comboBoxAmbitoProyectoOrto->itemData(text,Qt::UserRole+2).toInt();
    //    if (tPixel!=-1)
    //    {
    //        for(int i=0;i<ui->comboBoxTamanoPixelOrto->count();i++)
    //        {
    //            if (ui->comboBoxTamanoPixelOrto->itemData(i).toInt()==tPixel)
    //            {
    //                ui->comboBoxTamanoPixelOrto->setCurrentIndex(i);
    //            }
    //        }
    //    }
    //    if (utm!=-1)
    //    {
    //        for(int i=0;i<ui->comboBoxCoordinateSystemOrto->count();i++)
    //        {
    //            if (ui->comboBoxCoordinateSystemOrto->itemData(i).toInt()==utm)
    //            {
    //                ui->comboBoxCoordinateSystemOrto->setCurrentIndex(i);
    //            }
    //        }
    //    }
    int valorAP = ui->comboBoxAmbitoProyectoOrto->currentIndex();
    QString path = ui->comboBoxAmbitoProyectoOrto->itemData(valorAP,Qt::UserRole+1).toString();
    punteroRegistroCreateOrto->setPathImageOrto(path);
    qDebug()<< path <<"pathitemData(valorAP,Qt::UserRole+1)";





    DataZoneProject::Ambito nombre = (DataZoneProject::Ambito)ui->comboBoxAmbitoProyectoOrto->itemData(valorAP,Qt::UserRole+6).toInt();
    punteroRegistroCreateOrto->setAmbitoOperacion(nombre);
    qDebug()<< nombre <<"nombreitemData(valorAP,Qt::UserRole+6)";

    QJsonArray listaExe=ui->comboBoxAmbitoProyectoOrto->itemData(valorAP,Qt::UserRole+4).toJsonArray();
    punteroRegistroCreateOrto->setListaEjecutables(listaExe);
    qDebug()<< listaExe.count() << listaExe <<"numero de elementos";
    qDebug()<< punteroRegistroCreateOrto->getTamanyPixel() <<"tamanyo pixelonCambioComboBoxAmbitoProyectoOrto";
    qDebug()<< punteroRegistroCreateOrto->getCoordinateSystem() <<"sistema coordenadasonCambioComboBoxAmbitoProyectoOrto";
    qDebug()<< punteroRegistroCreateOrto->getAmbitoOperacion() <<"Ambito operaciononCambioComboBoxAmbitoProyectoOrto";
}

void CreateOrto::on_pushButtonDeleteDatesOrto_clicked()
{
    ui->lineEditFolderOutOrto->clear();
    ui->comboBoxAmbitoProyectoOrto->setCurrentIndex(0);
    ui->comboBoxAnchoPasadaOrto->setCurrentIndex(0);
    ui->comboBoxNumeroCanalesspasadaOrto->setCurrentIndex(0);
    ui->comboBoxOffsetPasadaOrto->setCurrentIndex(0);
    ui->comboBoxSelectSensor->setCurrentIndex(0);
    ui->comboBoxTamanoPixelOrto->setCurrentIndex(0);
    ui->comboBoxTamanyoCortarOrto->setCurrentIndex(0);
    ui->comboBoxCoordinateSystemOrto->setCurrentIndex(0);
}

//Codigo nuevo////////////

void CreateOrto::evaluarEstadoWidgetOrto()
{
    //Si el checkExtreureMwet esta deseleccionadop return sin icono
    if(!ui->checkBoxExtraerOrto->isChecked())
    {
        emit cambioEstadoCorreccionOrto(0);
        qDebug() <<  "Icono 0";
        return;
    }
    //SI checkExtreureOrto esta activo y checcutOrto y checkFootprintOrto desactivados
    if(!ui->checkBoxCortarOrto->isChecked() && !ui->checkBoxFootPrintMaskOrto->isChecked())
    {
        if(!ui->lineEditFolderOutOrto->text().isEmpty() && ui->comboBoxAmbitoProyectoOrto->currentIndex()!=0
                && ui->comboBoxTamanoPixelOrto->currentIndex()!=0 && ui->comboBoxCoordinateSystemOrto->currentIndex()!=0)
        {
            qDebug() <<  "Icono 1";
            emit cambioEstadoCorreccionOrto(1);
        }
        else
        {
            qDebug() <<  "Icono 2";
            emit cambioEstadoCorreccionOrto(2);
        }
        return;
    }
    //Si checkBoxCortarOrto esta activo y CheckFootPrintmask desactivado
    if(ui->checkBoxCortarOrto->isChecked() && !ui->checkBoxFootPrintMaskOrto->isChecked())
    {
        //Si todos los datos de checkBoxExtraerOrto y checkBoxCortarOrto son correctos
        if(!ui->lineEditFolderOutOrto->text().isEmpty() && ui->comboBoxAmbitoProyectoOrto->currentIndex()!=0
                && ui->comboBoxTamanoPixelOrto->currentIndex()!=0 && ui->comboBoxCoordinateSystemOrto->currentIndex()!=0
                && ui->comboBoxTamanyoCortarOrto->currentIndex()!=0 && ui->comboBoxNumeroCanalesspasadaOrto->currentIndex()!=0 )
        {
            qDebug() <<  "Icono 1";
            emit cambioEstadoCorreccionOrto(1);
        }
        else
        {
            //Si los datos no son correctos
            qDebug() <<  "Icono 2";
            emit cambioEstadoCorreccionOrto(2);
        }
        return;
    }
    //Si checkBoxFootPrintMask esta activo ycheckBoxCortarOrto desactivado
    if(!ui->checkBoxCortarOrto->isChecked() && ui->checkBoxFootPrintMaskOrto->isChecked())
    {
        //Si todos los datos de checkBoxExtraerOrto y checkBoxFootPrintMask son correctos
        if(!ui->lineEditFolderOutOrto->text().isEmpty() && ui->comboBoxAmbitoProyectoOrto->currentIndex()!=0
                && ui->comboBoxTamanoPixelOrto->currentIndex()!=0 && ui->comboBoxCoordinateSystemOrto->currentIndex()!=0
                && ui->comboBoxAnchoPasadaOrto->currentIndex()!=0 && ui->comboBoxOffsetPasadaOrto->currentIndex()!=0
                && ui->comboBoxSelectSensor->currentIndex()!=0)
        {
            qDebug() <<  "Icono 1";
            emit cambioEstadoCorreccionOrto(1);
        }
        else
        {
            //Si los datos no son correctos
            qDebug() <<  "Icono 2";
            emit cambioEstadoCorreccionOrto(2);
        }
        return;
    }

    //Si todos los datos de checkBoxExtraerOrto y checkBoxFootPrintMask son correctos
    if(!ui->lineEditFolderOutOrto->text().isEmpty() && ui->comboBoxAmbitoProyectoOrto->currentIndex()!=0
            && ui->comboBoxTamanoPixelOrto->currentIndex()!=0 && ui->comboBoxCoordinateSystemOrto->currentIndex()!=0
            && ui->comboBoxAnchoPasadaOrto->currentIndex()!=0 && ui->comboBoxOffsetPasadaOrto->currentIndex()!=0
            && ui->comboBoxTamanyoCortarOrto->currentIndex()!=0 && ui->comboBoxNumeroCanalesspasadaOrto->currentIndex()!=0
            && ui->comboBoxSelectSensor->currentIndex()!=0)
    {
        qDebug() <<  "Icono 1";
        emit cambioEstadoCorreccionOrto(1);
    }
    else
    {
        //Si los datos no son correctos
        qDebug() <<  "Icono 2";
        emit cambioEstadoCorreccionOrto(2);
    }
    return;
}

void CreateOrto::cambioestadoCheckBox(int estado)
{
    qDebug() <<  "cambioestadoCheckBox";
    evaluarEstadoWidgetOrto();
}
void CreateOrto::cambioestadoComboBox(int estado)
{
    qDebug() <<  "cambioestadoComboBox";
    evaluarEstadoWidgetOrto();
}

void CreateOrto::cambioestadoLineEdit(QString directorio)
{
    qDebug() <<  "cambioestadoLineEdit";
    evaluarEstadoWidgetOrto();
}

void CreateOrto::VigilarTamanyPixel(int tamanyoPixel)
{
    double tPixel;
    tPixel=ui->comboBoxTamanoPixelOrto->itemData(tamanyoPixel).toDouble();
    punteroRegistroCreateOrto->setTamanyPixel(tPixel);
    tP=tPixel;

}
void CreateOrto::VigilarCoorSysOrto(int corSys)
{
    DataZoneProject::sistemaCoor coordinateS;
    coordinateS=(DataZoneProject::sistemaCoor)ui->comboBoxCoordinateSystemOrto->itemData(corSys).toInt();
    punteroRegistroCreateOrto->setCoordinateSystem(coordinateS);
}
void CreateOrto::VigilarSelectSensor(int sens)
{
    DataZoneProject::Sensor selectSensor;
    selectSensor=(DataZoneProject::Sensor)ui->comboBoxSelectSensor->itemData(sens).toInt();
    punteroRegistroCreateOrto->setSelectSensor(selectSensor);
}
void CreateOrto::VigilarTamanyoCorte(int tamanyoCorte)
{
    int tCorte;
    tCorte=ui->comboBoxTamanyoCortarOrto->itemData(tamanyoCorte).toInt();
    punteroRegistroCreateOrto->setTamanyoCorte(tCorte);
}
void CreateOrto::VigilarNumeroCanales(int numeroCanales)
{
    int nCanales;
    nCanales=ui->comboBoxNumeroCanalesspasadaOrto->itemData(numeroCanales).toInt();
    punteroRegistroCreateOrto->setNumeroCanales(nCanales);
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
    oPassada=ui->comboBoxOffsetPasadaOrto->itemData(offsetPasada).toInt();
    punteroRegistroCreateOrto->setOffsetPasada(oPassada);
}

void CreateOrto::recargarModelosAmbito()
{
    QSettings settings("tologar","ToolsPCOT",this);
    QString pathOrto=settings.value("variablesOrto").toString();
    FicheroDatosAmbitoPro lectorRecargarModelos(this,pathOrto);
    ui->comboBoxAmbitoProyectoOrto->setModel(lectorRecargarModelos.obtenerModelo());
}


