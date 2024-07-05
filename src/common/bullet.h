#ifndef BULLET_H
#define BULLET_H//暂不确定是贴图还是条状，加入wide和height
#include<string>
class Bullet {
public:
    Bullet(int row, int col,int height, int width, std::string type, double dir)
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
private:
    int row_id;
    int col_id;
    int width;
    int height;
    double dir;//采用弧度制，正右为0
    double speed;
    int hurt;//伤害值,暂定初始伤害为1
    std::string type;
};
#endif