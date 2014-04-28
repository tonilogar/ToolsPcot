#ifndef FICHEROSRAW_H
#define FICHEROSRAW_H

#include <QWidget>

namespace Ui {
    class FicherosRaw;
}

class FicherosRaw : public QWidget
{
    Q_OBJECT

public:
    explicit FicherosRaw(QWidget *parent = 0);
    ~FicherosRaw();

private:
    Ui::FicherosRaw *ui;
};

#endif // FICHEROSRAW_H
