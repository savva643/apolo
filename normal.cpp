#include "normal.h"
#include "profile.h"
#include "gamemenu.h"
#include "ui_normal.h"
#include <QStandardItemModel>
#include <QLabel>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <QTextStream>
#include <windows.h>
#include <wlanapi.h>
#include <iostream>
#include <QVideoWidget>
#include <QWebEngineView>
// Link with Wlanapi.lib
#pragma comment(lib, "wlanapi.lib")
QPixmap PixmapToRoundi(const QPixmap &src, int radius, int w, int h)
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
QJsonArray jsonObjecty;
int currentIndex = 0;
QJsonArray arrayis;
bool isopendmenu = false;
bool isopenrg = false;
normal::normal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::normal)
{
    ui->setupUi(this);


    QGraphicsOpacityEffect *opacityEffectl;
    opacityEffectl = new QGraphicsOpacityEffect(this);
    ui->widget_6->setGraphicsEffect(opacityEffectl);
    QPropertyAnimation *animationl = new QPropertyAnimation(opacityEffectl, "opacity");
    animationl->setDuration(1); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationl->setStartValue(0.0); // Fully transparent
    animationl->setEndValue(0.0); // Destination position// Easing curve for smooth movement
    animationl->start();

    QGraphicsOpacityEffect *opacityEffect;
    opacityEffect = new QGraphicsOpacityEffect(this);
    ui->widget_4->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(1); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animation->setStartValue(0.0); // Fully transparent
    animation->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animation->start();

    QMediaPlayer *player = new QMediaPlayer(this);
    QGraphicsVideoItem *item = new QGraphicsVideoItem;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsView *graphicsView = new QGraphicsView(scene);
    player->setVideoOutput(item);
    graphicsView->scene()->addItem(item);
    ui->gridLayout->addWidget(graphicsView);
    player->setSource(QUrl("qrc:/new/prefix2/image/backg.mp4"));
    graphicsView->setStyleSheet("border-radius:0px");
    QSize size = qApp->screens()[0]->size();
    ui->gridLayout->setGeometry(QRect(0,0,size.width(),size.height()));
    graphicsView->setGeometry(0,0,size.width(),size.height());
    scene->setSceneRect(0,0,size.width(),size.height());
    item->setSize(QSize(size.width(),size.height()));
    graphicsView->setSceneRect(0,0,size.width(),size.height());
    player->play();
    player->setLoops(QMediaPlayer::Infinite);

    QGraphicsOpacityEffect *opacityEffectg;
    opacityEffectg = new QGraphicsOpacityEffect(this);
    ui->widget_8->setGraphicsEffect(opacityEffectg);
    QPropertyAnimation *animationg = new QPropertyAnimation(opacityEffectg, "opacity");
    animationg->setDuration(1); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationg->setStartValue(0.0); // Fully transparent
    animationg->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationg->start();

    QGraphicsOpacityEffect *opacityEffectgi;
    opacityEffectgi = new QGraphicsOpacityEffect(this);
    ui->widget_2->setGraphicsEffect(opacityEffectgi);
    QPropertyAnimation *animationgi = new QPropertyAnimation(opacityEffectgi, "opacity");
    animationgi->setDuration(1); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationgi->setStartValue(0.0); // Fully transparent
    animationgi->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationgi->start();

    QWebEngineView *view = new QWebEngineView();
    view->setUrl(QUrl("https://ya.ru"));
    int tabIndex = ui->tabWidget->addTab(view,"Загрузка");
    QToolButton *button1 = new QToolButton();
    button1->setIcon(QIcon(":/new/prefix1/image/plus.png"));
    ui->tabWidget->setCornerWidget(button1, Qt::TopRightCorner);
    connect(button1, &QPushButton::clicked, this, &normal::createwet);

    connect(view, &QWebEngineView::titleChanged, this, [this, tabIndex](const QString &title) {
        ui->tabWidget->setTabText(tabIndex, title);
    });
    connect(view, &QWebEngineView::iconChanged, this, [this, tabIndex](const QIcon &title) {
        ui->tabWidget->setTabIcon(tabIndex, title);
    });
    ui->lineEdit->setText(view->url().toString());
    connect(ui->tabWidget, &QTabWidget::tabBarClicked, this, [=]() { ui->lineEdit->setText(view->url().toString());  });
    connect(ui->lineEdit, &QLineEdit::editingFinished, this, &normal::loadUrl);



    QGraphicsOpacityEffect *opacityEffectgih;
    opacityEffectgih = new QGraphicsOpacityEffect(this);
    ui->widget_9->setGraphicsEffect(opacityEffectgih);
    QPropertyAnimation *animationgih = new QPropertyAnimation(opacityEffectgih, "opacity");
    animationgih->setDuration(1); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationgih->setStartValue(0.0); // Fully transparent
    animationgih->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationgih->start();

    QSettings settings("Keep Pixel", "Apolo");
    QString tr = settings.value("token", "false").toString();
    qDebug() << tr;
    if (tr == "false"){
        QTimer::singleShot(2000, this, &normal::logan);
    }else{

        QTimer::singleShot(2000, this, &normal::loadmain);
    }


}

