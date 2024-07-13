#include "enemyshot.h"
#include "../viewmodel.h"
enemyShotCommand::enemyShotCommand(viewmodel* p) throw():pvm(p),param(0,0){}
void enemyShotCommand::SetParameter(const std::any& lparam)
{
    //qDebug()<<"SetParameter";
    //qDebug()<<std::any_cast<MoveParameter>(lparam).x<<std::any_cast<MoveParameter>(lparam).y;
    param=std::any_cast<EnemyParameter>(lparam);
}
void enemyShotCommand::Exec()
{
    double dir;
    int i;
    //qDebug()<<"Derection is x:" << i << " y:" << j;
    pvm->enemyShot(dir,i);
}