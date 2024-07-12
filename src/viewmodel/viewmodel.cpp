#include "viewmodel.h"
viewmodel::viewmodel():
    cmd_move(std::make_shared<moveCommand>(this)),
    m_sink(std::make_shared<viewmodelSink>(this))
{}
void viewmodel::set_model(const std::shared_ptr<dataModel>& model)
{
    qDebug()<<"set_model";
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
std::shared_ptr<Role> viewmodel::get_role()
{
    return datamodel->get_role();
}
std::shared_ptr<Map> viewmodel::get_map()
{
    return datamodel->get_map();
}
bool viewmodel::move(int i,int j)
{
    qDebug()<<"viewmodelmove";
    qDebug()<<i<<j;
    return datamodel->move(i,j);
}
bool viewmodel::bulletMove(int i)
{
    datamodel->bulletMove(i);
}
bool viewmodel::bulletMove(Bullet* q)
{
    datamodel->bulletMove(q);
}
bool viewmodel::enemyMove(double dir,int i)
{
    datamodel->enemyMove(dir,i);
}
bool viewmodel::shot(double dir)
{
    return datamodel->shot(dir);
}