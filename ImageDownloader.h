#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

#include <QApplication>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QUrl>

class ImageDownloader : public QObject
{
    Q_OBJECT
public:
    ImageDownloader(const QUrl& url, QObject* parent = nullptr)
        : QObject(parent), m_url(url)
    {
        connect(&m_manager, &QNetworkAccessManager::finished, this, &ImageDownloader::onDownloadFinished);
    }

    void startDownload()
    {
        qDebug() << "Failurejkl";
        QNetworkRequest request(m_url);
        m_manager.get(request);
    }

signals:
    void downloadFinished(const QPixmap& pixmap);

private slots:
    void onDownloadFinished(QNetworkReply* reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            const QByteArray data = reply->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(data);
            qDebug() << "Failure" <<data;
            emit downloadFinished(pixmap);
        }

        reply->deleteLater();
        deleteLater();
    }

private:
    QUrl m_url;
    QNetworkAccessManager m_manager;
};

#endif // IMAGEDOWNLOADER_H
