#ifndef NORMAL_H
#define NORMAL_H

#include <QMainWindow>
#include <QDebug>
#include <QKeyEvent>
#include <QListView>

namespace Ui {
class normal;
}

class normal : public QMainWindow
{
    Q_OBJECT

public:
    explicit normal(QWidget *parent = nullptr);
    ~normal();
    int inar;
    void finmove();

public slots:
    void handleItemClick(int index)
    {
        qDebug() << "Clicked on item at index:" << index;
        inar = index;
    }
    void openweb();
    void closeweb();
signals:
    void firsatWindow();


private slots:
    void timerUpdate();
    void dssd();
    void dssdo();
    void gfdg();
    void gfdgo();
    void hek();
    void logan();
    void closelog();
    void chechqr();
    void loadmain();
    void finispi(int dsd);
    void showWIFI();
    void loadUrl();
    void createwet();
    void on_pushButton_clicked();
    void gdgd(){
        this->close();
    }

    void on_pushButton_2_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_23_clicked();

private:
    Ui::normal *ui;
    void keyPressEvent(QKeyEvent *event);
};

#endif // NORMAL_H
