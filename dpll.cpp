#include "head.h"
//变元选择策略
/**
 * 函数名称：ChooseNum
 * 函数参数：cnfpoint G
 * 函数功能：变元选择策略函数
 * 返回值：返回链表中的值
 **/
status ChooseNum(cnfpoint G)
{
    clausenode *cnfpoint;
    cnfpoint=G->root->next_clausenode;
    while(cnfpoint)
    {
        if(cnfpoint->next_literalnode!=nullptr)
            return cnfpoint->next_literalnode->x_rank;
        cnfpoint=cnfpoint->next_clausenode;
        //printf("aaaaa\n\n");
    }
    return 0;
}

/**
 * 函数名称：JWChooseNum
 * 函数参数：cnfpoint G
 * 函数功能：JW算法的变元选择策略函数
 * 返回值：返回出现频率最大的值
 **/
status JWChooseNum(cnfpoint G)
{
    for(int i=1;i<=answerlength;i++)
    {
            answer[i].negtive=0;
            answer[i].positive=0;
    }
    clausenode * cnfpoint;
    literalnode * xpoint;
    cnfpoint=G->root->next_clausenode;
    while (cnfpoint) {
        xpoint=cnfpoint->next_literalnode;
        while (xpoint) {
        if(xpoint->x_rank>0)
                answer[xpoint->x_rank].positive+=pow(2,-cnfpoint->literal_num);
        else
                answer[-xpoint->x_rank].negtive+=pow(2,-cnfpoint->literal_num);
                xpoint=xpoint->next_literalnode;
        }
        cnfpoint=cnfpoint->next_clausenode;
    }
    double max = 0.0,total;
    int p = 1;
    for(int i=1;i<=answerlength;i++)
    {
        //if(answer[i].xnum!=0) continue;
        total=answer[i].positive+answer[i].negtive;
        if(max<total)
        {
            max=total;
            p=i;
        }
    }
    if(answer[p].positive>answer[p].negtive)
        return p;
    return -p;
}

/**
 * 函数名称：SingleSimplify
 * 函数参数：Graph *G, int x
 * 函数功能：进行单子句化简
 * 返回值：void
 **/
void SingleSimplify(cnfpoint *G, int x)
{
    answer[abs(x)].xnum=(x>0?1:-1); //记录答案
    DeleteClauseIncludeX(G, x);
    DeleteXinCnf(G, -x);
}

/**
 * 函数名称：DeleteCnfIncludeX
 * 函数参数：Graph *G, int x
 * 函数功能：调用removeClause 删除CNF中含x的整个句子
 * 返回值：TRUE
 **/
status DeleteClauseIncludeX(cnfpoint *G, int x)
{
    clausenode *clause,*previousclause;
    clause=(*G)->root->next_clausenode;
    previousclause=(*G)->root;
    while (clause!=nullptr)
    {
        if (SearchXinClause(x,clause))
        {
            previousclause->next_clausenode=clause->next_clausenode;
            RemoveClause(clause); //
            free(clause);
            clause=previousclause;
        }
        previousclause=clause;
        clause=clause->next_clausenode;
    }
    return TRUE;
}


/**
 * 函数名称：RemoveClause
 * 函数参数：clausenode * cnfpoint
 * 函数功能：删除含x的句子
 * 返回值：TRUE
 **/
status RemoveClause(clausenode * clausepoint)
{
    literalnode *xpoint,*p;
    xpoint=clausepoint->next_literalnode;
    while (xpoint) {
        p=xpoint->next_literalnode;
        free(xpoint);
        xpoint=p;
    }
    return TRUE;
}


/**
 * 函数名称：DeleteXinCnf
 * 函数参数：Graph *G, int x
 * 函数功能：调用DeletexInClause删除句子中的x
 * 返回值：TRUE
 **/
status  DeleteXinCnf(cnfpoint *G, int x)
{
    clausenode * clausepoint;
    clausepoint=(*G)->root->next_clausenode;
    while (clausepoint)
    {
        if(SearchXinClause(x,clausepoint))
        {
            DeleteXinClause(x,clausepoint);
            clausepoint->literal_num--;
            if(clausepoint->literal_num==0) clausepoint->next_literalnode=nullptr;
        }
        clausepoint=clausepoint->next_clausenode;
    }

    return TRUE;
}

/**
 * 函数名称：DeleteXinClause
 * 函数参数：literal *xhead, int x
 * 函数功能：删除句子中的x
 * 返回值：TRUE
 **/
