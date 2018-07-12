#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

int n;

typedef struct
{
    int num;
    char name[10];
    int counts;
    int rank;
}ElemType;

typedef struct
{
    ElemType *elem;
    int length;
}Sqlist;

int InitList(Sqlist &l,int n)
{
    int i;
    l.elem=(ElemType *)malloc(sizeof(ElemType)*(n+1));
    if(!l.elem)  return 0;
    l.length=n;
    for(i=0;i<n;i++)
        l.elem[i].counts=0;
    return 1;
}

void Bubble_Sort(Sqlist &l)
{
    int m=l.length-1;int flag=1,j;
    ElemType t;
    while((m>0)&&(flag==1))
    {
        flag=0;
        for(j=0;j<m;j++)
            if(l.elem[j].counts<l.elem[j+1].counts)
            {
                flag=1;
                t=l.elem[j+1];l.elem[j+1]=l.elem[j];l.elem[j]=t;
            }
        --m;
    }
}
int Partition(Sqlist &l,int low,int high)
{
    int pivotkey;
    l.elem[l.length]=l.elem[low];
    pivotkey=l.elem[low].counts;
    while(low<high)
    {
        while(low<high&&l.elem[high].counts<=pivotkey) --high;
        l.elem[low]=l.elem[high];
        while(low<high&&l.elem[low].counts>=pivotkey) ++low;
        l.elem[high]=l.elem[low];
    }
    l.elem[low]=l.elem[l.length];
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
void Quick_Sort(Sqlist &l)
{
    Qsort(l,0,l.length-1);
}
void Print_list(Sqlist &l)
{
    int i,m;
    for(i=0;i<l.length;i++)
    {
        if(i>0)
        {
            if(l.elem[i].counts==l.elem[i-1].counts)
                l.elem[i].rank=m;
            else
            {
                l.elem[i].rank=i+1;
                m=i+1;
            }
        }
        else
        {
            l.elem[i].rank=i+1;
            m=i+1;
        }
    }
    for(i=0;i<l.length;i++)
        cout << l.elem[i].rank <<'\t'<< l.elem[i].num << '\t'<<l.elem[i].name <<'\t' <<'\t'<<l.elem[i].counts << endl;
}
int main()
{
    int i,a;
    Sqlist l;
    cout << "电视大赛观众投票及排名系统"<<endl;
    cout << "请输入参赛选手人数："<<endl;
    cin >> n;
    InitList(l,n);
    cout << "请输入参赛选手编号和姓名："<<endl;
    for(i=0;i<n;i++)
    {
        cin >> l.elem[i].num >> l.elem[i].name;
    }
    cout << "请输入观众投票（以0结束）："<<endl;
    cin >> a;
    while(a!=0)
    {
        for(i=0;i<n;i++)
            if(l.elem[i].num==a)
            {
                l.elem[i].counts++;
                break;
            }
        if(i==n) cout << "error:未找到该编号的参赛选手，请重新输入"<<endl;
        cin >> a;
    }
    //Bubble_Sort(l);
    Quick_Sort(l);
    Print_list(l);
}
