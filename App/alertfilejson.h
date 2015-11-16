#ifndef ALERTFILEJSON_H
#define ALERTFILEJSON_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QSettings>
#include "dialogpre.h"
/*!
 * @class AlertFileJson
 * @brief AlertFileJson
 * Finestra d'alerta para seleccionar o crear ficher de preferencies Json.
 *
 */
namespace Ui {
class AlertFileJson;
}

class AlertFileJson : public QDialog
{
    Q_OBJECT

public:
    /*!
     * Constructor es necessari un punter nul.
     */
    explicit AlertFileJson(QWidget *parent = 0);
    /*!
     * Destructor  per defecte.
     */
    ~AlertFileJson();

private:
    Ui::AlertFileJson *ui;

    DialogPre *_objetoDialogoPr;
private slots:
    /*!
     * Lanza una ventana para seleccionar el fichero Json de preferencias.
     */
    void selectJson();
    void createJson();
    void cancel();
};

#endif // ALERTFILEJSON_H
