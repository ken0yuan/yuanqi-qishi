#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "../model/model.h"
#include "commands/leftmove.h"
#include "commands/rightmove.h"
#include "commands/upmove.h"
#include "commands/downmove.h"
#include "../common/etlbase.h"
class viewmodel
{
public:
    viewmodel();
    void set_model(const std::shared_ptr<dataModel>& model);
    std::shared_ptr<ICommandBase> get_leftmove_command() throw();
    std::shared_ptr<ICommandBase> get_rightmove_command() throw();
    std::shared_ptr<ICommandBase> get_upmove_command() throw();
    std::shared_ptr<ICommandBase> get_downmove_command() throw();
    bool leftmove();
    bool rightmove();
    bool upmove();
    bool downmove();
private:
    std::shared_ptr<dataModel> datamodel;
    std::shared_ptr<leftmoveCommand> cmd_leftmove;
    std::shared_ptr<rightmoveCommand> cmd_rightmove;
    std::shared_ptr<upmoveCommand> cmd_upmove;
    std::shared_ptr<downmoveCommand> cmd_downmove;
};
#endif