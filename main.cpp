#include <QCoreApplication>
#include <iostream>
#include <Windows.h>
#include "auserver.h"
using namespace  std;
void s() ;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AuServer as;
    as.StartServer();
    return a.exec();

}
//打开任意程序
void s()
{
    STARTUPINFO startupInfo = {0};
    PROCESS_INFORMATION processInformation = {0};

    BOOL bSuccess = CreateProcess(
                TEXT("C:\\Program Files (x86)\\Tencent\\TIM\\Bin\\QQScLauncher.exe"),NULL,NULL,
                NULL,FALSE,NULL,NULL,NULL,&startupInfo,
                &processInformation);
    if(bSuccess)
    {
        cout<<"Process ID:\t"
           <<processInformation.dwProcessId<<endl;
    }
}
