#include "yuanqi_qishi.h"

yuanqi_qishi::yuanqi_qishi(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_yuanqi_qishi)
{
    ui->setupUi(this);
}

yuanqi_qishi::~yuanqi_qishi()
{
    delete ui; 
}