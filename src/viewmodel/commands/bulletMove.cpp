#include "bulletMove.h"
#include "../viewmodel.h"
bulletMoveCommand::bulletMoveCommand(viewmodel* p) throw():pvm(p),param(0){}
void bulletMoveCommand::SetParameter(const std::any& lparam)
{
    //qDebug()<<"SetParameter";
    //qDebug()<<std::any_cast<MoveParameter>(lparam).x<<std::any_cast<MoveParameter>(lparam).y;
    param=std::any_cast<BulletMoveParameter>(lparam);
}
void bulletMoveCommand::Exec()
{
    int i;
    //qDebug()<<"Derection is x:" << i << " y:" << j;
    pvm->bulletMove(i);
}