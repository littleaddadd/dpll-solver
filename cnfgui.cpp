#include "cnfgui.h"
#include "ui_cnf.h"
#include "cdcl.h"
#include <sstream>

/**
 * 函数名称：cnf
 * 函数参数：QWidget *parent
 * 函数功能：构造函数
 * 返回值：
 **/
cnf::cnf(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cnf)
{
    ui->setupUi(this);
    this->setFixedSize(685,634);  //设置框大小
    this->setWindowTitle("xtcnf"); //设置标题
    show_hide();
}

/**
 * 函数名称：scan
 * 函数参数：Edit input, Args&&...args
 * 函数功能：实现类似scanf的输入函数 方便读取
 * 返回值：void
 **/
template <typename Edit, typename ...Args>
void cnf::scan(Edit input, Args&&...args)
{
    auto text = input->text().toStdString();
    input->setText("");
    std::istringstream stream(text);
    int list[] __attribute__((unused))= {(stream >> std::forward<Args>(args), 0)...};
}

/**
 * 函数名称：clear_output
 * 函数参数：
 * 函数功能：清屏
 * 返回值：void
 **/
void cnf::clear_output()
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
//    void append(QString &str, char i)
//    {
//        str += QString::number(i);
//    }
}
/**
 * 函数名称：print
 * 函数参数：Args&&...args
 * 函数功能：实现类似printf的输出功能
 * 返回值：void
 **/
template <typename ...Args>
//输出函数
void cnf::print(Args&&...args)
{
//    QTextStream stream(&output);
    int list[] __attribute__((unused)) = {(append(output, std::forward<Args>(args)), 0)...};
}
/**
 * 函数名称：print_and_flush
 * 函数参数：Args&&...args
 * 函数功能：实现类似printf的输出功能并完成刷新
 * 返回值：void
 **/
template <typename ...Args>
void cnf::print_and_flush(Args&&...args)
{
    print(std::forward<Args>(args)...);
    flush();
}

/**
 * 函数名称：flush
 * 函数参数：
 * 函数功能：刷新textBrowser的显示信息
 * 返回值：void
 **/
void cnf::flush()
{
    ui->textBrowser->setText(output);
}

/**
 * 函数名称：～cnf
 * 函数参数：
 * 函数功能：cnf类的析构函数
 * 返回值：
 **/
cnf::~cnf()
{
    delete ui;
}

/**
 * 函数名称：show_hide
 * 函数参数：
 * 函数功能：实现对部分控件的隐藏功能
 * 返回值：void
 **/
void cnf::show_hide()
{
    ui->label->hide();     //隐藏label
    //ui->label_2->hide();   //隐藏label_2
    ui->lineEdit->hide();  //隐藏输入框
    ui->okButton->hide();  //隐藏ok按钮
}


/*按钮信号部分*/
//ok按钮
/**
 * 函数名称：on_okButton_clicked
 * 函数参数：
 * 函数功能：ok按钮的槽函数
 * 返回值：void
 **/
void cnf::on_okButton_clicked()
{
    input_handler();
}

/**
 * 函数名称：on_existButton_clicked
 * 函数参数：
 * 函数功能：exist按钮的槽函数
 * 返回值：void
 **/
void cnf::on_existButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_exist();      //调用对应的gui函数
}

//读取
/**
 * 函数名称：on_readButton_clicked
 * 函数参数：
 * 函数功能：read按钮的槽函数
 * 返回值：void
 **/
void cnf::on_readButton_clicked()
{
      clear_output();
      show_hide();
      ui->textBrowser->show();
      gui_read();     //调用对应的gui函数
}

/**
 * 函数名称：on_writeButton_clicked
 * 函数参数：
 * 函数功能：write按钮的槽函数
 * 返回值：void
 **/
void cnf::on_writeButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_write();      //调用对应的gui函数
}

/**
 * 函数名称：on_printButton_clicked
 * 函数参数：
 * 函数功能：print按钮的槽函数
 * 返回值：void
 **/
void cnf::on_printButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_print();      //调用对应的gui函数
}

/**
 * 函数名称：on_solveButton_clicked
 * 函数参数：
 * 函数功能：solve按钮的槽函数
 * 返回值：void
 **/
void cnf::on_solveButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_solve();     //调用对应的gui函数
}

/**
 * 函数名称：on_createButton_clicked
 * 函数参数：
 * 函数功能：create按钮的槽函数
 * 返回值：void
 **/
void cnf::on_createButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_create();    //调用对应的gui函数
}

/**
 * 函数名称：on_addButton_clicked
 * 函数参数：
 * 函数功能：add按钮的槽函数
 * 返回值：void
 **/
