#include "mydelaymachine.h"
#include <QThread>
MyDelayMachine::MyDelayMachine(QObject *parent) : QObject(parent)
{
}
void MyDelayMachine::delay(int delayInMilSec)
{
    QThread::msleep(delayInMilSec);
    emit doneDelaying();
}
