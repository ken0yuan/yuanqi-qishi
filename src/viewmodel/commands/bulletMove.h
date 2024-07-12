#ifndef BULLETMOVE_H
#define BULLETMOVE_H
#include "../../common/base.h"
#include "../../common/parameter.h"
class viewmodel;
class bulletMoveCommand: public ICommandBase
{
public:
    bulletMoveCommand(viewmodel* p) throw();
    virtual void SetParameter(const std::any &lparam);
    virtual void Exec();
private:
    viewmodel* pvm;
    BulletMoveParameter param;
};
#endif