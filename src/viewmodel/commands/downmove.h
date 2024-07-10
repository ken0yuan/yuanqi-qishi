#ifndef DOWNMOVE_H
#define DOWNMOVE_H
#include "../../common/base.h"
class downmoveCommand: public ICommandBase
{
public:
    virtual void Exec();
private:
    int ismove;
};
#endif