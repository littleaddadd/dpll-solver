#ifndef XTMINISAT_HEAD_H
#define XTMINISAT_HEAD_H
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
typedef int Bool;
static const Bool True =1;
static const Bool False=0;

typedef int lit;
typedef char lbool;
typedef unsigned long long uint64;

static const int var_Undef = -1;
static const int lit_Undef =-2;

static const char l_Undef = 0;
static const char l_True  = 1;
static const char l_False =-1;

//手写的一个向量容器 int
typedef struct veci_t{
    int size;
    int cap;
    int * ptr;
}veci;

//手写的一个向量容器
typedef struct vecp_t{
    int size;
    int cap;
    void** ptr;
}vecp;

//用于子句学习的结构
typedef struct clause_t
{
    int size_learnt;
    lit lits[0];
}clause_of_cdcl;

typedef struct stats_t
{
    uint64   starts, decisions, propagations, inspects, conflicts;
    uint64   clauses, clauses_literals, learnts, learnts_literals, max_literals, tot_literals;
}stats;

typedef struct solver_t
{
    int size;           //变量数量
    int cap;            //size of varmaps
    int qhead;          //queue 头
    int qtail;          //queue 尾

    //clauses
    vecp clauses;       //list of problem constraints 问题约束列表
    vecp learnts;       //list of learnt clauses 学习句子的列

    //activities
    double var_inc;     //与下一个变量冲突的数量
    double var_decay;   //Inverse衰减因子对活跃变量
    float cla_inc;      //与下一个句子冲突
    float cla_decay;    //Inverse衰减因子对活跃句子

    vecp* wlists;       //
    double * activity;  //变量活动的启发式测量
    lbool* assigns;     //当前的变量赋值
    int * orderpos;     //变量顺序
    clause_of_cdcl** reasons;   //
    int* levels;        //
    lit* trail;         //追踪

    clause_of_cdcl* binary;     //
    lbool * tags;       //
    veci tagged;        //容纳变量
    veci stack;         //容纳变量

    veci order;         //变量顺序（堆） 容纳堆是变量
    veci trail_lim;     //tail中不同决策级别的分隔符索引
    veci model;         //只要是可满足 就会包含解在里面

    int root_level;     //
    int simpdb_assigns; //
    int simpdb_props;   //
    double random_seed; //
    double progress_estimate; //
    int verbosity;      //
    stats stats;        //
}solver;



//函数声明部分
//==================================*veci容器处理*================================//
void veci_new(veci* v);
void veci_delete(veci *v);
int* veci_begin(veci *v);
int  veci_size(veci *v);
void veci_resize(veci* v, int k);
void veci_push(veci *v,int e);
//==================================*vecp容器处理*================================//
void vecp_new(vecp* v);
void vecp_delete(vecp *v);
void** vecp_begin(vecp *v);
int vecp_size(vecp *v);
void vecp_resize(vecp *v,int k);
void vecp_push(vecp *v,void* e);
//=================================*literal简单处理函数*===================================//
int lit_nneg(int l);
int toLit (int v) ;
int lit_var(int l);
int lit_sign(int l);
//=================================*答案打印函数*==========================================//
void printTime(stats * stats,int cpu_time);

solver* solver_new(void);
void solver_delete(solver* s);
Bool solver_addclause(solver *s,lit* begin,lit* end);
Bool solver_simplify(solver *s);
Bool solver_solve(solver* s,lit * begin,lit *end);
int solver_nvars(solver* s);
int solver_nclauses(solver* s);
int solver_nconflicts(solver* s);
void solver_setnvars(solver* s,int n);
void sort(void** array, int size, int(*comp)(const void *, const void *));

int read_File(std::string filename,solver *s);
#endif //XTMINISAT_HEAD_H
