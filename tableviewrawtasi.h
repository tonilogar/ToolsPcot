#ifndef TABLEVIEWRAWTASI_H
#define TABLEVIEWRAWTASI_H

#include <QWidget>

namespace Ui {
    class TableViewRawTasi;
}

class TableViewRawTasi : public QWidget
{
    Q_OBJECT

public:
    explicit TableViewRawTasi(QWidget *parent = 0);
    ~TableViewRawTasi();

private:
    Ui::TableViewRawTasi *ui;
};

#endif // TABLEVIEWRAWTASI_H
