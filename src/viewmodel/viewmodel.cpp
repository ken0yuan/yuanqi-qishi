#include "viewmodel.h"
viewmodel::viewmodel():
    cmd_move(std::make_shared<moveCommand>(this)),
    cmd_shot(std::make_shared<shotCommand>(this)),
    cmd_bulletMove(std::make_shared<bulletMoveCommand>(this)),
    m_sink(std::make_shared<viewmodelSink>(this))
{}
void viewmodel::set_model(const std::shared_ptr<dataModel>& model)
{
    //qDebug()<<"set_model";
    datamodel=model;
    datamodel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}
dataModel& viewmodel::get_model() throw()
{
    return *datamodel;
}
std::shared_ptr<ICommandBase> viewmodel::get_move_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(cmd_move);
}
std::shared_ptr<ICommandBase> viewmodel::get_bulletMove_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(cmd_bulletMove);
}
std::shared_ptr<ICommandBase> viewmodel::get_shot_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(cmd_shot);
}
std::shared_ptr<Role> viewmodel::get_role()
{
    return datamodel->get_role();
}
std::shared_ptr<Map> viewmodel::get_map()
{
    return datamodel->get_map();
}
std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> viewmodel::get_bullet()
{
    return datamodel->get_bullet();
}
bool viewmodel::move(int i,int j)
{
    //qDebug()<<"viewmodelmove";
    //qDebug()<<i<<j;
    return datamodel->move(i,j);
}
bool viewmodel::bulletMove(int i)
{
    //qDebug()<<"viewmodelbulletMove";
    return datamodel->bulletMove(i);
}
bool viewmodel::bulletMove(Bullet* q)
{
    //qDebug()<<"viewmodelbulletMove";
    datamodel->bulletMove(q);
}
bool viewmodel::enemyMove(double dir,int i)
{
    return datamodel->enemyMove(dir,i);
}
bool viewmodel::shot(double dir)
{
    //qDebug()<<"viewmodelshot";
    return datamodel->shot(dir);
}