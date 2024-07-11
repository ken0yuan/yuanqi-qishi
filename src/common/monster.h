#ifndef MONSTER_H
#define MONSTER_H//建议为圆形，适合判断碰撞
//暂时缺少部分关于怪物运动的函数
#include<string>
#include<QObject>
#include<QTimer>
#include<QRandomGenerator>
#include<cmath>
#define FRIGHTEN_RADIUS 200
class Enemy:public QObject{
    Q_OBJECT
public:
    Enemy(int row, int col, std::string type)
    {
        this->row_id = row;
        this->col_id = col;
        if(type == "pig"||type == "boss" ||type == "archer")
            this->type = type;
        this->frighten=false;
        this->speed=5.0;
        startTimer = new QTimer(this);
        moveTimer = new QTimer(this);
        stopTimer = new QTimer(this);
        //connect(startTimer, &QTimer::timeout, &Enemy::startMoving);
        //connect(moveTimer, &QTimer::timeout, &Enemy::move);
        //connect(stopTimer, &QTimer::timeout, &Enemy::stopMoving);
        startTimer->start(2000);
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getRadius() const {return radius;};
    bool getFrighten(int row, int col) 
    {
        if((row-row_id)*(row-row_id)+(col-col_id)*(col-col_id)<=FRIGHTEN_RADIUS*FRIGHTEN_RADIUS)
            frighten=true;
        else
            frighten=false;
        return frighten;
    };
    void attack()//个人理解，不在此处实现，通过判断是否frighten在主函数确定攻击方式
    {  
        if (type=="pig")
        {
            /* code */
        }
        else if (type=="boss")
        {
            /* code */
        }
        else if (type=="archer")
        {
            /* code */
        }
    };//暂定怪物攻击函数
    std::string getType() const{ return type;};
    int returnHurt()
    {
        if(type=="pig")
            return 1;
        else if(type=="boss")
            return 2;
        else if(type=="archer")
            return 3;
        return 0;
    };
    void setRow(int row){this->row_id = row;};
    void setCol(int col){this->col_id = col;};
    void setRadius(int radius){this->radius = radius;};
    void setType(std::string type)
    {
        if(type == "pig"||type == "boss" ||type == "archer")
            this->type = type;
    };
private slots:
    void startMoving()
    {
        dir = QRandomGenerator::global()->bounded(2 * 3.1415926);
        moveTimer->start(100); // 100毫秒后开始移动
        startTimer->stop(); // 停止startTimer
        stopTimer->start(2000); // 停止stopTimer
    };
    void move()
    {
        // 实际移动操作，每次调用时怪物移动一小段距离
        if (!frighten && !stop)
        {
            // 设置moveTimer以较短的间隔重复触发移动操作，模拟缓慢移动
            row_id += speed * cos(dir);
            col_id += speed * sin(dir);
            // 可以添加代码来检查怪物是否移动出了允许的范围或碰到了障碍物
        }
    }
    void stopMoving()
    {
        stop = true;
        moveTimer->stop(); // 停止moveTimer，从而停止移动
        //moveTimer->start(100); // 100毫秒后重新开始移动
        stopTimer->stop(); 
        startTimer->start(2000); // 2000毫秒后重新开始移动
    };
private:
    int row_id;
    int col_id;
    int radius;
    double dir;//采用弧度制，正右为0
    double speed;
    bool stop;//建议采用随机定时赋值，考虑怪在不被惊动时动与否
    bool frighten;//通过采用人与怪的距离判断是否被惊动
    std::string type;
    QTimer *startTimer;
    QTimer *moveTimer;
    QTimer *stopTimer;
};
#endif