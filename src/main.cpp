#include "yuanqi_qishi.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    yuanqi_qishi w;
    w.show();
    return a.exec();
}