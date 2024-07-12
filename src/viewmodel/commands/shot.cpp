#include "shot.h"
#include "../viewmodel.h"
shotCommand::shotCommand(viewmodel* p) throw():pvm(p),param(0.0){}
void shotCommand::SetParameter(const std::any& lparam)
{
    qDebug()<<"SetParameter";
    //qDebug()<<std::any_cast<MoveParameter>(lparam).x<<std::any_cast<MoveParameter>(lparam).y;
    param=std::any_cast<ShotParameter>(lparam);
}
void shotCommand::Exec()
{
    double dir;
    dir=param.dir;
    qDebug()<<"Derection is x:" << dir;
    pvm->shot(dir);
}