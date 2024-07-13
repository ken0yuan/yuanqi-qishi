#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QWidget>
#include <QRandomGenerator>
#include <cmath>
#include <any>
#include "../common/parameter.h"
#include "../common/role.h"
#include "../common/map.h"
#include "../common/base.h"
#include "../common/bullet.h"
#include "../common/monster.h"
#include "sink/mainwindowsink.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_move_command(std::shared_ptr<ICommandBase> move_command);
    void set_shot_command(std::shared_ptr<ICommandBase> shot_command);
    void set_bulletmove_command(std::shared_ptr<ICommandBase> bullet_command);
    void set_enemymove_command(std::shared_ptr<ICommandBase> enemymove_command);
    void set_enemyshot_command(std::shared_ptr<ICommandBase> enemyshot_command);
    void set_role(const std::shared_ptr<Role> r);
    void set_map(const std::shared_ptr<Map> m);
    void set_bullet(const std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> b);
    void set_enemy(const std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> e);
    void init();
    std::shared_ptr<IPropertyNotification> get_property_sink() throw();
public slots:
    void slotbulletmove();
    void slotrandomdirection();
    void slotenemymove();
    void slotenemyshot();
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::MainWindow *ui;
    std::shared_ptr<Role> R;
    std::shared_ptr<Map> M;
    std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> B;
    std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> E;
    std::shared_ptr<ICommandBase> cmd_shot;
    std::shared_ptr<ICommandBase> cmd_move;
    std::shared_ptr<ICommandBase> cmd_bulletmove;
    std::shared_ptr<ICommandBase> cmd_enemymove;
    std::shared_ptr<ICommandBase> cmd_enemyshot;
    std::shared_ptr<MainWindowSink> m_sink;
    QTimer *runtime;
    QTimer *bulletmovetime;
    QTimer *enemyshottime;
    int click_x,click_y;
    std::vector<double> direction;
    QPixmap tmp;
};

#endif // MAINWINDOW_H
