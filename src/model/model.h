#ifndef MODEL_H
#define MODEL_H
#include "../common/role.h"
#include "../common/monster.h"
#include "../common/bullet.h"
#include "../common/block.h"
#include "../common/weapon.h"
#include <memory>
#include <QObject>
#include <QString>

class dataModel
{
public:
    dataModel();
    std::shared_ptr<Role> get_role() throw();
    bool leftmove();
    bool rightmove();
    bool upmove();
    bool downmove();
private:
    std::shared_ptr<Role> r;
};

#endif // SWMODEL_H