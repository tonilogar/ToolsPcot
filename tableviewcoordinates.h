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
/*!
 * @class TableViewCoordinates
 * @brief Interface grafica per mostra el fitxer de coordenades.
 */

namespace Ui {
    class TableViewCoordinates;
}

class TableViewCoordinates : public QWidget
{
    Q_OBJECT

public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit TableViewCoordinates(QWidget *parent = 0);
    ~TableViewCoordinates();

    ModeloCoordenadas *getModeloCoordenadas();
signals:
    /*!
    * TableView ple.
    */
    void filledTableView(bool state);

private slots:


private:
    Ui::TableViewCoordinates *ui;                       ///< Nom del interface grafica.
    QString _pathFileCoordinates;                       ///< Nom del fitxer de coordenades.
    bool _filledCoordenadas;                            ///< Estat ple o buit.
    ModeloCoordenadas *_modelo;                         ///< Nom del model de punter modeloCoordenades.

};

#endif // TABLEVIEWCOORDINATES_H
