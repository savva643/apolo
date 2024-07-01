#include "profile.h"
#include "normal.h"
#include "ui_profile.h"
#include "mainwindow.h"
#include <QSettings>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

void delayu( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

profile::profile(const QJsonArray& text, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    ui->label_2->setText(text[1].toString());
    ui->label_3->setText(text[5].toString());
    QEventLoop eventLoope;
        // "quit()" the event-loop, when the network request "finished()"
        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoope, SLOT(quit()));

        // the HTTP request
        QNetworkRequest req( text[4].toString() );
        QNetworkReply *reply = mgr.get(req);
        eventLoope.exec(); // blocks stack until "finished()" has been called

        if (reply->error() == QNetworkReply::NoError) {
            //success
            QByteArray imageData = reply->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio));
        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }
}

profile::~profile()
{
    delete ui;
}

void profile::on_pushButton_clicked()
{
    normal *sWindow = new normal();
    sWindow->setWindowState(Qt::WindowFullScreen);
    sWindow->show();
    delayu(100);
    this->close();
}


void profile::on_quitBtn_2_clicked()
{
    QSettings settings("Keep Pixel", "Apolo");
    settings.setValue("token", "false");
    settings.sync();
    MainWindow *sWindow = new MainWindow();
    sWindow->setWindowState(Qt::WindowFullScreen);
    sWindow->show();
    delayu(100);
    this->close();
}

