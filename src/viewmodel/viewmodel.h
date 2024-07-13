#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "../model/model.h"
#include "commands/move.h"
#include "commands/bulletMove.h"
#include "commands/shot.h"
#include "../common/base.h"
#include "commands/enemyMove.h"
#include "commands/enemyshot.h"
#include "sink/viewmodelsink.h"
class viewmodel:public Proxy_CommandNotification<viewmodel>,public Proxy_PropertyNotification<viewmodel>
{
public:
    viewmodel();
    void set_model(const std::shared_ptr<dataModel>& model);
    dataModel& get_model() throw();
    std::shared_ptr<ICommandBase> get_move_command() throw();
    std::shared_ptr<ICommandBase> get_bulletMove_command() throw();
    std::shared_ptr<ICommandBase> get_shot_command() throw();
    std::shared_ptr<ICommandBase> get_enemyShot_command() throw();
    std::shared_ptr<ICommandBase> get_enemyMove_command() throw();
    std::shared_ptr<Role> get_role();//获取model里的role属性
    std::shared_ptr<Map> get_map();//获取model里的map属性
    std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> get_bullet();
    std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> get_enemy();
    bool move(int i,int j);//在view里面通过四个按键的状态决定i和j的值，向x正方向移动i为1，反方向为-1
                           //向y正方向移动j为1，反方向为-1。静止时两个都为0
    bool bulletMove(int i);
    bool bulletMove(Bullet* q);
    bool enemyMove(double dir,int i);
    bool shot(double dir);
    bool enemyShot(double dir,int i);
private:
    std::shared_ptr<dataModel> datamodel;
    std::shared_ptr<moveCommand> cmd_move;
    std::shared_ptr<shotCommand> cmd_shot;
    std::shared_ptr<bulletMoveCommand> cmd_bulletMove;
    std::shared_ptr<enemyShotCommand> cmd_enemyShot;
    std::shared_ptr<enemyMoveCommand> cmd_enemyMove;
    std::shared_ptr<viewmodelSink> m_sink;
};
#endif