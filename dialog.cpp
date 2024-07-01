#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    swWindow = new normal();
        // подключаем к слоту запуска главного окна по кнопке во втором окне
        connect(swWindow, &normal::firsatWindow, this, &Dialog::show);
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_pushButton_2_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow();
}


void Dialog::on_pushButton_3_clicked()
{
    swWindow->setWindowState(Qt::WindowFullScreen);
    swWindow->show();  // Показываем второе окно
    this->close();
}

