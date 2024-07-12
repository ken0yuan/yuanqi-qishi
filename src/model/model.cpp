#include "model.h"
dataModel::dataModel():
    r(std::make_shared<Role>(750,750)),
    m(std::make_shared<Map>("C:/Users/user/Desktop/name/C++/yuanqi_qishi/src/map.txt"))
{
    qDebug()<<m->isRock(1,1);
    qDebug()<<m->isRock(50,52);
    qDebug()<<m->isRock(50,50);
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
    //qDebug()<<"modelmove";
    //qDebug()<<i<<j;
    double di=sqrt(i*i+j*j);
    if((i!=0||j!=0)&&coli(i,j)==false)
    {
        if(i<0)
        {
            //qDebug()<<"leftmove";
            Fire_OnPropertyChanged("leftmove");
            r->setdirection(1);
        }
        else if(i>0)
        {
            //qDebug()<<"rightmove";
            Fire_OnPropertyChanged("rightmove");
            r->setdirection(2);
        }
        else if(j<0)
        {
            //qDebug()<<"upmove";
            Fire_OnPropertyChanged("upmove");
            r->setdirection(4);
        }
        else
        {
            //qDebug()<<"downmove";
            Fire_OnPropertyChanged("downmove");
            r->setdirection(3);
        }
        //qDebug()<<r->getRowId()<<r->getColId();
        int x=r->getRowId();
        int y=r->getColId();
        int x1,y1;
        //qDebug()<<r->getspeed();
        x1=x+(int)((double)i*(double)(r->getspeed())/di);
        y1=y+(int)((double)j*(double)(r->getspeed())/di);
        //qDebug()<<x<<y;
        r->setRow(x1);
        r->setCol(y1);
        return true;
    }//如果没有碰撞就可以正常移动
    Fire_OnPropertyChanged("Nomove");
    r->setdirection(0);
    return true;
}
bool dataModel::coli(int i,int j)
{
    int x=r->getRowId();
    int y=r->getColId();
    int ra=r->getRadius();
    if((m->isBox((x-ra)/50,y/50)||m->isRock((x-ra)/50,y/50))&&i<0)
        return true;
    if((m->isBox(x-ra,y+ra)||m->isRock((x-ra)/50,(y+ra)/50))&&(i<0||j>0))
        return true;
    if((m->isBox(x,y+ra)||m->isRock(x/50,(y+ra)/50))&&j>0)
        return true;
    if((m->isBox(x+ra,y+ra)||m->isRock((x+ra)/50,(y+ra)/50))&&(i>0||j>0))
        return true;
    if((m->isBox(x+ra,y)||m->isRock((x+ra)/50,y/50))&&i>0)
        return true;
    if((m->isBox(x+ra,y-ra)||m->isRock((x+ra)/50,(y-ra)/50))&&(i>0||j<0))
        return true;
    if((m->isBox(x,y-ra)||m->isRock(x/50,(y-ra)/50))&&j<0)
        return true;
    if((m->isBox(x-ra,y-ra)||m->isRock((x-ra)/50,(y-ra)/50))&&(i<0||j<0))
        return true;
    qDebug()<<"not coli";
    return false;
}//如果在运动的方向上和墙接触，就会发生碰撞
