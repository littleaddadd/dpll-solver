#include "head.h"
/*cnf部分*/
/**
 * 函数名称：existCnf
 * 函数参数：cnfpoint *G
 * 函数功能：判断内存中是否存在cnf
 * 返回值：TRUE FALSE
 **/
status ExistCnf(cnfpoint *G)
{
    if(G==nullptr) return  FALSE;        //传参失败
    if(*G!=nullptr) return  TRUE;        //创建成功
    //if((*G)->root!=NULL) return TRUE; //说明已经创建了
    else return  FALSE;
}

/**
 * 函数名称：ReadCnfWithName
 * 函数参数：Graph *G,std::string filename
 * 函数功能：按照输入的文件名读取文件
 * 返回值：TRUE FALSE
 **/
status ReadCnfWithName(cnfpoint *G,std::string filename)
{
    if(ExistCnf(G)==TRUE)    //首先判断是否存在
        return  FALSE;
    FILE *fp;
    if((fp=fopen(filename.c_str(),"r"))==nullptr) return  FALSE;  //打开文件

    *G=(cnfpoint)malloc(sizeof(struct cnfnode));  //申请空间
    char string[80];
    while(1)
    {
        fscanf(fp,"%s",string);
        if(strcmp(string,"cnf")==0)  //读到cnf的时候退出循环
            break;
    }
    fscanf(fp,"%d",&(*G)->total_literal_num);  //读取x数量
    fscanf(fp,"%d",&(*G)->total_clause_num);  //读取cnf数量

       clausenode* cnfpoint=nullptr;
       clausenode* cnfend=nullptr;

       (*G)->root=(clausenode *)malloc(sizeof(clausenode));
       cnfend=(*G)->root;
       for(int i = 0; i < (*G)->total_clause_num; ++i)
       {
           cnfpoint=(clausenode *)malloc(sizeof(clausenode));
           cnfpoint->clause_rank=i;
           literalnode * xpoint=nullptr;
           literalnode * xclause=nullptr;

           xpoint=nullptr;
           xclause=nullptr;
           int j;
           for (j = 0;;j++) {
               int readnum;
               fscanf(fp,"%d",&readnum);
               if(readnum==0) break;
               xpoint=(literalnode *)malloc(sizeof(literalnode));
               xpoint->x_rank=readnum;
               if(xclause==nullptr)
               {
                   cnfpoint->next_literalnode=xpoint;
                   xclause=xpoint;
               }
               else
               {
                   xclause->next_literalnode=xpoint;
                   xclause=xpoint;
               }
           }
           xclause->next_literalnode=nullptr;
           cnfpoint->literal_num=j;
           cnfend->next_clausenode=cnfpoint;
           cnfend=cnfpoint;
       }
       cnfend->next_clausenode=nullptr;
       fclose(fp);
       //printFormula(*G);
//       answer=(struct answer *)calloc((*G)->total_literal_num+1, sizeof(struct answer));
//       answerlength=(*G)->total_literal_num;
       return TRUE;
}

/**
 * 函数名称：WriteCnfWithName
 * 函数参数：cnfpoint G,std::string filename
 * 函数功能：按照文件名写入文件
 * 返回值：TRUE FALSE
 **/
status  WriteCnfWithName(cnfpoint G,std::string filename)
{
    if(ExistCnf(&G)==FALSE)   //判断存在
        return FALSE;
    FILE *fp;

    if((fp=fopen(filename.c_str(),"w"))==nullptr) return FALSE; //打开文件

    fprintf(fp,"%c %s %d %d\n",'p',"cnf",G->total_literal_num,G->total_clause_num);  //写入总的信息

    clausenode * cnfpoint;
    literalnode * xpoint;
    cnfpoint=(G->root->next_clausenode);
    for(int i=0;i<G->total_clause_num;i++)
    {

        xpoint=cnfpoint->next_literalnode;
        while (xpoint)
        {
            fprintf(fp,"%d ",xpoint->x_rank);  //打印式子中每个x
            xpoint=xpoint->next_literalnode;
        }
        fprintf(fp,"%d\n",0);               //打印0
        cnfpoint=cnfpoint->next_clausenode;
    }
    fclose(fp);  //关闭文件指针
    return TRUE;
}