void normal::loadmain(){
    ui->widget_9->raise();
    ui->widget_8->lower();
    QGraphicsOpacityEffect *opacityEffectgih;
    opacityEffectgih = new QGraphicsOpacityEffect(this);
    ui->widget_2->setGraphicsEffect(opacityEffectgih);
    QPropertyAnimation *animationgih = new QPropertyAnimation(opacityEffectgih, "opacity");
    animationgih->setDuration(400); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationgih->setStartValue(0.0); // Fully transparent
    animationgih->setEndValue(1.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationgih->start();
    QPropertyAnimation *animationie = new QPropertyAnimation(ui->widget_2, "geometry");
    animationie->setDuration(400); // Animation duration in milliseconds
    animationie->setStartValue(QRect(0, -600, 2560, 1440)); // Initial position
    animationie->setEndValue(QRect(0, 0, 2560, 1440));  // Destination position
    animationie->start();
    QEventLoop eventLoopi;
    QSettings settings("Keep Pixel", "Apolo");
    QString tr = settings.value("token", "false").toString();
    qDebug() << ":dsaasddsa" <<tr;
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgri;
    QObject::connect(&mgri, SIGNAL(finished(QNetworkReply*)), &eventLoopi, SLOT(quit()));
    // the HTTP request
    QNetworkRequest reqi( QUrl( QString("http://keeppixel.store/getabout?token="+tr) ) );
    QNetworkReply *replyi = mgri.get(reqi);
    eventLoopi.exec(); // blocks stack until "finished()" has been called
    if (replyi->error() == QNetworkReply::NoError) {
        //success
        QByteArray qti = replyi->readAll();
        QJsonParseError err;
        if (qti != "false"){
            QJsonDocument jsonDocument = QJsonDocument::fromJson(qti, &err);

            QJsonArray jsonObject = jsonDocument.array();
            jsonObjecty = jsonObject;
            QEventLoop eventLoope;
            // "quit()" the event-loop, when the network request "finished()"
            QNetworkAccessManager mgr;
            QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoope, SLOT(quit()));
            qDebug() << jsonObject[4].toString();
            // the HTTP request
            QNetworkRequest req( jsonObject[4].toString() );
            QNetworkReply *reply = mgr.get(req);
            eventLoope.exec(); // blocks stack until "finished()" has been called
            ui->label_5->setText(jsonObject[1].toString());
            ui->label_12->setText(jsonObject[1].toString());
            if (reply->error() == QNetworkReply::NoError) {
                //success
                QByteArray imageData = reply->readAll();
                QPixmap pixmap;
                pixmap.loadFromData(imageData);
                pixmap = PixmapToRoundi(pixmap, 200, 400, 400);
                ui->pushButton_2->setIcon(QIcon(pixmap));
                ui->pushButton_11->setIcon(QIcon(pixmap));
                ui->pushButton_13->setIcon(QIcon(pixmap));
            }
            else {
                //failure
                qDebug() << "Failure" <<reply->errorString();
                delete reply;
            }

        }else{
            qDebug() << "nooooof";
        }
        delete replyi;
    }
    else {
        //failure
        qDebug() << "Failure" <<replyi->errorString();
        delete replyi;
    }




    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    QSize size = qApp->screens()[0]->size();
    ui->widget_2->setGeometry(0,0,size.width(),size.height());
    ui->label_7->adjustSize();
    ui->label_8->adjustSize();
    ui->label_9->adjustSize();
    ui->label_4->setMaximumWidth(ui->label_7->geometry().width()+26);
    ui->label->setMaximumWidth(ui->label_9->geometry().width()+26);
    ui->label_3->setMaximumWidth(ui->label_8->geometry().width()+26);
    ui->label_4->setMinimumWidth(ui->label_7->geometry().width()+26);
    ui->label->setMinimumWidth(ui->label_9->geometry().width()+26);
    ui->label_3->setMinimumWidth(ui->label_8->geometry().width()+26);
    QEventLoop eventLoop;
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req( QUrl( QString("http://keeppixel.store/getgamesyou?token="+tr) ) );
    QNetworkReply *reply = mgr.get(req);

    eventLoop.exec(); // blocks stack until "finished()" has been called
    if (reply->error() == QNetworkReply::NoError) {
        //success
        QByteArray qti = reply->readAll();

        QJsonParseError err;
        if (qti != "false"){
            QJsonDocument jsonDocument = QJsonDocument::fromJson(qti, &err);
            if (!jsonDocument.isNull() && jsonDocument.isObject())
            {
                QJsonObject jsonObject = jsonDocument.object();

                QJsonArray arrayi = jsonObject["epol"].toArray();
                arrayis = arrayi;
                int nop = jsonObject["num"].toInt();
                for(int i = 0; i < nop; i++)
                {
                    QJsonObject jsonObjecti = arrayi[i].toObject();
                    QString nim = jsonObjecti["name"].toString();
                    QString imi = jsonObjecti["img"].toString();
                    QString cmd = jsonObjecti["cmd"].toString();
                    QString filei = jsonObjecti["file"].toString();
                    QString opica = jsonObjecti["opic"].toString();
                    QString componya = jsonObjecti["compony"].toString();
                    QString papki = jsonObjecti["papka"].toString();
                    QString idi = jsonObjecti["id"].toString();
                    QString ici = jsonObjecti["icon"].toString();
                    QString icie = jsonObjecti["icontext"].toString();
                    QString sysi = "0";
                    QStringList list;
                    list.append(nim);
                    list.append(imi);
                    list.append(cmd);
                    list.append(filei);
                    list.append(opica);
                    list.append(componya);
                    list.append(papki);
                    list.append(idi);
                    list.append(ici);
                    list.append(sysi);
                    gamemenu *w = new gamemenu(list, arrayi[i].toString());
                    connect(w, &gamemenu::voidSignal, this, &normal::gdgd);
                    ui->horizontalLayout->layout()->addWidget(w);
                    if(i==0){
                        w->setMinimumSize(400,225);
                        w->showdw();
                        QUrl labely = icie;
                        QEventLoop eventLoopy;
                        // "quit()" the event-loop, when the network request "finished()"
                        QNetworkAccessManager mgry;
                        QObject::connect(&mgry, SIGNAL(finished(QNetworkReply*)), &eventLoopy, SLOT(quit()));

                        // the HTTP request
                        QNetworkRequest reqy( labely );
                        QNetworkReply *replyy = mgry.get(reqy);
                        eventLoopy.exec(); // blocks stack until "finished()" has been called

                        if (replyy->error() == QNetworkReply::NoError) {
                            //success
                            QByteArray imageData = replyy->readAll();
                            QPixmap pixmap;
                            pixmap.loadFromData(imageData);
                            ui->label_6->setPixmap(pixmap.scaled(ui->label_6->size(), Qt::KeepAspectRatio));
                        }
                        else {
                            //failure
                            qDebug() << "Failure" <<replyy->errorString();
                            delete replyy;
                        }
                    }else{
                        w->setMinimumSize(181,225);
                    }
                    ui->horizontalLayout->setAlignment(Qt::AlignLeft);

                }
                QStringList list;
                list.append("1");
                list.append("1");
                list.append("1");
                list.append("1");
                list.append("1");
                list.append("1");
                list.append("1");
                list.append("1");
                list.append("1");
                list.append("1");
                gamemenu *w = new gamemenu(list, "j");
                ui->horizontalLayout->layout()->addWidget(w);
                w->setMinimumSize(181,225);
                QPushButton *myButton = w->findChild<QPushButton*>("pushButton");
                if (myButton) {
                    // Connect the button's clicked signal to the slot
                    connect(myButton, &QPushButton::clicked, this, &normal::openweb);
                } else {
                    qDebug() << "Button not found!";
                }

                //listView->setModel(model);
                //ui->verticalLayout_2->addWidget(listView);
            }else{
                qDebug() << "rrrrrrrrrr:" << err.errorString();
            }
        }else{
            qDebug() << "nooooof";
        }
        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
    ui->widget_2->raise();
    ui->widget_8->lower();


}

bool wasopened = false;
bool canmove = true;
bool lockopen = false;
bool openapp = false;
QString qrhash;

void normal::finmove(){
    canmove = true;
}

void normal::logan(){
    QGraphicsOpacityEffect *opacityEffectgih;
    opacityEffectgih = new QGraphicsOpacityEffect(this);
    ui->widget_9->setGraphicsEffect(opacityEffectgih);
    QPropertyAnimation *animationgih = new QPropertyAnimation(opacityEffectgih, "opacity");
    animationgih->setDuration(400); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationgih->setStartValue(0.0); // Fully transparent
    animationgih->setEndValue(1.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationgih->start();
    QPropertyAnimation *animationie = new QPropertyAnimation(ui->widget_9, "geometry");
    animationie->setDuration(200); // Animation duration in milliseconds
    animationie->setStartValue(QRect(880, 0, 2560, 1440)); // Initial position
    animationie->setEndValue(QRect(0, 0, 2560, 1440));  // Destination position
    animationie->start();
    ui->widget_9->raise();
    ui->widget_8->lower();
    QEventLoop eventLoopi;
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgri;
    QObject::connect(&mgri, SIGNAL(finished(QNetworkReply*)), &eventLoopi, SLOT(quit()));
    // the HTTP request
    QNetworkRequest reqi( QUrl( QString("http://keeppixel.store/blastlog?ser=apolo") ) );
    QNetworkReply *replyi = mgri.get(reqi);
    eventLoopi.exec(); // blocks stack until "finished()" has been called
    if (replyi->error() == QNetworkReply::NoError) {
        //success
        QByteArray qti = replyi->readAll();
        QJsonParseError err;
        if (qti != "false"){
            QJsonDocument jsonDocument = QJsonDocument::fromJson(qti, &err);

            QJsonArray jsonObject = jsonDocument.array();
            QEventLoop eventLoope;
            // "quit()" the event-loop, when the network request "finished()"
            QNetworkAccessManager mgr;
            QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoope, SLOT(quit()));
            qDebug() << jsonObject[0].toString();
            // the HTTP request
            QNetworkRequest req( jsonObject[0].toString() );
            QNetworkReply *reply = mgr.get(req);
            eventLoope.exec(); // blocks stack until "finished()" has been called
            qrhash = jsonObject[1].toString();
            if (reply->error() == QNetworkReply::NoError) {
                //success
                QByteArray imageData = reply->readAll();
                QPixmap pixmap;
                qDebug() << "asasdasdas";
                pixmap.loadFromData(imageData);
                pixmap = PixmapToRoundi(pixmap, 35, 480, 480);
                ui->label_21->setPixmap(pixmap);
                QTimer::singleShot(1000, this, &normal::chechqr);
            }
            else {
                //failure
                qDebug() << "Failure" <<reply->errorString();
                delete reply;
            }

        }else{
            qDebug() << "nooooof";
        }
        delete replyi;
    }
    else {
        //failure
        qDebug() << "Failure" <<replyi->errorString();
        delete replyi;
    }
}

void normal::closelog(){
    QGraphicsOpacityEffect *opacityEffectgih;
    opacityEffectgih = new QGraphicsOpacityEffect(this);
    ui->widget_9->setGraphicsEffect(opacityEffectgih);
    QPropertyAnimation *animationgih = new QPropertyAnimation(opacityEffectgih, "opacity");
    animationgih->setDuration(400); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationgih->setStartValue(1.0); // Fully transparent
    animationgih->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationgih->start();
    QPropertyAnimation *animationie = new QPropertyAnimation(ui->widget_9, "geometry");
    animationie->setDuration(200); // Animation duration in milliseconds
    animationie->setStartValue(QRect(0, 0, 2560, 1440)); // Initial position
    animationie->setEndValue(QRect(880, 0, 2560, 1440));  // Destination position
    animationie->start();

    QTimer::singleShot(1000, this, &normal::loadmain);
}

void normal::createwet(){
    QWebEngineView *view = new QWebEngineView();
    view->setUrl(QUrl("https://ya.ru"));
    int tabIndex = ui->tabWidget->addTab(view,"Загрузка");
    connect(view, &QWebEngineView::titleChanged, this, [this, tabIndex](const QString &title) {
        ui->tabWidget->setTabText(tabIndex, title);
    });
    connect(view, &QWebEngineView::iconChanged, this, [this, tabIndex](const QIcon &title) {
        ui->tabWidget->setTabIcon(tabIndex, title);
    });
}
void normal::loadUrl()
{
    QString urlText = ui->lineEdit->text();
    if (!urlText.startsWith("http://") && !urlText.startsWith("https://")) {
        urlText = "https://ya.ru/search/?text=" + urlText;
    }

    QUrl url(urlText);
    if (url.isValid()) {
        QWebEngineView *currentWebView = qobject_cast<QWebEngineView *>(ui->tabWidget->currentWidget());
        if (currentWebView) {
            currentWebView->setUrl(url);
        }
    } else {
        // Handle invalid URL input
        ui->lineEdit->setText("Invalid URL");
    }
}

QPushButton *buttonplaui;
void normal::openweb(){
    qDebug() << "dfsaadsdsa";
    openapp = true;
    QGraphicsOpacityEffect *opacityEffectg;
    opacityEffectg = new QGraphicsOpacityEffect(this);
    ui->widget_8->setGraphicsEffect(opacityEffectg);
    QPropertyAnimation *animationg = new QPropertyAnimation(opacityEffectg, "opacity");
    animationg->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationg->setStartValue(0.0); // Fully transparent
    animationg->setEndValue(1.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationg->start();
    QPropertyAnimation *animationie = new QPropertyAnimation(ui->widget_8, "geometry");
    animationie->setDuration(200); // Animation duration in milliseconds
    animationie->setStartValue(QRect(880, 495, 800, 450)); // Initial position
    animationie->setEndValue(QRect(0, 0, 2560, 1440));  // Destination position
    animationie->start();

    ui->widget_8->raise();
    buttonplaui= new QPushButton();
    QIcon buttonIcon(":/new/prefix1/image/play.png");
    buttonplaui->setIcon(buttonIcon);

    // Optional: Adjust the size of the icon and button
    buttonplaui->setIconSize(QSize(64, 64));  // Size of the icon
    buttonplaui->setFixedSize(80, 60);
    ui->horizontalLayout_2->insertWidget(3,buttonplaui);
    connect(buttonplaui, &QPushButton::clicked, this, &normal::hek);

}


void normal::closeweb(){
    qDebug() << "dfsaadsdsa";
openapp = false;
    wasopened = true;
    QGraphicsOpacityEffect *opacityEffectg;
    opacityEffectg = new QGraphicsOpacityEffect(this);
    ui->widget_8->setGraphicsEffect(opacityEffectg);
    QPropertyAnimation *animationg = new QPropertyAnimation(opacityEffectg, "opacity");
    animationg->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationg->setStartValue(1.0); // Fully transparent
    animationg->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationg->start();
    QPropertyAnimation *animationie = new QPropertyAnimation(ui->widget_8, "geometry");
    animationie->setDuration(200); // Animation duration in milliseconds
    animationie->setStartValue(QRect(0, 0, 2560, 1440)); // Initial position
    animationie->setEndValue(QRect(880, 495, 800, 450));  // Destination position
    animationie->start();


     hek();
}


void normal::showWIFI()
{
    HANDLE hClient = NULL;
    DWORD dwMaxClient = 2; // Version 2 of the API
    DWORD dwCurVersion = 0;
    DWORD dwResult = 0;
    int signalLevel = -1;

    // Initialize the handle
    dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
    if (dwResult != ERROR_SUCCESS) {
        qDebug() << "WlanOpenHandle failed with error: " << dwResult;

    }

    // Enumerate wireless interfaces
    PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
    PWLAN_INTERFACE_INFO pIfInfo = NULL;
    dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
    if (dwResult != ERROR_SUCCESS) {
        qDebug() << "WlanEnumInterfaces failed with error: " << dwResult;
        WlanCloseHandle(hClient, NULL);

    }

    // Get the first interface (assuming there is at least one interface)
    if (pIfList->dwNumberOfItems > 0) {
        pIfInfo = &pIfList->InterfaceInfo[0];

        PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
        dwResult = WlanGetAvailableNetworkList(hClient, &pIfInfo->InterfaceGuid, 0, NULL, &pBssList);
        if (dwResult == ERROR_SUCCESS) {
            // Iterate over the list of available networks
            for (unsigned int i = 0; i < pBssList->dwNumberOfItems; i++) {
                PWLAN_AVAILABLE_NETWORK pBssEntry = &pBssList->Network[i];
                if (pBssEntry->bNetworkConnectable) {
                    // Assume connected network and get its signal level
                    signalLevel = pBssEntry->wlanSignalQuality;
                    break;
                }
            }
            WlanFreeMemory(pBssList);
        } else {
            qDebug() << "WlanGetAvailableNetworkList failed with error: " << dwResult;
        }
    }

    if (pIfList != NULL) {
        WlanFreeMemory(pIfList);
    }

    if (hClient != NULL) {
        WlanCloseHandle(hClient, NULL);
    }


    if(signalLevel < 34){
        QPixmap pixmap(":/new/prefix1/image/wife1.png");
        ui->pushButton_5->setIcon(QIcon(pixmap));
    }else if (signalLevel < 67){
        QPixmap pixmap(":/new/prefix1/image/wife2.png");
        ui->pushButton_5->setIcon(QIcon(pixmap));
    }else if (signalLevel <= 100){
        QPixmap pixmap(":/new/prefix1/image/wife3.png");
        ui->pushButton_5->setIcon(QIcon(pixmap));
    }
}

void normal::timerUpdate()
{
    QString nop = QTime::currentTime().toString("hh:mm");
    ui->label_2->setText(nop);
    showWIFI();
}

void normal::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_D){
        if(!isopenrg && !isopendmenu){
            if(canmove == true && lockopen == false){
                if((ui->horizontalLayout->layout()->count()-1) > currentIndex){
                    canmove = false;
                    QWidget *ds = ui->horizontalLayout->layout()->itemAt(currentIndex)->widget();
                    if (gamemenu *myWidget = qobject_cast<gamemenu *>(ds)) {
                        myWidget->hidedw();
                    }

                    // ds->setFixedSize(181,181);
                    QPropertyAnimation *animation = new QPropertyAnimation(ui->horizontalLayout->layout()->itemAt(currentIndex)->widget(), "minimumSize");
                    animation->setDuration(600); // Animation verticalLayout_2 in milliseconds
                    animation->setStartValue((QSize(400,225))); // Initial position
                    animation->setEndValue((QSize(181,225))); // Destination position
                    animation->setEasingCurve(QEasingCurve::InOutQuad); // Easing curve for smooth movement
                    // Start the animation
                    animation->start();
                    currentIndex = currentIndex + 1;
                    QPropertyAnimation *animationi = new QPropertyAnimation(ui->horizontalLayout->layout()->itemAt(currentIndex)->widget(), "minimumSize");
                    animationi->setDuration(600); // Animation duration in milliseconds
                    animationi->setStartValue(QSize(181,225)); // Initial position
                    animationi->setEndValue((QSize(400,225))); // Destination position
                    animationi->setEasingCurve(QEasingCurve::InOutQuad); // Easing curve for smooth movement

                    // Start the animation
                    animationi->start();
                    if (gamemenu *myWidget = qobject_cast<gamemenu *>(ui->horizontalLayout->layout()->itemAt(currentIndex)->widget())) {
                        myWidget->showdw();
                    }
                    // ui->horizontalLayout->layout()->itemAt(currentIndex)->widget()->setFixedSize(400,181);
                    connect(animation, &QPropertyAnimation::finished, this, &normal::finmove);
                }

                QJsonObject jsonObjecti = arrayis[currentIndex].toObject();
                QString icie = jsonObjecti["icontext"].toString();
                QUrl labely = icie;
                QEventLoop eventLoopy;
                // "quit()" the event-loop, when the network request "finished()"
                QNetworkAccessManager mgry;
                QObject::connect(&mgry, SIGNAL(finished(QNetworkReply*)), &eventLoopy, SLOT(quit()));

                // the HTTP request
                QNetworkRequest reqy( labely );
                QNetworkReply *replyy = mgry.get(reqy);
                eventLoopy.exec(); // blocks stack until "finished()" has been called

                if (replyy->error() == QNetworkReply::NoError) {
                    //success
                    QByteArray imageData = replyy->readAll();
                    QPixmap pixmap;
                    pixmap.loadFromData(imageData);
                    ui->label_6->setPixmap(pixmap.scaled(ui->label_6->size(), Qt::KeepAspectRatio));
                }
                else {
                    //failure
                    qDebug() << "Failure" <<replyy->errorString();
                    delete replyy;
                }
            }
        }
    }
    if(event->key() == Qt::Key_L){
        if(!isopenrg){

            if(!isopendmenu){
                isopendmenu = true;

                ui->widget_4->raise();
                QGraphicsOpacityEffect *opacityEffect;
                opacityEffect = new QGraphicsOpacityEffect(this);
                ui->widget_4->setGraphicsEffect(opacityEffect);
                QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
                animation->setDuration(200); // Animation duration in milliseconds
                    // Make the button transparent before showing it
                animation->setStartValue(0.0); // Fully transparent
                animation->setEndValue(1.0); // Destination position// Easing curve for smooth movement

                // Start the animation
                animation->start();
                QGraphicsOpacityEffect *opacityEffectiy;
                opacityEffectiy = new QGraphicsOpacityEffect(this);
                ui->label_11->setGraphicsEffect(opacityEffectiy);
                QPropertyAnimation *animationiy = new QPropertyAnimation(opacityEffectiy, "opacity");
                animationiy->setDuration(200); // Animation duration in milliseconds
                    // Make the button transparent before showing it
                animationiy->setStartValue(1.0); // Fully transparent
                animationiy->setEndValue(0.0); // Destination position// Easing curve for smooth movement

                // Start the animation
                animationiy->start();

                QPropertyAnimation *animationi = new QPropertyAnimation(ui->widget_4, "geometry");
                animationi->setDuration(200); // Animation duration in milliseconds
                animationi->setStartValue(QRect(0, -160, 2560, 1840)); // Initial position
                animationi->setEndValue(QRect(0, -400, 2560, 1840));  // Destination position
                animationi->start();
                QPropertyAnimation *animationie = new QPropertyAnimation(ui->widget_2, "geometry");
                animationie->setDuration(200); // Animation duration in milliseconds
                animationie->setStartValue(QRect(0, 0, 2560, 1440)); // Initial position
                animationie->setEndValue(QRect(0, -108, 2560, 1440));  // Destination position
                animationie->start();
                dssd();
            }else{
                hek();


            }
        }
    }
    if(event->key() == Qt::Key_F){
        if(!isopenrg){
            isopenrg = true;
            ui->widget_6->raise();
            gfdg();
        }else{
            isopenrg = false;

            gfdgo();
        }

    }
    if (event->key() == Qt::Key_A){
        if(!isopenrg && !isopendmenu){
            if(canmove == true && lockopen == false){
                if(currentIndex > 0){
                    canmove = false;
                    QWidget *ds = ui->horizontalLayout->layout()->itemAt(currentIndex)->widget();
                    if (gamemenu *myWidget = qobject_cast<gamemenu *>(ds)) {
                        myWidget->hidedw();
                    }

                    // ds->setFixedSize(181,181);
                    QPropertyAnimation *animation = new QPropertyAnimation(ui->horizontalLayout->layout()->itemAt(currentIndex)->widget(), "minimumSize");
                    animation->setDuration(600); // Animation verticalLayout_2 in milliseconds
                    animation->setStartValue((QSize(400,225))); // Initial position
                    animation->setEndValue((QSize(181,225))); // Destination position
                    animation->setEasingCurve(QEasingCurve::InOutQuad); // Easing curve for smooth movement
                    // Start the animation
                    animation->start();
                    currentIndex = currentIndex - 1;
                    QPropertyAnimation *animationi = new QPropertyAnimation(ui->horizontalLayout->layout()->itemAt(currentIndex)->widget(), "minimumSize");
                    animationi->setDuration(600); // Animation duration in milliseconds
                    animationi->setStartValue(QSize(181,225)); // Initial position
                    animationi->setEndValue((QSize(400,225))); // Destination position
                    animationi->setEasingCurve(QEasingCurve::InOutQuad); // Easing curve for smooth movement

                    // Start the animation
                    animationi->start();
                    if (gamemenu *myWidget = qobject_cast<gamemenu *>(ui->horizontalLayout->layout()->itemAt(currentIndex)->widget())) {
                        myWidget->showdw();
                    }
                    // ui->horizontalLayout->layout()->itemAt(currentIndex)->widget()->setFixedSize(400,181);
                    connect(animation, &QPropertyAnimation::finished, this, &normal::finmove);
                    QJsonObject jsonObjecti = arrayis[currentIndex].toObject();
                    QString icie = jsonObjecti["icontext"].toString();
                    QUrl labely = icie;
                    QEventLoop eventLoopy;
                    // "quit()" the event-loop, when the network request "finished()"
                    QNetworkAccessManager mgry;
                    QObject::connect(&mgry, SIGNAL(finished(QNetworkReply*)), &eventLoopy, SLOT(quit()));

                    // the HTTP request
                    QNetworkRequest reqy( labely );
                    QNetworkReply *replyy = mgry.get(reqy);
                    eventLoopy.exec(); // blocks stack until "finished()" has been called

                    if (replyy->error() == QNetworkReply::NoError) {
                        //success
                        QByteArray imageData = replyy->readAll();
                        QPixmap pixmap;
                        pixmap.loadFromData(imageData);
                        ui->label_6->setPixmap(pixmap.scaled(ui->label_6->size(), Qt::KeepAspectRatio));
                    }
                    else {
                        //failure
                        qDebug() << "Failure" <<replyy->errorString();
                        delete replyy;
                    }
                }
            }
        }
    }
}

