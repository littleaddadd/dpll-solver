#include "sudokugui.h"
#include <sstream>
using namespace std;

/**
 * 函数名称：MainWindow
 * 函数参数：QWidget *parent
 * 函数功能：构造函数
 * 返回值：
 **/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flag = false;  //标记棋盘是否存在
    eflag = true;  //最终答案的标记
    cflag = true ;  //冲突标记
    rflag = true ;  //冲突标记
    sflag = true;   //冲突标记
    createMenu(); //显示菜单
    frame=new QFrame(this); //新建Qframe
    createBlocks(); //创建9*9格子
    drawLine();  //画线
    this->setFixedSize(637,501);  //设置框大小
    frame->move(15,15);
    this->setWindowTitle("xtshudu"); //设置标题
    judgeerror();//

}

/**
 * 函数名称：judgeerror
 * 函数参数：
 * 函数功能：连接信号和检查错误函数的函数
 * 返回值：void
 **/
void MainWindow::judgeerror()
{
    print_and_flush("启动\n");
    for(int i=0 ; i<Max ; i++)
    {
        for(int j=0 ; j<Max ; j++)
        {
                //blocks[i][j]->setValue(sudokuData::num[i][j]);
                blocks[i][j]->setStyleSheet("background-color:rgba(0,0,0,0)"); //设置颜色
                connect(blocks[i][j],SIGNAL(valueChanged()),this,SLOT(checkBlocks())); //一旦值变化 就检查变色
                connect(blocks[i][j],SIGNAL(confirmAnswers()),this,SLOT(checkAnswers())); //一旦确定答案 就检查
        }
    }
    flag=true; //创建成功
}


/**
 * 函数名称：clear_output
 * 函数参数：
 * 函数功能：清屏
 * 返回值：void
 **/
void MainWindow::clear_output()
{
    output = "";
    ui->textBrowser->setText(output);
}

namespace
{
    void append(QString &str, int i)
    {
        str += QString::number(i);
    }
    void append(QString &str, char const* s)
    {
        str += s;
    }
    void append(QString &str, std::string const&s)
    {
        str += s.c_str();
    }
}

/**
 * 函数名称：print
 * 函数参数：Args&&...args
 * 函数功能：实现类似printf的功能函数
 * 返回值：void
 **/
template <typename ...Args>
void MainWindow::print(Args&&...args)
{
//    QTextStream stream(&output);
    int list[] __attribute__((unused)) = {(append(output, std::forward<Args>(args)), 0)...};
}

/**
 * 函数名称：printf_and_flush
 * 函数参数：Args&&...args
 * 函数功能：实现类似printf的功能函数并完成刷新
 * 返回值：void
 **/
template <typename ...Args>
void MainWindow::print_and_flush(Args&&...args)
{
    print(std::forward<Args>(args)...);
    flush();
}

/**
 * 函数名称：flush
 * 函数参数：
 * 函数功能：刷新函数
 * 返回值：void
 **/
void MainWindow::flush()
{
    ui->textBrowser->setText(output);
}

/**
 * 函数名称：easyInitialize
 * 函数参数：
 * 函数功能：简单棋盘初始化
 * 返回值：void
 **/
void MainWindow::easyInitialize()
{
    blocksReset();
    int nums = 0;
    nums = (int)(10.0*rand()/(RAND_MAX+1.0)); //生成随机数 范围 [0,10)
    print_and_flush("第",nums,"个简单棋盘\n");
    easyRandom(nums);  //随机取棋盘
    for(int i=0 ; i<Max ; i++)
    {
        for(int j=0 ; j<Max ; j++)
        {
            if(sudokuData::num[i][j]!=0)
            {
                blocks[i][j]->setValue(sudokuData::num[i][j]);
                //blocks[i][j]->setEnabled(false); //设置不可选定 false不可选
                blocks[i][j]->setStyleSheet("background-color:rgba(0,0,0,0)"); //设置颜色
                connect(blocks[i][j],SIGNAL(valueChanged()),this,SLOT(checkBlocks())); //一旦值变化 就检查
                connect(blocks[i][j],SIGNAL(confirmAnswers()),this,SLOT(checkAnswers())); //一旦确定答案 就检查
            }
            else  //如果数组没有 就连接信号
            {
                connect(blocks[i][j],SIGNAL(valueChanged()),this,SLOT(checkBlocks())); //一旦值变化 就检查
                connect(blocks[i][j],SIGNAL(confirmAnswers()),this,SLOT(checkAnswers())); //一旦确定答案 就检查
            }
        }
    }
    flag=true; //创建成功
}

