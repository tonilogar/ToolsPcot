#ifndef COMBINECNP_H
#define COMBINECNP_H

#include <QWidget>
/*!
 * @class CombineCnp
 * @brief CombineCnp
 * Combinar els fitxers de punts control i punt de enllaç cnp per generar els fitxers *.cl *.xyz.
 *
 */
namespace Ui {
class CombineCnp;
}

class CombineCnp : public QWidget
{
    Q_OBJECT

public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit CombineCnp(QWidget *parent = 0);
    ~CombineCnp();

private:
    Ui::CombineCnp *ui;
};

#endif // COMBINECNP_H
