#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ok 1
#define error 0
#define maxsize 100
typedef struct//OPTR结构体
{
    char *base,*top;
    int stacksize;
}Sqstack_ch;
typedef struct//OPND结构体
{
    double *base,*top;
    int stacksize;
}Sqstack_num;
int Initstack_ch(Sqstack_ch *s)//初始化_OPTR
{
    s->base=(char*)malloc(sizeof(char)*maxsize);
    if(!s->base) return error;
    s->top=s->base;
    s->stacksize=maxsize;
    return ok;
}
int Initstack_num(Sqstack_num *s)//初始化_OPND
{
    s->base=(double*)malloc(4*maxsize);
    if(!s->base) return error;
    s->top=s->base;
    s->stacksize=maxsize;
    return ok;
}
int Push(Sqstack_ch *s,char e)//进栈_OPTR
{
    if(s->top-s->base==s->stacksize) return error;
    *s->top=e;
    s->top++;
    return ok;
}
int Pop(Sqstack_ch *s,char *e)//出栈_OPTR
{
    if(s->top==s->base) return error;
    *e=*--s->top;
    return ok;
}
int In(Sqstack_num *s,double e)//进栈_OPND
{
    if(s->top-s->base==s->stacksize) return error;
    *s->top=e;
    s->top++;
    return ok;
}
int Out(Sqstack_num *s,double *e)//出栈_OPND
{
    if(s->top==s->base) return error;
    *e=*--s->top;
    return ok;
}
int Gettop_ch(Sqstack_ch *s)//取出栈顶的值_OPTR
{
    if(s->top!=s->base)
        return *(s->top-1);
}
double Gettop_num(Sqstack_num *s)//取出栈顶的值_OPND
{
    if(s->top!=s->base)
        return *(s->top-1);
}
int judge(char ch)//判断字符是否为操作数 返回1为操作数 返回0位运算符
{
    if(ch>='0'&&ch<='9'||ch=='.')
        return 1;//为操作数
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='=')//运算符
            return 0;
}
char Precede(char a1,char a2)//优先级比较
{
    if(a1=='+')
        switch(a2)
        {
            case '+':return '>';
            case '-':return '>';
            case '*':return '<';
            case '/':return '<';
            case '(':return '<';
            case ')':return '>';
            case '=':return '>';
        }
    else if(a1=='-')
        switch(a2)
        {
            case '+':return '>';
            case '-':return '>';
            case '*':return '<';
            case '/':return '<';
            case '(':return '<';
            case ')':return '>';
            case '=':return '>';
        }
    else if(a1=='*')
        switch(a2)
        {
            case '+':return '>';
            case '-':return '>';
            case '*':return '>';
            case '/':return '>';
            case '(':return '<';
            case ')':return '>';
            case '=':return '>';
        }
    else if(a1=='/')
        switch(a2)
        {
            case '+':return '>';
            case '-':return '>';
            case '*':return '>';
            case '/':return '>';
            case '(':return '<';
            case ')':return '>';
            case '=':return '>';
        }
    else if(a1=='(')
        switch(a2)
        {
            case '+':return '<';
            case '-':return '<';
            case '*':return '<';
            case '/':return '<';
            case '(':return '<';
            case ')':return '=';
        }

    else if(a1==')')
        switch(a2)
        {
            case '+':return '>';
            case '-':return '>';
            case '*':return '>';
            case '/':return '>';
            case ')':return '>';
            case '=':return '>';
        }

    else if(a1=='=')
        switch(a2)
        {
            case '+':return '<';
            case '-':return '<';
            case '*':return '<';
            case '/':return '<';
            case '(':return '<';
        }
}
double Operate(double a,char c,double b)
{
    switch(c)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}
double Evaluateexpression()//返回1为操作数OPND num 返回0为运算符OPTR ch
{
    Sqstack_ch OPTR;
    Sqstack_num OPND;
    char ch,z[100]={0},theta,x;
    int i=0;
    double a,b,c;
    Initstack_ch(&OPTR);
    Initstack_num(&OPND);
    Push(&OPTR,'=');
    while(ch=getchar())
    {
        if(ch=='='&&(OPTR.top-OPTR.base)%2!=0)break;
    while(ch!='='||Gettop_ch(&OPTR)!='=')
    {
        if(judge(ch)==0)//返回0位运算符OPTR ch
        {
            switch(Precede(Gettop_ch(&OPTR),ch))
            {
                case '<':
                    Push(&OPTR,ch);
                    ch=getchar();
                    break;
                case '>':
                    Pop(&OPTR,&theta);
                    Out(&OPND,&c);Out(&OPND,&b);//弹出2个操作数
                    In(&OPND,Operate(b,theta,c));
                    break;
                case '=':
                    Pop(&OPTR,&x);ch=getchar();
                    break;
            }
        }
        else if(judge(ch)==1) //返回1为操作数OPND num
        {
            for(i=0;judge(ch);i++)
            {
                z[i]=ch;
                scanf("%c",&ch);
            }
            a=strtod(z,NULL);
            In(&OPND,a);
            memset(z,0,100);
            continue;
        }
    }
    getchar();//消除回车键
    printf("%.2lf\n",Gettop_num(&OPND));
    }
    free(OPTR.base);//在测试数据的时候，发现分配的空间如果不及时释放，会影响下次程序运行（会出现卡慢的现象）
    free(OPND.base);
}
int main()
{
    Evaluateexpression();
    return 0;
}
