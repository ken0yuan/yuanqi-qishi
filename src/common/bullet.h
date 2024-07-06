#ifndef BULLET_H
#define BULLET_H//暂不确定是贴图还是条状，加入wide和height
#include<string>
#include <QTimer>  
#include <QObject>  
#include <QPainter>  
#include <QWidget>
class Bullet :public QObject{
    Q_OBJECT
public:
    Bullet::Bullet(int row, int col,int height, int width, std::string type, double dir,QObject* parent = nullptr)
    :row_id(row),col_id(col),height(height),width(width),type(type),dir(dir),QObject(parent)
    {
        this->row_id = row;
        this->col_id = col;
        if(type == "enemy"||type == "mine")
            this->type = type;
        this->hurt=1;
        this->dir=dir;
        this->height=height;
        this->width=width;
        this->speed=0.5;
        timer = new QTimer(this);  
        QObject::connect(timer, &QTimer::timeout, &Bullet::move); 
        timer->start(100);
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getWidth() const {return width;};
    int getHeight()const {return height;};
    int getHurt() const {return hurt;};
    double getDir() const {return dir;};
    double getSpeed() const {return speed;};
    std::string getType() const{ return type;};
    void setRow(int row){this->row_id = row;};
    void setHurt(int hurt){this->hurt=hurt;};
    void setCol(int col){this->col_id = col;};
    void setWidth(int width){this->width = width;};
    void setHeight(int height){this->height = height;};
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
    int width;
    int height;
    double dir;//采用弧度制，正右为0
    double speed;
    int hurt;//伤害值,暂定初始伤害为1
    std::string type;
    QTimer *timer;
};
#endif