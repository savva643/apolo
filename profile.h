#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>
#include <QJsonArray>
namespace Ui {
class profile;
}

class profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit profile(const QJsonArray& text, QWidget *parent = nullptr);
    ~profile();

private slots:
    void on_pushButton_clicked();

    void on_quitBtn_2_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
