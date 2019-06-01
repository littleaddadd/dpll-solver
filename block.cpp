#include "block.h"
/**
 * 函数名称：Block
 * 函数参数：QWidget *parent
 * 函数功能：类构造
 * 返回值：
 **/
Block::Block(QWidget *parent)
    :QWidget(parent)
{
    nubEidt=new QLineEdit(this);
    nubEidt->setAlignment(Qt::AlignCenter);

    QFont font;
    font.setPixelSize(30);

    QPalette palette=this->palette();
    palette.setColor(QPalette ::Disabled,QPalette::Text,Qt::black);

    nubEidt->setPalette(palette);
    nubEidt->setFont(font);
    nubEidt->setMinimumSize(50,50);
    nubEidt->setMaximumSize(50,50);

    QRegExp regExp("[1-9]{1}");
    nubEidt->setValidator(new QRegExpValidator(regExp,this));

    connect(nubEidt,SIGNAL(textChanged(QString)),this,SLOT(dataChange(QString))); //内容改变时产生信号
    connect(nubEidt,SIGNAL(textEdited(QString)),this,SLOT(valueChange()));        //内容编辑时产生信号

    nubEidt->setText("");
    da = -1;
}

/**
 * 函数名称：valueChange()
 * 函数参数：
 * 函数功能：产生内容改变信号
 * 返回值： void
 **/
void Block::valueChange()
{
    emit valueChanged(); //发信号
}

/**
 * 函数名称：changeColor
 * 函数参数：const QColor &color
 * 函数功能：改变颜色
 * 返回值：void
 **/
void Block::changeColor(const QColor &color)
{
    QPalette pal;
    pal.setColor(QPalette::Text,color);
    nubEidt->setPalette(pal);
}

/**
 * 函数名称：setValue
 * 函数参数：int a
 * 函数功能：用于设置值
 * 返回值：
 **/
void Block::setValue(int a) //mainwindow里面都是用这个设初始结果的
{
    if(a<1) //不允许小于1 传0的时候 设为空
    {
        nubEidt->setText("");
        da= -1; //-1表示空
    }
    else
    {
        nubEidt->setText(QString::number(a));
        da=a; //设置成功
    }
}

/**
 * 函数名称：getValue
 * 函数参数：
 * 函数功能：用于获取值转为int
 * 返回值：int
 **/
int Block::getValue()
{
    QString num;
    num = nubEidt->text();  //获取值
    int nums = num.toInt();  //转为int
    return nums;
}

/**
 * 函数名称：dataChange
 * 函数参数：const QString &data
 * 函数功能：用于发检查信号的答案
 * 返回值：void
 **/
void Block::dataChange(const QString &data)
{
    if(data.isEmpty()) //为空
    {
        da=-1;
    }
    else //不为空
    {
        da=data.toInt();  //转为int
        emit confirmAnswers();  //发送信号 //每次修改都会判断是不是填完了
    }
}

