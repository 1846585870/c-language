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
int Initlist(LNode *l)               //初始化
{
    l=(LNode*)malloc(sizeof(LNode));
    l->next=NULL;
    return ok;
}
int Getelem(LNode *l,int i,book *e) //取值
{
    LNode *p;
    int j=1;
    p=l->next;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return error;
    *e=p->data;
    return ok;
}
LNode *LocateElem(LNode *l,book e) //找到目标指针的前驱指针
{
    LNode *p;
    p=l;
    while(p->next&&strcmp(p->next->data.num,e.num)!=0)
        p=p->next;
    return p;
}
float Findmostex(LNode *l)//find the most expensive book
{
    LNode *p;
    float maxprice;
    p=l->next;
    if(!p)
        return error;//数据空
    maxprice=p->data.price;
    for(p=l->next;p!=NULL;p=p->next)
        if(p->data.price > maxprice)
            maxprice=p->data.price;
    return maxprice;

}
int Listinsert(LNode *l,int i,book e)//add elem
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
int Createpoint(LNode *l,int i,book e)
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
    newpoint->next=NULL;
    p->next=newpoint;
    return ok;
}
/*int Listdelete(LNode *l,int i)//delete a elem
{
    LNode *p,*q;
    int j=0;
    p=l;
    while((p->next)&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||(j>i-1)) return error;
    q=p->next;
    p->next=q->next;
    free(q);
    return ok;
}*/
int Deleteelem(LNode *p)
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
                if(p->next==NULL)//表中无数据
                {
                    printf("图书管理系统暂无任何书籍信息\n");
                    return error;
                }
                q=p->next->next;
                if(q==NULL)//表中仅有一个数据 无需排序
                {
                    printf("%s %s %.2f\n",p->next->data.num,p->next->data.name,p->next->data.price);
                    return ok;
                }
                for(p=l,q=p->next->next;q!=NULL;p=p->next,q=p->next->next)
                {
                    printf("2");
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
                    printf("1");
                }
                break;

            }
        case 2:
            {
                p=l;
                if(p->next==NULL)//表中无数据
                {
                    printf("图书管理系统暂无任何书籍信息\n");
                    return error;
                }
                q=p->next->next;
                if(q==NULL)//表中仅有一个数据 无需排序
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
        case 3:;
        case 4:;
        case 5:break;
        default:printf("非法指令\n");
    }
}
int main()
{
    LNode l;
    Initlist(&l);
    l.next=NULL;//缺少这条语句会进入死循环？？
    book e;
    char a[50];
    int i=1,N,j,n;
    float max,price;
    LNode *p;
    printf("************************************************************************\n");
    printf("         |            欢迎进入图书管理系统~!             |\n");
    printf("         |                                               |\n");
    printf("         |            请输入数字选择服务：               |\n");
    printf("         |                1.新书入库：                   |\n");//ok
    printf("         |                2.旧书出库：                   |\n");//ok
    printf("         |               3.最贵书查找：                  |\n");//ok
    printf("         |              4.修改书籍信息：                 |\n");//ok
    printf("         |            5.查询所有书籍信息：               |\n");//ok
    printf("         |                  6.排序：                     |\n");//ok
    printf("         |                7.离开系统                     |\n");//ok
    while(scanf("%d",&N)!=EOF)
    {
        switch(N)
        {
            case 1:
                {
                    printf("请依次输入新书的书号 书名 价格:\n");
                    scanf("%s %s %f",&e.num,&e.name,&e.price);
                    Createpoint(&l,i,e);
                    i++;
                    break;
                }
            case 2:
                {
                    printf("请输入将要出库的旧书书号：\n");
                    scanf("%s",&e.num);
                    p=LocateElem(&l,e);
                    if(p->next==NULL)
                    {
                        printf("这本书不在管理系统的数据内\n");
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
                    if(p==NULL) printf("图书管理系统暂无任何书籍信息\n");
                    else
                    {
                        printf("以下书价格最贵：\n");
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
                    printf("修改信息格式如下：【书名】【需要修改的项目number,name,price】【项目的数值】\n如：9787302257646 price 29.00\n");
                    scanf("%s",&e.num);
                    scanf("%s",&e.name);
                    if(strcmp(e.name,"price")==0)
                    {
                        scanf("%f",&price);
                        p=LocateElem(&l,e);
                        if(p->next==NULL)
                        {
                            printf("这本书不在管理系统的数据内\n");
                            break;
                        }
                        p->next->data.price=price;
                    }
                    else
                    {
                        scanf("%s",&a);
                        p=LocateElem(&l,e);
                        if(p->next==NULL)
                        {
                            printf("这本书不在管理系统的数据内\n");
                            break;
                        }
                        if(strcmp(e.name,"number")==0)
                            strcpy(p->next->data.num,a);
                        else if(strcmp(e.name,"name")==0)
                                strcpy(p->next->data.name,a);
                            else
                                printf("非法指令\n");
                    }

                    break;
                }
            case 5:
                {
                    p=l.next;
                    if(p==NULL)
                    {
                        printf("图书管理系统暂无任何书籍信息\n");
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
                    printf("请继续输入数字：1.价格升序 2.价格降序 3.书号升序 4.书号降序 5.取消\n");
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
}
