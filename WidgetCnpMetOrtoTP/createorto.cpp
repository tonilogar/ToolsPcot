#include "createorto.h"
#include "ui_createorto.h"

CreateOrto::CreateOrto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOrto)
{
    ui->setupUi(this);
}

CreateOrto::~CreateOrto()
{
    delete ui;
}
