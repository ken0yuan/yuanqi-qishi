#ifndef ROLE_H
#define ROLE_H//建议为圆形，适合判断碰撞
#include<string>
#include <QTimer>  
#include <QObject>  
#include <QPainter>  
#include <QWidget>
#include <QKeyEvent>
#include"weapon.h"

#define MAXHP 5
#define MAXSP 5
#define MAXMP 500

class Role{
friend class Weapon;
public:
    Role(int row, int col)
    {
        this->row_id = row;
        this->col_id = col;
        this->speed=15;
        this->radius=70;
        this->direction=0;
        this->HP=4;
        this->MP=356;
        this->SP=3;
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getRadius() const {return radius;};
    int getHP() const {return HP;};
    int getSP() const {return SP;};
    int getMP() const {return MP;};
    int getspeed() const {return speed;};
    int getdirection() const {return direction;};
    void setRow(int row){this->row_id = row;};
    void setCol(int col){this->col_id = col;};
    void setdirection(int dir){this->direction = dir;};
    bool shot(int consume)
    {
        if(MP>=consume)
        {
            MP-=consume;
            return true;
        }
        return false;
    };//武器耗蓝量
    void hurt(int damage)
    {
        if(SP>=damage)
        {
            SP-=damage;
        }
        else
        {
            HP-=damage-SP;
            SP=0;
        }
    };//受伤害
    void recover()
    {
    };//暂定不受伤害多少时间回盾，不回蓝条和血条
    void setRadius(int radius){this->radius = radius;};
private:
    int row_id;
    int col_id;
    int radius;
    int HP;//血条 暂定max为5（UI界面）
    int SP;//盾条 暂定max为5
    int MP;//蓝条 暂定max为500
    int speed;
    int direction;
};
#endif