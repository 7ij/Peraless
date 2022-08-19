#include "aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setWindowTitle("About - Khoi Vaja"
                   "");
    ui.setupUi(this);

}
