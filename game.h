#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QtNetwork>
#include <QProgressBar>
namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(const QStringList& text, QWidget *parent = nullptr);
    ~game();
signals:
    void firsatyWindow();

private slots:
    void on_pushButton_clicked();

    void on_quitBtn_clicked();



    void on_quitBtn_2_clicked();

    void on_quitBtn_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::game *ui;
    QNetworkReply *reply;
    QProgressBar *progressBar;
    QFile *file;

};

#endif // GAME_H
