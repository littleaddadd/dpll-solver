#ifndef CNF_H
#define CNF_H

#include <QMainWindow>
#include "head.h"

namespace Ui {
class cnf;
}

class cnf : public QMainWindow
{
    Q_OBJECT

public:
    explicit cnf(QWidget *parent = nullptr);
    ~cnf();

    cnfpoint G=nullptr; //表示图
    cnfpoint *p;        //
    template <typename Edit, typename ...Args>
    void scan(Edit input, Args&&...args);
    void clear_output();
    template <typename ...Args>
    void print(Args&&...args);
    template <typename ...Args>
    void print_and_flush(Args&&...args);
    void flush();
    QString output;
    void gui_read();
    Ui::cnf *ui;

    std::string solvefilename="chuli";
private slots:
    void on_printButton_clicked();   //打印按钮
    void on_readButton_clicked();    //读取按钮
    void on_writeButton_clicked();   //写入按钮
    void on_okButton_clicked();      //确定按钮
    void on_solveButton_clicked();   //解决按钮
    void on_existButton_clicked();   //判断存在按钮
    void on_createButton_clicked();  //创造按钮
    void on_destroyButton_clicked(); //摧毁按钮
    void on_answerButton_clicked();  //答案按钮
    void on_addButton_clicked();     //添加按钮


    void on_cdclButton_clicked();

private:
    std::function<void()> input_handler; //实现ok提交
    //cnf功能
    void gui_exist();              //实现判断存在的gui函数
    void show_hide();              //隐藏函数
    void gui_write();              //实现写入的gui函数
    void gui_print();              //实现打印的gui函数
    status PrintCnf(cnfpoint G);      //打印CNF 放在gui类 因为要实现gui输出
    void gui_create();             //实现创造的gui函数
    void gui_add();                //实现添加的gui函数
    void gui_destroy();            //实现摧毁的gui函数
    void gui_solve();              //实现解决的gui函数
    void gui_answer();             //实现答案的gui函数
    void PrintAnswer();            //实现打印答案的函数 放在gui类 因为要实现gui输出
    void gui_cdcl();               //
};
#endif // CNF_H
