#ifndef TABLEVIEWCOORDINATES_H
#define TABLEVIEWCOORDINATES_H

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>
#include "modelocoordenadas.h"
#include <QWidget>
#include  "dialoghelpfilecoordinates.h"


namespace Ui {
    class TableViewCoordinates;
}

class TableViewCoordinates : public QWidget
{
    Q_OBJECT

public:
    explicit TableViewCoordinates(QWidget *parent = 0);
    ~TableViewCoordinates();
    TableViewCoordinates * getObjetoTableViewCoordinates();
    void selectFileCoordinates();
    QString sowFileCoordinates();
    void chekingFileCoordinates();    
    QStringList sowCoordinates();
    void sowModelTableView();
    void deleteTableViewCoordinates();
    void mostrarQMessageBox(QString);
    ModeloCoordenadas *getModeloCoordenadas();
signals:
    void filledTableView(bool state);


private slots:
    void on_pushButtonSelecionarTxtCoordenadas_clicked();

    void on_pushButtonBorrarListadoCoordenadas_clicked();

    void on_pushButtonHelpFilecoordinates_clicked();

private:
    Ui::TableViewCoordinates *ui;
    QString fileCoordinates;
    QStringList lineQstringListDef;
    bool controlCoordenadas;
    ModeloCoordenadas *modelo;
    TableViewCoordinates *punteroTableViewCoordinates;

};

#endif // TABLEVIEWCOORDINATES_H
