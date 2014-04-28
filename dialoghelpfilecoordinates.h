#ifndef DIALOGHELPFILECOORDINATES_H
#define DIALOGHELPFILECOORDINATES_H

#include <QDialog>

namespace Ui {
class DialogHelpFilecoordinates;
}

class DialogHelpFilecoordinates : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogHelpFilecoordinates(QWidget *parent = 0);
    ~DialogHelpFilecoordinates();
    
private:
    Ui::DialogHelpFilecoordinates *ui;
};

#endif // DIALOGHELPFILECOORDINATES_H
