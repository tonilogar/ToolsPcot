#ifndef COMBINECNP_H
#define COMBINECNP_H

#include <QWidget>

namespace Ui {
class CombineCnp;
}

class CombineCnp : public QWidget
{
    Q_OBJECT

public:
    explicit CombineCnp(QWidget *parent = 0);
    ~CombineCnp();

private:
    Ui::CombineCnp *ui;
};

#endif // COMBINECNP_H
