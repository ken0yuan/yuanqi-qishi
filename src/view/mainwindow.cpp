#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <qwidget.h>
#include <any>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_sink(std::make_shared<MainWindowSink>(this))
{
    ui->setupUi(this);
    //connect(ui->m_move_command.get(), &ICommandBase::CanExecuteChanged, this, &MainWindow::on_can_execute_changed);
    // 设置背景图片
    runtime=new QTimer(this);
    connect(runtime,SIGNAL(timeout()),this,SLOT(on_secondadd()));
    runtime->start(1000);
    connect(runtime,SIGNAL(timeout()),this,SLOT(update()));
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
    cmd_move = move_command;
};
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W||event->key() == Qt::Key_A||event->key() == Qt::Key_S||event->key() == Qt::Key_D)
    {
        std::any param2 (std::make_any<MoveParameter>());
        MoveParameter& dir= std::any_cast<MoveParameter&>(param2);
        if (event->key() == Qt::Key_W)
        {
            dir.y = 1;
        }
        if (event->key() == Qt::Key_A)
        {
            dir.x = -1;
        }
        if (event->key() == Qt::Key_S)
        {
            dir.y = -1;
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
    resize(800, 600);
};
std::shared_ptr<IPropertyNotification> MainWindow::get_property_sink() throw()
{
    return std::static_pointer_cast<IPropertyNotification>(m_sink);
};
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    paint_my_window=&painter;
    QPixmap upImage = QPixmap("../images/l3.png");
    QPixmap downImage = QPixmap("../images/l3.png");
    QPixmap leftImage = QPixmap("../images/l3.png");
    QPixmap rightImage = QPixmap("../images/r1.png");
    switch (R->getdirection)
    {
    case 1:
        setPixmap(upImage);
        break;
    case 2:
        setPixmap(downImage);
        break;
    case 3:
        setPixmap(leftImage);
        break;
    case 4:
        setPixmap(rightImage);
        break;
    case 0:
        setPixmap(rightImage);
        break;
    }
};
void MainWindow::set_role(const std::shared_ptr<Role> r)
{
    this->R=r;
}
void MainWindow::set_map(const std::shared_ptr<Map> m)
{
    this->M=m;
}