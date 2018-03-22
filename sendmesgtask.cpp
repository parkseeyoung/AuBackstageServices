#include "sendmesgtask.h"

sendMesgTask::sendMesgTask()
{

}
void sendMesgTask::run()
{
    //time consumer
    qDebug()<<"Task Start";
    int iNumber = 0;
    for(int i = 0 ; i < 100 ;i++)
    {
        iNumber += i;
    }
    qDebug() << "Task Done";
    emit Result(iNumber);
}
