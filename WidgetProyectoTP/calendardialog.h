#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include "widgetproyectotp_global.h"

#include <QDialog>
#include <QDate>

namespace Ui {
class CalendarDialog;
}

class WIDGETPROYECTOTPSHARED_EXPORT CalendarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarDialog(QWidget *parent = 0);
    ~CalendarDialog();
    QDate getSelectDate();
    void setSelectDate(QDate fecha);
private:
    Ui::CalendarDialog *ui;


};

#endif // CALENDARDIALOG_H
