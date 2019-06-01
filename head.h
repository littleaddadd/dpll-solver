//
// Created by littleadd on 2019-01-23.
//
#ifndef INC_2019KESHE_DPLL_H
#define INC_2019KESHE_DPLL_H
#include <stdio.h>
#include <mm_malloc.h>
#include <stdlib.h>
//#include <curses.h>
#include <functional>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <math.h>
typedef int status;
#define  ERRORr -1
#define  TRUE 1
#define FALSE 0
extern int num_of_cnf;
extern int num_of_x;
extern struct answer *answer;//答案数组
//extern  int *answer;
extern int answerlength;
extern int soduko[9][9];
extern int true_false;


/*以下为结构体定义*/
//记录单个x的结点
typedef struct literalnode
{
    int x_rank; //记录是变元x几
    //float jx; //for jw algorithm
    struct literalnode *next_literalnode; //指向下一个结点的指针
}literalnode;
//cnf结点
typedef struct clausenode
{
    int clause_rank;//记录是第几个子句
    int literal_num; //当前子句有几个文字
    struct clausenode *next_clausenode;//指向下一个子句
    struct literalnode *next_literalnode ;//指向子句的文字链
}clausenode;
//公式结点
typedef struct cnfnode
{
    int total_clause_num; //子句数量
    int total_literal_num;//文字x数量
    clausenode * root;//指向第一个cnf链表
    //bool exist;
}*cnfpoint;
//答案链记录结点
struct answer{
    int xnum;
    double positive=0; //用于JW算法对正文字的统计
    double negtive=0;  //用于JW算法对负文字的统计
};


/*cnf.cpp文件中函数的声明*/
status ExistCnf(cnfpoint *G);//判断内存中是否存在cnf链表
status ReadCnfWithName(cnfpoint *G,std::string filename);//按照filename读取文件
status  WriteCnfWithName(cnfpoint G,std::string filename); //按照filename写入文件
status CreateClause(cnfpoint *G);//创建链表
status AddClause(cnfpoint *G,std::vector<std::string>result_list);//添加式子
status DestroyClause(cnfpoint *G);//摧毁内存中的链表
void DestroyLiteral(clausenode * cnfpoint); //摧毁单个式子链
/*dpll.cpp文件中函数的声明*/
status ChooseNum(cnfpoint G);       //选择变元策略函数
status JWChooseNum(cnfpoint G);     //JW选择变元策略函数
void SingleSimplify(cnfpoint *G, int x); //单子句化简函数
status DeleteClauseIncludeX(cnfpoint *formula, int x); //调用RemoveClause 删除含x的整个式子
status RemoveClause(clausenode * cnfpoint);  //删除含x的整个式子
status  DeleteXinCnf(cnfpoint *G, int x);   //调用DeleteXinClause删除cnf公式中的x
status DeleteXinClause(int x, clausenode * xhead); //删除句子中的x
status SearchXinClause(int x,clausenode * cnfpoint);//查找含有x的cnf式子
cnfpoint  CopyCNF(cnfpoint * formula,int n);//复制链表并加上单子句
cnfpoint* AddChoseNumforG(cnfpoint *G,int input_xnum);//在链表尾加单子句
status DPLL(cnfpoint *G); //DPLL过程
clausenode* isUnitClause(cnfpoint G);//判断是不是单子句
status SearchNull(cnfpoint G); //寻找空子句
status SisEmpty(cnfpoint G);   //是不是不含任何文字了
status WriteAnswer(std::string filename, int num, double time);//写处理答案
void InitAnswer(cnfpoint G);//初始化答案链表
/*soduko.cpp文件中函数的声明*/
void easyRandom(int nums);          //初始化简单列表
void difficultRandom(int nums);     //初始化复杂列表
status sudokutocnf();               //将现成的数独棋盘打印成需要的cnf
status at_least_once();             //保证每一个格子只允许存在一个取值
status row_at_most_once();           //一行最多出现一个值
status col_at_most_once();           //一列最多出现一个值
status three_square_atmost_once(); //3*3格子最多出现一个值
status solvesudoku(cnfpoint *G);     //调用DPLL解决函数
#endif //INC_2019KESHE_DPLL_H