status DeleteXinClause(int x, clausenode * clausepoint)
{
    literalnode * p=clausepoint->next_literalnode;
    literalnode * q=nullptr;
    if(p->x_rank==x)
    {
        clausepoint->next_literalnode=p->next_literalnode;
        free(p);
    }
    else
    {
        while (p!=nullptr)
        {
            q=p;
            p=p->next_literalnode;
            if(p->x_rank==x)
            {
                q->next_literalnode=p->next_literalnode;
                free(p);
                break;
            }
        }
    }
    return  TRUE;
}

/**
 * 函数名称：Searchxincnf
 * 函数参数：clause *cnfpoint, int x
 * 函数功能：查找含x的句子
 * 返回值：TRUE FALSE
 **/
status SearchXinClause(int x,clausenode * clausepoint)
{
    literalnode *xpoint;
    xpoint=clausepoint->next_literalnode;
    while(xpoint){
        if(xpoint->x_rank==x)
            return TRUE;
        xpoint=xpoint->next_literalnode;
    }
    return FALSE;
}

/**
 * 函数名称：CopyFormula
 * 函数参数：cnfpoint * cnf,int n
 * 函数功能：复制链表并加单子句
 * 返回值：返回复制链表的头结点
 **/
cnfpoint  CopyCnf(cnfpoint * cnf,int n)
{
    cnfpoint  newcnf;
    clausenode *currunt_clause;
    clausenode *previous_clause;
    clausenode * clause_point;
    literalnode *literal_point,*currunt_literal,*previous_literal = nullptr;
    clause_point=(*cnf)->root->next_clausenode;

    (newcnf)=(cnfpoint )malloc(sizeof(struct cnfnode));
    (newcnf)->total_literal_num=(*cnf)->total_literal_num;
    (newcnf)->total_clause_num=(*cnf)->total_clause_num;
    (newcnf)->root=(clausenode *)malloc(sizeof(clausenode));

    previous_clause=nullptr;
    while (clause_point!=nullptr)
    {
        currunt_clause=(clausenode *)malloc(sizeof(clausenode));
        currunt_clause->next_clausenode=nullptr;
        currunt_clause->next_literalnode=nullptr;

        currunt_clause->clause_rank=clause_point->clause_rank;//////
        currunt_clause->literal_num=clause_point->literal_num;//////

        if(previous_clause==nullptr)
        {
            newcnf->root->next_clausenode=currunt_clause;
            previous_clause=newcnf->root->next_clausenode;
        }
        else {
            previous_clause->next_clausenode = currunt_clause;
            previous_clause = currunt_clause;
        }

        literal_point=clause_point->next_literalnode;
        while (literal_point!=nullptr)
        {
            currunt_literal=(literalnode*)malloc(sizeof(literalnode));
            if(currunt_clause->next_literalnode==nullptr)
                currunt_clause->next_literalnode=currunt_literal;
            else if(currunt_clause->next_literalnode!=nullptr)
                previous_literal->next_literalnode=currunt_literal;
            currunt_literal->x_rank=literal_point->x_rank;
            currunt_literal->next_literalnode=nullptr;
            previous_literal=currunt_literal;
            literal_point=literal_point->next_literalnode;
        }
        clause_point=clause_point->next_clausenode;
    }

    currunt_clause=(clausenode *)malloc(sizeof(clausenode));
    currunt_clause->next_clausenode=nullptr;
    currunt_clause->next_literalnode=nullptr;

    if(previous_clause==nullptr)
    {
        newcnf->root=currunt_clause;
        previous_clause=newcnf->root;
    }
    else {
        previous_clause->next_clausenode = currunt_clause;
        previous_clause = currunt_clause;
    }

    currunt_literal=(literalnode*)malloc(sizeof(literalnode));
    currunt_clause->next_literalnode=currunt_literal;
    currunt_literal->x_rank=n;
    currunt_literal->next_literalnode=nullptr;

    return newcnf;
}

/**
 * 函数名称：AddchoseNumforG
 * 函数参数：cnfpoint *G,int input_xnum
 * 函数功能：在链表尾加单子句
 * 返回值：返回链表的头结点
 **/
