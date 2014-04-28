#ifndef DIALOGORAW_H
#define DIALOGORAW_H

#include <QDialog>

namespace Ui {
class DialogoRaw;
}

class DialogoRaw : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoRaw(QWidget *parent = 0);
    ~DialogoRaw();

private slots:
    void on_pushButtonCancel_clicked();

private:
    Ui::DialogoRaw *ui;
};

#endif // DIALOGORAW_H
