#include "qtdownload.h"
#include <QCoreApplication>
#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>

QtDownload::QtDownload() : QObject(0) {
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
}

QtDownload::~QtDownload() {

}


void QtDownload::setTarget(const QString &t) {
    this->target = t;
}

void QtDownload::downloadFinished(QNetworkReply *data) {
    QFile localFile("downloadedfile");
    if (!localFile.open(QIODevice::WriteOnly))
        return;
    const QByteArray sdata = data->readAll();
    localFile.write(sdata);
    qDebug() << sdata;
    localFile.close();

    emit done();
}

void QtDownload::download() {
    QUrl url = QUrl::fromEncoded(this->target.toLocal8Bit());
    QNetworkRequest request(url);
    QObject::connect(manager.get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));

}

void QtDownload::downloadProgress(qint64 recieved, qint64 total) {
    qDebug() << recieved << total;
}
