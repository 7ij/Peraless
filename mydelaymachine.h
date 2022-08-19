#ifndef MYDELAYMACHINE_H
#define MYDELAYMACHINE_H

#include <QObject>

class MyDelayMachine : public QObject
{
    Q_OBJECT
public:
    explicit MyDelayMachine(QObject *parent = nullptr);
    void delay(int delayInMilSec);
signals:
    void doneDelaying();
private:
};

#endif // MYDELAYMACHINE_H
