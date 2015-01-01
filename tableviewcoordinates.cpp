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
    _modelo=new ModeloCoordenadas(this);

    //Ens permet ordenar les dades del tableView
    QSortFilterProxyModel *modeloFiltrado=new QSortFilterProxyModel(this);


    modeloFiltrado->setSourceModel(_modelo);
    ui->tableViewCoordenadas->setModel(modeloFiltrado);
    // ENDCODE

    ui->tableViewCoordenadas->setSortingEnabled(true);//Esta funci�n abilita la ordenaci�n del tableview
    //    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    //    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    //    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    //    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    //    ui->tableViewCoordenadas->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    connect(ui->pushButtonSelecionarTxtCoordenadas,SIGNAL(clicked()),this,SLOT(openFileCoordinates()));
    connect(ui->pushButtonBorrarListadoCoordenadas,SIGNAL(clicked()),this,SLOT(cleanTableView()));
    connect(ui->pushButtonHelpFilecoordinates,SIGNAL(clicked()),this,SLOT(help()));
}

TableViewCoordinates::~TableViewCoordinates()
{
    delete ui;
}
ModeloCoordenadas *TableViewCoordinates::getModeloCoordenadas()
{
    return _modelo;
}
void TableViewCoordinates::openFileCoordinates()
{
    ReaderCoordinatesBasico readCoor;
    _pathFileCoordinates=QFileDialog::getOpenFileName(this,"Select file coordinates",QString(),"text files(*.txt)");
    if(readCoor.canRead(_pathFileCoordinates))
    {
        if(readCoor.tryRead(_pathFileCoordinates))
        {
            _modelo->setListaRegistro(readCoor.getListCoordinates());
            _filledCoordenadas=true;
            emit filledTableView(_filledCoordenadas);
        }
        else
        {
            QMessageBox::warning(this, "File coordinates - error",readCoor.lastError());
            _filledCoordenadas=false;
            emit filledTableView(_filledCoordenadas);
        }
    }
    else
    {
        QMessageBox::warning(this, "File coordinates - error","el fitxer de coordenades no es un format valid");
        _filledCoordenadas=false;
        emit filledTableView(_filledCoordenadas);
    }
}

void TableViewCoordinates::cleanTableView()
{
    _modelo->clear();
    _pathFileCoordinates=QString();
    _filledCoordenadas=false;
    emit filledTableView(_filledCoordenadas);
}

void TableViewCoordinates::help()
{
    DialogHelpFilecoordinates dialogo;
    dialogo.exec();
}

