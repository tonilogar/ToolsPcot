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
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit TableViewCoordinates(QWidget *parent = 0);
    ~TableViewCoordinates();
    /*!
     * Mostrar els valors al tabeltiew.
     */
    TableViewCoordinates * getObjetoTableViewCoordinates();
    /*!
     * seleccionar el fitxer de coordenades.
     */
    void selectFileCoordinates();
    /*!
     * Mostrar el path del fitxer de coordenades.
     */
    QString sowFileCoordinates();
    /*!
     * Mostrar el fitxer de coordenades.
     */
    void chekingFileCoordinates();
    /*!
     * Mostrar el contingut del fitxer de coordenades.
     */
    QStringList sowCoordinates();
    /*!
     * Mostrar el model.
     */
    void sowModelTableView();
    /*!
     * Borrar les dades del tabletview.
     */
    void deleteTableViewCoordinates();
    /*!
     * Mostrar missatge d'advertència.
     *
     */
    void mostrarQMessageBox(QString);
    /*!
     * Mostrar i donar valor al model.
     *
     */
    ModeloCoordenadas *getModeloCoordenadas();
signals:
    /*!
    *Senyal per activar o desactivar les opcions gràfiques de les operacions de coordenades.
    *
     */
    void filledTableView(bool state);


private slots:
    /*!
    *Selecciona comprovar i crea el model del fitxer de coordenades.
    *
    */
    void on_pushButtonSelecionarTxtCoordenadas_clicked();
    /*!
    *Borrar dades del tabletviewRaw.
    *
    */
    void on_pushButtonBorrarListadoCoordenadas_clicked();
    /*!
    *Fitxer d'ajuda.
    *
    */
    void on_pushButtonHelpFilecoordinates_clicked();

private:
    Ui::TableViewCoordinates *ui;                       ///< Nom del interface grafica.
    QString fileCoordinates;                            ///< Nom del fitxer de coordenades.
    QStringList lineQstringListDef;                     ///< Nom del llistat del contingut del fitxer de coordenades.
    bool controlCoordenadas;                            ///< Estat de les dades del fitxer de coordenades.
    ModeloCoordenadas *modelo;                          ///< Nom del model de punter modeloCoordenades.
    TableViewCoordinates *punteroTableViewCoordinates;  ///< Nom del punter TableViewCoordinates.

};

#endif // TABLEVIEWCOORDINATES_H
