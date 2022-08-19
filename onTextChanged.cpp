#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_txtResult_textChanged()
{
    if(ui->txtResult->toPlainText().contains("ঝাকানাকা ঝাকানাকা"))
    {
        ui->txtResult->clear();
        ui->txtResult->setText("");
    }
    if(ui->ckbxMerge->checkState()==Qt::Checked)
    qclipboard->setText(ui->txtResult->toPlainText());
}
