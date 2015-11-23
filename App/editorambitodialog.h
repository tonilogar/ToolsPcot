#ifndef EDITORAMBITODIALOG_H
#define EDITORAMBITODIALOG_H

#include <QDialog>
#include <QDebug>
#include <AmbitoTP/ambitjson.h>
#include <AmbitoTP/ambito.h>
#include <QMap>

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


private:
    Ui::EditorAmbitoDialog *ui;
    AmbitJson *_archivoAm;
    QList<Ambito*> _qlistAmbitos;
    QMap<QString,QFileInfo*> _ejecutables;

public slots:
//setters
void showDataAmbito();

};

#endif // EDITORAMBITODIALOG_H
