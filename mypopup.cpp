#include "mypopup.h"

MyPopUp::MyPopUp(QWidget *parent) : QWidget(parent)
{

    connect(&concurrentDelayMachine, &MyConcurrentDelayMachine::doneConCurrentDelaying,
            this, &MyPopUp::on_doneConCurrentDelaying_finished);
}
void MyPopUp::setPopWidget(QWidget *widget)
{
    this->widget = widget;
}
void MyPopUp::setPopTime(int timeInMiliSec)
{
    this->time = timeInMiliSec;
}
void MyPopUp::show()
{
    widget->show();
    concurrentDelayMachine.conCurrentDelay(time);
}
void MyPopUp::on_doneConCurrentDelaying_finished()
{
    widget->hide();
    qDebug()<<"Hiddent The Widget Successfully";
}
