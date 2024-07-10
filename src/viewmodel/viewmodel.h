#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "../model/model.h"
#include "commands/move.h"
#include "../common/base.h"
#include "sink/viewmodelsink.h"
class viewmodel:public Proxy_CommandNotification<viewmodel>,public Proxy_PropertyNotification<viewmodel>
{
public:
    viewmodel();
    void set_model(const std::shared_ptr<dataModel>& model);
    dataModel& get_model() throw();
    std::shared_ptr<ICommandBase> get_move_command() throw();
    std::shared_ptr<Role> get_role();//获取model里的role属性
    std::shared_ptr<Map> get_map();//获取model里的map属性
    bool move(int i,int j);//在view里面通过四个按键的状态决定i和j的值，向x正方向移动i为1，反方向为-1
                           //向y正方向移动j为1，反方向为-1。静止时两个都为0
private:
    std::shared_ptr<dataModel> datamodel;
    std::shared_ptr<moveCommand> cmd_move;
    std::shared_ptr<viewmodelSink> m_sink;
};
#endif