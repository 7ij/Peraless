#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::makeWebSocketSignalSlotConnections()
{
    connect(&webSocket, &QWebSocket::connected,
            this, &MainWindow::onConnected);
    connect(&webSocket, &QWebSocket::disconnected,
            this, &MainWindow::onDisconnected);
    connect(&webSocket, &QWebSocket::textMessageReceived,
                     this, &MainWindow::onMsgReceived);
}
