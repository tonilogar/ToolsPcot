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
#include "tableviewraw.h"
#include "ui_tableviewraw.h"
#include <QFileDialog>
#include <QLineEdit>
TableViewRaw::TableViewRaw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableViewRaw)
{
    ui->setupUi(this);

    // Codigo para el ModeloCoordenadas
    modelo=new ModeloRaw(this);
    ui->tableViewRaw->setModel(modelo);
    _rename=" Name File";
    _estadoactual=false;
    _estadoWidgets=false;
    _estadoModelo=false;
    // ENDCODE
    //ui->tableViewRaw->horizontalHeader()->setStretchLastSection(true);
    //ui->tableViewRaw->setSortingEnabled(true);//Esta función abilita la ordenación del tableview
    connect(ui->lineEditPrefix,SIGNAL(textChanged(QString)),modelo,SLOT(setPrefix(QString)));
    connect(ui->lineEditCodigoSensor,SIGNAL(textChanged(QString)),modelo,SLOT(setCodiSensor(QString)));
    connect(ui->comboBoxNombreAvion,SIGNAL(currentIndexChanged(QString)),modelo,SLOT(setNomAvio(QString)));
    connect(ui->comboBoxNumeroVuelo,SIGNAL(currentIndexChanged(QString)),modelo,SLOT(setNumeroVol(QString)));
    connect(ui->comboBoxRangoPasada,SIGNAL(currentIndexChanged(QString)),modelo,SLOT(setRangoPasada(QString)));
    connect(ui->lineEditPrefix,SIGNAL(textChanged(QString)),this,SLOT(evaluarWidget()));
    connect(ui->lineEditCodigoSensor,SIGNAL(textChanged(QString)),this,SLOT(evaluarWidget()));
    connect(ui->lineEditFicheroRad,SIGNAL(textChanged(QString)),this,SLOT(evaluarWidget()));
    connect(ui->comboBoxNombreAvion,SIGNAL(currentIndexChanged(int)),this,SLOT(evaluarWidget()));
    connect(ui->comboBoxNumeroVuelo,SIGNAL(currentIndexChanged(int)),this,SLOT(evaluarWidget()));
    connect(ui->lineEditFicheroRadcor,SIGNAL(textChanged(QString)),this,SLOT(evaluarWidget()));
    connect(ui->lineEditFicheroAttsync,SIGNAL(textChanged(QString)),this,SLOT(evaluarWidget()));
    connect(ui->lineEditParametrosRadcor,SIGNAL(textChanged(QString)),this,SLOT(evaluarWidget()));
    connect(ui->lineEditParametrosAttsync,SIGNAL(textChanged(QString)),this,SLOT(evaluarWidget()));
    connect(ui->comboBoxRangoPasada,SIGNAL(currentIndexChanged(int)),this,SLOT(evaluarWidget()));
    connect(modelo,SIGNAL(cambioEstado(bool)),this,SLOT(setEstadoModelo(bool)));
    ui->tableViewRaw->setItemDelegateForColumn(4,new SignoPasadaDelegate(this));
    ui->lineEditParametrosRadcor->setText(",rb -f 1 -j 110 -g -50 -v 0 -s 300 -n 1000000 -r Y -R Y -A 11");
    ui->lineEditParametrosAttsync->setText(" -f Y -r Y -l"+ _rename+".log -t N -m T -i Y");
}

TableViewRaw::~TableViewRaw()
{
    delete ui;
}
void TableViewRaw::selectFilesRaw()
{
    controlRaw=true;
    QString pbSelectFolder="Q://soft//Antonio//raw";
    filesRaw=QFileDialog::getOpenFileNames
    (0,("Selecionar fitxer"),(pbSelectFolder),"Text Files (*.raw)");

    //si no se selecciona ningún fichero raw controlRaw=false
    if (filesRaw.count()==0)
    {
        controlRaw=false;
    }
}
 ModeloRaw* TableViewRaw::getModeloRaw()
 {
  return modelo;
 }

QStringList TableViewRaw::sowFilesRaw()
{
    return filesRaw;
}

void TableViewRaw::chekingFilesRaw()
{
    //si no se seleccionan ficheros raw
    if (controlRaw==true)
     ListFilesGlobalRaw <<  filesRaw;
    {
    foreach(const QString &file, filesRaw)
        {//3
         if(!ListFilesGlobalRaw.contains(file))
            ListFilesGlobalRaw.append(file);
        }//3
    ListFilesGlobalRaw.removeDuplicates();
}
}

