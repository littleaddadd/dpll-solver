//
// Created by littleadd on 2019-02-24.
//
#include <stdio.h>
#include <math.h>
#include "cdcl.h"
//==========================================================================================
//简单的操作函数
void printTime(stats * stats,int cpu_time)
{
    double Time    = (float)(cpu_time)/(float)(CLOCKS_PER_SEC);
    printf("CPU solving time : %12.2f sec\n", Time);
}

//函数功能
//初始化veci向量
void veci_new(veci* v){
    v->size=0;
    v->cap=4;
    v->ptr=(int*)malloc(sizeof(int)*v->cap);
}
//删除veci向量
void veci_delete(veci* v)
{
    free(v->ptr);
}
//返回veci开始指针
int * veci_begin(veci* v)
{
    return v->ptr;
}
//返回veci向量规模
int veci_size(veci *v)
{
    return v->size;
}
//重新设置veci向量规模
void veci_resize(veci* v,int k)
{
    v->size=k;
}
//将e入veci向量
void veci_push(veci* v, int e)
{
    if(v->size==v->cap)
    {
        int newsize=v->cap*2+1;
        v->ptr=(int*)realloc(v->ptr, sizeof(int)*newsize);
        v->cap=newsize;
    }
    v->ptr[v->size++]=e;
}

//初始化vecp向量
void vecp_new(vecp * v)
{
    v->size=0;
    v->cap=4;
    v->ptr=(void**)malloc(sizeof(void*)*v->cap);
}
//删除vecp向量
void vecp_delete(vecp* v)
{
    free(v->ptr);
}
//返回vecp向量的头指针
void ** vecp_begin(vecp *v)
{
    return v->ptr;
}
//返回vecp向量的规模
int vecp_size(vecp *v)
{
    return v->size;
}
//重新更改vecp的规模
void vecp_resize(vecp *v,int k)
{
    v->size=k;
}
//将数送入vecp
void vecp_push(vecp *v,void * e)
{
    if(v->size==v->cap){
        int newsize=v->cap*2+1;
        v->ptr=(void**)realloc(v->ptr, sizeof(void*)*newsize);
        v->cap=newsize;
    }
    v->ptr[v->size++]=e;
}

// *2 变量转文字
int toLit(int v)
{
    return 2*v;
}
// /2 文字转变量
int lit_var(lit l)
{
    return l/2;
}

// n%2 判断奇数偶数
int lit_sign(lit l)
{
    return (l%2);
}

//偶数变奇数 奇数变偶数 其实就是改正负
int lit_nneg(int l) {
    return l^1;
}

//==========================================================================================
//产生[0,1)的随机数
double drand(double* seed)
{
    int q;
    *seed *= 1389796;
    q = (int)(*seed / 2147483647);
    *seed -= (double)q * 2147483647;
    return *seed / 2147483647;
}
//产生[0,size)
static inline int irand(double* seed, int size)
{
    return (int)(drand(seed) * size);
}
//==========================================================================================
//较小的句子处理函数
//返回学习子句的size
int clause_size (clause_of_cdcl* c)
{
    return c->size_learnt >> 1;
}
//返回式子头
lit* clause_begin(clause_of_cdcl* c)
{
    return c->lits;
}
//
int clause_learnt(clause_of_cdcl* c)
{
    return c->size_learnt&1;
}
//
float clause_activity (clause_of_cdcl* c)
{
    return *((float*)&c->lits[c->size_learnt>>1]);
}
//设置活跃因子a
void clause_setactivity(clause_of_cdcl* c,float a)
{
    *((float*)&c->lits[c->size_learnt>>1]) = a;
}
//==========================================================================================
//文字编在式子里
clause_of_cdcl* clause_from_lit(lit l)
{
    return (clause_of_cdcl*)((unsigned long)l+(unsigned long)l+1); //2l+1
}
//判断
Bool clause_is_lit (clause_of_cdcl* c)
{
    return ((unsigned long)c & 1);
}
//从句子读文字
lit clause_read_lit(clause_of_cdcl* c)
{
    return (lit)((unsigned long)c >> 1);
}
//==========================================================================================
//简单处理
int solver_dlevel(solver* s)
{
    return veci_size(&s->trail_lim);
}

vecp* solver_read_wlist(solver* s,lit l)
{
    return &s->wlists[l];
}

void vecp_remove(vecp* v, void* e)
{
    void** ws = vecp_begin(v);
    int    j  = 0;

    for (; ws[j] != e  ; j++);
    for (; j < vecp_size(v)-1; j++) ws[j] = ws[j+1];
    vecp_resize(v,vecp_size(v)-1);
}

