#ifndef NEWMENU_H
#define NEWMENU_H

#include <QMainWindow>

namespace Ui {
class newmenu;
}

class newmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit newmenu(QWidget *parent = nullptr);
    ~newmenu();

private:
    Ui::newmenu *ui;
};

#endif // NEWMENU_H
