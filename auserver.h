#ifndef AUSERVER_H
#define AUSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QAbstractSocket>
#include "myclient.h"

class AuServer : public QTcpServer,public QObject
{
    Q_OBJECT
public:
    explicit AuServer(QObject *parent = 0);
    void StartServer();

protected:
    void incomingConnection(qintptr handle);

private:
    //获取本机ip
    QString getHostIP();

    //读取ini文件
    bool readIni(const QString &filename,QString& _port,QString& _ip,QString &_dwname);
signals:
    void startOne(const QString&);
};

#endif // AUSERVER_H
