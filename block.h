//格子类 用来实现格子的取值 变色 赋值等操作
#ifndef BLOCK_H
#define BLOCK_H
#include <QLineEdit>
#include <QRegExp>
#include <QValidator>
#include <QtGui>
#include <QPalette>

class Block :public QWidget
{
    Q_OBJECT

public:
    Block(QWidget *parent=0);               //类构造函数
    void setValue(int a);                   //设置值
    int getValue();                         //获取值
    void changeColor(const QColor &color);  //更改颜色
private slots:
    void dataChange(const QString & data);  //修改后检查答案是否填完
    void valueChange();                     //修改值的同时发信号检测冲突变色
signals:
    void valueChanged();                    //信号
    void confirmAnswers();                  //信号
private:
    QLineEdit *nubEidt;
    int da;
    QPalette pal;
};
#endif // BLOCK_H
