#ifndef DIALOGOPREFERENCIAS_H
#define DIALOGOPREFERENCIAS_H

#include <QDialog>
#include <QFileDialog>
#include <QSettings>
#include <QDebug>

namespace Ui {
class DialogoPreferencias;
}

class DialogoPreferencias : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoPreferencias(QWidget *parent = 0);
    ~DialogoPreferencias();

    bool isChanged() const
    { return _isChanged; }

    void accept();

private:
    Ui::DialogoPreferencias *ui;
    bool _isChanged;    ///< Bandera de control, si se han producido cambios en las rutas

private slots:

    void buscarArchivoMET();
    void buscarArchivoORTO();
};

#endif // DIALOGOPREFERENCIAS_H
