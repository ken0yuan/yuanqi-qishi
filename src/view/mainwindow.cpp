#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <QImage>
#include <any>
#define M_PI       3.14159265358979323846
QPainter *paint_my_window;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_sink(std::make_shared<MainWindowSink>(this))
    , tmp(":/new/prefix1/images/r1.png")
    , direction(std::vector<double>(3,0.0))
    , move_x(0)
    , move_y(0)
{
    ui->setupUi(this);
    //connect(ui->m_move_command.get(), &ICommandBase::CanExecuteChanged, this, &MainWindow::on_can_execute_changed);
    // 设置背景图片
    runtime=new QTimer(this);
    bulletmovetime=new QTimer(this);
    enemyshottime=new QTimer(this);
    //paintflag=0;
    runtime->start(1000);
    bulletmovetime->start(15);
    enemyshottime->start(700);
    connect(runtime,SIGNAL(timeout()),this,SLOT(update()));
    connect(runtime,SIGNAL(timeout()),this,SLOT(slotrandomdirection()));
    connect(bulletmovetime,SIGNAL(timeout()),this,SLOT(slotbulletmove()));
    connect(bulletmovetime,SIGNAL(timeout()),this,SLOT(slotenemymove()));
    connect(bulletmovetime,SIGNAL(timeout()),this,SLOT(slotmove()));
    connect(enemyshottime,SIGNAL(timeout()),this,SLOT(slotenemyshot()));
    qDebug()<<direction[0]<<direction[1]<<direction[2];
    //ui->backgroundLabel->setPixmap(QPixmap(":/images/background.png"));
    //ui->backgroundLabel->setScaledContents(true);
    //ui->backgroundLabel->lower();
//
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::set_move_command(std::shared_ptr<ICommandBase> move_command)
{
    //qDebug()<<"set_move_command";
    cmd_move = move_command;
};
void MainWindow::set_shot_command(std::shared_ptr<ICommandBase> shot_command)
{
    cmd_shot = shot_command;
}
void MainWindow::set_bulletmove_command(std::shared_ptr<ICommandBase> bullet_command)
{
    cmd_bulletmove = bullet_command;
}
void MainWindow::set_enemymove_command(std::shared_ptr<ICommandBase> enemymove_command)
{
    cmd_enemymove = enemymove_command;
}
void MainWindow::set_enemyshot_command(std::shared_ptr<ICommandBase> enemyshot_command)
{
    cmd_enemyshot = enemyshot_command;
}
void MainWindow::slotbulletmove()
{
    for(int i=0;i<(*B).size();i++)
    {
        //qDebug()<<"slotbulletmove";
        std::any param (std::make_any<BulletMoveParameter>());
        BulletMoveParameter& j=std::any_cast<BulletMoveParameter&>(param);
        j.i=i;
        cmd_bulletmove->SetParameter(param);
        cmd_bulletmove->Exec();
    }
}
void MainWindow::slotrandomdirection()
{
    for(int i=0;i<(*E).size();i++)
    {
        direction[i] = QRandomGenerator::global()->bounded(2 * M_PI) - M_PI;
    }
}
void MainWindow::slotenemyshot()
{
    for(int i=0;i<(*E).size();i++)
    {
        if((*E)[i]->getFrighten(R->getRowId(),R->getColId()))
        {
        std::any param (std::make_any<EnemyParameter>());
        EnemyParameter& j=std::any_cast<EnemyParameter&>(param);
        if((*E)[i]->getRowId()==R->getRowId())
        {
            if(R->getColId()>(*E)[i]->getRowId())
                j.dir=M_PI/2.0;
            else
                j.dir=-M_PI/2.0;
        }
        else
        {
            double k=(double)(R->getColId()-(*E)[i]->getColId())/(double)(R->getRowId()-(*E)[i]->getRowId());
            if(R->getColId()>(*E)[i]->getColId())
            {
                if(k>0)
                    j.dir=atan(k);
                else
                    j.dir=atan(k)+M_PI;
            }
            else
            {
                if(k>0)
                    j.dir=atan(k)-M_PI;
                else
                    j.dir=atan(k);
            }
        }
        j.i=i;
        cmd_enemyshot->SetParameter(param);
        cmd_enemyshot->Exec();
        }
    }
}
void MainWindow::slotenemymove()
{
    for(int i=0;i<(*E).size();i++)
    {
        //qDebug()<<"slotenemymove";
        std::any param (std::make_any<EnemyParameter>());
        EnemyParameter& j=std::any_cast<EnemyParameter&>(param);
        j.dir=direction[i];
        j.i=i;
        //qDebug()<<j.dir<<j.i;
        cmd_enemymove->SetParameter(param);
        cmd_enemymove->Exec();
    }
}
void MainWindow::slotmove()
{
    std::any param (std::make_any<MoveParameter>());
    MoveParameter& dir= std::any_cast<MoveParameter&>(param);
    dir.x=move_x;
    dir.y=move_y;
    cmd_move->SetParameter(param);
    cmd_move->Exec();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"keyPressEvent";
    if (event->key() == Qt::Key_W||event->key() == Qt::Key_A||event->key() == Qt::Key_S||event->key() == Qt::Key_D)
    {
        if (event->key() == Qt::Key_W)
        {
            move_y = -1;
        }
        if (event->key() == Qt::Key_A)
        {
            move_x = -1;
        }
        if (event->key() == Qt::Key_S)
        {
            move_y = 1;
        }
        if (event->key() == Qt::Key_D)
        {
            move_x = 1;
        }
    }
};
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W||event->key() == Qt::Key_A||event->key() == Qt::Key_S||event->key() == Qt::Key_D)
    {
        if (event->key() == Qt::Key_W && move_y==-1)
        {
            move_y = 0;
        }
        if (event->key() == Qt::Key_A && move_x==-1)
        {
            move_x = 0;
        }
        if (event->key() == Qt::Key_S && move_y==1)
        {
            move_y = 0;
        }
        if (event->key() == Qt::Key_D && move_x==1)
        {
            move_x = 0;
        }
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    click_x=event->x();
    click_y=event->y();
    if(event->buttons()==(Qt::LeftButton))
    {
        //qDebug()<<"Shot";
        std::any param (std::make_any<ShotParameter>());
        ShotParameter& dir= std::any_cast<ShotParameter&>(param);
        if(click_x==R->getRowId())
        {
            if(click_y>R->getColId())
                dir.dir=M_PI/2.0;
            else
                dir.dir=-M_PI/2.0;
        }
        else
        {
            double k=(double)(click_y-R->getColId())/(double)(click_x-R->getRowId());
            if(click_y>R->getColId())
            {
                if(k>0)
                    dir.dir=atan(k);
                else
                    dir.dir=atan(k)+M_PI;
            }
            else
            {
                if(k>0)
                    dir.dir=atan(k)-M_PI;
                else
                    dir.dir=atan(k);
            }
        }
        cmd_shot->SetParameter(param);
        //qDebug()<<dir.dir;
        cmd_shot->Exec();
    }
}
void MainWindow::init()
{
    //qDebug()<<"init";
    resize(3000, 2000);
};
std::shared_ptr<IPropertyNotification> MainWindow::get_property_sink() throw()
{
    //qDebug()<<"get_property_sink";
    return std::static_pointer_cast<IPropertyNotification>(m_sink);
};
void MainWindow::paintEvent(QPaintEvent *event)
{
    //qDebug()<<"paintEvent";
    QPainter painter(this);
    paint_my_window=&painter;
    QPixmap upImage(":/new/prefix1/images/r1.png");
    QPixmap downImage(":/new/prefix1/images/l3.png");
    QPixmap leftImage(":/new/prefix1/images/l3.png");
    QPixmap rightImage(":/new/prefix1/images/r1.png");
    QPixmap rockImage(":/new/prefix1/images/rock.png");
    QPixmap grassImage(":/new/prefix1/images/grass.png");
    QPixmap bulletImage(":/new/prefix1/images/bullet.png");
    QPixmap enemybulletImage(":/new/prefix1/images/enemybullet.png");
    QPixmap boxImage(":/new/prefix1/images/box.png");
    QPixmap pigImage(":/new/prefix1/images/pig.png");
    QPixmap bossImage(":/new/prefix1/images/boss.png");
    QPixmap archerImage(":/new/prefix1/images/archer.png");
    QPixmap a=leftImage;
    QPixmap b=rightImage;
    //painter.drawPixmap(400,300,100,100,QPixmap(":/new/prefix1/images/l3.png"));
    //if(paintflag==0)
    //{
    for(int i=500;i<=2000;i+=50)
    {
        for(int j=0;j<=1500;j+=50)
        {
            if(M->isRock(i/50,j/50))
                painter.drawPixmap(i,j,50,50,rockImage);
            else if(M->isBox(i/50,j/50))
                painter.drawPixmap(i,j,50,50,boxImage);
            else 
                painter.drawPixmap(i,j,50,50,grassImage);
        }
    }
    int rrr=R->getRadius();
    switch (R->getdirection())
    {
    case 1:
        //qDebug()<<"direction1";
        //qDebug()<<R->getRowId()<<R->getColId();
        tmp=leftImage;
        painter.drawPixmap(R->getRowId()-rrr,R->getColId()-rrr,rrr*2,rrr*2,tmp);
        break;
    case 2:
        //qDebug()<<"direction2";
        //qDebug()<<R->getRowId()<<R->getColId();
        tmp=rightImage;
        painter.drawPixmap(R->getRowId()-rrr,R->getColId()-rrr,rrr*2,rrr*2,tmp);
        break;
    case 3:
        //qDebug()<<"direction3";
        //qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId()-rrr,R->getColId()-rrr,rrr*2,rrr*2,tmp);
        break;
    case 4:
        //qDebug()<<"direction4";
        //qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId()-rrr,R->getColId()-rrr,rrr*2,rrr*2,tmp);
        break;
    case 0:
        //qDebug()<<"direction0";
        //qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId()-rrr,R->getColId()-rrr,rrr*2,rrr*2,tmp);
        break;
    }
    for(int i=0;i<(*E).size();i++)
    {
        int radius=(*E)[i]->getRadius();
        if((*E)[i]->getType()=="pig")
            painter.drawPixmap((*E)[i]->getRowId()-radius,(*E)[i]->getColId()-radius,2*radius,2*radius,pigImage);
        else if((*E)[i]->getType()=="boss")
            painter.drawPixmap((*E)[i]->getRowId()-radius,(*E)[i]->getColId()-radius,2*radius,2*radius,bossImage);
        else
            painter.drawPixmap((*E)[i]->getRowId()-radius,(*E)[i]->getColId()-radius,2*radius,2*radius,archerImage);
    }
    for(int i=0;i<(*B).size();i++)
    {
        int radius=(*B)[i]->getRadius();
        if((*B)[i]->getType()=="mine")
            painter.drawPixmap((*B)[i]->getRowId()-radius,(*B)[i]->getColId()-radius,radius*2,radius*2,bulletImage);
        else
            painter.drawPixmap((*B)[i]->getRowId()-radius,(*B)[i]->getColId()-radius,radius*2,radius*2,enemybulletImage);
    }
    /*
    painter.setBrush(Qt::red);
    painter.drawRect(0, 0, 200,50);
    painter.setBrush(Qt::transparent);
    painter.drawRect(200, 0,100,50);
    */
   /*
      painter.setRenderHint(QPainter::Antialiasing, true); // 启用抗锯齿以获得更平滑的边缘

        // 设置矩形的位置和大小
        QRect rect(50, 50, 400, 300);
        
        // 设置圆角半径
        int cornerRadius = 20;

        // 设置填充颜色和边框颜色
        QColor customColor = QColor::fromRgb(173, 216, 230); // 浅蓝色 (LightBlue)
        painter.setBrush(customColor);
        painter.setPen(Qt::black);

        // 绘制带有圆角的矩形
        painter.drawRoundedRect(rect, cornerRadius, cornerRadius);

        painter.setBrush(Qt::red);
        painter.drawRect(100, 100, 200,40);
        painter.setBrush(Qt::transparent);
        painter.drawRect(300, 100,100,40);

        painter.setBrush(Qt::blue);
        painter.drawRect(100, 160, 200,40);
        painter.setBrush(Qt::transparent);
        painter.drawRect(300, 160,100,40);


        painter.setBrush(Qt::gray);
        painter.drawRect(100, 220, 200,40);
        painter.setBrush(Qt::transparent);
        painter.drawRect(300, 220,100,40);
   */
    QImage stateboard(":/new/prefix1/images/stateboard.png");
    QImage redbar(":/new/prefix1/images/red.png");
    QImage bluebar(":/new/prefix1/images/blue.png");
    QImage greybar(":/new/prefix1/images/grey.png");
    QImage scaledImage = stateboard.scaled(400,800, Qt::KeepAspectRatio);
    int nowHP,nowMP,nowSP;
    nowHP = R->getHP();
    nowMP = R->getMP();
    nowSP = R->getSP();
    QImage red = redbar.scaled(((double)nowHP/MAXHP)*290,36);
    QImage blue = bluebar.scaled(((double)nowMP/MAXMP)*290,36);
    QImage grey = greybar.scaled(((double)nowSP/MAXSP)*290,36);
    painter.drawImage(50, 50, scaledImage);
    painter.drawImage(132,72,red);
    painter.drawImage(132,116,grey);
    painter.drawImage(132,166,blue);
    for (int i = 0; i < (*E).size(); i++)
    {
        QImage monsterHP;
        if((*E)[i]->getType()=="pig")
            monsterHP = redbar.scaled(((double)(*E)[i]->getHP()/pigMaxHP)*(*E)[i]->getRadius()*2,18);
        else if((*E)[i]->getType()=="boss")
            monsterHP = redbar.scaled(((double)(*E)[i]->getHP()/bossMaxHP)*(*E)[i]->getRadius()*2,18);
        else
            monsterHP = redbar.scaled(((double)(*E)[i]->getHP()/archerMaxHP)*(*E)[i]->getRadius()*2,18);
        painter.drawImage((*E)[i]->getRowId()-(*E)[i]->getRadius(),(*E)[i]->getColId()-(*E)[i]->getRadius()-20,monsterHP);
    }
    QFont font("Arial", 20); // 字体、大小
    painter.setFont(font);
    painter.setPen(Qt::white);

    QString redstring = QString::number(nowHP);
    QString bluestring = QString::number(nowMP);
    QString greystring  = QString::number(nowSP);
    redstring += "/5";
    bluestring += "/500";
    greystring += "/5";

    painter.drawText(252,98,redstring);
    painter.drawText(252,144,greystring);
    painter.drawText(212,196,bluestring);


}
void MainWindow::set_role(const std::shared_ptr<Role> r)
{
    //qDebug()<<"set_role";
    this->R=r;
}
void MainWindow::set_map(const std::shared_ptr<Map> m)
{
    //qDebug()<<"set_map";
    this->M=m;
}
void MainWindow::set_bullet(const std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> b)
{
    //qDebug()<<"set_bullet";
    this->B=b;
}
void MainWindow::set_enemy(const std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> e)
{
    //qDebug()<<"set_enemy";
    this->E=e;
}