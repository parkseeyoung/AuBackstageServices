#include "myhttpdownload.h"
#include <QDebug>

#define UNIT_KB 1024
#define UNIT_MB 1024*1024
#define UNIT_GB 1024*1024*1024

#define TIME_INTERVAL 300

MyHttpDownload::MyHttpDownload(QObject *parent) : QObject(parent)
  , m_downloadManager(NULL)
  , m_url("")
  , m_timeInterval(0)
  , m_currentDownload(0)
  , m_intervalDownload(0)
{

}
MyHttpDownload::~MyHttpDownload()
{

}

void MyHttpDownload::ini()
{

}

void MyHttpDownload::onStartDownload(const QString&_url)
{
    m_url = _url;
    //可能会重新下载
    if(m_downloadManager == NULL)
    {
        m_downloadManager = new DownLoadManager(this);
        connect(m_downloadManager , SIGNAL(signalDownloadProcess(qint64, qint64)), this, SLOT(onDownloadProcess(qint64, qint64)));
        connect(m_downloadManager, SIGNAL(signalReplyFinished(int)), this, SLOT(onReplyFinished(int)));
    }

//    QString url = m_downloadManager->getDownloadUrl();
//    if(url != m_url)
//    {
//        m_downloadManager->reset();
//    }
    //m_downloadManager->setDownInto(true);
    m_downloadManager->downloadFile(m_url,"D://MyDownloadFile.exe");
    m_timeRecord.start();
    m_timeInterval = 0;
}
void MyHttpDownload::onStopDownload()
{

}
void MyHttpDownload::onCloseDownload()
{

}
void MyHttpDownload::onDownloadProcess(qint64 bytesRecived, qint64 bytesTotal)
{

}
void MyHttpDownload::onReplyFinished(int)
{

}
