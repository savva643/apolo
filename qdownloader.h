#ifndef QDOWNLOADER_H
#define QDOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QStringList>
#include <QDir>
#include <QProgressBar>
#include <QProcess>
#include <QPushButton>

class QDownloader : public QObject
{
    Q_OBJECT
public:
    explicit QDownloader(QObject *parent = 0);
    virtual ~QDownloader();
    void setFile(QString fileURL, QString filepatch, QProgressBar *progressBar, QStringList texi, QPushButton *domlound, QPushButton *play);

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
    QProgressBar *progressBari;
    QPushButton *domloundi;
    QPushButton *playi;
    QString saveFilePath;
    QString filePathi;
    QStringList texiy;
private slots:
    void onDownloadProgress(qint64,qint64);
    void onFinished(QNetworkReply*);
    void onReadyRead();
    void onReplyFinished();
};

#endif // QDOWNLOADER_H