void cnf::on_addButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_add();       //调用对应的gui函数
}

/**
 * 函数名称：on_destroyButton_clicked
 * 函数参数：
 * 函数功能：destroy按钮的槽函数
 * 返回值：void
 **/
void cnf::on_destroyButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_destroy();    //调用对应的gui函数
}

/**
 * 函数名称：on_answerButton_clicked
 * 函数参数：
 * 函数功能：answer按钮的槽函数
 * 返回值：void
 **/
void cnf::on_answerButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_answer();     //调用对应的gui函数
}
/**
 * 函数名称: cnf::on_cdclButton_clicked
 *
 * 函数功能：cdcl按钮的槽函数
 * 返回值： void
 */
void cnf::on_cdclButton_clicked()
{
    clear_output();
    show_hide();
    ui->textBrowser->show();
    gui_cdcl();
}


/*gui部分*/
/**
 * 函数名称：gui_exist
 * 函数参数：
 * 函数功能：exist按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_exist()
{
    print_and_flush("点击按钮查看存在性\n");
    ui->okButton->show();
    input_handler=[this]
    {
        int judge=ExistCnf(&G);
        if(judge==TRUE)
            print_and_flush("已存在cnf范式");
        else
            print_and_flush("尚未存在cnf范式");
        show_hide();
    };
}

/**
 * 函数名称：gui_read
 * 函数参数：
 * 函数功能：read按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_read()
{
    print_and_flush("请输入文件名\n");
    ui->label->setText("文件名");
    ui->lineEdit->show();
    ui->okButton->show();
    ui->label->show();
    input_handler=[this]
    {
        //std::string filename;
        scan(ui->lineEdit,solvefilename);
        int judge=ReadCnfWithName(&G,solvefilename);
        if(judge==TRUE)
        {
            print("该文件有",(*G).total_literal_num,"个x\n");
            print("该文件有",(*G).total_clause_num,"个cnf式子\n");
            print_and_flush("读取成功\n");
        }
        else {
            print_and_flush("读取失败\n");
            print_and_flush(solvefilename);
        }
        show_hide();
    };
}

/**
 * 函数名称：gui_write
 * 函数参数：
 * 函数功能：write按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_write()
{
    print_and_flush("请输入文件名\n");
    ui->label->setText("文件名");
    ui->lineEdit->show();
    ui->okButton->show();
    ui->label->show();
    input_handler=[this]
    {
        std::string filename;
        scan(ui->lineEdit,filename);
        int judge=WriteCnfWithName(G,filename);
        if(judge==TRUE)
        {
            print_and_flush("写入成功");
        }
        else {
            print_and_flush("写入失败");
        }
        show_hide();
    };
}

/**
 * 函数名称：gui_print
 * 函数参数：
 * 函数功能：print按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_print()
{
    ui->okButton->show();
    input_handler=[this]
    {
        int judge=PrintCnf(G);
        if(judge==TRUE)
        {
            print_and_flush("打印成功");
        }
        else {
            print_and_flush("打印失败");
        }
        show_hide();
    };
}

/**
 * 函数名称：gui_create
 * 函数参数：
 * 函数功能：create按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_create()
{
    print_and_flush("请按ok创建\n");
    ui->okButton->show();
    input_handler=[this]
    {
        int judge=CreateClause(&G);
        if(judge==TRUE)
            print_and_flush("创建成功");
        else {
            print_and_flush("创建失败");
        }
        show_hide();
    };
}

/**
 * 函数名称：gui_add
 * 函数参数：
 * 函数功能：add按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_add()
{
    print_and_flush("按ok完成添加 0结尾");
    ui->okButton->show();
    ui->lineEdit->show();
    ui->label->show();
    ui->label->setText("按逗号间隔输入 0结尾");
    input_handler=[this]
    {
        int judge;
        QString qstr=ui->lineEdit->text();
        ui->lineEdit->setText("");
        std::string str=qstr.toUtf8().constData(); //格式转换
        std::vector<std::string> result_list;
        std::string bufstr;
        for(int index = 0,range=(int)str.size();index != range;++index)
        {
            if(str[index]!=','){   //如果不是逗号，加入缓冲
                bufstr.push_back(str[index]);
            }
            else                  //遇到逗号 push_back并清除缓冲
            {
                result_list.push_back(bufstr);
                bufstr.erase();
            }
        }
        result_list.push_back(bufstr);//将最后一个,后的数据加入缓冲
        judge=AddClause(&G,result_list);
        if(judge==TRUE)
            print_and_flush("添加成功");
        else {
            print_and_flush("添加失败");
        }
        show_hide();
    };
}

/**
 * 函数名称：gui_destroy
 * 函数参数：
 * 函数功能：destroy按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_destroy()
{
    print_and_flush("请按ok摧毁");
    ui->okButton->show();
    input_handler=[this]
    {
        int judge=DestroyClause(&G);
        if(judge==TRUE)
        {
            true_false=0;
            print_and_flush("摧毁成功");
            solvefilename="chuli";
        }
        else {
            print_and_flush("摧毁失败");
        }
        show_hide();
    };
}

/**
 * 函数名称：gui_solve
 * 函数参数：
 * 函数功能：solve按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_solve()
{
    print_and_flush("点击ok解决\n");
    ui->okButton->show();
    input_handler=[this]
    {
        clock_t begintime,endtime;
        double duration = 0.0;
        double time;
        InitAnswer(G);       //创建答案记录链表
        begintime=clock();   //开始计时
        if(DPLL(&G)==TRUE)   //DPLL过程
        {
            endtime=clock();     //结束计时
            print_and_flush("求解成功\n");
            true_false=1;
            time=1000*(endtime-begintime);
            duration = double(time) / CLOCKS_PER_SEC;
            //print_and_flush("duration",duration);
            WriteAnswer(solvefilename+".res",1,duration);
        }
        else
        {
            endtime=clock();     //结束计时
            print_and_flush("求解失败\n");
            time=1000*(endtime-begintime);
            duration = double(time) / CLOCKS_PER_SEC;
            WriteAnswer(solvefilename+".res",0,duration);
        }
        print_and_flush(duration,"ms\n\n");
    };
}

/**
 * 函数名称：gui_answer
 * 函数参数：
 * 函数功能：answer按钮调用的gui函数
 * 返回值：void
 **/
