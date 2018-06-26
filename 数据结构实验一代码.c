#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ok 1
#define error 0
typedef struct
{
    char num[20];
    char name[50];
    float price;
    int *next;
}book;
typedef struct LNode
{
    book data;
    struct LNode *next;
}LNode,*Linklist;
int Initlist(LNode *l)               //��ʼ��
{
    l=(LNode*)malloc(sizeof(LNode));
    l->next=NULL;
    return ok;
}
LNode *LocateElem(LNode *l,book e) //�ҵ�Ŀ��ָ���ǰ��ָ��
{
    LNode *p;
    p=l;
    while(p->next&&strcmp(p->next->data.num,e.num)!=0)
        p=p->next;
    return p;
}
float Findmostex(LNode *l)//�ҵ�������ļ۸�
{
    LNode *p;
    float maxprice;
    p=l->next;
    if(!p)
        return error;//���ݿ�
    maxprice=p->data.price;
    for(p=l->next;p!=NULL;p=p->next)
        if(p->data.price > maxprice)
            maxprice=p->data.price;
    return maxprice;

}
int Createpoint(LNode *l,int i,book e)//��������Ŀ
{
    LNode *p,*newpoint;
    int j=0;
    p=l;
    while(p&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
        return error;
    newpoint=(LNode*)malloc(sizeof(LNode));
    newpoint->data=e;
    newpoint->next=p->next;
    p->next=newpoint;
    return ok;
}
int Deleteelem(LNode *p)//ɾ��
{
    LNode *q;
    q=p->next;
    p->next=q->next;
    free(q);
    return ok;
}
int listsort(LNode *l,int n)
{
    LNode *p,*q,*t,*s;
    switch(n)
    {
        case 1:
            {
                p=l;
                if(p->next==NULL)//����������
                {
                    printf("ͼ�����ϵͳ�����κ��鼮��Ϣ\n");
                    return error;
                }
                q=p->next->next;
                if(q==NULL)//���н���һ������ ��������
                {
                    printf("%s %s %.2f\n",p->next->data.num,p->next->data.name,p->next->data.price);
                    return ok;
                }
                for(p=l,q=p->next->next;q!=NULL;p=p->next,q=p->next->next)
                {
                    for(;q!=NULL;)
                    {
                        if(q->data.price<p->next->data.price)
                        {
                            for(s=p;s->next!=q;s=s->next);
                            t=p->next;
                            p->next=q;
                            q=p->next->next;
                            p->next->next=t;
                            s->next=q;
                        }
                            else q=q->next;
                    }
                }
                break;

            }
        case 2:
            {
                p=l;
                if(p->next==NULL)//����������
                {
                    printf("ͼ�����ϵͳ�����κ��鼮��Ϣ\n");
                    return error;
                }
                q=p->next->next;
                if(q==NULL)//���н���һ������ ��������
                {
                    printf("%s %s %.2f\n",p->next->data.num,p->next->data.name,p->next->data.price);
                    return ok;
                }
                for(p=l,q=p->next->next;q!=NULL;p=p->next,q=p->next->next)
                {
                    for(;q!=NULL;)
                    {
                        if(q->data.price>=p->next->data.price)
                        {
                            for(s=p;s->next!=q;s=s->next);
                            t=p->next;
                            p->next=q;
                            q=p->next->next;
                            p->next->next=t;
                            s->next=q;
                        }
                            else q=q->next;
                    }
                }
                break;
            }
        case 3:break;
        default:printf("�Ƿ�ָ��\n");
    }
}
int Average(LNode *l)
{
LNode *p;
    int i=0;
    p=l->next;
    float a=0;
    if(p==NULL) return -1;
    for(p=l->next;p;p=p->next)
    {
        a+=p->data.price;
        i++;
    }
    printf("%.2f\n",a/i);
    for(p=l->next;p;p=p->next)
    {
        if(p->data.price<a/i)
            p->data.price*=1.2;
        else
            p->data.price*=1.1;
    }
    return ok;
}
int main()
{
    LNode l;
    Initlist(&l);
    l.next=NULL;//ȱ���������������ѭ������
    book e;
    char a[50];
    int i=1,N,j,n,k;
    float max,price;
    LNode *p;
    printf("************************************************************************\n");
    printf("         |            ��ӭ����ͼ�����ϵͳ~!             |\n");
    printf("         |                                               |\n");
    printf("         |            ����������ѡ�����               |\n");
    printf("         |                1.������⣺                   |\n");//ok
    printf("         |                2.������⣺                   |\n");//ok
    printf("         |               3.�������ң�                  |\n");//ok
    printf("         |              4.�޸��鼮��Ϣ��                 |\n");//ok
    printf("         |            5.��ѯ�����鼮��Ϣ��               |\n");//ok
    printf("         |                  6.����                     |\n");//ok
    printf("         |                7.�뿪ϵͳ                     |\n");//ok
    while(scanf("%d",&N)!=EOF)
    {
        switch(N)
        {
            case 1:
                {
                    printf("�������������λ�� �������� ���� �۸�:\n");
                    scanf("%d %s %s %f",&k,&e.num,&e.name,&e.price);
                    if(Createpoint(&l,k,e)==0)
                        printf("��Ǹ�����λ�÷Ƿ�\n");
                    else i++;
                    break;
                }
            case 2:
                {
                    printf("�����뽫Ҫ����ľ�����ţ�\n");
                    scanf("%s",&e.num);
                    p=LocateElem(&l,e);
                    if(p->next==NULL)
                    {
                        printf("�Ȿ�鲻�ڹ���ϵͳ��������\n");
                        break;
                    }
                    else
                    {
                        Deleteelem(p);
                        i--;
                    }
                    break;
                }
            case 3:
                {
                    max=Findmostex(&l);
                    p=l.next;
                    if(p==NULL) printf("ͼ�����ϵͳ�����κ��鼮��Ϣ\n");
                    else
                    {
                        printf("������۸����\n");
                        for(j=1;p!=NULL;j++,p=p->next)
                            if(p->data.price==max)
                            {
                                printf("%s %s %.2f\n",p->data.num,p->data.name,p->data.price);
                            }
                    }
                    break;
                }
            case 4:
                {
                    Average(&l);
                }
            case 5:
                {
                    p=l.next;
                    if(p==NULL)
                    {
                        printf("ͼ�����ϵͳ�����κ��鼮��Ϣ\n");
                        break;
                    }
                    for(;p!=NULL;)
                    {
                        printf("%s %s %.2f\n",p->data.num,p->data.name,p->data.price);
                        p=p->next;
                    }
                    break;
                }
            case 6:
                {
                    printf("������������֣�1.�۸����� 2.�۸��� 3.ȡ��\n");
                    scanf("%d",&n);
                    listsort(&l,n);
                    break;
                }
            case 7:
                {
                    exit(0);
                }
            default: break;
        }
    }
    return 0;
}
