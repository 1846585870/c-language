#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
#define maxsize 100
typedef struct
{
    char *base,*top;
    int stacksize;
}Sqstack;
int Initstack(Sqstack *S)//初始化
{
    S->base=(char*)malloc(maxsize);
    if(!S->base) exit(error);
    S->top=S->base;
    S->stacksize=maxsize;
    return ok;
}
int Push(Sqstack *S,char e)
{
    if(S->top-S->base==S->stacksize) return error;
    *S->top=e;
    S->top++;
    return ok;
}
int Pop(Sqstack *S,char *e)
{
    if(S->top==S->base) return error;
    *e=*--S->top;
    return ok;
}
int Gettop(Sqstack *S)
{
    if(S->top!=S->base)
        return *(S->top-1);
}
int judge(char ch)
{
    if(ch>='0'&&ch<='9'||ch=='.')
        return 1;//为操作数
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='=')//运算符
            return 0;
}
char Precede(char a1,char a2)
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
            case '#':return '>';
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
            case '#':return '>';
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
            case '#':return '>';
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
            case '#':return '>';
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
            case '#':return '>';
        }

    else if(a1=='#')
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
double strreverse(char num[],int length)
{
    char t;
    int i;
    for(i=0;i<=length/2;i++)
    {
      t=num[i];
      num[i]=num[length-1-i];
      num[length-1-i]=t;
    }
    return (double)atof(num);
}
char Evaluateexpression()
{
    Sqstack *OPND,*OPTR;
    char ch,theta,x,y,num[100];
    double a,b,t;
    int i,j;
    Initstack(OPND);
    Initstack(OPTR);
    Push(OPTR,'#');
    Push(OPND,'#');
    while(ch!='#'||Gettop(OPTR)!='#')//表达式没有扫描完毕orOPTR栈顶不为“#”
    {
        if(judge(ch)!=0)
        {
            Push(OPND,ch);
            ch=getchar();
            if(judge(ch)==0)
                Push(OPND,'#');
        }
        else
        {
            switch(Precede(Gettop(OPTR),ch))
            {
                case '<':
                    Push(OPTR,ch);
                    ch=getchar();
                    break;
                case '>':
                    Pop(OPTR,&theta);
                    //弹出2个操作数
                    for(i=0,j=0;i<=2;j++)
                    {
                        Pop(OPND,&y);
                        num[j]=y;
                        if(y=='#')
                        {
                            i++;
                            if(i==1)
                                a=strreverse(num,j+1);
                            if(i==2)
                                b=strreverse(num,j+1);
                            if(i==3)
                                Push(OPND,'#');
                        }
                    }
                    Push(OPND,Operate(a,theta,b));
                    break;
                case '=':
                    Pop(OPTR,&x);
                    ch=getchar();
                    break;
            }
        }
    }
    return Gettop(OPND);
}


int main()
{
    Evaluateexpression();
}
