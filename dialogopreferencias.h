#ifndef DIALOGOPREFERENCIAS_H
#define DIALOGOPREFERENCIAS_H

#include <QDialog>

namespace Ui {
class DialogoPreferencias;
}

class DialogoPreferencias : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoPreferencias(QWidget *parent = 0);
    ~DialogoPreferencias();

private:
    Ui::DialogoPreferencias *ui;
};

#endif // DIALOGOPREFERENCIAS_H
