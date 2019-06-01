#include "sudokugui.h"
#include "cnfgui.h"

#include <QApplication>
#include <QDialog>
#include <login.h>

int num_of_cnf;
int num_of_x;
struct answer *answer;//答案数组
int answerlength;
int soduko[9][9]={{0,0,7,0,0,0,3,0,6},
                  {6,0,0,4,0,0,2,7,0},
                  {0,5,2,0,1,6,0,8,0},
                  {0,0,0,1,0,7,0,3,8},
                  {0,7,8,0,0,0,5,9,0},
                  {2,6,0,8,0,5,0,0,0},
                  {0,2,0,5,8,0,1,6,0},
                  {0,3,1,0,0,9,0,0,7},
                  {8,0,6,0,0,0,4,0,0}
};
int true_false=0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    cnf w1;
    login dlg;                        // 建立自己新建的LoginDlg类的实例dlg
    if(dlg.exec() == QDialog::Accepted) // 利用Accepted返回值判断按钮是否被按下
    {
        if(dlg.choosenum==1)
            w.show();                      // 如果被按下，显示主窗口
        if(dlg.choosenum==2)
            w1.show();
        return a.exec();              // 程序一直执行，直到主窗口关闭
    }

    return 0;          //如果没有被按下，则不会进入主窗口，整个程序结束运行
}
