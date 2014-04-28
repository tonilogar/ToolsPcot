#ifndef TABLEVIEWRAW_H
#define TABLEVIEWRAW_H

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QDateTime>
#include <QLineEdit>
#include "modeloraw.h"
#include "signopasadadelegate.h"

namespace Ui {
    class TableViewRaw;
}

class TableViewRaw : public QWidget
{
    Q_OBJECT

public:
    explicit TableViewRaw(QWidget *parent = 0);
    ~TableViewRaw();
    void selectFilesRaw();
    QStringList sowFilesRaw();
    void chekingFilesRaw();
    void sowModelTableView();
    void deleteTableViewRaw();
    void mostrarQMessageBox(QString);
    ModeloRaw *getModeloRaw();
signals:

    void filledTableView(bool state);

    void cambioEstadoRaw(bool state);


private slots:
    void on_pushButtonSeleccionarRaw_clicked();

    void on_pushButtonBorrarListadoRaw_clicked();

    void on_pushButtonFicheroRad_clicked();

    void evaluarWidget();

    void setEstadoModelo(bool estado);

    void setEstadoWidget(bool estado);

    void on_pushButtonFicheroRadcor_clicked();

    void on_pushButtonFicheroAttsync_clicked();

private:
    Ui::TableViewRaw *ui;
    QStringList filesRaw;
    QStandardItemModel *modeloRaw;
    QStringList ListFilesGlobalRaw;
    bool controlRaw;
    ModeloRaw *modelo;
    bool _estadoactual; ///< Estado actual tableviewRaw
    bool _estadoWidgets;
    bool _estadoModelo;
    void evaluaEstadoGeneral();
    void evaluaEstadoRaw();///Comprobara el estado de widget y el estado de modelo.
    QString _rename;
};

#endif // TABLEVIEWRAW_H
