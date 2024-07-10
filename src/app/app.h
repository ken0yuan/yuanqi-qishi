#ifndef APP_H
#define APP_H
#include <QApplication>
#include "../view/mainwindow.h"
#include "../model/model.h"
#include "../viewmodel/viewmodel.h"
class App
{
public:
    App();
    ~App() throw();
    bool Init(MainWindow& w);
private:
    std::shared_ptr<viewmodel>  m_ViewModel;
};

#endif // MSAPP_H