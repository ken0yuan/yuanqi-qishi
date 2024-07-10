#include "model.h"
dataModel::dataModel():
    r(std::make_shared<Role>(500,500)),
    m(std::make_shared<Map>("../../picture/map.txt"))
{}
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
    if(coli(i,j)==false)
    {
        int x=r->getRowId();
        int y=r->getColId();
        int *x1,*y1;
        *x1=x+i*r->getspeed();
        *y1=y+j*r->getspeed();
        r->setRow(x1);
        r->setCol(y1);
        return true;
    }//如果没有碰撞就可以正常移动
}
bool dataModel::coli(int i,int j)
{
    int x=r->getRowId();
    int y=r->getColId();
    int ra=r->getRadius();
    if((m->isBox(x-ra,y)||m->isRock(x-ra,y))&&i<0)
        return true;
    if((m->isBox(x-ra,y+ra)||m->isRock(x-ra,y+ra))&&(i<0||j>0))
        return true;
    if((m->isBox(x,y+ra)||m->isRock(x,y+ra))&&j>0)
        return true;
    if((m->isBox(x+ra,y+ra)||m->isRock(x+ra,y+ra))&&(i>0||j>0))
        return true;
    if((m->isBox(x+ra,y)||m->isRock(x+ra,y))&&i>0)
        return true;
    if((m->isBox(x+ra,y-ra)||m->isRock(x+ra,y-ra))&&(i>0||j<0))
        return true;
    if((m->isBox(x,y-ra)||m->isRock(x,y-ra))&&j<0)
        return true;
    if((m->isBox(x-ra,y-ra)||m->isRock(x-ra,y-ra))&&(i<0||j<0))
        return true;
    return false;
}//如果在运动的方向上和墙接触，就会发生碰撞
