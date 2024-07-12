#ifndef BULLET_H
#define BULLET_H//暂不确定是贴图还是条状，加入wide和height
#include<string>
//#include <QTimer>  
//#include <QObject>  
//#include <QPainter>  
//#include <QWidget>
#include<QDebug>
class Bullet{
    //Q_OBJECT
public:
    Bullet(int row, int col,int radius ,std::string type, double dir)
    :row_id(row),col_id(col),radius(radius),type(type),dir(dir)
    {
        //qDebug()<<"Bullet init";
        this->row_id = row;
        this->col_id = col;
        if(type == "enemy"||type == "mine")
            this->type = type;
        this->hurt=1;
        this->dir=dir;
        this->radius=radius;
        this->speed=15;
        //timer = new QTimer(this);  
        //QObject::connect(timer, &QTimer::timeout, &Bullet::move); 
        //timer->start(100);
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getRadius() const {return radius;};
    int getHurt() const {return hurt;};
    double getDir() const {return dir;};
    int getSpeed() const {return speed;};
    std::string getType() const{ return type;};
    void setRow(int row){this->row_id = row;};
    void setHurt(int hurt){this->hurt=hurt;};
    void setCol(int col){this->col_id = col;};
    void setRadius(int Radius){this->radius = Radius;};
    void setType(std::string type)
    {
        if(type == "enemy"||type == "mine")
            this->type = type;
    };
public slots: 
    void move()
    {
        this->row_id+=speed*cos(dir);
        this->col_id+=speed*sin(dir);
    };
private:
    int row_id;
    int col_id;
    int radius;
    double dir;//采用弧度制，正右为0
    int speed;
    int hurt;//伤害值,暂定初始伤害为1
    std::string type;
    //QTimer *timer;
};
#endif