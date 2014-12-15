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
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit TableViewRaw(QWidget *parent = 0);
    ~TableViewRaw();

    void selectFilesRaw();
    /*!
     * Mostra els fitxers *.raw seleccionats.
     *
     */
    QStringList sowFilesRaw();
    /*!
     * Filtrar les seleccions.
     *
     */
    void chekingFilesRaw();
    /*!
     * Mostrar el model per omplir el tabletview.
     *
     */
    void sowModelTableView();
    /*!
     * Borrar les dades del tabletView.
     *
     */
    void deleteTableViewRaw();
    /*!
     * Mostrar missatge d'advertència.
     *
     */
    void mostrarQMessageBox(QString);
    /*!
     *Mostrar i donar valor al model.
     *
     */
    ModeloRaw *getModeloRaw();
signals:
    /*!
    *Senyal per activar o desactivar les opcions gràfiques de les operacions cnp.
    *
     */
    void filledTableView(bool state);
    /*!
    *Senyal per activar o desactivar les opcions gràfiques de les operacions cnp.
    *
    */
    void cambioEstadoRaw(bool state);


private slots:
    /*!
    *Selecciona comprovar i crea el model dels fitxers raw.
    *
    */
    void on_pushButtonSeleccionarRaw_clicked();
    /*!
    *Borrar dades del tabletviewRaw.
    *
    */
    void on_pushButtonBorrarListadoRaw_clicked();
    /*!
    *Seleccionar fitxer *.rad.
    *
    */
    void on_pushButtonFicheroRad_clicked();

    /*!
    *Comprovar que totes les dades són correctes.
    *
    */
    void evaluarWidget();

    /*!
    *Canvia l'estat del model.
    *
    */
    void setEstadoModelo(bool estado);

    /*!
    *Canvia l'estat del widget.
    *
    */
    void setEstadoWidget(bool estado);
    /*!
    *Selecciona el fitxer radcor.
    *
    */
    void on_pushButtonFicheroRadcor_clicked();

    /*!
    *Selecciona el fitxer Attsync.
    *
    */
    void on_pushButtonFicheroAttsync_clicked();

private:
    Ui::TableViewRaw *ui;                ///< Nom del interface grafica.
    QStringList filesRaw;                ///< Nom del llistat de fitxers *.raw.
    QStandardItemModel *modeloRaw;       ///< Nom del model de fitxers *.raw.
    QStringList ListFilesGlobalRaw;      ///< Nom del llistat de fitxers *.raw per comprobar les seleccions.
    bool controlRaw;                     ///< Estat de les dades raw.
    ModeloRaw *modelo;                   ///< Nom del model de punter modeloRaw.
    bool _estadoactual;                  ///< Estat actual tableviewRaw
    bool _estadoWidgets;                 ///< Estat widget
    bool _estadoModelo;                  ///< Estat model
    void evaluaEstadoGeneral();          ///< Evaluar estat de les dades raw.
    void evaluaEstadoRaw();              ///Comprobara el estado de widget y el estado de modelo.
    QString _rename;
};

#endif // TABLEVIEWRAW_H
