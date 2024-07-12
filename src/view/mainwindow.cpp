#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <any>
#define M_PI       3.14159265358979323846
QPainter *paint_my_window;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_sink(std::make_shared<MainWindowSink>(this))
    , tmp(":/new/prefix1/images/r1.png")
{
    ui->setupUi(this);
    //connect(ui->m_move_command.get(), &ICommandBase::CanExecuteChanged, this, &MainWindow::on_can_execute_changed);
    // 设置背景图片
    runtime=new QTimer(this);
    //paintflag=0;
    runtime->start(1000);
    connect(runtime,SIGNAL(timeout()),this,SLOT(update()));
    //qDebug() << "finish connect";
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
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"keyPressEvent";
    if (event->key() == Qt::Key_W||event->key() == Qt::Key_A||event->key() == Qt::Key_S||event->key() == Qt::Key_D)
    {
        std::any param2 (std::make_any<MoveParameter>());
        MoveParameter& dir= std::any_cast<MoveParameter&>(param2);
        dir.x=0;
        dir.y=0;
        if (event->key() == Qt::Key_W)
        {
            dir.y = -1;
        }
        if (event->key() == Qt::Key_A)
        {
            dir.x = -1;
        }
        if (event->key() == Qt::Key_S)
        {
            dir.y = 1;
        }
        if (event->key() == Qt::Key_D)
        {
            dir.x = 1;
        }
        cmd_move->SetParameter(param2);
        cmd_move->Exec();
    }
};
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    click_x=event->x();
    click_y=event->y();
    if(event->buttons()==(Qt::LeftButton))
    {
        qDebug()<<"Shot";
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
        qDebug()<<dir.dir;
        cmd_shot->Exec();
    }
}
void MainWindow::init()
{
    //qDebug()<<"init";
    resize(800, 600);
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
            else 
                painter.drawPixmap(i,j,50,50,grassImage);
        }
    }
    switch (R->getdirection())
    {
    case 1:
        qDebug()<<"direction1";
        qDebug()<<R->getRowId()<<R->getColId();
        tmp=leftImage;
        painter.drawPixmap(R->getRowId()-70,R->getColId()-70,140,140,tmp);
        break;
    case 2:
        qDebug()<<"direction2";
        qDebug()<<R->getRowId()<<R->getColId();
        tmp=rightImage;
        painter.drawPixmap(R->getRowId()-70,R->getColId()-70,140,140,tmp);
        break;
    case 3:
        qDebug()<<"direction3";
        qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId()-70,R->getColId()-70,140,140,tmp);
        break;
    case 4:
        qDebug()<<"direction4";
        qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId()-70,R->getColId()-70,140,140,tmp);
        break;
    case 0:
        qDebug()<<"direction0";
        qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId()-70,R->getColId()-70,140,140,tmp);
        break;
    }
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