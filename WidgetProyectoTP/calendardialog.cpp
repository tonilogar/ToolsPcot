#include "calendardialog.h"
#include "ui_calendardialog.h"

CalendarDialog::CalendarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarDialog)
{
    ui->setupUi(this);
    ui->calendarWidget->showToday();
}

CalendarDialog::~CalendarDialog()
{
    delete ui;
}
QDate CalendarDialog::getSelectDate()
{
return ui->calendarWidget->selectedDate();
}
void CalendarDialog::setSelectDate(QDate fecha)
{
  ui->calendarWidget->setSelectedDate(fecha);
}
