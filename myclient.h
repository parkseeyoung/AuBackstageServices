#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = 0);
    void SetSocket(int Descriptor);
signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void TaskResult(int Number);

private:
    QTcpSocket *socket;

};

#endif // MYCLIENT_H
