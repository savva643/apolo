#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QtWidgets>
#include <QtNetwork>
#include <QWidget>
#include <game.h>
#include <normal.h>
namespace Ui {
class gamemenu;
}

class gamemenu : public QWidget
{
    Q_OBJECT

public:
    explicit gamemenu(const QStringList& text,const QString& jsonObjecti, QWidget *parent = nullptr);
    ~gamemenu();
    void showdw();
    void hidedw();

private:
    Ui::gamemenu *ui;
    game *siyWindow;

signals:
    void voidSignal();

private slots:

    void dfgdfgfdg();
    void sendVoid()
        {
            emit voidSignal();
        }
};

#endif // GAMEMENU_H
