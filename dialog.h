#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <normal.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие


private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    normal *swWindow;
};

#endif // DIALOG_H
