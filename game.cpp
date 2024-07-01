#include "game.h"
#include "normal.h"
#include "ui_game.h"
#include <QNetworkReply>
#include <QtWidgets>
#include <QtNetwork>
#include <QTime>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include "qdownloader.h"
#include <QFileDialog>

bool fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}
QStringList list;
QString filka;
game::game(const QStringList& text, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    list = text;
    ui->progressBar->setValue(0);
    ui->progressBar->setStyleSheet(
                "QProgressBar {"
                "   border: 2px solid grey;"
                "   border-radius: 10px;"
                "   text-align: center;"
                "   background-color: rgb(67, 67, 67);"
                "   font: 900 22pt 'Segoe UI;'"
                "}"
                "QProgressBar::chunk {"
                "   background-color: #0000ff;"
                "   width: 20px;"
                "}"
                "QProgressBar::subcontrol:groove {"
                "   background: transparent;"
                "}"
                "QProgressBar::chunk::subcontrol {"
                "   color: white;"
                "}"
                "QProgressBar::subcontrol:text {"
                "   top: -3px;"
                "   position: relative;"
                "   color: white;"
                "}"
            );
    ui->label_2->setText(list[0]);
    QUrl labeli = list[1];
    ui->label_6->setText(list[1]);
    ui->label_5->setText(list[2]);
    ui->label_4->setText(list[3]);
    ui->label_7->setText(list[6]);
    ui->label_8->setText(list[7]);
    ui->widget->hide();
    ui->widget_2->hide();
    ui->pushButton_5->hide();
    QStringList listy;
    listy.append("false");
    QSettings settings("Keep Pixel", "Apolo");
    QStringList tr = settings.value(list[7], listy).toStringList();
    ui->progressBar->setVisible(false);
    if (tr != listy){
        if (fileExists(tr[1])){
            ui->quitBtn->setVisible(false);
            ui->progressBar->setVisible(false);
        }else{
            settings.setValue(ui->label_2->text(), listy);
            settings.sync();
            ui->quitBtn_2->setVisible(false);
            ui->quitBtn_3->setVisible(false);
        }
    }else{
        ui->quitBtn_2->setVisible(false);
        ui->quitBtn_3->setVisible(false);
    }

               QEventLoop eventLoop;
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
                         ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio));
                     }
                     else {
                         //failure
                         qDebug() << "Failure" <<reply->errorString();
                         delete reply;
                     }
}

game::~game()
{
    delete ui;
}

void delayo( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}


void game::on_pushButton_clicked()
{
    ui->widget->hide();
    normal *sWindow = new normal();
    sWindow->setWindowState(Qt::WindowFullScreen);
    sWindow->show();
    delayo(100);
    this->close();
}




void game::on_quitBtn_clicked()
{
        QString filePath = QFileDialog::getExistingDirectory(nullptr, "Save File", "");
        ui->widget->hide();
        // Check if a file was selected
        if (!filePath.isEmpty())
        {
            QStringList listy;
            listy.append(ui->label_2->text());
            listy.append(ui->label_6->text());
            listy.append(ui->label_5->text());
            listy.append(ui->label_4->text());
            listy.append(ui->label_7->text());
            listy.append(ui->label_8->text());
            QString filik = "http://keeppixel.store/"+ui->label_4->text();
            qDebug() << filik;
            progressBar = ui->progressBar;
            QDownloader *qte = new QDownloader();
            qte->setFile(filik, filePath, progressBar, listy, ui->quitBtn, ui->quitBtn_2);
        }


}


void game::on_quitBtn_2_clicked()
{
    ui->widget->hide();
    QSettings settings("Keep Pixel", "Apolo");
    QStringList listy;
    listy.append("false");
    QStringList tr = settings.value(ui->label_8->text(), listy).toStringList();
    QProcess::startDetached(tr[1], QStringList() << "any_argument");
    QString outputDir = tr[2];
    QString fileName = tr[3];
    QString sgasi = "cd /d "+outputDir+" && del "+fileName;
                    QByteArray bai = sgasi.toLocal8Bit();
                    const char *c_str2i = bai.data();
                    // Create the unzip command
                    system(c_str2i);
}


void game::on_quitBtn_3_clicked()
{
    ui->widget->show();
}


void game::on_pushButton_4_clicked()
{
     ui->widget->hide();
}


void game::on_pushButton_3_clicked()
{
    QSettings settings("Keep Pixel", "Apolo");
    QStringList listy;
    listy.append("false");
    QStringList tr = settings.value(ui->label_8->text(), listy).toStringList();
    QString outputDir = tr[2];
    QString fileName = tr[3];
    QString sgasi = "cd /d "+outputDir+" && del "+fileName;
                    QByteArray bai = sgasi.toLocal8Bit();
                    const char *c_str2i = bai.data();
                    // Create the unzip command
                    system(c_str2i);

                    QString outputDiri = tr[4];
                    QString fileNamei = tr[5];
                    QString sgasii = "cd /d "+outputDiri+" && rd /s /q "+fileNamei;
                    qDebug() << sgasii;
                                    QByteArray baii = sgasii.toLocal8Bit();
                                    const char *c_str2ii = baii.data();
                                    // Create the unzip command
                                    system(c_str2ii);
                    ui->widget->hide();
}


void game::on_pushButton_5_clicked()
{
    ui->widget_2->hide();
    ui->pushButton_5->hide();
}


void game::on_pushButton_2_clicked()
{
    ui->widget_2->show();
    ui->pushButton_5->show();
    ui->widget->hide();
}


void game::on_pushButton_6_clicked()
{
    ui->widget_2->hide();
    ui->pushButton_5->hide();
}

