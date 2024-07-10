#include "model.h"
dataModel::dataModel():r(std::make_shared<Role>(50,50)){}
std::shared_ptr<Role> dataModel::get_role() throw()
{
    return r.get();
}
bool dataModel::move(int i,int j)
{
    r.get()->getRowId();
}
