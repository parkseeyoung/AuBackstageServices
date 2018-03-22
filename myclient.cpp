#include "myclient.h"
#include "sendmesgtask.h"
#include <QThreadPool>
MyClient::MyClient(QObject *parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(15);
}

void MyClient::SetSocket(int Descriptor)
{
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    socket->setSocketDescriptor(Descriptor);

    qDebug()<<"client connected";
}

void MyClient::connected()
{
    qDebug()<<"client connected event";
}

void MyClient::disconnected()
{
    qDebug()<<"client disconnected";
}

void MyClient::readyRead()
{
    qDebug()<<socket->readAll();

    //
    sendMesgTask *pTask = new sendMesgTask();
    pTask->setAutoDelete(true);
    connect(pTask,SIGNAL(Result(int)),this,SLOT(TaskResult(int)),Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(pTask);
}

void MyClient::TaskResult(int Number)
{
    //right here
    qDebug()<<"干完了！";
    QByteArray Buffer;
    Buffer.append("Task Result = ");
    Buffer.append(QString::number(Number));
    Buffer.append(QString::number(QThreadPool::globalInstance()->activeThreadCount()));

    socket->write(Buffer);
}
