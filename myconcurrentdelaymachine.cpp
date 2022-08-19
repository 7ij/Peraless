#include "myconcurrentdelaymachine.h"

MyConcurrentDelayMachine::MyConcurrentDelayMachine(QObject *parent) : QObject(parent)
{
    connect(&delayMachine, &MyDelayMachine::doneDelaying,
            this, &MyConcurrentDelayMachine::on_conCurrentDelay_Finished);
}

void MyConcurrentDelayMachine::conCurrentDelay(int delayInMilSec)
{
     QtConcurrent::run(&delayMachine, &MyDelayMachine::delay, delayInMilSec);
}

void MyConcurrentDelayMachine::on_conCurrentDelay_Finished()
{
    emit doneConCurrentDelaying();
}
