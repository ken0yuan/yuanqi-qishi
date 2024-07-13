#include "enemyMove.h"
#include "../viewmodel.h"
enemyMoveCommand::enemyMoveCommand(viewmodel* p) throw():pvm(p),param(0.0,0){}
void enemyMoveCommand::SetParameter(const std::any& lparam)
{
    //qDebug()<<"SetParameter";
    //qDebug()<<std::any_cast<MoveParameter>(lparam).x<<std::any_cast<MoveParameter>(lparam).y;
    param=std::any_cast<EnemyParameter>(lparam);
}
void enemyMoveCommand::Exec()
{
    double dir;
    int i;
    dir=param.dir;
    i=param.i;
    //qDebug()<<"Derection is dir:" << dir << " i:" << i;
    pvm->enemyMove(dir,i);
}