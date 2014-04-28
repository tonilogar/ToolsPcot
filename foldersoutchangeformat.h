#ifndef FOLDERSOUTCHANGEFORMAT_H
#define FOLDERSOUTCHANGEFORMAT_H

#include <QWidget>
#include "registrofolderoutchangeformat.h"

namespace Ui {
    class FoldersOutChangeFormat;
}

class FoldersOutChangeFormat : public QWidget
{
    Q_OBJECT

public:
    explicit FoldersOutChangeFormat(QWidget *parent = 0);
    ~FoldersOutChangeFormat();
    RegistroFolderOutChangeFormat * getObjetoRegistroFolOut();

signals:

void cambioEstadoFoldersOut(bool state);

private slots:

    void on_pushButtonAtt_clicked();

    void on_pushButtonPix_clicked();

    void on_pushButtonAtp_clicked();

    void on_pushButtonRf_clicked();

    void on_pushButtonJpg_clicked();

    void comprobarEstado();

private:
    Ui::FoldersOutChangeFormat *ui;
    RegistroFolderOutChangeFormat *punteroRegistroFolderOut;
};

#endif // FOLDERSOUTCHANGEFORMAT_H
