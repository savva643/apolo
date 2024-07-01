#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDir>
#include <QDebug>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QObject* parent = nullptr)
        : QObject(parent)
    {
        networkManager = new QNetworkAccessManager(this);
        connect(networkManager, &QNetworkAccessManager::finished, this, &FileDownloader::onDownloadFinished);
    }

    void downloadFile(const QUrl& url, const QString& filePath)
    {
        QNetworkRequest request(url);
        networkManager->get(request);
        this->filePath = filePath;
    }

signals:
    void downloadCompleted(bool success, const QString& filePath);

private slots:
    void onDownloadFinished(QNetworkReply* replyi)
    {
        if (replyi->error() == QNetworkReply::NoError)
        {
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly))
            {
                file.write(replyi->readAll());
                file.close();
                emit downloadCompleted(true, filePath);
            }
            else
            {
                qWarning() << "Failed to open file for writing: " << filePath;
                emit downloadCompleted(false, filePath);
            }
        }
        else
        {
            qWarning() << "Download failed: " << replyi->errorString();
            emit downloadCompleted(false, filePath);
        }

        replyi->deleteLater();
    }

private:
    QNetworkReply* replyi;
    QNetworkAccessManager* networkManager;
    QString filePath;
};
#endif // FILEDOWNLOADER_H
