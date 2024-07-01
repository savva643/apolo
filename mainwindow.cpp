#include "mainwindow.h"
#include "ui_loginstart.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkReply>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTime>
#include <QFile>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);









}

MainWindow::~MainWindow()
{
    delete ui;
}


void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}



void MainWindow::on_quitBtn_clicked()
{
    QSettings settings("Keep Pixel", "Apolo");

    QString text = ui->lineEdit->text();
    QString text2 = ui->lineEdit_2->text();

            QEventLoop eventLoop;

                // "quit()" the event-loop, when the network request "finished()"
                QNetworkAccessManager mgr;
                QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

                // the HTTP request
                QNetworkRequest req( QUrl( QString("http://kompot.site/anlog?login="+text+"&password="+text2) ) );
                QNetworkReply *reply = mgr.get(req);
                eventLoop.exec(); // blocks stack until "finished()" has been called

                if (reply->error() == QNetworkReply::NoError) {
                    //success
                    QByteArray qti = reply->readAll();

                    QJsonParseError err;

                    QJsonDocument jsonDocument = QJsonDocument::fromJson(qti);
                        if (!jsonDocument.isNull() && jsonDocument.isObject())
                        {
                            QJsonObject jsonObject = jsonDocument.object();

                            QString stats = jsonObject["status"].toString();
                            QString token = jsonObject["token"].toString();


                            if (stats == "true"){
                                settings.setValue("token", token);
                                settings.sync();
                                sWindow = new normal();
                                    // подключаем к слоту запуска главного окна по кнопке во втором окне

                                connect(sWindow, &normal::firsatWindow, this, &MainWindow::show);
                                sWindow->setWindowState(Qt::WindowFullScreen);
                                sWindow->show();  // Показываем второе окно
                                delay(200);
                                this->close();    // Закрываем основное окно    rgb(255, 0, 4)
                            }else{
                                ui->label_4->setStyleSheet(QString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 0)); color:rgb(255, 0, 4)"));
                                qDebug() << "nooooof";
                            }

                        }else{
                             qDebug() << "rrrrrrrrrr:" << err.errorString();
                        }

                    delete reply;
                }
                else {
                    //failure
                    qDebug() << "Failure" <<reply->errorString();
                    delete reply;
                }

}




