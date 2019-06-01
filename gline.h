#ifndef GLINE_H
#define GLINE_H

//画线类
#include <QWidget>
#include <QPainter>
#include <QColor>

class GLine:public QWidget
{
public :
    GLine(QWidget *parent=0);
    void setPen(int penSize,const QColor & color);  //设置画线颜色 宽度
    void draw(int z, int len); //z=0 H,z=1,V       设置画线坐标

protected:
    void paintEvent(QPaintEvent *);

private:
    int penSize;   //宽度
    QColor penColor;  //颜色
    int z;
    int len;
};
#endif // GLINE_H

