#include "model.h"
dataModel::dataModel():
    r(std::make_shared<Role>(750,750)),
    m(std::make_shared<Map>("C:/Users/user/Desktop/name/C++/yuanqi_qishi/src/map.txt")),
    e(),
    b(std::make_shared<std::vector<std::shared_ptr<Bullet>>>())
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
std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> dataModel::get_bullet() throw()
{
    //qDebug()<<"modelgetbullet";
    //qDebug()<<(*b).size();
    return b;
}
bool dataModel::shot(double dir)
{
    //qDebug()<<"modelshot";
    if(r->shot(2))
    b->push_back(std::make_shared<Bullet>(r->getRowId(),r->getColId(), 20, "mine", dir));
    //qDebug()<<b.size();
    Fire_OnPropertyChanged("bulletMove");
    return true;
}
bool dataModel::bulletMove(int i)
{
    //qDebug()<<"modelbulletMove";
    int x=(*b)[i]->getColId();
    int y=(*b)[i]->getRowId();
    double dir=(*b)[i]->getDir();
    int speed=(*b)[i]->getSpeed();
    int radius=(*b)[i]->getRadius();
    //qDebug()<<x<<y<<dir<<radius;
    if (m->isRock((y+radius)/50,(x+radius)/50)||
    m->isRock((y+radius*cos(dir))/50,(x+radius*sin(dir))/50)||
    m->isRock((y-radius)/50,(x+radius)/50)||
    m->isRock((y-radius)/50,(x-radius)/50)||
    m->isRock((y+radius)/50,(x-radius)/50))
    {
        (*b).erase((*b).begin()+i);
        Fire_OnPropertyChanged("bulletMove");
        return true;
    }
    else if(m->isBox((y+radius*cos(dir))/50,(x+radius*sin(dir))/50))
    {
        (*b).erase((*b).begin()+i);
        m->deleteBlock((y+radius*cos(dir))/50,(x+radius*sin(dir))/50);
        Fire_OnPropertyChanged("bulletMove");
        return true;
    }
    else if(m->isBox((y+radius)/50,(x+radius)/50))
    {
        (*b).erase((*b).begin()+i);
        m->deleteBlock((y+radius)/50,(x+radius)/50);
        Fire_OnPropertyChanged("bulletMove");
        return true;
    }
    else if(m->isBox((y-radius)/50,(x+radius)/50))
    {
        (*b).erase((*b).begin()+i);
        m->deleteBlock((y-radius)/50,(x+radius)/50);
        Fire_OnPropertyChanged("bulletMove");
        return true;
    }
    else if(m->isBox((y-radius)/50,(x-radius)/50))
    {
        (*b).erase((*b).begin()+i);
        m->deleteBlock((y-radius)/50,(x-radius)/50);
        Fire_OnPropertyChanged("bulletMove");
        return true;
    }
    else if(m->isBox((y+radius)/50,(x-radius)/50))
    {
        (*b).erase((*b).begin()+i);
        m->deleteBlock((y+radius)/50,(x-radius)/50);
        Fire_OnPropertyChanged("bulletMove");
        return true;
    }
    else{}
    (*b)[i]->setCol(x+speed*sin(dir));
    (*b)[i]->setRow(y+speed*cos(dir));
    Fire_OnPropertyChanged("bulletMove");
    return true;
}
bool dataModel::bulletMove(Bullet* q)
{
    int x=q->getColId();
    int y=q->getRowId();
    double dir=q->getDir();
    int radius=q->getRadius();
    if (m->isRock(y/50,x/50)||m->isRock((y+radius*sin(dir))/50,(x+radius*cos(dir))/50))
    {
        for (int i=0;i<(*b).size();i++)
        {
            if((*b)[i]->getColId()==x&&(*b)[i]->getRowId()==y)
                (*b).erase((*b).begin()+i);
        }
        Fire_OnPropertyChanged("bulletMove");
        return true;
    }
    else if(m->isBox(y/50,x/50)||m->isBox((y+radius*sin(dir))/50,(x+radius*cos(dir))/50)){
        for (int i=0;i<(*b).size();i++)
        {
            if((*b)[i]->getColId()==x&&(*b)[i]->getRowId()==y)
                (*b).erase((*b).begin()+i);
        }
        Fire_OnPropertyChanged("bulletMove");
        m->deleteBlock(y/50,x/50);
        m->deleteBlock((y+radius*sin(dir))/50,(x+radius*cos(dir))/50);
        return true;
    }
    else{}
    q->setCol(x+radius*cos(dir));
    q->setRow(y+radius*sin(dir));
    Fire_OnPropertyChanged("bulletMove");
    return true;
}
bool dataModel::enemyMove(double dir,int i)
{
    return true;
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
    if((m->isBox((x-ra)/50,(y+ra)/50)||m->isRock((x-ra)/50,(y+ra)/50))&&(i<0||j>0))
        return true;
    if((m->isBox(x/50,(y+ra)/50)||m->isRock(x/50,(y+ra)/50))&&j>0)
        return true;
    if((m->isBox((x+ra)/50,(y+ra)/50)||m->isRock((x+ra)/50,(y+ra)/50))&&(i>0||j>0))
        return true;
    if((m->isBox((x+ra)/50,y/50)||m->isRock((x+ra)/50,y/50))&&i>0)
        return true;
    if((m->isBox((x+ra)/50,(y-ra)/50)||m->isRock((x+ra)/50,(y-ra)/50))&&(i>0||j<0))
        return true;
    if((m->isBox(x/50,(y-ra)/50)||m->isRock(x/50,(y-ra)/50))&&j<0)
        return true;
    if((m->isBox((x-ra)/50,(y-ra)/50)||m->isRock((x-ra)/50,(y-ra)/50))&&(i<0||j<0))
        return true;
    qDebug()<<"not coli";
    return false;
}//如果在运动的方向上和墙接触，就会发生碰撞
