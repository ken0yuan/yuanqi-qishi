#include "app.h"
App::App()
{
}
App::~App() throw()
{
}
bool App::Init(MainWindow& w)
{
    //objects
    std::shared_ptr<dataModel> m_Model(std::make_shared<dataModel>());
    m_ViewModel = std::make_shared<viewmodel>();
    m_ViewModel->set_model(m_Model);
    //binding
    // properties
    // commands
    w.set_move_command(m_ViewModel->get_move_command());
    // notifications
    m_ViewModel->AddPropertyNotification(w.get_property_sink());
    w.setWindowTitle("YUAN QI QI SHI");
    w.init();
    w.show();
    return true;
}