//OK
//===========================================================================================
//variable order functions:

void order_update(solver * s,int v) //updateorder
{
    int * orderpos=s->orderpos;
    double * activity=s->activity;
    int * heap =veci_begin(&s->order);
    int i=orderpos[v];
    int x=heap[i];
    int parent=(i-1)/2;

    while (i!=0 && activity[x]>activity[heap[parent]])
    {
        heap[i]=heap[parent];
        orderpos[heap[i]]=i;
        i=parent;
        parent=(i-1)/2;
    }
    heap[i] =x;
    orderpos[x]=i;
}

void order_assigned(solver *s,int v)
{

}

void order_unassigned(solver *s ,int v)
{
    int * orderpos=s->orderpos;
    if (orderpos[v] == -1){
        orderpos[v] = veci_size(&s->order);
        veci_push(&s->order,v);
        order_update(s,v);
    }
}

int  order_select(solver* s, float random_var_freq) // selectvar
{
    int*    heap;
    double* activity;
    int*    orderpos;

    lbool* values = s->assigns;

    // Random decision:
    if (drand(&s->random_seed) < random_var_freq){
        int next = irand(&s->random_seed,s->size);
        if (values[next] == l_Undef)
            return next;
    }

    // Activity based decision:

    heap     = veci_begin(&s->order);
    activity = s->activity;
    orderpos = s->orderpos;


    while (veci_size(&s->order) > 0){
        int    next  = heap[0];
        int    size  = veci_size(&s->order)-1;
        int    x     = heap[size];

        veci_resize(&s->order,size);

        orderpos[next] = -1;

        if (size > 0){
            double act   = activity[x];

            int    i     = 0;
            int    child = 1;


            while (child < size){
                if (child+1 < size && activity[heap[child]] < activity[heap[child+1]])
                    child++;

                if (act >= activity[heap[child]])
                    break;

                heap[i]           = heap[child];
                orderpos[heap[i]] = i;
                i                 = child;
                child             = 2 * child + 1;
            }
            heap[i]           = x;
            orderpos[heap[i]] = i;
        }

        if (values[next] == l_Undef)
            return next;
    }

    return var_Undef;
}

//OK
//============================================================
//Activity functions:
void act_var_rescale(solver* s) {
    double* activity = s->activity;
    int i;
    for (i = 0; i < s->size; i++)
        activity[i] *= 1e-100;
    s->var_inc *= 1e-100;
}


void act_var_bump(solver* s, int v) {
    double* activity = s->activity;
    if ((activity[v] += s->var_inc) > 1e100)
        act_var_rescale(s);

    //printf("bump %d %f\n", v-1, activity[v]);

    if (s->orderpos[v] != -1)
        order_update(s,v);

}

void act_var_decay(solver* s)
{
    s->var_inc *= s->var_decay;
}

void act_clause_rescale(solver* s) {
    clause_of_cdcl** cs = (clause_of_cdcl**)vecp_begin(&s->learnts);
    int i;
    for (i = 0; i < vecp_size(&s->learnts); i++){
        float a = clause_activity(cs[i]);
        clause_setactivity(cs[i], a * (float)1e-20);
    }
    s->cla_inc *= (float)1e-20;
}

void act_clause_bump(solver* s, clause_of_cdcl *c) {
    float a = clause_activity(c) + s->cla_inc;
    clause_setactivity(c,a);
    if (a > 1e20) act_clause_rescale(s);
}

void act_clause_decay(solver* s) { s->cla_inc *= s->cla_decay; }

//OK
//===================================================
//clause functions:
clause_of_cdcl * clause_new(solver * s,lit * begin,lit *end,int learnt)
{
    int size;
    clause_of_cdcl* c;
    int i;

    size=end-begin;
    c   =(clause_of_cdcl*)malloc(sizeof(clause_of_cdcl)+ sizeof(lit)*size+learnt* sizeof(float));
    c->size_learnt=(size<<1) | learnt; //size*2 按位或

    for (int i = 0; i < size; ++i) {
        c->lits[i]=begin[i]; //赋值
    }
    if(learnt)
        *((float*)&c->lits[size])=0.0;

    vecp_push(solver_read_wlist(s,lit_nneg(begin[0])),(void*)(size > 2 ? c : clause_from_lit(begin[1]))); //
    vecp_push(solver_read_wlist(s,lit_nneg(begin[1])),(void*)(size > 2 ? c : clause_from_lit(begin[0]))); //
    return c;
}

