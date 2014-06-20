#include "combinecnp.h"
#include "ui_combinecnp.h"

CombineCnp::CombineCnp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombineCnp)
{
    ui->setupUi(this);
}

CombineCnp::~CombineCnp()
{
    delete ui;
    ui->comboBoxCombineCnp->addItem("No seleccionado",-1);
    for (int i=1; i< 11; i++){
        ui->comboBoxCombineCnp->addItem(QString::number(i),i);
    }
}
