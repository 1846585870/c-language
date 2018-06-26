#include<iostream>

#define Hashsize 10
#define maxint 32767
#define ok 1

using namespace std;

typedef struct HashNode
{
    int num;                //序号
    int key;                //关键字
    struct HashNode *next;         //next指针
}HashNode;

int a[Hashsize]={10,9,1,23,14,36,55,20,84,27};
int b[Hashsize];
HashNode HashT[Hashsize];

int H(int key)
{
    return key % 7;
}

//线性探测
int Create_1()
{
    int i,j;
    for(i=0;i<Hashsize;i++)
        b[i]=maxint;        //数组初始化
    for(i=1;i<Hashsize;i++)
    {
        if(b[H(a[i])]==maxint)
            b[H(a[i])]=a[i];
        else
        {
            for(j=H(a[i]);j<Hashsize;j++)
            {
                if(b[j]==maxint)
                {b[j]=a[i];break;}
                else if(j==Hashsize-1)
                {j=0;continue;}
                else continue;
            }
        }
    }
    return ok;
}

void Print_1()
{
    int i;
    cout << "地址探测法:" << '\n';
    for(i=0;i<Hashsize;i++)
        cout << i << " " << b[i] << '\n';
}

//链地址法
int Create_2()
{
    int i;HashNode *p,*q;
    for(i=0;i<Hashsize;i++)
        {HashT[i].num=i;HashT[i].key=maxint;HashT[i].next=NULL;}//初始化
    for(i=1;i<Hashsize;i++)
    {
        if(HashT[H(a[i])].key==maxint)
            HashT[H(a[i])].key=a[i];
        else
        {
            for(p=&HashT[H(a[i])];p->next!=NULL;p=p->next);
            q=new HashNode;
            q->key=a[i];q->num=i;q->next=NULL;
            p->next=q;
        }
    }
    return ok;
}

void Print_2()
{
    int i;HashNode *p;
    cout << "链地址法：" << '\n';
    for(i=0;i<Hashsize;i++)
    {
        if(HashT[i].key==maxint && HashT[i].next==NULL)
            cout << i << "->" << "null" << '\n';
        else
        {
            cout << i << "->" ;
            for(p=&HashT[H(i)];p!=NULL;p=p->next)
                cout << p->key << "->";
            cout << "null" <<'\n';
        }
    }
}

void Insert_(int key)
{
    //线性探测 插入_43
    int j;HashNode *p,*q;
    for(j=H(key);j<Hashsize;j++)
    {
        if(b[j]==maxint)
            b[j]=key;
        else
        {
            if(j==Hashsize-1){j=0;continue;}
            else continue;
        }
    }
    //链地址 插入_43
    for(p=&HashT[H(key)];p->next!=NULL;p=p->next);
    q=new HashNode;q->key=key;q->num=H(key);q->next=NULL;
    p->next=q;
}
void Delete_(int key)
{
    //线性探测 删除_36
    int i,m;HashNode *p,*q;
    for(i=0;i<Hashsize;i++)
        if(b[i]==key)
        {b[i]=maxint;m=i;}
    for(i=m;i<Hashsize;i++)
    {
        if(H(b[i])<i)
        {
            b[m]=b[i];
            b[i]=maxint;
            m=i;
        }
    }
    //链地址 删除_36
    p=&HashT[H(key)];
    if(p->key==key&&p->next==NULL)
        p->key=maxint;
    else if(p->key==key&&p->next!=NULL)
    {
        q=p->next;p->key=q->key;p->next=q->next;delete q;
    }
    else
    {
        for(q=p,p=p->next;p!=NULL;q=p,p=p->next)
            if(p->key==key)
            {q->next=p->next;delete p;}
    }
}
int main()
{
    Create_1();
    Print_1();
    Create_2();
    Print_2();
    Insert_(43);
    Delete_(36);
    Print_1();
    Print_2();
    return 0;
}
