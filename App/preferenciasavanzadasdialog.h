#ifndef PREFERENCIASAVANZADASDIALOG_H
#define PREFERENCIASAVANZADASDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QFileDialog>
#include <dialogpre.h>

namespace Ui {
class PreferenciasAvanzadasDialog;
}

class PreferenciasAvanzadasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferenciasAvanzadasDialog(QWidget *parent = 0);
    ~PreferenciasAvanzadasDialog();

public slots:

    void reload();

private:
    Ui::PreferenciasAvanzadasDialog *ui;

    void setup();
    DialogPre *_objetoDialogoPrefe;///< Puntero de la clase DialogPre, es una clase con entorno grafico para poder seleccionar los ficheros que no se encuentran.
private slots:

    void selectAmbitoFile();
    void editPreferences();


};

#endif // PREFERENCIASAVANZADASDIALOG_H
