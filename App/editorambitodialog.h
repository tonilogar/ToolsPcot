#ifndef EDITORAMBITODIALOG_H
#define EDITORAMBITODIALOG_H

#include <QDialog>

#include <AmbitoTP/ambitjson.h>

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
    AmbitJson *_archivoAmbito;
    public slots:
    void showDialog();
public slots:
//setters

};

#endif // EDITORAMBITODIALOG_H
