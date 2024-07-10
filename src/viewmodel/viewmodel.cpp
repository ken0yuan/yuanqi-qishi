#include "viewmodel.h"
viewmodel::viewmodel():
    cmd_move(std::make_shared<moveCommand>(this))
{}
void viewmodel::set_model(const std::shared_ptr<dataModel>& model)
{
    datamodel=model;
    datamodel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}
std::shared_ptr<ICommandBase> viewmodel::get_move_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(cmd_move);
}
bool viewmodel::move(int i,int j)
{
    return datamodel->move(i,j);
}