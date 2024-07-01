#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <normal.h>
#include <QTimer>
#include <QList>
#include <QInputDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quitBtn_clicked();

private:
    Ui::MainWindow *ui;
    normal *sWindow;
};



#endif // MAINWINDOW_H