void clause_remove(solver* s, clause_of_cdcl* c)
{
    lit* lits = clause_begin(c);

    //vecp_remove(solver_read_wlist(s,lit_neg(lits[0])),(void*)c);
    //vecp_remove(solver_read_wlist(s,lit_neg(lits[1])),(void*)c);

    vecp_remove(solver_read_wlist(s,lit_nneg(lits[0])),(void*)(clause_size(c) > 2 ? c : clause_from_lit(lits[1])));
    vecp_remove(solver_read_wlist(s,lit_nneg(lits[1])),(void*)(clause_size(c) > 2 ? c : clause_from_lit(lits[0])));

    if (clause_learnt(c)){
        s->stats.learnts--;
        s->stats.learnts_literals -= clause_size(c);
    }else{
        s->stats.clauses--;
        s->stats.clauses_literals -= clause_size(c);
    }

    free(c);
}


lbool clause_simplify(solver* s, clause_of_cdcl* c)
{
    lit*   lits   = clause_begin(c);
    lbool* values = s->assigns;
    int i;


    for (i = 0; i < clause_size(c); i++){
        lbool sig = !lit_sign(lits[i]); sig += sig - 1;
        if (values[lit_var(lits[i])] == sig)
            return l_True;
    }
    return l_False;
}

//OK
//==============================================================
//Minor (solver) functions:

void solver_setnvars(solver* s,int n)
{
    int var;
    if(s->cap<n)
    {
        while (s->cap<n) s->cap=s->cap*2+1;
        //字符串realloc
        s->wlists    = (vecp*)   realloc(s->wlists,   sizeof(vecp)*s->cap*2);
        s->activity  = (double*) realloc(s->activity, sizeof(double)*s->cap);
        s->assigns   = (lbool*)  realloc(s->assigns,  sizeof(lbool)*s->cap);
        s->orderpos  = (int*)    realloc(s->orderpos, sizeof(int)*s->cap);
        s->reasons   = (clause_of_cdcl**)realloc(s->reasons,  sizeof(clause_of_cdcl*)*s->cap);
        s->levels    = (int*)    realloc(s->levels,   sizeof(int)*s->cap);
        s->tags      = (lbool*)  realloc(s->tags,     sizeof(lbool)*s->cap);
        s->trail     = (lit*)    realloc(s->trail,    sizeof(lit)*s->cap);
    }

    for (var=s->size;var<n;var++)
    {
        vecp_new(&s->wlists[2*var]);
        vecp_new(&s->wlists[2*var+1]);
        s->activity[var]=0;
        s->assigns[var]=l_Undef;  //l_Undef就是0
        s->orderpos[var]=veci_size(&s->order);
        s->reasons[var]=(clause_of_cdcl*)0;
        s->levels[var]=0;
        s->tags[var]=l_Undef;

        veci_push(&s->order,var);
        order_update(s,var);
    }
    s->size=n > s->size? n: s->size;
}


Bool enqueue(solver * s,lit l,clause_of_cdcl* from)
{
    lbool * values=s->assigns;  //lboor就是  char   变量的临时取值
    int v=lit_var(l);           // /2
    lbool val=values[v];

    lbool sig = !lit_sign(l);   // l为奇数 式子为0  l为偶数 式子为1
    sig+=sig-1;                  //奇数-1 偶数1
    if(val!=l_Undef)             //如果已经定义过了
        return val==sig;
    else
    {
        int * levels=s->levels;
        clause_of_cdcl** reasons = s->reasons;

        values[v]=sig;

        levels[v]=solver_dlevel(s);    //veci_size(&s->trail_lim);
        reasons[v]=from;               // 0
        s->trail[s->qtail++]=l;        //进入队列 q->tail表示队列头 l就是值

        order_assigned(s,v);         //暂时为空
        return True;
    }
}

void assume(solver* s,lit l)
{
    veci_push(&s->trail_lim,s->qtail);
    enqueue(s,l,(clause_of_cdcl*)0);
}

void solver_canceluntil(solver* s,int level){
    lit* trail;
    lbool * values;
    clause_of_cdcl** reasons;
    int bound;
    int c;

    if(solver_dlevel(s)<=level)
        return;

    trail = s->trail;
    values = s->assigns;
    reasons=s->reasons;
    bound   = (veci_begin(&s->trail_lim))[level];

    for (c = s->qtail-1; c >= bound; c--) {
        int     x  = lit_var(trail[c]);
        values [x] = l_Undef;
        reasons[x] = (clause_of_cdcl*)0;
    }

    for (c = s->qhead-1; c >= bound; c--)
        order_unassigned(s,lit_var(trail[c]));

    s->qhead = s->qtail = bound;
    veci_resize(&s->trail_lim,level);


}

