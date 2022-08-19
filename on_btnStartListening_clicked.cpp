#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::on_btnStartListening_clicked()
{
    if(webSocketConnected == false)
    {
        ui->btnConenct->click();
        connInitiatedByStartListening = true;
    }
    else
    {
        qDebug()<<"message sent: a";
        webSocket.sendTextMessage("a");
    }
}
