#include "model.h"
dataModel::dataModel():
    r(std::make_shared<Role>(250,250)),
    m(std::make_shared<Map>("../map.txt"))
{
    r->setGeometry(250,250,100,100);
    r->show();
}
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
    double di=sqrt(i*i+j*j);
    if((i!=0||j!=0)&&coli(i,j)==false)
    {
        if(i<0)
        {
            Fire_OnPropertyChanged("leftmove");
            r->setdirection(1);
        }
        else if(i>0)
        {
            Fire_OnPropertyChanged("rightmove");
            r->setdirection(2);
        }
        else if(j<0)
        {
            Fire_OnPropertyChanged("downmove");
            r->setdirection(3);
        }
        else
        {
            Fire_OnPropertyChanged("upmove");
            r->setdirection(4);
        }
        int x=r->getRowId();
        int y=r->getColId();
        int *x1,*y1;
        *x1=x+(int)(i*r->getspeed()/di);
        *y1=y+(int)(j*r->getspeed()/di);
        r->setRow(x1);
        r->setCol(y1);
        return true;
    }//如果没有碰撞就可以正常移动
    Fire_OnPropertyChanged("Nomove");
    r->setdirection(0);
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
