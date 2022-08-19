#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>
#include <QObject>
#include "test.h"
#include <QClipboard>
#include <QApplication>
//#include "uglobalhotkeys.h"
#include <QLabel>
#include <QThread>
#include <QHBoxLayout>
#include "mypopup.h"
#include "aboutwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void startListening();
    void showUi();
    void showMinimal();
    void showMaximal();
    void showAbout();
    ~MainWindow();
private slots:
    void on_btnConenct_clicked();
    void onConnected();
    void onMsgReceived(QString msg);
    void on_btnDisconnect_clicked();
    void on_btnClear_clicked();
    void onDisconnected();
    void on_btnStartListening_clicked();
    void on_btnStopListening_clicked();
//    void onHotKey_StartListening_Activated(size_t id);
//    void onHotKey_StopListening_Activated(size_t id);
//    void onHotKey_Clear_Activated(size_t id);
//    void onHotKey_Connect_Activated(size_t id);
//    void onHotKey_Disconnect_Activated(size_t id);
//    void onHotKey_OpacityReset_Activated(size_t id);
//    void onHotKey_MinimalMode_Activated(size_t id);
//    void onHotKey_MaximalMode_Activated(size_t id);
//    void onHotKey_showAbout_Activated(size_t id);
    void on_label_linkActivated(const QString &link);
    void on_ckbxMiniModeEnabled_clicked(bool checked);
    void on_ckbxIsConfigMode_toggled(bool checked);
    void on_txtCurrentServer_textChanged();
    void on_txtResult_textChanged();

    void on_hsldOpacity_valueChanged(int value);


    void on_btnHide_clicked();

    void on_btnShowAbout_clicked();

private:
    Ui::MainWindow *ui;
    QWebSocket webSocket;
    QString serverUrl = "ws://192.168.0.100:3000";

    QClipboard *qclipboard;

    QLabel lblClear;
    QHBoxLayout hldClear;
    QWidget holderClear;
    MyPopUp popup;

    QString shortCutPrefix  = "Ctrl+Shift+",
            shortCutConnect = "m",
            shortCutDisconnect ="k",
            shortCutStartListening ="Space",
            ShortCutStopListening = "x",
            shortCutClear="n",
            shortCutMinimalMode="q",
            shortCutMaximalMode="w",
            shortCutShowAbout="e",
            shortCutOpacityReset="i";
//    UGlobalHotkeys hotKeyManager[9];


    bool webSocketConnected = false,
         connInitiatedByStartListening = false;
//    void makeHotKeyConnections();
    void makeWebSocketSignalSlotConnections();
    void saveConfig();
    void loadConfig();
    void makeWindowSticky();
    void makeWindowNormal();
    void hideSomeToMakeMini();
    void showAlltoMakeMaxi();
    bool inMiniMode=false;
    AboutWindow aboutWindow;
};
#endif // MAINWINDOW_H
