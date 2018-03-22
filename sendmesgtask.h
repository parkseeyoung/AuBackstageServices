#ifndef SENDMESGTASK_H
#define SENDMESGTASK_H

#include <QDebug>
#include <QObject>
#include <QRunnable>

class sendMesgTask : public QObject,public QRunnable
{
    Q_OBJECT
public:
    sendMesgTask();

signals:
    void Result(int Number);

protected:
    void run();
};

#endif // SENDMESGTASK_H
