#include "model.h"
dataModel::dataModel():r(std::make_shared<Role>(50,50)),m(std::make_shared<Map>("../../picture/map.txt")){}
std::shared_ptr<Role> dataModel::get_role() throw()
{
    return r;
}
std::shared_ptr<Map> dataModel::get_map() throw()
{
    return m;
}
bool dataModel::move(int i,int j)
{
    if(coli()==false)
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
}
bool dataModel::coli()
{
    int x=r->getRowId();
    int y=r->getColId();
    int ra=r->getRadius();
    if(m->isBox(x-ra,y)||m->isRock(x-ra,y))
        return true;
    if(m->isBox(x-ra,y+ra)||m->isRock(x-ra,y+ra))
        return true;
    if(m->isBox(x,y+ra)||m->isRock(x,y+ra))
        return true;
    if(m->isBox(x+ra,y+ra)||m->isRock(x+ra,y+ra))
        return true;
    if(m->isBox(x+ra,y)||m->isRock(x+ra,y))
        return true;
    if(m->isBox(x+ra,y-ra)||m->isRock(x+ra,y-ra))
        return true;
    if(m->isBox(x,y-ra)||m->isRock(x,y-ra))
        return true;
    if(m->isBox(x-ra,y-ra)||m->isRock(x-ra,y-ra))
        return true;
    return false;
}
