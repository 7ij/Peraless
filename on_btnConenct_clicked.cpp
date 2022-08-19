#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::on_btnConenct_clicked()
{
    webSocket.open(QUrl(ui->txtCurrentServer->toPlainText()));
}