static void solver_record(solver* s, veci* cls)
{
    lit*    begin = veci_begin(cls);
    lit*    end   = begin + veci_size(cls);
    clause_of_cdcl* c     = (veci_size(cls) > 1) ? clause_new(s,begin,end,1) : (clause_of_cdcl*)0;
    enqueue(s,*begin,c);

    if (c != 0) {
        vecp_push(&s->learnts,c);
        act_clause_bump(s,c);
        s->stats.learnts++;
        s->stats.learnts_literals += veci_size(cls);
    }
}

static double solver_progress(solver* s)
{
    lbool*  values = s->assigns;
    int*    levels = s->levels;
    int     i;

    double  progress = 0;
    double  F        = 1.0 / s->size;
    for (i = 0; i < s->size; i++)
        if (values[i] != l_Undef)
            progress += pow(F, levels[i]);
    return progress / s->size;
}

//OK
//===================================================================
//major methods:
Bool solver_lit_removable(solver* s, lit l, int minl)
{
    lbool*   tags    = s->tags;
    clause_of_cdcl** reasons = s->reasons;
    int*     levels  = s->levels;
    int      top     = veci_size(&s->tagged);

    veci_resize(&s->stack,0);
    veci_push(&s->stack,lit_var(l));

    while (veci_size(&s->stack) > 0){
        clause_of_cdcl* c;
        int v = veci_begin(&s->stack)[veci_size(&s->stack)-1];
        veci_resize(&s->stack,veci_size(&s->stack)-1);
        c    = reasons[v];

        if (clause_is_lit(c)){
            int v = lit_var(clause_read_lit(c));
            if (tags[v] == l_Undef && levels[v] != 0){
                if (reasons[v] != 0 && ((1 << (levels[v] & 31)) & minl)){
                    veci_push(&s->stack,v);
                    tags[v] = l_True;
                    veci_push(&s->tagged,v);
                }else{
                    int* tagged = veci_begin(&s->tagged);
                    int j;
                    for (j = top; j < veci_size(&s->tagged); j++)
                        tags[tagged[j]] = l_Undef;
                    veci_resize(&s->tagged,top);
                    return False;
                }
            }
        }else{
            lit*    lits = clause_begin(c);
            int     i, j;

            for (i = 1; i < clause_size(c); i++){
                int v = lit_var(lits[i]);
                if (tags[v] == l_Undef && levels[v] != 0){
                    if (reasons[v] != 0 && ((1 << (levels[v] & 31)) & minl)){

                        veci_push(&s->stack,lit_var(lits[i]));
                        tags[v] = l_True;
                        veci_push(&s->tagged,v);
                    }else{
                        int* tagged = veci_begin(&s->tagged);
                        for (j = top; j < veci_size(&s->tagged); j++)
                            tags[tagged[j]] = l_Undef;
                        veci_resize(&s->tagged,top);
                        return False;
                    }
                }
            }
        }
    }

    return True;
}

