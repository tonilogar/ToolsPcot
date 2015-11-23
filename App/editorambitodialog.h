#ifndef EDITORAMBITODIALOG_H
#define EDITORAMBITODIALOG_H

#include <QDialog>
#include <QDebug>
#include <AmbitoTP/ambitjson.h>
#include <AmbitoTP/ambito.h>
#include <QMap>

#include "ambitowidget.h"

namespace Ui {
class EditorAmbitoDialog;
}

class EditorAmbitoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditorAmbitoDialog(QWidget *parent = 0,AmbitJson *archivoAmb=0);
    ~EditorAmbitoDialog();
   //Getter

public slots:

    int exec();


private:
    Ui::EditorAmbitoDialog *ui;
    AmbitJson *_archivoAm;

public slots:

private:

    void recargarAmbitos();

};

#endif // EDITORAMBITODIALOG_H
