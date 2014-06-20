#ifndef CORRECTION_H
#define CORRECTION_H

#include <QWidget>

namespace Ui {
class Correction;
}

class Correction : public QWidget
{
    Q_OBJECT

public:
    explicit Correction(QWidget *parent = 0);
    ~Correction();

private:
    Ui::Correction *ui;
};

#endif // CORRECTION_H
