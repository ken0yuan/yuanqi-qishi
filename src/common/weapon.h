#ifndef WEAPON_H
#define WEAPON_H
#include<string>
class Weapon {
public:
    Weapon(int row, int col, std::string type)
    {
        this->row_id = row;
        this->col_id = col;
        if(type == "sword"||type == "pistol" ||type == "rifle")
            this->type = type;
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getWidth() const {return width;};
    int getHeight()const {return height;};
    double getDir()const {return dir;};
    std::string getType() const{ return type;};
    void setRow(int row){this->row_id = row;};
    void setCol(int col){this->col_id = col;};
    void setType(std::string type)
    {
        if(type == "sword"||type == "pistol" ||type == "rifle")
            this->type = type;
    };
private:
    int row_id;
    int col_id;
    int width;
    int height;
    double dir;//采用弧度制，正右为0
    int consume;
    std::string type;
};
#endif