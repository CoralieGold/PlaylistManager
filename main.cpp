#include <QtGui>
#include <QApplication>
#include "mainwindow.h"

int qMain(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow* win = new MainWindow();
    win->show();
    return app.exec();
}
