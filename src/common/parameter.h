#ifndef PARAMETER_H
#define PARAMETER_H
#include<QString>
#include<string>

class MapParameter
{
public:
    MapParameter() throw();
    MapParameter(const MapParameter& src);
    MapParameter(MapParameter&& src);

    MapParameter(int a, int b)
    {
        chang = a;
        kuan = b;
    };
    MapParameter& operator=(const MapParameter& src)
    {
        if (this!=&src)
        {
            chang = src.chang;
            kuan = src.kuan;
        }
        return *this;
    }
    MapParameter& operator=(MapParameter&& src)
    {
        if (this!=&src)
        {
            chang = src.chang;
            kuan = src.kuan;
        }
        return *this;
    };
public:
    int chang;
    int kuan;
};

class BlockPosParameter{
public:
    BlockPosParameter() throw();
    BlockPosParameter(const BlockPosParameter& src);
    BlockPosParameter(BlockPosParameter&& src);

    BlockPosParameter(int a, int b)
    {
        col = a;
        row = b;
    };
    BlockPosParameter& operator=(const BlockPosParameter& src)
    {
        if (this!=&src)
        {
            col = src.col;
            row = src.row;
        }
        return *this;
    };
    BlockPosParameter& operator=(BlockPosParameter&& src)
    {
        if (this!=&src)
        {
            col = src.col;
            row = src.row;
        }
        return *this;
    };
public:
    int col;
    int row;
};

class OtherPosParameter{
public:
    OtherPosParameter() throw();
    OtherPosParameter(const OtherPosParameter& src);
    OtherPosParameter(OtherPosParameter&& src);

    OtherPosParameter(int a, int b)
    {
        col = a;
        row = b;
    };
    OtherPosParameter& operator=(const OtherPosParameter& src)
    {
        if (this!=&src)
        {
            col = src.col;
            row = src.row;
        }
        return *this;
    };
    OtherPosParameter& operator=(OtherPosParameter&& src)
    {
        if (this!=&src)
        {
            col = src.col;
            row = src.row;
        }
        return *this;
    };
public:
    int row;
    int col;
};

class MoveParameter{
public:
    MoveParameter() throw();
    MoveParameter(const MoveParameter& src);
    MoveParameter(MoveParameter&& src);

    MoveParameter(int a, int b)
    {
        x = a;
        y = b;
    };
    MoveParameter& operator=(const MoveParameter& src)
    {
        if (this!=&src)
        {
            y = src.y;
            x = src.x;
        }
        return *this;
    };
    MoveParameter& operator=(MoveParameter&& src)
    {
        if (this!=&src)
        {
            y = src.y;
            x = src.x;
        }
        return *this;
    };
public:
    int y;
    int x;
};
#endif