/**
 * 函数名称：difficultInitialize
 * 函数参数：
 * 函数功能：复杂棋盘初始化
 * 返回值：void
 **/
void MainWindow::difficultInitialize()
{
    blocksReset();
    int nums = 0;
    nums = (int)(10.0*rand()/(RAND_MAX+1.0)); //生成随机数 [0,10)
    print_and_flush("第",nums,"个复杂棋盘");
    difficultRandom(nums);  //取棋盘
    for(int i=0 ; i<Max ; i++)
    {
        for(int j=0 ; j<Max ; j++)
        {
            if(sudokuData::num[i][j]!=0)
            {
                blocks[i][j]->setValue(sudokuData::num[i][j]);
               //blocks[i][j]->setEnabled(false); //设置不可选定 false不可选
                blocks[i][j]->setStyleSheet("background-color:rgba(0,0,0,0)"); //设置颜色
                connect(blocks[i][j],SIGNAL(valueChanged()),this,SLOT(checkBlocks())); //一旦值变化 就检查
                connect(blocks[i][j],SIGNAL(confirmAnswers()),this,SLOT(checkAnswers())); //一旦确定答案 就检查
            }
            else  //如果数组没有 就连接信号
            {
                connect(blocks[i][j],SIGNAL(valueChanged()),this,SLOT(checkBlocks())); //一旦值变化 就检查
                connect(blocks[i][j],SIGNAL(confirmAnswers()),this,SLOT(checkAnswers())); //一旦确定答案 就检查
            }
        }
    }
    flag=true; //创建成功
}

/**
 * 函数名称：solve
 * 函数参数：
 * 函数功能：实现数独的求解
 * 返回值：void
 **/
void MainWindow::solve()
{
    int judge;
   // easyButton->hide();
    for(int i=0;i<Max;i++)
    {
        for(int j=0;j<Max;j++)
        {
            sudokuData::num[i][j]=blocks[i][j]->getValue();
        }
    }
    sudokutocnf();
    at_least_once();
    row_at_most_once();
    col_at_most_once();
    three_square_atmost_once();

    judge=solvesudoku(&G);
    if(judge==FALSE)
    {
        QMessageBox::information(this, "Sorry", "this puzzle can't solve", QMessageBox::Ok ); //失败信息的弹框
        //return ;
    }

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            blocks[i][j]->setValue(sudokuData::num[i][j]);   //赋求解后的值
            blocks[i][j]->setStyleSheet("background-color:rgba(0,0,0,0)"); //设置颜色
        }
    }
   print_and_flush("成功\n");
}

/**
 * 函数名称：outprint
 * 函数参数：
 * 函数功能：输出转换的cnf信息
 * 返回值：void
 **/
void MainWindow::outprint()
{
    for(int i=0;i<Max;i++)
    {
        for(int j=0;j<Max;j++)
        {
            sudokuData::num[i][j]=blocks[i][j]->getValue();
        }
    }
    sudokutocnf();
    at_least_once();
    row_at_most_once();
    col_at_most_once();
    three_square_atmost_once();
    print_and_flush("输出cnf成功");
}

/**
 * 函数名称：createBlocks
 * 函数参数：
 * 函数功能：实现数独盘的创建
 * 返回值：void
 **/
void MainWindow::createBlocks()  //创建数独列表盘
{
    for(int i=0;i<Max;i++)
    {
        for(int j=0;j<Max;j++)
        {
            blocks[i][j]=new Block(frame);
            blocks[i][j]->move(j*50,i*50); //创建block后移动到相应地方
        }
    }
    int w=(50)*9+1;
    frame->setMinimumSize(w,w);//设置适当大小
}

/**
 * 函数名称：drawLine
 * 函数参数：
 * 函数功能：实现画线
 * 返回值：void
 **/
