#include "dialogopreferencias.h"
#include "ui_dialogopreferencias.h"

DialogoPreferencias::DialogoPreferencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoPreferencias)
{
    ui->setupUi(this);
}

DialogoPreferencias::~DialogoPreferencias()
{
    delete ui;
}
