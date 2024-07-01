#include "qdownloader.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTime>
#include <QSettings>
#include <QPushButton>

bool fileExistsi(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

QDownloader::QDownloader(QObject *parent) :
    QObject(parent)
{
    manager = new QNetworkAccessManager;
}

QDownloader::~QDownloader()
{
    manager->deleteLater();
}

void QDownloader::setFile(QString fileURL, QString filepatch, QProgressBar *progressBar, QStringList texi, QPushButton *domlound, QPushButton *play)
{
    QString filePath = fileURL;
    texiy = texi;
    QStringList filePathList = filePath.split('/');
    QString fileName = filePathList.at(filePathList.count() - 1);
    saveFilePath = QString(filepatch + "/" + fileName);
    QNetworkRequest request;
    request.setUrl(QUrl(fileURL));
    reply = manager->get(request);
    filePathi = filepatch;
    file = new QFile;
    file->setFileName(saveFilePath);
    file->open(QIODevice::WriteOnly);
    progressBari = progressBar;
    playi = play;
    domloundi = domlound;
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(onDownloadProgress(qint64,qint64)));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinished(QNetworkReply*)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(onReplyFinished()));
    progressBari->setVisible(true);
}

void QDownloader::onDownloadProgress(qint64 bytesRead,qint64 bytesTotal)
{
    qDebug(QString::number(bytesRead).toLatin1() +" - "+ QString::number(bytesTotal).toLatin1());


    qDebug()<< progressBari->value();
      progressBari->setMaximum(bytesTotal);
      progressBari->setValue(bytesRead);
}

void delayp( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void QDownloader::onFinished(QNetworkReply * reply)
{
    switch(reply->error())
    {
        case QNetworkReply::NoError:
        {
            qDebug("file is downloaded successfully.");
            QString zipFilePath = saveFilePath;

                QString outputDir = filePathi;
                QStringList filePathList = zipFilePath.split('/');
                QString fileName = filePathList.at(filePathList.count() - 1);
                QString sgas = "tar -xf "+zipFilePath+" -C "+outputDir;
                qDebug() << texiy[2];
                QByteArray ba = sgas.toLocal8Bit();
                const char *c_str2 = ba.data();
                // Create the unzip command
                system(c_str2);

                QStringList gamesave;
                gamesave.append(texiy[0]);
                gamesave.append(filePathi + "/"+texiy[4]+"/"+texiy[2]+".exe");
                gamesave.append(outputDir);
                gamesave.append(fileName);
                gamesave.append(filePathi);
                gamesave.append(texiy[4]);
                QSettings settings("Keep Pixel", "Apolo");
                settings.setValue(texiy[5], gamesave);
                settings.sync();
                playi->setVisible(true);
                progressBari->setVisible(false);
                domloundi->setVisible(false);
               }
        default:{
            qDebug(reply->errorString().toLatin1());
        };
    }

    if(file->isOpen())
    {
        file->close();
        file->deleteLater();
    }
}

void QDownloader::onReadyRead()
{
    file->write(reply->readAll());
}

void QDownloader::onReplyFinished()
{

        file->close();
        file->deleteLater();

}
