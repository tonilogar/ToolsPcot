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

private:
    Ui::EditorAmbitoDialog *ui;
    AmbitJson *_archivoAmbito;
};

#endif // EDITORAMBITODIALOG_H
