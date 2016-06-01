#ifndef WIDGETCNP_H
#define WIDGETCNP_H
#include <QWidget>
#include "widgetregistrotp_global.h"
#include "widgetregistro.h"
#include <RegistroTP/registrocnp.h>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class WidgetCNP;
}

class WIDGETREGISTROTPSHARED_EXPORT WidgetCNP : public WidgetRegistro
{
    Q_OBJECT

public:
    explicit WidgetCNP(QWidget *parent = 0);
    ~WidgetCNP();
private slots:

   void selectOutFolder();
   void deleteData();

private:
    Ui::WidgetCNP *ui;
    RegistroCnp *registro;

protected:

    virtual void conectarInterface();
    virtual void desconectarInterface();

    virtual void activarInterface();
    virtual void desactivarInterface();

    virtual void checkEstadoCorreccion();
    virtual void connectRegistro();
    virtual void loadRegistro(QVariantMap mapa);

protected slots:

    void setCnpsEnabled(int s);
    void changeOnCnpsEnabled(bool b);
    void changeOnFolderOut(QString fOut);

};

#endif // WIDGETCNP_H