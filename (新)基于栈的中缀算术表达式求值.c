#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ok 1
#define error 0
#define maxsize 100
typedef struct//OPTR�ṹ��
{
    char *base,*top;
    int stacksize;
}Sqstack_ch;
typedef struct//OPND�ṹ��
{
    double *base,*top;
    int stacksize;
}Sqstack_num;
int Initstack_ch(Sqstack_ch *s)//��ʼ��_OPTR
{
    s->base=(char*)malloc(sizeof(char)*maxsize);
    if(!s->base) return error;
    s->top=s->base;
    s->stacksize=maxsize;
    return ok;
}
int Initstack_num(Sqstack_num *s)//��ʼ��_OPND
{
    s->base=(double*)malloc(4*maxsize);
    if(!s->base) return error;
    s->top=s->base;
    s->stacksize=maxsize;
    return ok;
}
int Push(Sqstack_ch *s,char e)//��ջ_OPTR
{
    if(s->top-s->base==s->stacksize) return error;
    *s->top=e;
    s->top++;
    return ok;
}
int Pop(Sqstack_ch *s,char *e)//��ջ_OPTR
{
    if(s->top==s->base) return error;
    *e=*--s->top;
    return ok;
}
int In(Sqstack_num *s,double e)//��ջ_OPND
{
    if(s->top-s->base==s->stacksize) return error;
    *s->top=e;
    s->top++;
    return ok;
}
int Out(Sqstack_num *s,double *e)//��ջ_OPND
{
    if(s->top==s->base) return error;
    *e=*--s->top;
    return ok;
}
int Gettop_ch(Sqstack_ch *s)//ȡ��ջ����ֵ_OPTR
{
    if(s->top!=s->base)
        return *(s->top-1);
}
double Gettop_num(Sqstack_num *s)//ȡ��ջ����ֵ_OPND
{
    if(s->top!=s->base)
        return *(s->top-1);
}
int judge(char ch)//�ж��ַ��Ƿ�Ϊ������ ����1Ϊ������ ����0λ�����
{
    if(ch>='0'&&ch<='9'||ch=='.')
        return 1;//Ϊ������
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='=')//�����
            return 0;
}
char Precede(char a1,char a2)//���ȼ��Ƚ�
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
double Evaluateexpression()//����1Ϊ������OPND num ����0Ϊ�����OPTR ch
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
        if(judge(ch)==0)//����0λ�����OPTR ch
        {
            switch(Precede(Gettop_ch(&OPTR),ch))
            {
                case '<':
                    Push(&OPTR,ch);
                    ch=getchar();
                    break;
                case '>':
                    Pop(&OPTR,&theta);
                    Out(&OPND,&c);Out(&OPND,&b);//����2��������
                    In(&OPND,Operate(b,theta,c));
                    break;
                case '=':
                    Pop(&OPTR,&x);ch=getchar();
                    break;
            }
        }
        else if(judge(ch)==1) //����1Ϊ������OPND num
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
    getchar();//�����س���
    printf("%.2lf\n",Gettop_num(&OPND));
    }
    free(OPTR.base);//�ڲ������ݵ�ʱ�򣬷��ַ���Ŀռ��������ʱ�ͷţ���Ӱ���´γ������У�����ֿ���������
    free(OPND.base);
}
int main()
{
    Evaluateexpression();
    return 0;
}