void MainWindow::drawLine()
{
    GLine *line_H[4];
    QColor color;
    QRgb rgb=qRgb(220,91,111); //设置颜色 #rgb 220 91 111
    color.setRgb(rgb);
    for(int i=0;i<4;i++) //画垂直的线
    {
        line_H[i]=new GLine(frame); //线
        line_H[i]->setPen(3,color); //设置粗细
        line_H[i]->draw(1,frame->height());
        if(i>0)
             line_H[i]->move(blocks[0][i*3+1]->pos().x()+blocks[0][i*3+1]->width()-2,0); //4 7 10的线
        else
            line_H[i]->move(0,0);//0的线
    }

    GLine *line_V[4];
    for(int i=0;i<4;i++)
    {
        line_V[i]=new GLine(frame);
        line_V[i]->setPen(3,color);
        line_V[i]->draw(0,frame->width());
        if(i>0)
            line_V[i]->move(0,blocks[i*3-1][0]->pos().y()+blocks[i*3-1][0]->height()+ui->menuBar->height()-4); //2 5 8的线
        else
            line_V[i]->move(0,0);
    }
}

/**
 * 函数名称：blocksReset
 * 函数参数：
 * 函数功能：实现Reset功能
 * 返回值：void
 **/
void MainWindow::blocksReset()
{
    for(int i=0 ; i<Max ; i++)
    {
        for(int j=0 ; j<Max ; j++)
        {
            blocks[i][j]->setValue(0); //全设为0
            blocks[i][j]->setEnabled(true);//所有格子可选定
            sudokuData::num[i][j]=0;//默认置0
            blocks[i][j]->changeColor(Qt::black); //设置颜色
            disconnect(blocks[i][j], 0, 0, 0) ; //断开信号联系
        }
    }
    DestroyClause(&G);
    flag=true;
}

/**
 * 函数名称：blocksClear
 * 函数参数：
 * 函数功能：实现Clear功能
 * 返回值：void
 **/
void MainWindow::blocksClear()
{
    for(int i=0 ; i<Max ; i++)
    {
        for(int j=0 ; j<Max ; j++)
        {
            if (sudokuData::num[i][j] == 0)
            {
                blocks[i][j]->setValue(0); //置0
            }
            blocks[i][j]->changeColor(Qt::black);
        }
    }
}

/**
 * 函数名称：checkBlocks
 * 函数参数：
 * 函数功能：实现检测重复功能 重复则变色
 * 返回值：void
 **/
void MainWindow::checkBlocks() //检测重复 不行就变色
{
    cflag = true;
    rflag = true;
    sflag = true;
    if (flag == true)
    {
        for(int i=0 ; i<Max ; i++)
        {
            for(int j=0 ; j<Max ; j++)
            {
                blocks[i][j]->changeColor(Qt::black);  //先全部设置为黑
            }
        }

        for (int i=0 ; i<Max ; i++)
        {
            for(int j=0;j<Max;j++)
            {
                nums[j]= blocks[j][i]->getValue();  //获取值
            }

            for (int m=0 ; m<Max ; m++)
            {
                for (int n=m+1 ; n<Max ; n++)
                {
                    if(nums[m] == nums[n] &&nums[n]!=0)
                    {
                        blocks[m][i]->changeColor(Qt::red);  //有冲突就变红
                        blocks[n][i]->changeColor(Qt::red);
                        cflag = false;
                    }
                }
            }
        }

        for (int i=0 ; i<Max ; i++)
        {
            for(int j=0;j<Max;j++)
            {
                nums[j]= blocks[i][j]->getValue();
            }

            for (int m=0 ; m<Max ; m++)
            {
                for (int n=m+1 ; n<Max ; n++)
                {
                    if(nums[m] == nums[n]&&nums[n]!=0)
                    {
                        blocks[i][m]->changeColor(Qt::red);
                        blocks[i][n]->changeColor(Qt::red);
                        rflag = false;
                    }
                }
            }
        }

        for(int row=0 ; row<Max ; row=row+3)
        {
            for(int col=0 ; col<Max ; col=col+3)
            {
                int s=0;
                for (int i=row ; i<row+3 ; i++)
                {
                    for(int j=col ; j<col+3 ; j++)
                    {
                        nums[s]= blocks[i][j]->getValue();
                        s++;
                    }
                }

                for (int i=0 ; i<Max ; i++)
                {
                    for (int j=i+1 ; j<Max ; j++)
                    {
                        if(nums[i] == nums[j]&&nums[i]!=0)
                        {
                            if (i<3)
                            {
                                blocks[row][i+col]->changeColor(Qt::red);
                                if (j<3)
                                {
                                    blocks[row][j+col]->changeColor(Qt::red);
                                }
                                if (2<j && j<6)
                                {
                                    blocks[row+1][j+col-3]->changeColor(Qt::red);
                                }
                                if (5<j && j<9)
                                {
                                    blocks[row+2][j+col-6]->changeColor(Qt::red);
                                }
                            }
                            if (2<i && i<6)
                            {
                                blocks[row+1][i+col-3]->changeColor(Qt::red);
                                if (2<j && j<6)
                                {
                                    blocks[row+1][j+col-3]->changeColor(Qt::red);
                                }
                                if (5<j && j<9)
                                {
                                    blocks[row+2][j+col-6]->changeColor(Qt::red);
                                }
                            }
                            if (5<i && i<9)
                            {
                                blocks[row+2][i+col-6]->changeColor(Qt::red);
                                blocks[row+2][j+col-6]->changeColor(Qt::red);
                            }
                        sflag = false;
                        }
                    }
                }
            }
        }
    }
}

