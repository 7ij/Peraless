#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::on_btnClear_clicked()
{
    ui->txtResult->clear();
    qDebug()<<"All text cleared\n";

    popup.setPopWidget(&holderClear);
    popup.setPopTime(500);
    popup.setWindowFlag(Qt::Popup);
    popup.setWindowFlags(Qt::WindowStaysOnTopHint);
    popup.show();
}
