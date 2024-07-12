#ifndef MODEL_H
#define MODEL_H
#include "../common/role.h"
#include "../common/monster.h"
#include "../common/bullet.h"
#include "../common/block.h"
#include "../common/weapon.h"
#include "../common/base.h"
#include "../common/map.h"
#include <memory>
#include <QObject>
#include <QString>
#include <QtDebug>

class dataModel:public Proxy_PropertyNotification<dataModel>
{
public:
    dataModel();
    std::shared_ptr<Role> get_role() throw();
    std::shared_ptr<Map> get_map() throw();
    std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> get_bullet() throw();
    bool move(int i,int j);
    bool shot(double dir);
    bool bulletMove(int i);
    bool bulletMove(Bullet* q);
    bool enemyMove(double dir,int i);
    bool coli(int i,int j);
private:
    std::shared_ptr<Role> r;
    std::shared_ptr<Map> m;
    std::vector<std::shared_ptr<Enemy>> e;
    std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> b;
};

#endif // MODEL_H