#include "move.h"
#include "../viewmodel.h"
moveCommand::moveCommand(viewmodel* p) throw():pvm(p),param(0,0){}
void moveCommand::SetParameter(const std::any& lparam)
{
    //qDebug()<<"SetParameter";
    //qDebug()<<std::any_cast<MoveParameter>(lparam).x<<std::any_cast<MoveParameter>(lparam).y;
    param=std::any_cast<MoveParameter>(lparam);
}
void moveCommand::Exec()
{
    int i,j;
    i=param.x;
    j=param.y;
    //qDebug()<<"Derection is x:" << i << " y:" << j;
    pvm->move(i,j);
}