#include "model.h"
dataModel::dataModel():r(std::make_shared<Role>(50,50)){}
std::shared_ptr<Role> dataModel::get_role() throw()
{
    return r;
}
bool dataModel::move(int i,int j)
{
    int x=r->getRowId();
    int y=r->getColId();
    int *x1,*y1;
    *x1=x+i*r->getspeed();
    *y1=y+j*r->getspeed();
    r->setRow(x1);
    r->setCol(y1);
    return true;
}
