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
#include "tableviewcoordinates.h"
#include "ui_tableviewcoordinates.h"

#include <QSortFilterProxyModel>

#include <QErrorMessage>

TableViewCoordinates::TableViewCoordinates(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableViewCoordinates)
{
    ui->setupUi(this);

    // Codigo para el ModeloCoordenadas
    modelo=new ModeloCoordenadas(this);

    QSortFilterProxyModel *modeloFiltrado=new QSortFilterProxyModel(this);

    modeloFiltrado->setSourceModel(modelo);
    ui->tableViewCoordenadas->setModel(modeloFiltrado);
    // ENDCODE

    ui->tableViewCoordenadas->setSortingEnabled(true);//Esta funci�n abilita la ordenaci�n del tableview
//    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
//    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
//    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
//    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
//    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
}

TableViewCoordinates::~TableViewCoordinates()
{
    delete ui;
}

void TableViewCoordinates::selectFileCoordinates()
{
    controlCoordenadas=true;
    QString pbSelectFolder="Q://soft//Antonio//";

    fileCoordinates=QFileDialog::getOpenFileName
    (0,("Selecionar fitxer"),(pbSelectFolder),"Text Files (*.txt)");

    //si no se selecciona el fichero de coordenadas controlCoordenadas=false
    if (fileCoordinates.count()==0)
    {
        controlCoordenadas=false;
        emit filledTableView(false);
    }
}

QString TableViewCoordinates::sowFileCoordinates()
{
  return fileCoordinates;
}

void TableViewCoordinates::chekingFileCoordinates()
{
    // Codigo para el ModeloCoordenadas
    modelo->clear();
    // ENDCODE
    if (controlCoordenadas==true)
    {
         QStringList lineErrorQstringList;
         lineQstringListDef.clear();
         lineErrorQstringList.clear();
         QFile readFile(fileCoordinates);
         readFile.open(QFile::ReadOnly);//Crear el fichero openClose.txt.
         QTextStream streamReadFile (&readFile);
         QString ficheroVacio=streamReadFile.readAll();
         qDebug()<< ficheroVacio << "pepestreamReadFile.read----------------------------------------------------";
         streamReadFile.seek(0);
         if(ficheroVacio=="")
         {
             mostrarQMessageBox("El fitxer de coordenades es incorrecte");
              emit filledTableView(false);
             controlCoordenadas=false;
           qDebug()<< "Vaciopepe----------------------------------------------------";
         }
         else
         {
         while(!streamReadFile.atEnd())//mientras la variable esta leyendo no este en el final del archivo
         {
             QStringList lineQstringList;
             QString line=streamReadFile.readLine();//cada line leida sera un QString
             line.replace("	"," ");//Cambio los tabuladores por espacios
             line.simplified();//Cambio los elementos considerados como espacios por espacios
             line.replace(",",".");//Cambio la comas por puntos
             QString lineTrimmed= line.trimmed();//Creo una nueva variable y borro los espacios del principio y fin
             lineQstringList = lineTrimmed.split(" ");//Creo un QStringList y anyado como elemento separador los espacios
             lineQstringList.removeAll(NULL);//Borro todos los elementos del QStrinList que sean nulos
             //Si el numero de elementos es diferente a 5 control False
             if (lineQstringList.count()!= 5)
             {
                 lineErrorQstringList <<"1";
                 controlCoordenadas=false;
             }
             if (lineQstringList.count()== 5)
             {
              if (lineQstringList.at(1).toDouble()==false)
              {
                  lineErrorQstringList <<"1";
                  controlCoordenadas=false;
              }
              if (lineQstringList.at(2).toDouble()==false)
              {
                  lineErrorQstringList <<"1";
                  controlCoordenadas=false;
              }
              if (lineQstringList.at(3).toDouble()==false)
              {
                  lineErrorQstringList <<"1";
                  controlCoordenadas=false;
              }
              if (lineQstringList.at(4).toDouble()==false)
              {
                  lineErrorQstringList <<"1";
                  controlCoordenadas=false;
              }
              if (lineErrorQstringList.isEmpty())
              {
                  emit filledTableView(true);

               QString fileCoordinatesDef= lineQstringList.join(" ");
               lineQstringListDef << fileCoordinatesDef;
               controlCoordenadas=true;
              }
             }
         }
         }
         if (!lineErrorQstringList.isEmpty())
         {
             mostrarQMessageBox("El fitxer de coordenades es incorrecte");
              emit filledTableView(false);

             controlCoordenadas=false;
         }
readFile.close();
    }
}
QStringList TableViewCoordinates::sowCoordinates()
{
    return lineQstringListDef;
}

void TableViewCoordinates::sowModelTableView()
{
    if (controlCoordenadas==true)
    {
        // Codigo para el ModeloCoordenadas
        modelo->clear();
        // ENDCODE
        QList<RegistroCoordenadas*> listaRegistros;
        foreach(const QString &file, lineQstringListDef)
        {//3

            // Codigo para el ModeloCoordenadas
            RegistroCoordenadas *registro=new RegistroCoordenadas();
            QStringList lineQstringList=file.split(" ");
            registro->setIdentificador(lineQstringList[0]);
            registro->setXA(lineQstringList[1].toDouble());
            registro->setYA(lineQstringList[2].toDouble());
            registro->setXB(lineQstringList[3].toDouble());
            registro->setYB(lineQstringList[4].toDouble());
            registro->ordenarCoordenadas();
            listaRegistros.append(registro);
            // ENDCODE
        }

        // Codigo para el ModeloCoordenadas
        modelo->setListaRegistro(listaRegistros);
        // ENDCODE
    }
}


void TableViewCoordinates::deleteTableViewCoordinates()
{
    // Codigo para el ModeloCoordenadas
    modelo->clear();
    // ENDCODE

    emit filledTableView(false);

}

void TableViewCoordinates::mostrarQMessageBox(QString texto)
{
QMessageBox ms;
ms.setText (texto);
ms.exec();
}



void TableViewCoordinates::on_pushButtonSelecionarTxtCoordenadas_clicked()
{
  selectFileCoordinates();
  chekingFileCoordinates();
  sowModelTableView();
}

void TableViewCoordinates::on_pushButtonBorrarListadoCoordenadas_clicked()
{
deleteTableViewCoordinates();
}

TableViewCoordinates * TableViewCoordinates::getObjetoTableViewCoordinates()
{
   return punteroTableViewCoordinates;
}
 ModeloCoordenadas *TableViewCoordinates::getModeloCoordenadas()
 {
     ModeloCoordenadas *punteroModelocoord;
     punteroModelocoord=modelo;
  return punteroModelocoord;

 }

void TableViewCoordinates::on_pushButtonHelpFilecoordinates_clicked()
{
DialogHelpFilecoordinates dialogo;
dialogo.exec();

}
