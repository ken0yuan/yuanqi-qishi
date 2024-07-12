#ifndef SHOT_H
#define SHOT_H
#include "../../common/base.h"
#include "../../common/parameter.h"
class viewmodel;
class shotCommand: public ICommandBase
{
public:
    shotCommand(viewmodel* p) throw();
    virtual void SetParameter(const std::any &lparam);
    virtual void Exec();
private:
    viewmodel* pvm;
    ShotParameter param;
};
#endif