cnfpoint* AddChoseNumforG(cnfpoint *G,int n)
{
    clausenode * cnfpoint=(*G)->root->next_clausenode;
    clausenode * newcnf;
    (*G)->total_clause_num++;
    while (cnfpoint->next_clausenode)
        cnfpoint=cnfpoint->next_clausenode;
    newcnf=(clausenode*)malloc(sizeof(clausenode));
    cnfpoint->next_clausenode=newcnf;

    newcnf->next_literalnode=(literalnode *)malloc(sizeof(literalnode));
    newcnf->next_literalnode->next_literalnode=nullptr;
    newcnf->next_clausenode=nullptr;
    newcnf->next_literalnode->x_rank=n;
    newcnf->clause_rank=(*G)->total_clause_num;
    if(n>(*G)->total_literal_num)
        (*G)->total_literal_num=n;
    return G;
}
/**
 * 函数名称：DPLL
 * 函数参数：cnfpoint *G
 * 函数功能：用于DPLL过程
 * 返回值：
 */
status DPLL(cnfpoint *G)
{
    clausenode * single;
    int a;
    while ((single=isUnitClause(*G))!=nullptr)
    {
        a=single->next_literalnode->x_rank;
        SingleSimplify(G,a);
        if(SearchNull(*G))
        {
            //printf("11");
            return FALSE;
        }
        if(SisEmpty(*G))
        {
            return TRUE;
        }
    }
    //int n=returnMore(*G);
    int n=ChooseNum(*G);
    cnfpoint cloneG=CopyCnf(G,n);
    //printFormula(*cloneG);
    //printf("choose:%d\n",n);
    if(DPLL(&cloneG))
    {
        DestroyClause(&cloneG);
        return TRUE;
    }
    else if(DPLL(AddChoseNumforG(G,-n)))
    {
        DestroyClause(&cloneG);
        return TRUE;
    }
    DestroyClause(&cloneG);
    return FALSE;
}

/**
 * 函数名称：isUnitClause
 * 函数参数：cnfpoint G
 * 函数功能：在CNF公式中查找单子句
 * 返回值：单子句的句子结点或者是nullptr
 **/
clausenode* isUnitClause(cnfpoint G)
{
    clausenode * clausepoint;
    clausepoint=G->root->next_clausenode;
    //printFormula(G);
    while (clausepoint)
    {
       if(clausepoint->next_literalnode!=nullptr && clausepoint->next_literalnode->next_literalnode==nullptr)
            return clausepoint;
       clausepoint=clausepoint->next_clausenode;
    }
    return nullptr;
}

/**
 * 函数名称：SearchNull
 * 函数参数：cnfpoint G
 * 函数功能：寻找空子句
 * 返回值：TRUE FALSE
 **/
status SearchNull(cnfpoint G)
{
    clausenode * clausepoint;
    clausepoint=G->root->next_clausenode;
    while (clausepoint)
    {
        if(clausepoint->next_literalnode==NULL)
         {

            return TRUE;
         }
        clausepoint=clausepoint->next_clausenode;
    }
    return FALSE;
}

/**
 * 函数名称：SisEmpty
 * 函数参数：Graph G
 * 函数功能：判断内存中的链表是不是不含任何文字了
 * 返回值：TRUE FALSE
 **/
status SisEmpty(cnfpoint G)
{
    clausenode * clausepoint;
    clausepoint=G->root->next_clausenode;
    while (clausepoint)
    {
       if(clausepoint->next_literalnode!=nullptr)
              return  FALSE;
       clausepoint=clausepoint->next_clausenode;
    }
    //printf("检测空\n");
    return  TRUE;
//    if(clausepoint==nullptr) return TRUE;
//    else return FALSE;
}

/**
 * 函数名称：WriteAnswer
 * 函数参数：char *filename, int num, double time
 * 函数功能：按要求写入文件
 * 返回值：TRUE FALSE
 **/
status WriteAnswer(std::string filename, int num, double time)
{
    FILE *fp;
    if((fp=fopen(filename.c_str(),"w"))==nullptr) return  FALSE;
    fprintf(fp,"%c %d\n",'s',num);
    if(num==0) {
        fclose(fp);
        return TRUE;
    }
    fprintf(fp,"%c ",'v');
    for(int i=1;i<=answerlength;i++)
        fprintf(fp,"%d ",answer[i].xnum*i);
    //printf("%lf",time*1000);
    fprintf(fp,"\n%c %lf\n",'t',time);
    fclose(fp);
    return TRUE;
}

/**
 * 函数名称：InitAnswer
 * 函数参数：Graph G
 * 函数功能：按照内存中x数量初始化答案
 * 返回值：void
 **/
void InitAnswer(cnfpoint G)
{
    answer=(struct answer *)malloc(((G)->total_literal_num+1)*sizeof(struct answer));
    answerlength=(G)->total_literal_num;

    for(int i=1;i<=answerlength;i++)
    {
            answer[i].negtive=0;
            answer[i].positive=0;
    }
}


