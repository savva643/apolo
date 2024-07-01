
#include "gamemenu.h"
#include "game.h"
#include "normal.h"
#include "ui_gamemenu.h"
#include "ImageDownloader.h"
#include <QNetworkReply>
#include <QtWidgets>
#include <QtNetwork>
#include <QTime>
QWidget *dg;
QStringList listi;


QPixmap PixmapToRound(const QPixmap &src, int radius, int w, int h)
{
    if (src.isNull()) {
        return QPixmap();
    }
    QSize size(w, h);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), radius, radius);
    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}

gamemenu::gamemenu(const QStringList& text, const QString& jsonObjecti, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamemenu)
{

    ui->setupUi(this);


    listi = text;
    if(listi[9] == "0"){
        ui->label->setText(text[8]);
        QUrl labeli = text[8];

        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
        ui->label_3->setGraphicsEffect(opacityEffect);
        QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
        animation->setDuration(1); // Animation duration in milliseconds
            // Make the button transparent before showing it
        animation->setStartValue(0.0); // Fully transparent
        animation->setEndValue(0.0); // Destination position// Easing curve for smooth movement

        // Start the animation
        animation->start();
        siyWindow = new game(listi);
        QEventLoop eventLoop;
        connect(ui->pushButton, &QPushButton::clicked, this, &gamemenu::sendVoid);
        // "quit()" the event-loop, when the network request "finished()"
        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        // the HTTP request
        QNetworkRequest req( labeli );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        if (reply->error() == QNetworkReply::NoError) {
            //success
            QByteArray imageData = reply->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            pixmap = PixmapToRound(pixmap, 18, 181, 181);
            ui->label_2->setPixmap(pixmap.scaled(ui->label_2->size(), Qt::KeepAspectRatio));
        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }


        QUrl labely = text[1];
        QEventLoop eventLoopy;
        // "quit()" the event-loop, when the network request "finished()"
        QNetworkAccessManager mgry;
        QObject::connect(&mgry, SIGNAL(finished(QNetworkReply*)), &eventLoopy, SLOT(quit()));

        // the HTTP request
        QNetworkRequest reqy( labely );
        QNetworkReply *replyy = mgry.get(reqy);
        eventLoopy.exec(); // blocks stack until "finished()" has been called
        connect(ui->pushButton, &QPushButton::clicked, this, &gamemenu::dfgdfgfdg);
        if (replyy->error() == QNetworkReply::NoError) {
            //success
            QByteArray imageData = replyy->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            pixmap = PixmapToRound(pixmap, 20, 400, 225);
            ui->label_3->setPixmap(pixmap.scaled(ui->label_3->size(), Qt::KeepAspectRatio));
        }
        else {
            //failure
            qDebug() << "Failure" <<replyy->errorString();
            delete replyy;
        }
    }else{
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
        ui->label_3->setGraphicsEffect(opacityEffect);
        QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
        animation->setDuration(1); // Animation duration in milliseconds
            // Make the button transparent before showing it
        animation->setStartValue(0.0); // Fully transparent
        animation->setEndValue(0.0);
        animation->start();
        ui->label->setText("Браузер");
        QPixmap pixmap(":/new/prefix1/image/web.png");
        pixmap = PixmapToRound(pixmap, 18, 181, 181);
        ui->label_2->setPixmap(pixmap.scaled(ui->label_2->size(), Qt::KeepAspectRatio));
        QPixmap pixmapi(":/new/prefix1/image/biginternet.png");
        pixmapi = PixmapToRound(pixmapi, 20, 400, 225);
        ui->label_3->setPixmap(pixmapi.scaled(ui->label_3->size(), Qt::KeepAspectRatio));


    }


}



gamemenu::~gamemenu()
{
    delete ui;
}
void delayi( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void gamemenu::showdw()
{

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
    ui->label_3->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(600); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animation->setStartValue(0.0); // Fully transparent
    animation->setEndValue(1.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animation->start();
    QPropertyAnimation *animationi = new QPropertyAnimation(ui->label_3, "geometry");
    animationi->setDuration(600); // Animation duration in milliseconds
    animationi->setStartValue(QRect(0, 20, 181, 181)); // Initial position
    animationi->setEndValue(QRect(0, 0, 400, 225)); // Destination position
    animationi->start();
    ui->label_2->pixmap().width();

}
void gamemenu::hidedw()
{
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
    ui->label_3->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(600); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animation->setStartValue(1.0); // Fully transparent
    animation->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animation->start();
    QPropertyAnimation *animationi = new QPropertyAnimation(ui->label_3, "geometry");
    animationi->setDuration(600); // Animation duration in milliseconds
    animationi->setStartValue(QRect(0, 0, 400, 225)); // Initial position
    animationi->setEndValue(QRect(0, 20, 181, 181)); // Destination position
    animationi->start();
}

void gamemenu::dfgdfgfdg()
{
    qDebug()<<"dwada";
    siyWindow->setWindowState(Qt::WindowFullScreen);
    siyWindow->show();
    delayi(200);

}




















