#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(argc==1)
        w.startListening();
    else
    {
        if(qstrcmp(argv[1], "show_full")==0)
            w.showMaximal();
        else if(qstrcmp(argv[1], "show_minimal")==0)
        {
            w.showMinimal();
        }
        else if(qstrcmp(argv[1], "show_about")==0)
        {
            w.showAbout();
        }
        w.showMaximal();
    }

    return a.exec();
}
