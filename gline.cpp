#include "gline.h"
/**
 * 函数名称：Gline
 * 函数参数：QWidget *parent
 * 函数功能：构造函数
 * 返回值：
 **/
GLine::GLine(QWidget *parent)
    :QWidget(parent)
{
    setPen(3,QColor(Qt::black));
    draw(0,100);
}

/**
 * 函数名称：setPen
 * 函数参数：int penSize, const QColor &color
 * 函数功能：设置线的宽度和颜色
 * 返回值：void
 **/
void GLine::setPen(int penSize, const QColor &color)
{
    this->penSize=penSize;   //宽度
    this->penColor=color;    //颜色
}

/**
 * 函数名称：draw
 * 函数参数：int z, int len
 * 函数功能：设置画线
 * 返回值：void
 **/
void GLine::draw(int z, int len)
{
    this->z=z;
    this->len=len;

    if(z==0)
    {
        setMinimumSize(len,penSize);
        setMaximumSize(len,penSize);
    }
    else
    {
        setMinimumSize(penSize,len);
        setMaximumSize(penSize,len);
    }
    this->update();
}

/**
 * 函数名称：paintEvent
 * 函数参数：QPaintEvent *
 * 函数功能：调用函数完成画线准备
 * 返回值：void
 **/
void GLine::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(penSize);
    pen.setColor(penColor);
    int sx,sy,ex,ey;
    if(z==0)
    {
        sx=0;
        sy=penSize/2;
        ex=len;
        ey=sy;
    }
    else
    {
        sx=penSize/2;
        sy=0;
        ex=sx;
        ey=len;
    }
    painter.setPen(pen);
    painter.drawLine(sx,sy,ex,ey);
}