void solver_analyze(solver* s,clause_of_cdcl* c,veci* learnt)
{
    lit*     trail   = s->trail;
    lbool*   tags    = s->tags;
    clause_of_cdcl** reasons = s->reasons;
    int*     levels  = s->levels;
    int      cnt     = 0;
    lit      p       = lit_Undef;
    int      ind     = s->qtail-1;
    lit*     lits;
    int      i, j, minl;
    int*     tagged;

    veci_push(learnt,lit_Undef);
    do{

        if (clause_is_lit(c)){
            lit q = clause_read_lit(c);
            if (tags[lit_var(q)] == l_Undef && levels[lit_var(q)] > 0){
                tags[lit_var(q)] = l_True;
                veci_push(&s->tagged,lit_var(q));
                act_var_bump(s,lit_var(q));
                if (levels[lit_var(q)] == solver_dlevel(s))
                    cnt++;
                else
                    veci_push(learnt,q);
            }
        }else{

            if (clause_learnt(c))
                act_clause_bump(s,c);

            lits = clause_begin(c);
            //printlits(lits,lits+clause_size(c)); printf("\n");
            for (j = (p == lit_Undef ? 0 : 1); j < clause_size(c); j++){
                lit q = lits[j];
                if (tags[lit_var(q)] == l_Undef && levels[lit_var(q)] > 0){
                    tags[lit_var(q)] = l_True;
                    veci_push(&s->tagged,lit_var(q));
                    act_var_bump(s,lit_var(q));
                    if (levels[lit_var(q)] == solver_dlevel(s))
                        cnt++;
                    else
                        veci_push(learnt,q);
                }
            }
        }

        while (tags[lit_var(trail[ind--])] == l_Undef);

        p = trail[ind+1];
        c = reasons[lit_var(p)];
        cnt--;

    }while (cnt > 0);

    *veci_begin(learnt) = lit_nneg(p);

    lits = veci_begin(learnt);
    minl = 0;
    for (i = 1; i < veci_size(learnt); i++){
        int lev = levels[lit_var(lits[i])];
        minl    |= 1 << (lev & 31);
    }

    // simplify (full)
    for (i = j = 1; i < veci_size(learnt); i++){
        if (reasons[lit_var(lits[i])] == 0 || !solver_lit_removable(s,lits[i],minl))
            lits[j++] = lits[i];
    }

    // update size of learnt + statistics
    s->stats.max_literals += veci_size(learnt);
    veci_resize(learnt,j);
    s->stats.tot_literals += j;

    // clear tags
    tagged = veci_begin(&s->tagged);
    for (i = 0; i < veci_size(&s->tagged); i++)
        tags[tagged[i]] = l_Undef;
    veci_resize(&s->tagged,0);

    if (veci_size(learnt) > 1){
        int max_i = 1;
        int max   = levels[lit_var(lits[1])];
        lit tmp;

        for (i = 2; i < veci_size(learnt); i++)
            if (levels[lit_var(lits[i])] > max){
                max   = levels[lit_var(lits[i])];
                max_i = i;
            }

        tmp         = lits[1];
        lits[1]     = lits[max_i];
        lits[max_i] = tmp;
    }
}


clause_of_cdcl * solver_propagate(solver *s)
{
    lbool * values = s->assigns;
    clause_of_cdcl* confl  =(clause_of_cdcl*)0;
    lit*    lits;

    while (confl ==0 && s->qtail-s->qhead>0){
        lit p = s->trail[s->qhead++];
        vecp* ws =solver_read_wlist(s,p);
        clause_of_cdcl **begin = (clause_of_cdcl**)vecp_begin(ws);
        clause_of_cdcl **end   =begin+vecp_size(ws);
        clause_of_cdcl **i,**j;

        s->stats.propagations++;
        s->simpdb_props--;

        for (i =j=begin; i < end;) {
            if (clause_is_lit(*i)){
                *j++=*i;
                if(!enqueue(s,clause_read_lit(*i),clause_from_lit(p))){
                    confl=s->binary;
                    (clause_begin(confl))[1]=lit_nneg(p);
                    (clause_begin(confl))[0]=clause_read_lit(*i++);

                    while (i<end)
                        *j++ = *i++;
                }
            }
            else
            {
                lit false_lit;
                lbool sig;
                lits=clause_begin(*i);

                false_lit=lit_nneg(p);
                if(lits[0]==false_lit)
                {
                    lits[0]=lits[1];
                    lits[1]=false_lit;
                }

                sig = !lit_sign(lits[0]); sig+=sig-1;
                if(values[lit_var(lits[0])]==sig){
                    *j++=*i;
                }
                else
                {
                    lit* stop=lits+clause_size(*i);
                    lit* k;
                    for (k = lits + 2; k < stop; k++){
                        lbool sig = lit_sign(*k); sig += sig - 1;
                        if (values[lit_var(*k)] != sig){
                            lits[1] = *k;
                            *k = false_lit;
                            vecp_push(solver_read_wlist(s,lit_nneg(lits[1])),*i);
                            goto next; }
                    }

                    *j++ = *i;
                    // Clause is unit under assignment:
                    if (!enqueue(s,lits[0], *i)){
                        confl = *i++;
                        // Copy the remaining watches:
                        while (i < end)
                            *j++ = *i++;
                    }
                }
            }
            next:
                i++;
        }
        s->stats.inspects+=j-(clause_of_cdcl**)vecp_begin(ws);
        vecp_resize(ws,j-(clause_of_cdcl**)vecp_begin(ws));
    }
    return confl;
}

int clause_cmp (const void* x, const void* y) {
    return clause_size((clause_of_cdcl*)x) > 2 && (clause_size((clause_of_cdcl*)y) == 2 || clause_activity((clause_of_cdcl*)x) < clause_activity((clause_of_cdcl*)y)) ? -1 : 1;
}


