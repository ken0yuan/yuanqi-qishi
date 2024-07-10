#ifndef DOWNMOVE_H
#define DOWNMOVE_H
#include "../../common/etlbase.h"
class downmoveCommand: public ICommandBase
{
public:
    virtual void set(int move);
    virtual void Exec();
private:
    int ismove;
};
#endif