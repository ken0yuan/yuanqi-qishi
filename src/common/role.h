#ifndef ROLE_H
#define ROLE_H//建议为圆形，适合判断碰撞
#include<string>
#include <QTimer>  
#include <QObject>  
#include <QPainter>  
#include <QWidget>
#include <QKeyEvent>
#include"weapon.h"
class Role :public QWidget{
friend class Weapon;
public:
    Role(int *row, int *col)
    {
        this->row_id = row;
        this->col_id = col;
        this->speed=5;
        this->radius=20;
        moveTimer = new QTimer(this);  
        connect(moveTimer, &QTimer::timeout, &Role::handleMovement);  
        // 设置定时器间隔  
        int timerInterval = 50; // 50 毫秒  
        moveTimer->setInterval(timerInterval);
    };
    int getRowId() const {return *row_id;};
    int getColId() const {return *col_id;};
    int getRadius() const {return radius;};
    int getHP() const {return HP;};
    int getSP() const {return SP;};
    int getMP() const {return MP;};
    int getspeed() const {return speed;};
    int getdirection() const {return direction;};
    void setRow(int *row){this->row_id = row;};
    void setCol(int *col){this->col_id = col;};
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
protected:  
    void keyPressEvent(QKeyEvent *event) override {  
        if (event->key() == Qt::Key_Left||event->key() == Qt::Key_Right||event->key() == Qt::Key_Up||event->key() == Qt::Key_Down){  
            moveTimer->start();  
        }
    }
    void keyReleaseEvent(QKeyEvent *event) override {  
        if (event->key() == Qt::Key_Left||event->key() == Qt::Key_Right||event->key() == Qt::Key_Up||event->key() == Qt::Key_Down) {  
            moveTimer->stop();  
        }  
    }  
private slots:  
    void handleMovement() {  
        QMap<int, bool> keyState; // Declare and define keyState variable
        if (keyState[Qt::Key_Left]) {  
            *row_id -= speed; // 向左移动  
        }  
        if (keyState[Qt::Key_Right]) {  
            *row_id += speed; // 向右移动  
        }  
        if (keyState[Qt::Key_Up]) {  
            *col_id += speed; // 向上移动  
        }  
        if (keyState[Qt::Key_Down]) {  
            *col_id -= speed; // 向下移动  
        }
    }  
private:
    int *row_id;
    int *col_id;
    int radius;
    int HP;//血条
    int SP;//盾条
    int MP;//蓝条
    int speed;
    int direction;
    QTimer* moveTimer;
};
#endif