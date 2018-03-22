#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class DownLoadManager : public QObject
{
    Q_OBJECT
public:
    DownLoadManager(QObject *parent = 0);
    ~DownLoadManager();

    //下载文件
    void downloadFile(QString url,QString fileName);
    //
    void setDownInfo(bool isSupportBreakPoint);
    //
    void stopDownload();
    void closeDownload();
    QString getDownloadUrl();
    void reset();

private:
    void stopWork();
    void removeFile(QString fileName);

signals:
    void signalDownloadProcess(qint64,qint64);
    void signalReplyFinished(int);
    void signalDownloadError();

private slots:
    void onDownloadProgress(qint64 bytesReceived,qint64 bytesTotal);
    void onReadyRead();
    void onFinished();
    void onError(QNetworkReply::NetworkError code);

private:
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_reply;
    QUrl m_url;
    QString m_fileName;

    bool m_isSupportBreadPoint;

    qint64 m_bytesReceived;
    qint64 m_bytesTotal;
    qint64 m_bytesCurrentReceived;

    bool m_isStop;
};

#endif // DOWNLOADMANAGER_H
