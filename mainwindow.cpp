#include "mainwindow.h"
#include "ui_mainwindow.h"
#
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QFont lblClearFont = lblClear.font();
    lblClearFont.setPointSize(72);
    lblClearFont.setBold(true);
    lblClear.setFont(lblClearFont);
    lblClear.setText("Cleared");
    hldClear.addWidget(&lblClear);
    holderClear.setLayout(&hldClear);
    ui->setupUi(this);

    loadConfig();

    ui->hsldOpacity->setValue(100);
    ui->txtCurrentServer->setPlainText(serverUrl);
    showUi();
    makeWebSocketSignalSlotConnections();
//    makeHotKeyConnections();


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onConnected()
{
    ui->btnConenct->setEnabled(false);
    ui->btnDisconnect->setEnabled(true);
    ui->btnStartListening->setEnabled(true);
    ui->btnStopListening->setEnabled(true);
    ui->txtCurrentServer->setEnabled(false);
    webSocketConnected = true;
    if(connInitiatedByStartListening)
    {
        ui->btnStartListening->click();
        connInitiatedByStartListening = false;
    }
    qDebug()<<"Connected to the websocket server";
}
void MainWindow::onDisconnected()
{
    ui->btnDisconnect->setEnabled(false);
    ui->btnConenct->setEnabled(true);
    ui->btnStartListening->setEnabled(false);
    ui->btnStopListening->setEnabled(false);
    ui->txtCurrentServer->setEnabled(true);
    webSocketConnected = false;
    qDebug()<<"Connection to the Server is lost!!!\n";
}
void MainWindow::onMsgReceived(QString msg)
{
    qDebug()<<msg;
    if(ui->ckbxMerge->checkState()!=Qt::Checked)
    {
        if(msg.contains("ঝাকানাকা ঝাকানাকা"))
            msg = " ";
        qclipboard->setText(msg+" ");
        system("xdotool key --clearmodifiers \"ctrl+v\"");
        return;
    }
    ui->txtResult->insertPlainText(msg + "। ");
}

void MainWindow::on_btnStopListening_clicked()
{
    qDebug()<<"Stop Listening Command Send!!! Which is \"b\"";
    webSocket.sendTextMessage("b");
}

void MainWindow::on_hsldOpacity_valueChanged(int value)
{
    setWindowOpacity(value/100.0);
}

void MainWindow::on_label_linkActivated(const QString &link)
{
    setWindowFlags(windowFlags()&~Qt::WindowDoesNotAcceptFocus);
    show();
}

void MainWindow::startListening()
{

   ui->btnStartListening->setEnabled(true);
   ui->btnStartListening->click();

}
void MainWindow::showUi()
{
    this->show();
}
void MainWindow::hideSomeToMakeMini()
{
    ui->txtResult->hide();
    ui->txtCurrentServer->hide();
    ui->btnClear->hide();
    ui->btnConenct->hide();
    ui->btnDisconnect->hide();
    ui->btnStopListening->hide();
    ui->hsldOpacity->hide();
    ui->ckbxIsConfigMode->hide();
    ui->btnShowAbout->hide();
    ui->btnHide->hide();
    ui->ckbxMerge->hide();
    ui->btnStartListening->setEnabled(true);
    setMaximumWidth(50);
    setMaximumHeight(40);
    show();
}

void MainWindow::showAlltoMakeMaxi()
{
    ui->txtResult->show();
    ui->txtCurrentServer->show();
    ui->btnClear->show();
    ui->btnConenct->show();
    ui->btnDisconnect->show();
    ui->btnStopListening->show();
    ui->hsldOpacity->show();
    ui->ckbxIsConfigMode->show();
    ui->ckbxMiniModeEnabled->show();
    ui->ckbxMerge->show();
    ui->btnStartListening->setEnabled(true);
    ui->btnShowAbout->show();
    ui->btnHide->show();
    setMaximumWidth(16777215);
    setMaximumHeight(16777215);
    show();
}
void MainWindow::showMaximal()
{
    showAlltoMakeMaxi();
}
void MainWindow::showMinimal()
{
    ui->ckbxMiniModeEnabled->setChecked(true);
    makeWindowSticky();
    hideSomeToMakeMini();

    ui->ckbxIsConfigMode->setChecked(false);
}
void MainWindow::on_ckbxMiniModeEnabled_clicked(bool checked)
{
    if(checked)
        showMinimal();
    else
        showMaximal();
}

void MainWindow::on_ckbxIsConfigMode_toggled(bool checked)
{
    if(checked)
        makeWindowNormal();
    else
        makeWindowSticky();

}

void MainWindow::makeWindowNormal()
{
    setWindowFlags( windowFlags() &~Qt::WindowStaysOnTopHint);
    setWindowFlags( windowFlags() &~Qt::WindowDoesNotAcceptFocus);
    setWindowFlags( windowFlags() &~Qt::FramelessWindowHint);
    show();
}
void MainWindow::makeWindowSticky()
{
    setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);
    setWindowFlags(windowFlags()|Qt::WindowDoesNotAcceptFocus);
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint);

    show();
}

void MainWindow::on_txtCurrentServer_textChanged()
{
    serverUrl = ui->txtCurrentServer->toPlainText();
    saveConfig();
}


void MainWindow::on_btnHide_clicked()
{
    hide();
}
void MainWindow::showAbout()
{
    aboutWindow.show();
}

void MainWindow::on_btnShowAbout_clicked()
{
    aboutWindow.show();
}
