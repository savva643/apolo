#include "restartstart.h"
#include "ui_restartstart.h"

restartstart::restartstart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restartstart)
{
    ui->setupUi(this);
}

restartstart::~restartstart()
{
    delete ui;
}

void restartstart::on_pushButton_3_clicked()
{
    system("shutdown -r -t 0");
}


void restartstart::on_pushButton_2_clicked()
{
    system("shutdown -s -t 0");
}


void restartstart::on_pushButton_clicked()
{
    this->close();      // Закрываем окно

}

