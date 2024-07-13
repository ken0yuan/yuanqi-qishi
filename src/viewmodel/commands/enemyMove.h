#ifndef ENEMYMOVE_H
#define ENEMYMOVE_H
#include "../../common/base.h"
#include "../../common/parameter.h"
class viewmodel;
class enemyMoveCommand: public ICommandBase
{
public:
    enemyMoveCommand(viewmodel* p) throw();
    virtual void SetParameter(const std::any &lparam);
    virtual void Exec();
private:
    viewmodel* pvm;
    EnemyParameter param;
};
#endif