/**
 * 函数名称：checkAnswers
 * 函数参数：
 * 函数功能：检查数独盘是否填满成功
 * 返回值：void
 **/
void MainWindow::checkAnswers()  //检查最终答案
{
    for(int i=0 ; i<Max ; i++)
    {
        for(int j=0 ; j<Max ;j++)
        {
            if(blocks[i][j]->getValue() > 0)
            {
                eflag = true;  //eflag
            }
            else  //一旦有空的 表示没有填满 eflag标为false 退出
            {
                eflag = false;
                break;
            }
        }
        if (eflag == false)
        {
            break;
        }
    }

    if (flag == true && cflag == true && rflag == true && sflag == true && eflag == true)
    {
        QMessageBox::information(this, "Congratulations", "Your solve this puzzle", QMessageBox::Ok ); //成功信息的弹框

        for(int i=0 ; i<Max ; i++)
        {
            for(int j=0 ; j<Max ;j++)
            {
                blocks[i][j]->setEnabled(false);  //设置所有框框不可选定
            }
        }
    }
}

/**
 * 函数名称：createMenu
 * 函数参数：
 * 函数功能：创建sudoku界面
 * 返回值：void
 **/
void  MainWindow::createMenu()
{
    //创建easy按钮
    easyButton = new QPushButton(tr("Easy"),this);
    easyButton->setGeometry(485,170,100,30);
    easyButton->show();
    //把按钮和信号联系
    connect(easyButton,SIGNAL(clicked()),this,SLOT(easyInitialize()));

    difficultButton = new QPushButton(tr("difficult"),this);
    difficultButton->setGeometry(485,210,100,30);
    difficultButton->show();
    //把按钮和信号联系
    connect(difficultButton,SIGNAL(clicked()),this,SLOT(difficultInitialize()));

    //创建solve按钮
    solveButton = new QPushButton(tr("solve"),this);
    solveButton->setGeometry(485,250,100,30);
    solveButton->show();
    connect(solveButton,SIGNAL(clicked()),this,SLOT(solve()));

    outprintButton = new QPushButton(tr("outprintcnf"),this);
    outprintButton->setGeometry(485,290,100,30);
    outprintButton->show();
    connect(outprintButton,SIGNAL(clicked()),this,SLOT(outprint()));

    //创建清屏按钮
    clearButton = new QPushButton(tr("Clear"),this);
    clearButton->setGeometry(485,330,100,30);
    clearButton->show();
    connect(clearButton,SIGNAL(clicked()),this,SLOT(blocksClear()));
    //创建重制按钮
    resetButton = new QPushButton(tr("Reset"),this);
    resetButton->setGeometry(485,370,100,30);
    resetButton->show();
    connect(resetButton,SIGNAL(clicked()),this,SLOT(blocksReset()));
    //创建推出按钮
    quitButton = new QPushButton(tr("Quit"),this);
    quitButton->setGeometry(485,410,100,30);
    quitButton->show();
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));

}

/**
 * 函数名称：~MainWindow
 * 函数参数：
 * 函数功能：MainWindow类的析构函数
 * 返回值：
 **/
MainWindow::~MainWindow()
{
    delete ui;
}
