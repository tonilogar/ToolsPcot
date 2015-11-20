#ifndef PREFERENCIASAVANZADASDIALOG_H
#define PREFERENCIASAVANZADASDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QFileDialog>

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

signals:
    void comprobarFileJson();

private:
    Ui::PreferenciasAvanzadasDialog *ui;

    void setup();
private slots:

    void selectAmbitoFile();
    void editPreferences();


};

#endif // PREFERENCIASAVANZADASDIALOG_H
