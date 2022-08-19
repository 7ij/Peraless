#ifndef MYPOPUP_H
#define MYPOPUP_H

#include <QObject>
#include <QWidget>
#include "myconcurrentdelaymachine.h"
class MyPopUp : public QWidget
{
    Q_OBJECT
public:
    explicit MyPopUp(QWidget *parent = nullptr);
    void setPopWidget(QWidget *widget);
    void setPopTime(int time);
    void show();
    void on_doneConCurrentDelaying_finished();
signals:
private:
    QWidget *widget;
    int time;
    MyConcurrentDelayMachine concurrentDelayMachine;
};

#endif // MYPOPUP_H
