#include "mainwindowsink.h"
#include "../mainwindow.h"
MainWindowSink::MainWindowSink(MainWindow* mw) throw():pmw(mw){}
void MainWindowSink::OnPropertyChanged(const std::string& str)
{
    if(str=="Nomove")
    {

    }
    if(str=="leftmove")
    {

    }
    if(str=="rightmove")
    {

    }
    if(str=="upmove")
    {

    }
    if(str=="downmove")
    {
        
    }
}