#ifndef EDITORAMBITODIALOG_H
#define EDITORAMBITODIALOG_H

#include <QDialog>
#include <QDebug>
#include <AmbitoTP/ambitjson.h>
#include <AmbitoTP/ambito.h>
#include <QMap>
#include <QFileInfo>
#include <QFileDialog>

#include "ambitowidget.h"

#include <AmbitoTP/ambevaluador.h>
#include <AmbitoTP/ambevaluatest.h>
#include <AmbitoTP/ambevextractiontest.h>
#include <AmbitoTP/ambevfootprinttest.h>

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
    QFileInfo getExtraction();
    QFileInfo getSubScene();
    QFileInfo getFootPrintMask();
    QFileInfo getResize();
    QFileInfo getImageOpeGeo();

public slots:
    int exec();

    void accept();
private slots:


    void setExtraction(QString file);
    void setSubScene(QString file);
    void setFootPrintMask(QString file);
    void setResize(QString file);
    void setImageOpeGeo(QString file);

    void selectExtraction();
    void selectSubScene();
    void selectFootPrintMask();
    void selectResize();
    void selectImageOpeGeo();

    void depuracionSalidaEvaluador(bool);

private:
    Ui::EditorAmbitoDialog *ui;
    AmbitJson *_archivoAm;

    QFileInfo _exeExtraction;
    QFileInfo _exeSubScene;
    QFileInfo _exeFootPrintMask;
    QFileInfo _exeResize;
    QFileInfo _exeImageOpeGeo;

    AmbEvaluador *_evaluador;

    void recargarAmbitos();
};

#endif // EDITORAMBITODIALOG_H
