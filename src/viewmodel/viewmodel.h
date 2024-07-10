#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "../model/model.h"
#include "commands/move.h"
#include "../common/base.h"
class viewmodel
{
public:
    viewmodel();
    void set_model(const std::shared_ptr<dataModel>& model);
    std::shared_ptr<ICommandBase> get_move_command() throw();
    bool move(int i,int j);
private:
    std::shared_ptr<dataModel> datamodel;
    std::shared_ptr<moveCommand> cmd_move;
};
#endif