#ifndef ENEMYSHOT_H
#define ENEMYSHOT_H
#include "../../common/base.h"
#include "../../common/parameter.h"
class viewmodel;
class enemyShotCommand: public ICommandBase
{
public:
    enemyShotCommand(viewmodel* p) throw();
    virtual void SetParameter(const std::any &lparam);
    virtual void Exec();
private:
    viewmodel* pvm;
    EnemyParameter param;
};
#endif