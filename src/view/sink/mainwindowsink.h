#ifndef MAINWINDOWSINK_H
#define MAINWINDOWSINK_H
#include "../../common/base.h"
class MainWindow;
class MainWindowSink:public IPropertyNotification
{
public:
    MainWindowSink(MainWindow* mw) throw();
    virtual void OnPropertyChanged(const std::string& str);
private:
    MainWindow* pmw;
};
#endif