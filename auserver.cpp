#include "auserver.h"
#include <QHostInfo>
#include <QSettings>
#include "myhttpdownload.h"
//获取本机ip
QString AuServer::getHostIP()
{
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());

    if(info.error() != QHostInfo::NoError)
    {
        qDebug()<<"lookup failed:"<<info.errorString();
        return "";
    }
    for(int i = 0 ; i < info.addresses().size(); i++)
    {
        if(info.addresses()[i].protocol() == QAbstractSocket::IPv4Protocol)
            return info.addresses()[i].toString();
    }
}
//读取ini
bool AuServer::readIni(const QString &filename, QString &_port, QString &_ip, QString &_dwname)
{
    try
    {
        QSettings *configIni = new QSettings(filename,QSettings::IniFormat);
        QString ip = configIni->value("ip").toString();
        QString port = configIni->value("port").toString();
        QString dwname = configIni->value("dw").toString();
        _port = port;
        _ip = ip;
        _dwname = dwname;
        configIni->deleteLater();
        return 1;
    }
    catch(...)
    {
        return -1;
    }
}

AuServer::AuServer(QObject *parent)
{
    MyHttpDownload *hd = new MyHttpDownload();
    hd->onStartDownload("http://192.168.0.244:190/OracleToAccess.exe");
}
void AuServer::StartServer()
{
    if(listen(QHostAddress::Any,9999))
    {
        qDebug() << "strated";
    }
    else
    {
        qDebug()<<"not started";
    }
    qDebug()<<getHostIP();
}


void AuServer::incomingConnection(qintptr handle)
{
    MyClient * client = new MyClient(this);
    client->SetSocket(handle);
}
