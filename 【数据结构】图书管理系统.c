#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define maxsize 10000
#define ok 1
#define error -1
typedef int ElemType;
typedef int Status;
ElemType j;
typedef struct Book
{
    char num[20];
    char name[50];
    float price;
}book;
typedef struct List
{
    book *elem;
    int length;
}SqList;
SqList L;

Status InitList(SqList *L)//创建
{
    (*L).elem=(ElemType*)malloc(maxsize*sizeof(ElemType));
    if(!(*L).elem) exit(OVERFLOW);
    (*L).length=0;
    return ok;
}
Status ListInsert(SqList *L,int i,book e)//在顺序表L中第i个位置插入元素
{
    if((i<1)||(i>(*L).length+1))
        return error;
    if((*L).length==maxsize)
        return error;
    for(j=(*L).length-1;j>i-1;j--)
        (*L).elem[j+1]=(*L).elem[j];
    (*L).elem[i-1]=e;
    ++(*L).length;
    return ok;
}
Status ListDelete(SqList *L,int i)//删除第i位置元素
{
    if((i<1)||(j>(*L).length)) return error;
    for(j=i;j<=(*L).length-1;j++)
        (*L).elem[j-1]=(*L).elem[j];
    --(*L).length;
    return ok;
}
Status GetElem(SqList L,int i,book *e)//取值
{
    if(i<1||i>L.length) return error;
    *e=L.elem[i-1];
    return ok;
}
Status LocateHighElem(SqList *L)//找出最贵的那本书
{
    int i,maxi=0;
    float max;
    max=(*L).elem[0].price;
    for(i=0;i<(*L).length;i++)
        if((*L).elem[i].price>max)
        {
            max=(*L).elem[i].price;
            maxi=i;
        }
    return maxi+1;
}
int main()
{
    printf("************************************************************************\n");
    printf("         |            欢迎进入图书管理系统~!             |\n");
    printf("         |                                               |\n");
    printf("         |            请输入数字选择服务：               |\n");
    printf("         |                1.新书入库：                   |\n");
    printf("         |                2.旧书出库：                   |\n");
    printf("         |               3.最贵书查找：                  |\n");
    printf("         |              4.修改书籍信息：                 |\n");
    char c,a[50];
    book e;
    int k;
    int maxpricei;
    float price;
    InitList(&L);
    strcpy(e.num, "9787302257646");
    strcpy(e.name, "程序设计基础");
    e.price=25.00;
    ListInsert(&L,1,e);
    strcpy(e.num, "9787302164340");
    strcpy(e.name, "程序设计基础（第二版）");
    e.price=20.00;
    ListInsert(&L,2,e);
    strcpy(e.num, "9787811234923");
    strcpy(e.name, "汇编语言程序设计教程");
    e.price=25.00;
    ListInsert(&L,3,e);
    int i=L.length+1;
    int o;
    c=getchar();
    if(c=='1')
    {
        printf("请依次输入新书 书号 书名 价格 并以0 0 0结束输入\n");
        while(scanf("%s %s %f",&e.num,&e.name,&e.price)!=EOF)
        {
            if(e.num[0]=='0'&&e.name[0]=='0'&&e.price==0)
            {
                printf("%d\n",L.length);
                for(k=0;k<L.length;k++)
                    printf("%s %s %.2f\n",L.elem[k].num,L.elem[k].name,L.elem[k].price);
                exit(0);
            }
            ListInsert(&L,i,e);
            i++;
        }
    }
    else if(c=='2')
    {
        printf("请依次输入出库的旧书的书号：（以0结束输入）\n");
        while(scanf("%s",&e.num)!=EOF)
        {
            if(e.num[0]=='0')
            {
                printf("%d\n",L.length);
                for(k=0;k<L.length;k++)
                    printf("%s %s %.2f\n",L.elem[k].num,L.elem[k].name,L.elem[k].price);
                exit(0);
            }
            else
            {
                o=L.length;
                for(k=0;k<L.length;k++)
                    if(strcmp(L.elem[k].num,e.num)==0)
                        {ListDelete(&L,k+1);break;}
                if(k==o)
                    printf("图书管理系统不存在这本书,请重新输入：\n");
            }

        }
    }
        else if(c=='3')
        {
            printf("正在处理数据：\n");
            maxpricei=LocateHighElem(&L);
            printf("以下书价格最贵：\n");
            for(k=0;k<L.length;k++)
                if(L.elem[k].price==L.elem[maxpricei-1].price)
                    printf("%s %s %.2f\n",L.elem[k].num,L.elem[k].name,L.elem[k].price);
        }
        else if(c=='4')
        {
            printf("修改信息格式如下：【书名】【需要修改的项目number,name,price】【项目的数值】\n如：9787302257646 price 29.00\n");
            scanf("%s",&e.num);
            scanf("%s",&e.name);
            if(strcmp(e.name,"price")==0)
            {
                scanf("%f",&price);
                for(k=0;k<L.length;k++)
                    if(strcmp(L.elem[k].num,e.num)==0)break;
                if(k==L.length)
                    {printf("图书管理系统不存在这本书\n");exit(0);}
                else
                    L.elem[k].price=price;
            }
            else
            {
                scanf("%s",&a);
                for(k=0;k<L.length;k++)
                    if(strcmp(L.elem[k].num,e.num)==0)break;
                if(k==L.length)
                    {printf("图书管理系统不存在这本书\n");exit(0);}
                if(strcmp(e.name,"number")==0)
                    strcpy(L.elem[k].num,a);
                else if(strcmp(e.name,"name")==0)
                    strcpy(L.elem[k].name,a);
                    else
                        printf("非法指令\n");
            }
            printf("%d\n",L.length);
                for(k=0;k<L.length;k++)
                    printf("%s %s %.2f\n",L.elem[k].num,L.elem[k].name,L.elem[k].price);
                exit(0);

        }

}

