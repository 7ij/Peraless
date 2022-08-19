#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include "ui_aboutwindow.h"
class AboutWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AboutWindow(QWidget *parent = nullptr);

signals:
private:
    Ui::Form ui;
};

#endif // ABOUTWINDOW_H
