#include "newmenu.h"
#include "ui_newmenu.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGraphicsView>
#include <QGraphicsVideoItem>

newmenu::newmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newmenu)
{
    ui->setupUi(this);
    QMediaPlayer *player = new QMediaPlayer(this);
    QGraphicsVideoItem *item = new QGraphicsVideoItem;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsView *graphicsView = new QGraphicsView(scene);
    player->setVideoOutput(item);
    graphicsView->scene()->addItem(item);
    ui->gridLayout->addWidget(graphicsView);
    player->setSource(QUrl("qrc:/new/prefix2/image/backg.mp4"));
    graphicsView->setStyleSheet("border-radius:0px");
    graphicsView->setGeometry(0,0,1920,1080);
    scene->setSceneRect(0,0,1920,1080);
    item->setSize(QSize(1920,1080));
    graphicsView->setSceneRect(0,0,1920,1080);
    player->play();
    player->setLoops(QMediaPlayer::Infinite);
}

newmenu::~newmenu()
{
    delete ui;
}
