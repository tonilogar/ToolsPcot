#ifndef TABLEVIEWRAWTASI_H
#define TABLEVIEWRAWTASI_H

#include <QWidget>
/*!
 * @class TableViewRawTasi
 * @brief Interfice grafica per els fitxers raw dels sensors tasi.
 *
 */
namespace Ui {
    class TableViewRawTasi;
}

class TableViewRawTasi : public QWidget
{
    Q_OBJECT

public:
    /*!
     * Constructor per defecte,necesita un punter nul, clase en construcció
     */
    explicit TableViewRawTasi(QWidget *parent = 0);
    ~TableViewRawTasi();

private:
    Ui::TableViewRawTasi *ui;
};

#endif // TABLEVIEWRAWTASI_H