void solver_reducedb(solver* s)
{
    int      i, j;
    double   extra_lim = s->cla_inc / vecp_size(&s->learnts); // Remove any clause below this activity
    clause_of_cdcl** learnts = (clause_of_cdcl**)vecp_begin(&s->learnts);
    clause_of_cdcl** reasons = s->reasons;

    sort(vecp_begin(&s->learnts), vecp_size(&s->learnts), &clause_cmp);

    for (i = j = 0; i < vecp_size(&s->learnts) / 2; i++){
        if (clause_size(learnts[i]) > 2 && reasons[lit_var(*clause_begin(learnts[i]))] != learnts[i])
            clause_remove(s,learnts[i]);
        else
            learnts[j++] = learnts[i];
    }
    for (; i < vecp_size(&s->learnts); i++){
        if (clause_size(learnts[i]) > 2 && reasons[lit_var(*clause_begin(learnts[i]))] != learnts[i] && clause_activity(learnts[i]) < extra_lim)
            clause_remove(s,learnts[i]);
        else
            learnts[j++] = learnts[i];
    }

    //printf("reducedb deleted %d\n", vecp_size(&s->learnts) - j);


    vecp_resize(&s->learnts,j);
}


lbool solver_search(solver *s ,int nof_conflicts,int nof_learnts)
{
    int*    levels          = s->levels;
    double  var_decay       = 0.95;
    double  clause_decay    = 0.999;
    double  random_var_freq = 0.02;

    int     conflictC       = 0;
    veci    learnt_clause;

    s->stats.starts++;
    s->var_decay = (float)(1 / var_decay   );
    s->cla_decay = (float)(1 / clause_decay);
    veci_resize(&s->model,0);
    veci_new(&learnt_clause);

    for (;;){
        clause_of_cdcl* confl = solver_propagate(s);
        if (confl != 0){
            // CONFLICT
            int blevel;

            s->stats.conflicts++; conflictC++;
            if (solver_dlevel(s) == s->root_level){
                veci_delete(&learnt_clause);
                return l_False;
            }

            veci_resize(&learnt_clause,0);
            solver_analyze(s, confl, &learnt_clause);
            blevel = veci_size(&learnt_clause) > 1 ? levels[lit_var(veci_begin(&learnt_clause)[1])] : s->root_level;
            blevel = s->root_level > blevel ? s->root_level : blevel;
            solver_canceluntil(s,blevel);
            solver_record(s,&learnt_clause);
            act_var_decay(s);
            act_clause_decay(s);

        }else{
            // NO CONFLICT
            int next;

            if (nof_conflicts >= 0 && conflictC >= nof_conflicts){
                // Reached bound on number of conflicts:
                s->progress_estimate = solver_progress(s);
                solver_canceluntil(s,s->root_level);
                veci_delete(&learnt_clause);
                return l_Undef; }

            if (solver_dlevel(s) == 0)
                // Simplify the set of problem clauses:
                solver_simplify(s);

            if (nof_learnts >= 0 && vecp_size(&s->learnts) - s->qtail >= nof_learnts)
                // Reduce the set of learnt clauses:
                solver_reducedb(s);

            // New variable decision:
            s->stats.decisions++;
            next = order_select(s,(float)random_var_freq);

            if (next == var_Undef){
                // Model found:
                lbool* values = s->assigns;
                int i;
                for (i = 0; i < s->size; i++) veci_push(&s->model,(int)values[i]);
                solver_canceluntil(s,s->root_level);
                veci_delete(&learnt_clause);

                /*
                veci apa; veci_new(&apa);
                for (i = 0; i < s->size; i++)
                    veci_push(&apa,(int)(s->model.ptr[i] == l_True ? toLit(i) : lit_neg(toLit(i))));
                printf("model: "); printlits((lit*)apa.ptr, (lit*)apa.ptr + veci_size(&apa)); printf("\n");
                veci_delete(&apa);
                */

                return l_True;
            }

            assume(s,lit_nneg(toLit(next)));
        }
    }

    return l_Undef; // cannot happen
}


