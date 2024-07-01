#ifndef RESTARTSTART_H
#define RESTARTSTART_H

#include <QDialog>

namespace Ui {
class restartstart;
}

class restartstart : public QDialog
{
    Q_OBJECT

public:
    explicit restartstart(QWidget *parent = nullptr);
    ~restartstart();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::restartstart *ui;
};

#endif // RESTARTSTART_H
