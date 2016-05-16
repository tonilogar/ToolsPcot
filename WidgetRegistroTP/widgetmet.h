#ifndef WIDGETMET_H
#define WIDGETMET_H

#include <QWidget>
#include "widgetregistrotp_global.h"
#include "widgetregistro.h"
#include <RegistroTP/registromet.h>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class WidgetMet;
}

class WIDGETREGISTROTPSHARED_EXPORT WidgetMet : public WidgetRegistro
{
    Q_OBJECT

public:
    explicit WidgetMet(QWidget *parent = 0);
    ~WidgetMet();
private slots:

   void selectOutFolder();
   void deleteData();
   
private:
    Ui::WidgetMet *ui;
    RegistroMet *registro;
    
protected:

    virtual void conectarInterface();
    virtual void desconectarInterface();
    virtual void activarInterface();
    virtual void desactivarInterface();

    virtual void checkEstadoCorreccion();
    virtual void connectRegistro();
    
protected slots:

    void setMetEnabled(int s);
    void changeOnMetEnabled(bool b);
    void changeOnFolderOut(QString fOut);
};

#endif // WIDGETMET_H
