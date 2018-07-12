#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <windows.h>
#define MAXSIZE 10

using namespace std;

//data
typedef FILE file;
typedef struct
{
    char num[5];
    char name[20];
    float price;
    int count;
    float sale;
}ElemType;
typedef struct
{
    ElemType drug[MAXSIZE+1];
    int length;
}Sqlist;
//data

void Print(Sqlist &l)
{
    int i;
    cout << "编号" <<" "<< "药名" <<'\t'<< "单价" <<'\t'<< "销售量" <<'\t'<< "销售额" <<endl;
    for(i=1;i<=l.length;i++)
        cout << l.drug[i].num <<" "<<l.drug[i].name <<'\t'<<l.drug[i].price <<'\t'<<l.drug[i].count <<'\t'<<l.drug[i].sale <<endl;
}
void Read_txt(Sqlist &l)
{
    file *fp;
    fp=fopen("D:\\data.txt","r+");
    if(fp==NULL)
    {
        cout << "文件不存在或者无权限读取" <<endl;exit(0);
    }
    for(int i=1;!feof(fp);i++)
    {
         fscanf(fp,"%s %s %f %d %f", &l.drug[i].num , &l.drug[i].name , &l.drug[i].price ,&l.drug[i].count , &l.drug[i].sale);
         l.length++;
    }
}
void Sort_num(Sqlist &l)
{
    int m=l.length-1,flag=1,j;
    ElemType t;
    while((m>0)&&flag==1)
    {
        flag=0;
        for(j=1;j<=m;j++)
            if(strcmp(l.drug[j].num,l.drug[j+1].num)>0)
            {
                flag=1;
                t=l.drug[j];l.drug[j]=l.drug[j+1];l.drug[j+1]=t;
            }
            --m;
    }
    Print(l);
}
void BubbleSort(Sqlist &l)
{
    int m=l.length-1,flag=1,j;
    ElemType t;
    while((m>0)&&flag==1)
    {
        flag=0;
        for(j=1;j<=m;j++)
            if(l.drug[j].price>l.drug[j+1].price)
            {
                flag=1;
                t=l.drug[j];l.drug[j]=l.drug[j+1];l.drug[j+1]=t;
            }
            --m;
    }
    Print(l);
}
int Partition(Sqlist &l,int low,int high)
{
    int pivotkey;
    l.drug[0]=l.drug[low];
    pivotkey=l.drug[low].count;
    while(low<high)
    {
        while(low<high&&l.drug[high].count>=pivotkey) --high;
        l.drug[low]=l.drug[high];
        while(low<high&&l.drug[low].count<=pivotkey) ++low;
        l.drug[high]=l.drug[low];
    }
    l.drug[low]=l.drug[0];
    return low;
}
void Qsort(Sqlist &l,int low,int high)
{
    int pivotloc;
    if(low<high)
    {
        pivotloc=Partition(l,low,high);
        Qsort(l,low,pivotloc-1);
        Qsort(l,pivotloc+1,high);
    }
}
void QuickSort(Sqlist &l)
{
    Qsort(l,1,l.length);
    Print(l);
}
void HeapAdjust(Sqlist &l,int s,int m)
{
    ElemType rc;
    rc=l.drug[s];
    for(int j=2*s;j<=m;j*=2)
    {
        if(j<m&&l.drug[j].sale<l.drug[j+1].sale) ++j;
        if(rc.sale>=l.drug[j].sale) break;
        l.drug[s]=l.drug[j];s=j;
    }
    l.drug[s]=rc;
}
void CreateHeap(Sqlist &l)
{
    int n=l.length;
    for(int i=n/2;i>0;--i)
        HeapAdjust(l,i,n);
}
void HeapSort(Sqlist &l)
{
    CreateHeap(l);
    ElemType x;
    for(int i=l.length;i>1;--i)
    {
        x=l.drug[1];
        l.drug[1]=l.drug[i];
        l.drug[i]=x;
        HeapAdjust(l,1,i-1);
    }
    Print(l);
}
int main()
{
    Sqlist l;
    int n;
    l.length=0;
    cout << "|                   欢迎来到药品销售统计系统                   |"<<endl;
    cout << "|             正在读入药品信息，请稍等............             |"<<endl;
    Read_txt(l);
    cout << "|                  读取成功，请稍等............                |"<<endl;
    system("CLS");
    cout << "—————————————————————————————————"<<endl;
    cout << "|                    欢迎来到药品销售统计系统                    |"<<endl;
    cout << "| 1.药品编号排序 2.单价排序 3.销售量排序 4.销售额排序 5.离开系统 |"<<endl;
    cout << "—————————————————————————————————"<<endl;
    cout << "请输入序号：" << endl;

    cin >> n;
    while(n!=5)
    {
        switch(n)
        {
        case 1:Sort_num(l);break;
        case 2:BubbleSort(l);break;
        case 3:QuickSort(l);break;
        case 4:HeapSort(l);break;
        default:cout << "error:序号有误，请重新输入"<<endl;break;
        }
            cout << "请输入序号：" << endl;
        cin >> n;
    }
    return 0;
}
