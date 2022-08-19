#ifndef MYCONCURRENTDELAYMACHINE_H
#define MYCONCURRENTDELAYMACHINE_H
#include "mydelaymachine.h"
#include <QObject>
#include <QtConcurrent/QtConcurrent>
class MyConcurrentDelayMachine : public QObject
{
    Q_OBJECT
public:
    explicit MyConcurrentDelayMachine(QObject *parent = nullptr);
    void conCurrentDelay(int delayInMilSec);
signals:
    void doneConCurrentDelaying();
public slots:
    void on_conCurrentDelay_Finished();
private:
    MyDelayMachine delayMachine;
};

#endif // MYCONCURRENTDELAYMACHINE_H

