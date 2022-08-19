#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
QString configPath = "~/.config/websocket/",
        configFile = "x.cfg";
void MainWindow::saveConfig()
{
    QFile qf(configPath + configFile);
    if(!qf.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"No Config File Exists";
        qDebug()<<"Creating Config File";
        QDir dir;
        if(!dir.exists(configPath))
            dir.mkpath(configPath);
        if(qf.open(QFile::WriteOnly|QFile::Text))
        {
            qDebug()<<"Succesfully Created new \"" + configFile +"\"";
        }
        else
        {
            qDebug()<<"Failed Again. Go fuck yourself";
        }
    }
    QTextStream qts(&qf);
    qts<<serverUrl<<"\n";
    qf.flush();
    qf.close();
}
void MainWindow::loadConfig()
{
    QFile qf(configPath + configFile);
    if(!qf.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"No Config File Found";
        qDebug()<<"We will use the default hardcoded server url. Try configuring manually";
        return;
    }
    QTextStream qts(&qf);
    qts>>serverUrl;
    qf.flush();
    qf.close();
}
