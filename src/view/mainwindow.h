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
#include <any>
#include "../common/parameter.h"
#include "../common/role.h"
#include "../common/map.h"
#include "../common/base.h"
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
    void set_role(const std::shared_ptr<Role> r);
    void set_map(const std::shared_ptr<Map> m);
    void init();
    std::shared_ptr<IPropertyNotification> get_property_sink() throw();
    
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Role> R;
    std::shared_ptr<Map> M;
    std::shared_ptr<ICommandBase> cmd_move;
    std::shared_ptr<MainWindowSink> m_sink;
    QTimer *runtime;
    QPixmap tmp;
};

#endif // MAINWINDOW_H