void cnf::gui_answer()
{
    ui->okButton->show();
    input_handler=[this]
    {
        if(true_false==1)
            PrintAnswer();
        else {
            print_and_flush("无解");
        }
        show_hide();
    };
}

void cnf::gui_cdcl()
{
    print_and_flush("请输入文件名\n");
    ui->label->setText("文件名");
    ui->lineEdit->show();
    ui->okButton->show();
    ui->label->show();

    input_handler=[this]
    {
      solver* s=solver_new();
      char st;
      double time;
      std::string filename;
      scan(ui->lineEdit,filename);
      int judge=read_File(filename,s);
      if(judge==0) print_and_flush("文件不存在");
      else {
           s->verbosity=1;
           clock_t start=clock();
           st=solver_solve(s,0,0);
           clock_t end=clock();
           print_and_flush(st==l_True? "满足\n":"不满足\n");
           time=1000*(end-start);
           double duration = (double)(time) / CLOCKS_PER_SEC;
           print_and_flush(duration," ms");
           if (st==l_True)
           {
               int k;
               print("\n可满足解:\n");
               for(k=0;k<s->model.size;k++)
               {
                   print(" x",k+1,"=",s->model.ptr[k] == l_True);  //l_True=lbool=char=1
                   if((k+1)%5==0) print("\n");
               }
               print_and_flush("\n");
           }
           solver_delete(s);
      }
      show_hide();
    };
}




/**
 * 函数名称：PrintCnf
 * 函数参数：Graph G
 * 函数功能：打印内存中的式子
 * 返回值：TRUE FALSE
 **/
status cnf::PrintCnf(cnfpoint G)
{
    if(ExistCnf(&G)==FALSE)     //如果不存在cnf在内存中 返回FALSE
        return  FALSE;

    print("总共有",G->total_literal_num,"个x\n");        //打印x总数
    print("总共有",G->total_clause_num,"个cnf\n");    //打印cnf总数
    clausenode * cnfpoint;
    literalnode * xpoint;
    cnfpoint=(G->root->next_clausenode);
    while (cnfpoint) {  //循环打印每个cnf式子
        xpoint = cnfpoint->next_literalnode;
        print("正在打印第",cnfpoint->clause_rank,"个式子:   \n");  //打印式子的位次
        print("本式子有",cnfpoint->literal_num,"个x\n");    //打印x的个数
        while (xpoint) {
            print(xpoint->x_rank," ");
            xpoint = xpoint->next_literalnode;
        }
        print(("\n"));
        cnfpoint=cnfpoint->next_clausenode;
    }
    flush();
    return  TRUE;
}

/**
 * 函数名称：PrintAnswer
 * 函数参数：void
 * 函数功能：打印答案
 * 返回值：void
 **/
void cnf::PrintAnswer(void)
{
    for(int i=1;i<=answerlength;i++)
        print("x:",answer[i].xnum*i,"\n");
       // print("x:",answer[i].xnum*i,"exist",answer[i].existnum,"times");
    print_and_flush("\n");
}




