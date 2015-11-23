#ifndef AMBITOWIDGET_H
#define AMBITOWIDGET_H

#include <QWidget>

#include <AmbitoTP/ambito.h>

namespace Ui {
class AmbitoWidget;
}

class AmbitoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AmbitoWidget(QWidget *parent = 0,Ambito *amb=0);
    ~AmbitoWidget();

private:
    Ui::AmbitoWidget *ui;
    Ambito *_ambito;
};

#endif // AMBITOWIDGET_H
