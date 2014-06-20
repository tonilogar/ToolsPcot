#include "correction.h"
#include "ui_correction.h"

Correction::Correction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Correction)
{
    ui->setupUi(this);
}

Correction::~Correction()
{
    delete ui;
}
