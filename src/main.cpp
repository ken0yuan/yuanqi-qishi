#include "app/app.h"
#include "view/mainwindow.h"

#include <QApplication>
#undef main
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    App app;
    app.Init(w);
    return a.exec();
}