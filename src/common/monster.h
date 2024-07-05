#ifndef MONSTER_H
#define MONSTER_H//建议为圆形，适合判断碰撞
//暂时缺少部分关于怪物运动的函数
#include<string>
class Enemy {
public:
    Enemy(int row, int col, std::string type)
    {
        this->row_id = row;
        this->col_id = col;
        if(type == "pig"||type == "boss" ||type == "archer")
            this->type = type;
        this->frighten=false;
        this->speed=5.0;
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getRadius() const {return radius;};
    bool getFrighten() const {return frighten;};
    std::string getType() const{ return type;};
    void setRow(int row){this->row_id = row;};
    void setCol(int col){this->col_id = col;};
    void setRadius(int radius){this->radius = radius;};
    void setType(std::string type)
    {
        if(type == "pig"||type == "boss" ||type == "archer")
            this->type = type;
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
};
#endif