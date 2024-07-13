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
    w.set_role(m_ViewModel->get_role());
    w.set_map(m_ViewModel->get_map());
    w.set_bullet(m_ViewModel->get_bullet());
    w.set_enemy(m_ViewModel->get_enemy());
    // commands
    w.set_move_command(m_ViewModel->get_move_command());
    w.set_shot_command(m_ViewModel->get_shot_command());
    w.set_bulletmove_command(m_ViewModel->get_bulletMove_command());
    w.set_enemyshot_command(m_ViewModel->get_enemyShot_command());
    w.set_enemymove_command(m_ViewModel->get_enemyMove_command());
    // notifications
    m_ViewModel->AddPropertyNotification(w.get_property_sink());
    w.setWindowTitle("YUAN QI QI SHI");
    w.init();
    w.show();
    return true;
}