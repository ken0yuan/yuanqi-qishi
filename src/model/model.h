#ifndef MODEL_H
#define MODEL_H
#include "../common/role.h"
#include "../common/monster.h"
#include "../common/bullet.h"
#include "../common/block.h"
#include "../common/weapon.h"
#include "../common/base.h"
#include <memory>
#include <QObject>
#include <QString>
#include <QtDebug>

class dataModel:public Proxy_PropertyNotification<dataModel>
{
public:
    dataModel();
    std::shared_ptr<Role> get_role() throw();
    bool move(int i,int j);
private:
    std::shared_ptr<Role> r;
};

#endif // MODEL_H