#ifndef DIFERENCES_H
#define DIFERENCES_H

#include <QWidget>

namespace Ui {
class Diferences;
}

class Diferences : public QWidget
{
    Q_OBJECT

public:
    explicit Diferences(QWidget *parent = 0);
    ~Diferences();

private:
    Ui::Diferences *ui;
};

#endif // DIFERENCES_H
