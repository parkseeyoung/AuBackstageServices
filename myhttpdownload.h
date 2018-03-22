#ifndef MYHTTPDOWNLOAD_H
#define MYHTTPDOWNLOAD_H

#include <QObject>
#include "downloadmanager.h"

class MyHttpDownload : public QObject
{
    Q_OBJECT
public:
    explicit MyHttpDownload(QObject *parent = 0);
    ~MyHttpDownload();void onStartDownload(const QString&_url);
private:
    void ini();
    //单位转换
    QString transformUnit(qint16 bytes,bool isSpeed = false);
    //时间转换
    QString transformTime(qint16 seconds);

private slots:

    void onStopDownload();
    void onCloseDownload();

    void onDownloadProcess(qint64 bytesRecived,qint64 bytesTotal);
    void onReplyFinished(int);

private:
    QString m_url;
    DownLoadManager * m_downloadManager;
    uint m_timeInterval;
    qint64 m_currentDownload;
    qint64 m_intervalDownload;
    QTime m_timeRecord;
};

#endif // MYHTTPDOWNLOAD_H
