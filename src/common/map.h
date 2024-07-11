#ifndef MAP_H
#define MAP_H
#include"block.h"
#include<vector>
#include<string>
#include<QDebug>
#include<fstream>
#include<iostream>
#include<sstream>
class Map {
public:
    Map(std::string path)
    {
        std::ifstream file(path);
        qDebug()<<"open file";
        if(!file.is_open())
        {
            std::cout<<"open file failed"<<std::endl;
            return;
        }
        std::string line;
        while(getline(file, line))
        {
            std::istringstream iss(line);
            int row, col;
            std::string type;
            iss>>row>>col>>type;
            std::vector<Block> rowVec;
            Block block(row,col,type);
            this->map.push_back(block);
        }
        file.close();
    };
    std::vector<Block> getMap() const {return map;};
    void setMap(std::vector<Block> map){this->map = map;};
    void addBlock(Block block){this->map.push_back(block);};
    void deleteBlock(int row, int col)
    {
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            if(iter->getRowId() == row && iter->getColId() == col)
            {
                map.erase(iter);
                return;
            }
        }
    };
    void deleteBlock(Block block)
    {
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            if(iter->getRowId() == block.getRowId() && iter->getColId() == block.getColId())
            {
                map.erase(iter);
                return;
            }
        }
    };
    bool isRock(int row, int col)
    {
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            if(iter->getRowId() == row && iter->getColId() == col&&iter->getType()=="rock")
            {
                return true;
            }
        }
        return false;
    };
    bool isBox(int row, int col)
    {
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            if(iter->getRowId() == row && iter->getColId() == col&&iter->getType()=="box")
            {
                return true;
            }
        }
        return false;
    };
private:
    std::vector<Block> map;
};
#endif
//map模块里面，我们暂定块的大小为50*50，块的左上角为块的地址，块的类型只能是"rock"或者"box
//其中，col和row是块的行列号，是像素点的坐标除以50得到的
//注意，其他地方的坐标是像素点的坐标，不是行列号