#include "login.h"
#include "ui_login.h"
/**111
 * 函数名称：login
 * 函数参数：QWidget *parent
 * 函数功能：实现登录框类的构造
 * 返回值：
 **/
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

/**
 * 函数名称：～login
 * 函数参数：
 * 函数功能：登录框类的析构函数
 * 返回值：
 **/
login::~login()
{
    delete ui;
}

/**
 * 函数名称：on_pushButton_clicked
 * 函数参数：
 * 函数功能：实现对soduko框的调用
 * 返回值：
 **/
void login::on_pushButton_clicked()
{
    choosenum=1;
    accept();
}

/**
 * 函数名称：on_pushButton_2_clicked
 * 函数参数：
 * 函数功能：实现对sat框的调用
 * 返回值：
 **/
void login::on_pushButton_2_clicked()
{
    choosenum=2;
    accept();
}