/**
 * 函数名称：CreateClause
 * 函数参数：Gnfpoint *G
 * 函数功能：创建链表
 * 返回值：TRUE FALSE
 **/
status CreateClause(cnfpoint *G)
{
    if(ExistCnf(G)==TRUE) //如果已经存在了cnf 不让继续创建
        return  FALSE;
    *G=(cnfpoint)malloc(sizeof(struct cnfnode));  //申请空间
    (*G)->total_clause_num=0;  //置0
    (*G)->total_literal_num=0;    //置0
    clausenode * cnfend;
    (*G)->root = (clausenode *) malloc(sizeof(clausenode)); //表示cnf式子的头结点空间
    cnfend=(*G)->root;
    (*G)->total_clause_num=0;            //记录cnf个数
    (*G)->total_literal_num=0;                 //记录x总数
    cnfend->next_clausenode=nullptr;       //链表尾的next置空
    return  TRUE;
}

/**
 * 函数名称：AddClause
 * 函数参数：cnfpoint *G,std::vector<std::string>result_list
 * 函数功能：在链表中添加式子
 * 返回值：
 **/
status AddClause(cnfpoint *G,std::vector<std::string>result_list)
{
    if(ExistCnf(G)==FALSE)
        return FALSE;
    clausenode * cnfpoint;
    cnfpoint=(*G)->root;
    clausenode *newcnf;
    (*G)->total_clause_num++;
    while(cnfpoint->next_clausenode)  //到cnf末尾
        cnfpoint=cnfpoint->next_clausenode;
    newcnf=(clausenode *)malloc(sizeof(clausenode)); //申请新的cnf链

    cnfpoint->next_clausenode=newcnf;
    literalnode *xpoint=nullptr;
    literalnode *xclause = nullptr;

//    newcnf->next_literalnode=(literal *)malloc(sizeof(literal));  //申请x空间
//    xend=newcnf->next_literalnode;

    int input_xnum;
    int x_in_cnf=0;
    for (unsigned int index=0;index != result_list.size();++index)
    {
        input_xnum=std::stoi(result_list[index]);  //取输入的数字
        if(input_xnum==0)
            break;
        //还要处理最大值的问题
        if(input_xnum>(*G)->total_literal_num) //最大值
            (*G)->total_literal_num=input_xnum;

        x_in_cnf++;

        xpoint=(literalnode *)malloc(sizeof(literalnode));
        xpoint->x_rank=input_xnum;
        if(xclause==nullptr)
        {
            newcnf->next_literalnode=xpoint;
            xclause=xpoint;
        }
        else {
            xclause->next_literalnode=xpoint;
            xclause=xpoint;
        }

    }
    xclause->next_literalnode=nullptr;
    newcnf->next_clausenode=nullptr;  //尾指针置空
    newcnf->literal_num=x_in_cnf;
    newcnf->clause_rank=(*G)->total_clause_num;
    return TRUE;
}

/**
 * 函数名称：destroyClause
 * 函数参数：cnfpoint *G
 * 函数功能：摧毁内存中的链表
 * 返回值：TRUE FALSE
 **/
status DestroyClause(cnfpoint *G)
{
    if(ExistCnf(G)==FALSE)
        return FALSE;
    clausenode * cnfpoint,*p;
    //literalnode * xpoint;
    cnfpoint=(*G)->root->next_clausenode;
    while (cnfpoint != nullptr)
    {
        p=cnfpoint->next_clausenode;
        DestroyLiteral(cnfpoint);
        free(cnfpoint);
        cnfpoint=p;
    }
    free(*G);
    (*G)=nullptr;
    return TRUE;
}

/**
 * 函数名称：destroyliteral
 * 函数参数：clause * clausepoint
 * 函数功能：摧毁句子
 * 返回值：
 **/
void DestroyLiteral(clausenode * clausepoint)
{
    literalnode *xpoint,*p;
    xpoint=clausepoint->next_literalnode;
    while(xpoint)
    {
        p=xpoint->next_literalnode;
        free(xpoint);
        xpoint=p;
    }
    clausepoint->next_literalnode=nullptr;
}
