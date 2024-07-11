#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <any>

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
    runtime->start(1000);
    connect(runtime,SIGNAL(timeout()),this,SLOT(update()));
    qDebug() << "finish connect";
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
    qDebug()<<"set_move_command";
    cmd_move = move_command;
};
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"keyPressEvent";
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
void MainWindow::init()
{
    qDebug()<<"init";
    resize(800, 600);
};
std::shared_ptr<IPropertyNotification> MainWindow::get_property_sink() throw()
{
    qDebug()<<"get_property_sink";
    return std::static_pointer_cast<IPropertyNotification>(m_sink);
};
void MainWindow::paintEvent(QPaintEvent *event)
{
    qDebug()<<"paintEvent";
    QPainter painter(this);
    paint_my_window=&painter;
    QPixmap upImage(":/new/prefix1/images/r1.png");
    QPixmap downImage(":/new/prefix1/images/l3.png");
    QPixmap leftImage(":/new/prefix1/images/l3.png");
    QPixmap rightImage(":/new/prefix1/images/r1.png");
    QPixmap a=leftImage;
    QPixmap b=rightImage;
    //painter.drawPixmap(400,300,100,100,QPixmap(":/new/prefix1/images/l3.png"));
    switch (R->getdirection())
    {
    case 1:
        qDebug()<<"direction1";
        qDebug()<<R->getRowId()<<R->getColId();
        tmp=leftImage;
        painter.drawPixmap(R->getRowId(),R->getColId(),140,140,tmp);
        break;
    case 2:
        qDebug()<<"direction2";
        qDebug()<<R->getRowId()<<R->getColId();
        tmp=rightImage;
        painter.drawPixmap(R->getRowId(),R->getColId(),140,140,tmp);
        break;
    case 3:
        qDebug()<<"direction3";
        qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId(),R->getColId(),140,140,tmp);
        break;
    case 4:
        qDebug()<<"direction4";
        qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId(),R->getColId(),140,140,tmp);
        break;
    case 0:
        qDebug()<<"direction0";
        qDebug()<<R->getRowId()<<R->getColId();
        painter.drawPixmap(R->getRowId(),R->getColId(),140,140,tmp);
        break;
    }
};
void MainWindow::set_role(const std::shared_ptr<Role> r)
{
    qDebug()<<"set_role";
    this->R=r;
}
void MainWindow::set_map(const std::shared_ptr<Map> m)
{
    qDebug()<<"set_map";
    this->M=m;
}