//OK
//===================================================================
//external solver functions:
solver* solver_new(void)
{
    solver* s=(solver*)malloc(sizeof(solver)); //申请空间

    //初始化向量
    vecp_new(&s->clauses);
    vecp_new(&s->learnts);

    veci_new(&s->order);
    veci_new(&s->trail_lim);
    veci_new(&s->tagged);
    veci_new(&s->stack);
    veci_new(&s->model);

    //初始化字符串
    s->wlists = 0;
    s->activity = 0;
    s->assigns=0;
    s->orderpos=0;
    s->reasons=0;
    s->levels=0;
    s->tags=0;
    s->trail=0;

    //初始化其他
    s->size                       =0;
    s->cap                        =0;
    s->qhead                      =0;
    s->qtail                      =0;
    s->cla_inc                    =1;
    s->cla_decay                  =1;
    s->var_inc                    =1;
    s->var_decay                  =1;
    s->root_level                 =0;
    s->simpdb_assigns             =0;
    s->simpdb_props               =0;
    s->random_seed                =91648253;
    s->progress_estimate          =0;
    s->binary                     =(clause_of_cdcl*)malloc(sizeof(clause_of_cdcl)+ sizeof(lit)*2);
    s->binary->size_learnt        =(2<<1);
    s->verbosity                  =0;

    //初始化stats里的数
    s->stats.starts           = 0;
    s->stats.decisions        = 0;
    s->stats.propagations     = 0;
    s->stats.inspects         = 0;
    s->stats.conflicts        = 0;
    s->stats.clauses          = 0;
    s->stats.clauses_literals = 0;
    s->stats.learnts          = 0;
    s->stats.learnts_literals = 0;
    s->stats.max_literals     = 0;
    s->stats.tot_literals     = 0;

    return s;
}

void solver_delete(solver* s)
{
    int i;
    for (i = 0; i < vecp_size(&s->clauses); i++)
        free(vecp_begin(&s->clauses)[i]);

    for (i = 0; i < vecp_size(&s->learnts); i++)
        free(vecp_begin(&s->learnts)[i]);

    // delete vectors
    vecp_delete(&s->clauses);
    vecp_delete(&s->learnts);
    veci_delete(&s->order);
    veci_delete(&s->trail_lim);
    veci_delete(&s->tagged);
    veci_delete(&s->stack);
    veci_delete(&s->model);
    free(s->binary);

    // delete arrays
    if (s->wlists != 0){
        int i;
        for (i = 0; i < s->size*2; i++)
            vecp_delete(&s->wlists[i]);

        // if one is different from null, all are
        free(s->wlists);
        free(s->activity );
        free(s->assigns  );
        free(s->orderpos );
        free(s->reasons  );
        free(s->levels   );
        free(s->trail    );
        free(s->tags     );
    }

    free(s);
}


//用于把句子加进来
Bool solver_addclause(solver* s,lit * begin,lit * end)  //lit就是int
{
    lit *i,*j;                //lit就是int
    int maxvar;
    lbool* values;           //lbool就是char
    lit last;

    if(begin == end) return False;    //返回false

    maxvar=lit_var(*begin);           //除2截断  其实就是还原了

    for (i = begin+1; i < end; ++i) {
        lit l;
        l = * i;
        maxvar = lit_var(l) > maxvar ? lit_var(l) : maxvar;  //找出最大的x
        for (j = i; j > begin && *(j-1) > l; j--) //其实就是交换排序 然后把最小的数放在了最前面
            *j = *(j-1);
        *j = l;
    }

    solver_setnvars(s,maxvar+1); //设置变量

    values=s->assigns; //变量 s-》assigns表示变量暂时的值

    last=lit_Undef;  //-2 表示文字尚未被定义
    for (i = j=begin; i < end; i++) {

        lbool sig = !lit_sign(*i);
        sig += sig-1;  //lbool就是char 奇数 sig=-1 偶数 sig=1
        if (*i==lit_nneg(last) || sig == values [lit_var(*i)]) // sig== (*i)/2 其实这里的奇数偶数就是判断正负的
            return True; //说明是个重言式
        else if (*i != last && values[lit_var(*i)] == l_Undef)  //l_Undef表示0 没定义才会加入j的统计
            last = *j++ = *i;  //如果遇到了一个句子中的重复文字 这句话是不会执行的
    }

    if(j==begin)           //空句子empty clause
        return False;
    else if(j-begin == 1)  //单子句unit clause
        return enqueue(s,*begin,(clause_of_cdcl*)0); //进队列
    vecp_push(&s->clauses,clause_new(s,begin,j,0)); //入栈

    s->stats.clauses++;
    s->stats.clauses_literals += j-begin;

    return True;
}

