#ifndef MOVE_H
#define MOVE_H
#include "../../common/base.h"
#include "../../common/parameter.h"
class viewmodel;
class moveCommand: public ICommandBase
{
public:
    moveCommand(viewmodel* p) throw();
    virtual void SetParameter(const std::any &lparam);
    virtual void Exec();
private:
    viewmodel* pvm;
    MoveParameter param;
};
#endif