void normal::dssd()
{
    QGraphicsOpacityEffect *opacityEffecte;
    opacityEffecte = new QGraphicsOpacityEffect(this);
    ui->widget->setGraphicsEffect(opacityEffecte);
    QPropertyAnimation *animatione = new QPropertyAnimation(opacityEffecte, "opacity");
    animatione->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animatione->setStartValue(1.0); // Fully transparent
    animatione->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animatione->start();
}

void normal::finispi(int dsd){
    if(dsd == 0){

    }else if(dsd == 1){

        if(openapp){
            ui->widget_8->raise();
        }else{
            if(wasopened){
                wasopened = false;
            qDebug() << "fgdfgdfgdfdg";
            buttonplaui->setFixedSize(0,0);
            ui->horizontalLayout_2->removeWidget(buttonplaui);
            ui->widget_8->lower();
            }
            ui->widget_2->raise();

        }

    }else if(dsd == 2){

        if(isopendmenu){
            ui->widget_4->raise();
        }else{
            if(openapp){
                ui->widget_8->raise();
            }else{

                ui->widget_2->raise();
            }
        }

    }
}

void normal::gfdg()
{
    QGraphicsOpacityEffect *opacityEffect;
    opacityEffect = new QGraphicsOpacityEffect(this);
    ui->widget_6->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animation->setStartValue(0.0); // Fully transparent
    animation->setEndValue(1.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animation->start();
    QPropertyAnimation *animationi = new QPropertyAnimation(ui->widget_6, "geometry");
    animationi->setDuration(200); // Animation duration in milliseconds
    animationi->setStartValue(QRect(0, 0, 3000, 1440)); // Initial position
    animationi->setEndValue(QRect(-440, 0, 3000, 1440));  // Destination position
    animationi->start();
}

void normal::gfdgo()
{
    QGraphicsOpacityEffect *opacityEffect;
    opacityEffect = new QGraphicsOpacityEffect(this);
    ui->widget_6->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animation->setStartValue(1.0); // Fully transparent
    animation->setEndValue(0.0); // Destination position// Easing curve for smooth movement
        connect(animation, &QPropertyAnimation::finished, this, [=]() { finispi(2); });
    // Start the animation
    animation->start();
    QPropertyAnimation *animationi = new QPropertyAnimation(ui->widget_6, "geometry");
    animationi->setDuration(200); // Animation duration in milliseconds
    animationi->setStartValue(QRect(-440, 0, 3000, 1440)); // Initial position
    animationi->setEndValue(QRect(0, 0, 3000, 1440));  // Destination position
    animationi->start();

}

void normal::dssdo()
{
    QGraphicsOpacityEffect *opacityEffecte;
    opacityEffecte = new QGraphicsOpacityEffect(this);
    ui->widget->setGraphicsEffect(opacityEffecte);
    QPropertyAnimation *animatione = new QPropertyAnimation(opacityEffecte, "opacity");
    animatione->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animatione->setStartValue(0.0); // Fully transparent
    animatione->setEndValue(1.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animatione->start();
}
void normal::hek()
{
    isopendmenu = false;
    QGraphicsOpacityEffect *opacityEffect;
    opacityEffect = new QGraphicsOpacityEffect(this);
    ui->widget_4->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animation->setStartValue(1.0); // Fully transparent
    animation->setEndValue(0.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, [=]() { finispi(1); });

    QGraphicsOpacityEffect *opacityEffectiy;
    opacityEffectiy = new QGraphicsOpacityEffect(this);
    ui->label_11->setGraphicsEffect(opacityEffectiy);
    QPropertyAnimation *animationiy = new QPropertyAnimation(opacityEffectiy, "opacity");
    animationiy->setDuration(200); // Animation duration in milliseconds
        // Make the button transparent before showing it
    animationiy->setStartValue(0.0); // Fully transparent
    animationiy->setEndValue(1.0); // Destination position// Easing curve for smooth movement

    // Start the animation
    animationiy->start();


    QPropertyAnimation *animationi = new QPropertyAnimation(ui->widget_4, "geometry");
    animationi->setDuration(200); // Animation duration in milliseconds
    animationi->setStartValue(QRect(0, -400, 2560, 1840)); // Initial position
    animationi->setEndValue(QRect(0, -160, 2560, 1840));  // Destination position
    animationi->start();
    QPropertyAnimation *animationie = new QPropertyAnimation(ui->widget_2, "geometry");
    animationie->setDuration(200); // Animation duration in milliseconds
    animationie->setStartValue(QRect(0, -108, 2560, 1440)); // Initial position
    animationie->setEndValue(QRect(0, 0, 2560, 1440));  // Destination position
    animationie->start();
    dssdo();
}
normal::~normal()
{
    delete ui;
}

void delayr( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void normal::on_pushButton_clicked()
{
    this->close();
}


void normal::on_pushButton_2_clicked()
{
    profile *sWindow = new profile(jsonObjecty);
    sWindow->setWindowState(Qt::WindowFullScreen);
    sWindow->show();
    delayr(100);
    this->close();
}


void normal::on_pushButton_12_clicked()
{
    if(openapp){

        closeweb();
    }else{
    hek();
    }
}

void normal::chechqr(){
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    qDebug() << "wadawd" << qrhash;
    // the HTTP request
    QNetworkRequest req( QUrl( QString("http://keeppixel.store/qrabout?hash="+qrhash) ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
    //success
    QByteArray qti = reply->readAll();

    QJsonParseError err;

    QJsonDocument jsonDocument = QJsonDocument::fromJson(qti);
    if (!jsonDocument.isNull() && jsonDocument.isArray())
    {
            QJsonArray jsonObject = jsonDocument.array();
            qDebug() << "wadawd" << qti;
            if (jsonObject[2].toString() == "1"){

                qDebug() << "wadawd" << jsonObject[2];
                QPixmap pixmap(":/new/prefix1/image/yeslog.png");
                ui->label_21->setPixmap(pixmap);

                QEventLoop eventLoopi;
                // "quit()" the event-loop, when the network request "finished()"
                QNetworkAccessManager mgri;
                QObject::connect(&mgri, SIGNAL(finished(QNetworkReply*)), &eventLoopi, SLOT(quit()));
                // the HTTP request
                QNetworkRequest reqi( QUrl( QString("http://keeppixel.store/qraccpet?hash="+qrhash) ) );
                QNetworkReply *replyi = mgri.get(reqi);
                eventLoopi.exec(); // blocks stack until "finished()" has been called
                if (replyi->error() == QNetworkReply::NoError) {
                    //success
                    QByteArray qti = replyi->readAll();
                    QJsonParseError err;
                    if (qti != "false"){
                        qDebug() << "rttxgrdrg";
                        QJsonDocument jsonDocument = QJsonDocument::fromJson(qti, &err);
                        QSettings settings("Keep Pixel", "Apolo");
                        settings.setValue("token", jsonObject[3].toString());
                        settings.sync();


                        closelog();


                    }else{

                        qDebug() << "nooooof";
                    }
                    delete replyi;
                }
                else {
                    //failure
                    qDebug() << "Failure" <<replyi->errorString();
                    delete replyi;
                }

            }else{
                qDebug() << "kuukyuhuki";
                QTimer::singleShot(1000, this, &normal::chechqr);
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


void normal::on_pushButton_23_clicked()
{
    QSettings settings("Keep Pixel", "Apolo");

    QString text = ui->lineEdit_5->text();
    QString text2 = ui->lineEdit_7->text();

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


                closelog();




                // Закрываем основное окно    rgb(255, 0, 4)
            }else{
                // ui->label_4->setStyleSheet(QString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 0)); color:rgb(255, 0, 4)")); типо неправильно что-то
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

