#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::on_btnDisconnect_clicked()
{
    webSocket.close();
}
