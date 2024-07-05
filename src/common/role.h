#ifndef ROLE_H
#define ROLE_H//建议为圆形，适合判断碰撞
//暂时缺少部分关于怪物运动的函数
#include<string>
class Role {
public:
    Role(int row, int col, std::string type)
    {
        this->row_id = row;
        this->col_id = col;
        if(type == "pig"||type == "boss" ||type == "archer")
            this->type = type;
        this->speed=5.0;
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getRadius() const {return radius;};
    int getHP();
    int getSP();
    int getMP();
    std::string getType() const{ return type;};
    void setRow(int row){this->row_id = row;};
    void setCol(int col){this->col_id = col;};
    void shot(int consume);//武器耗蓝量
    void hurt(int damage);
    void recover();//暂定不受伤害多少时间回盾，不回蓝条和血条
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
    int HP;//血条
    int SP;//盾条
    int MP;//蓝条
    double speed;
    std::string type;
};
#endif