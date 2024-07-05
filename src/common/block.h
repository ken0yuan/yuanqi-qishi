#ifndef BLOCK_H
#define BLOCK_H
#include<string>
#define BLOCK_WIDTH 50//暂定块的左上角为地址
#define BLOCK_HEIGHT 50
class Block {
public:
    Block(int row, int col, std::string type)
    {
        this->row_id = row;
        this->col_id = col;
        if(type == "rock"||type == "box")
            this->type = type;
        this->exist = true;
    };
    int getRowId() const {return row_id;};
    int getColId() const {return col_id;};
    int getWidth() const {return width;};
    int getHeight()const {return height;};
    std::string getType() const{ return type;};
    bool getExist() const {return exist;};
    void setRow(int row){this->row_id = row;};
    void setCol(int col){this->col_id = col;};
    void setWidth(int width){this->width = width;};
    void setHeight(int height){this->height = height;};
    void setType(std::string type)
    {
        if(type == "rock"||type == "box")//障碍物只能是"rock"||"box"，不然会出现问题
        this->type = type;
    };
    void setExist(bool exist){this->exist = exist;};
private:
    int row_id;
    int col_id;
    int width;
    int height;
    std::string type;
    bool exist;//好像没用，直接删除对象就好
};
#endif