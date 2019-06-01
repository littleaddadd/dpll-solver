#ifndef LOGIN_H
#define LOGIN_H
//登录框类
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
     int choosenum=0;

private slots:
    void on_pushButton_clicked();   //对应soduko按钮
    void on_pushButton_2_clicked();  //对应sat求解器按钮
private:
    Ui::login *ui;
};

#endif // LOGIN_H