void TableViewRaw::sowModelTableView()
{
    if (controlRaw==true)
    {
        // Codigo para el ModeloCoordenadas
        //modelo->clear();
        // ENDCODE
        QList<RegistroRaw*> listaRegistros;
        foreach(const QString &file, ListFilesGlobalRaw)
        {//3
            qDebug()<< ListFilesGlobalRaw << "for";
            qDebug()<< filesRaw << "for";
            // Codigo para el ModeloCoordenadas
            RegistroRaw *registro=new RegistroRaw();
           QString nom=QString(QFileInfo(file).fileName());
           QString path=QString(QFileInfo(file).absolutePath());
           qDebug()<< path << "path";
           qDebug()<< nom << "nom";
           //            registro->setPathRaw(path);
            registro->setPathRaw(path);
            registro->setNameRaw(nom);

            listaRegistros.append(registro);
            // ENDCODE
        }

        // Codigo para el ModeloCoordenadas
        modelo->setListaRegistro(listaRegistros);
        // ENDCODE
}
}
void TableViewRaw::deleteTableViewRaw()
{
    // Codigo para el ModeloCoordenadas
    modelo->clear();
    ListFilesGlobalRaw.clear();
    // ENDCODE
  emit cambioEstadoRaw(false);
}

void TableViewRaw::on_pushButtonSeleccionarRaw_clicked()
{
selectFilesRaw();
chekingFilesRaw();
sowModelTableView();
}

void TableViewRaw::on_pushButtonBorrarListadoRaw_clicked()
{
deleteTableViewRaw();
}

void TableViewRaw::on_pushButtonFicheroRad_clicked()
{
    QString pbfolderOut=QFileDialog::getOpenFileName
    (0,("Selecionar fitxer Rad"),("Q:\soft\Antonio"),"Rad Files (*.rad)");
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())ui->lineEditFicheroRad->setText(pbfolderOut);
//    //Si no se selecciona directorio no se cambian los paths
    modelo->setFicheroRad(pbfolderOut);
    modelo->getFicheroRad();
}
void TableViewRaw::on_pushButtonFicheroRadcor_clicked()
{
    QString pbfolderOut=QFileDialog::getOpenFileName
    (0,("Selecionar fitxer Radcorr"),("Q:\soft\Antonio"),"Rad Files (*.exe)");
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())ui->lineEditFicheroRadcor->setText(pbfolderOut);
//    //Si no se selecciona directorio no se cambian los paths
    modelo->setFicheroRadCorr(pbfolderOut);
    modelo->getFicheroRadCorr();
}
void TableViewRaw::on_pushButtonFicheroAttsync_clicked()
{
    QString pbfolderOut=QFileDialog::getOpenFileName
    (0,("Selecionar fitxer Radcorr"),("Q:\soft\Antonio"),"Attsync Files (*.exe)");
    if(!pbfolderOut.isNull() && !pbfolderOut.isEmpty())ui->lineEditFicheroAttsync->setText(pbfolderOut);
//    //Si no se selecciona directorio no se cambian los paths
    modelo->setFicheroAttsync(pbfolderOut);
    modelo->getFicheroAttsync();
}

void TableViewRaw::evaluaEstadoRaw()
{
    if(_estadoModelo && _estadoWidgets)
    {
        _estadoactual=true;
        emit cambioEstadoRaw(true);
    }
    else
    {
        _estadoactual=false;
        emit cambioEstadoRaw(false);
    }
qDebug()<< "estado Actual"<< _estadoactual;
}
 void TableViewRaw::setEstadoModelo(bool estado)
 {
     qDebug()<< "cambioEstadoModelo"<< estado;
   _estadoModelo=estado;
   evaluaEstadoRaw();
 }
 void TableViewRaw::setEstadoWidget(bool estado)
 {
     qDebug()<< "cambioEstadoWidget"<< estado;
   _estadoWidgets=estado;
   evaluaEstadoRaw();
 }

void TableViewRaw::evaluarWidget()
{
    if(ui->comboBoxNombreAvion->currentIndex()==0 ||
            ui->comboBoxNumeroVuelo->currentIndex()==0 ||
            ui->lineEditFicheroRadcor->text().isEmpty() ||
            ui->lineEditFicheroAttsync->text().isEmpty() ||
            ui->comboBoxRangoPasada->currentIndex()==0 ||
            ui->lineEditCodigoSensor->text().isEmpty() ||
            ui->lineEditFicheroRad->text().isEmpty() ||
            ui->lineEditPrefix->text().isEmpty() ||
            ui->lineEditParametrosRadcor->text().isEmpty() ||
            ui->lineEditParametrosAttsync->text().isEmpty())
    {
        setEstadoWidget(false);
    }
    else
    {
       setEstadoWidget(true);
    }
}




