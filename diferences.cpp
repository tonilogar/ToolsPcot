#include "diferences.h"
#include "ui_diferences.h"

Diferences::Diferences(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Diferences)
{
    ui->setupUi(this);
}

Diferences::~Diferences()
{
    delete ui;
}
