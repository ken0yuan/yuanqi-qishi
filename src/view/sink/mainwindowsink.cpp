#include "mainwindowsink.h"
#include "../mainwindow.h"
MainWindowSink::MainWindowSink(MainWindow* mw) throw():pmw(mw){}
void MainWindowSink::OnPropertyChanged(const std::string& str)
{
    if(str=="Nomove")
    {
        pmw->update();
    }
    if(str=="leftmove")
    {
        
        pmw->update();
    }
    if(str=="rightmove")
    {
        pmw->update();
    }
    if(str=="upmove")
    {
        pmw->update();
    }
    if(str=="downmove")
    {
        pmw->update();
    }
    if(str=="bulletMove")
    {
        pmw->update();
    }
}