Bool   solver_simplify(solver* s)
{
    clause_of_cdcl** reasons;
    int type;

    if (solver_propagate(s) != 0)
        return False;

    if (s->qhead == s->simpdb_assigns || s->simpdb_props > 0)
        return True;

    reasons = s->reasons;
    for (type = 0; type < 2; type++){
        vecp*    cs  = type ? &s->learnts : &s->clauses;
        clause_of_cdcl** cls = (clause_of_cdcl**)vecp_begin(cs);

        int i, j;
        for (j = i = 0; i < vecp_size(cs); i++){
            if (reasons[lit_var(*clause_begin(cls[i]))] != cls[i] &&
                clause_simplify(s,cls[i]) == l_True)
                clause_remove(s,cls[i]);
            else
                cls[j++] = cls[i];
        }
        vecp_resize(cs,j);
    }

    s->simpdb_assigns = s->qhead;
    // (shouldn't depend on 'stats' really, but it will do for now)
    s->simpdb_props   = (int)(s->stats.clauses_literals + s->stats.learnts_literals);

    return True;
}




Bool solver_solve(solver *s,lit *begin,lit * end)
{
    double nof_conflicts=100;
    double nof_learnts  =solver_nclauses(s)/3;
    char status = l_Undef ;//0
    char* values = s->assigns; //
    int* i;

    for (i = begin; i < end; ++i) {
        switch (lit_sign(*i) ? -values[lit_var(*i)] : values[lit_var(*i)])
        {
            case 1: /*l_True*/
                break;
            case 0: /*l_Undef*/
                assume(s,*i);
                if(solver_propagate(s)==NULL)
                    break;
            case -1:/*l_False*/
                solver_canceluntil(s,0);
                return False;
        }
    }

    s->root_level=solver_dlevel(s);
    if(s->verbosity >= 1)
    {
        printf("solving......................\n");
    }
    while (status == l_Undef)
    {
        double Ratio =(s->stats.learnts==0)?0.0:s->stats.learnts_literals/(double)s->stats.learnts;

        status=solver_search(s,(int)nof_conflicts,(int)nof_conflicts);
        nof_conflicts *= 1.5;
        nof_learnts   *=1.1;
    }
    solver_canceluntil(s,0);
    return status != l_False;
}


int solver_nclauses(solver* s)
{
    return vecp_size(&s->clauses);
}

//no OK
//=====================================================================
//Sorting functions (sigh):

void selectionsort(void** array, int size, int(*comp)(const void *, const void *))
{
    int     i, j, best_i;
    void*   tmp;

    for (i = 0; i < size-1; i++){
        best_i = i;
        for (j = i+1; j < size; j++){
            if (comp(array[j], array[best_i]) < 0)
                best_i = j;
        }
        tmp = array[i]; array[i] = array[best_i]; array[best_i] = tmp;
    }
}

void sortrnd(void** array, int size, int(*comp)(const void *, const void *), double* seed)
{
    if (size <= 15)
        selectionsort(array, size, comp);

    else{
        void*       pivot = array[irand(seed, size)];
        void*       tmp;
        int         i = -1;
        int         j = size;

        for(;;){
            do i++; while(comp(array[i], pivot)<0);
            do j--; while(comp(pivot, array[j])<0);

            if (i >= j) break;

            tmp = array[i]; array[i] = array[j]; array[j] = tmp;
        }

        sortrnd(array    , i     , comp, seed);
        sortrnd(&array[i], size-i, comp, seed);
    }
}

void sort(void** array, int size, int(*comp)(const void *, const void *))
{
    double seed = 91648253;
    sortrnd(array,size,comp,&seed);
}


int read_File(std::string filename, solver *s)
{
    FILE *fp;
    if((fp=fopen(filename.c_str(),"r"))==NULL) return 0;
    char string[1024];
    while (1)
    {
        fscanf(fp,"%s",string);
        if(strcmp(string,"cnf")==0)
        {
            fscanf(fp,"%s",string);
            fscanf(fp,"%s",string);
            break;
        }
    } //跳过前面注释

    veci lits;
    veci_new(&lits);
    for (int i = 0;; ++i) {
        lit* begin;

        int parsed_lit,var;
        veci_resize(&lits,0);
        for (int j = 0;; ++j) {
            int readnum;
            fscanf(fp,"%d",&readnum);
            if(readnum==0) break;
            var = abs(readnum)-1;
            //printf("%d                  %d  \n",var,toLit(var));
            veci_push(&lits, (readnum > 0 ? toLit(var) : lit_nneg(toLit(var))));
        }
        if (feof(fp)!=0) break;
        begin=veci_begin(&lits);

        if (!solver_addclause(s, begin, begin+veci_size(&lits))){
            veci_delete(&lits);
            return l_False;
        }
    }
    veci_delete(&lits);
    return solver_simplify(s);
}
