#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAXSIZE 3

using namespace std;

typedef FILE file;
//data
typedef struct
{
    char phonenum[13];
    char username[10];//一个汉字占2个字节
    char address[50];
}ElemType;

typedef struct
{
    ElemType data;
    int num;
    int sign;
}HashNode;

HashNode a[MAXSIZE];
int p;
int m=MAXSIZE;
void Initialization()
{
    int i,j;
    for(i=MAXSIZE;i>1;i--)
    {
        for(j=2;j<i;j++)
            if(i%j==0) break;
        if(j==i) break;
    }
    p=i;
    for(i=0;i<MAXSIZE;i++)
    {
        a[i].num=i;
        a[i].sign=0;
    }
}
int H(char key[])
{
    int i,sum=0;
    for(i=0;i<11;i++)
    {
        sum+=key[i]-48;
    }
    return sum%p;
}
int Hash(char key[],int di)
{
    return (H(key)+di)%m;
}

void create()
{
    ElemType e;int n,i,k,di;
    cout << "注意：多行数据(电话号码 用户名 地址)，请输入 0 0 0 以结束输入" <<endl;
    cin >> e.phonenum >> e.username >> e.address;
    while(MAXSIZE)
     {
         if(strcmp(e.phonenum,"0")==0&&strcmp(e.username,"0")==0&&strcmp(e.address,"0")==0) break;
        if(strlen(e.phonenum)<11||strlen(e.phonenum)>=12)
        {
            cout <<"手机号格式有误，请重新输入"<<endl;
            cin >> e.phonenum >> e.username >> e.address;
            continue;
        }
        n=Hash(e.phonenum,0);
        if(a[n].sign==0)
        {
            strcpy(a[n].data.phonenum,e.phonenum);
            strcpy(a[n].data.username,e.username);
            strcpy(a[n].data.address,e.address);
            a[n].sign=1;
        }
        else
        {
            for(k=1;k<=m/2;k++)
            {
                di=k*k;
                n=Hash(e.phonenum,di);
                if(a[n].sign==0)
                {
                    strcpy(a[n].data.phonenum,e.phonenum);
                    strcpy(a[n].data.username,e.username);
                    strcpy(a[n].data.address,e.address);
                    a[n].sign=1;
					break;
                }
                else
                {
                    di=-k*k;
                    n=Hash(e.phonenum,di);
                    if(a[n].sign==0)
                    {
                        strcpy(a[n].data.phonenum,e.phonenum);
                        strcpy(a[n].data.username,e.username);
                        strcpy(a[n].data.address,e.address);
                        a[n].sign=1;
						break;
                    }
                    else continue;
                }
            }
            if(k==m/2+1)
            {cout << "哈希表已满无法存储" << endl;break;}
        }
        cin >> e.phonenum >> e.username >> e.address;
     }
    for(i=0;i<m;i++)
    {
        if(a[i].sign==0)
            cout << "序号:" <<a[i].num+1 << "未填入数据"<<endl;
        else
            cout << "序号:"<<a[i].num+1 <<" \t电话:"<<a[i].data.phonenum<<"   用户名:"<<a[i].data.username<<"   地址:"<<a[i].data.address<<endl;
    }
}
void Find()
{
    int n,k,di;
    char tphonenum[13];
    cout << "请输入带查找的用户电话号码："<<endl;
    cin >> tphonenum;
    n=Hash(tphonenum,0);
    if(a[n].sign==0) cout << "找不到该用户"<<endl;
    else
    {
        if(strcmp(a[n].data.phonenum,tphonenum)==0)
            cout << "序号:"<<a[n].num+1 <<" \t电话:"<<a[n].data.phonenum<<"   用户名:"<<a[n].data.username<<"   地址:"<<a[n].data.address<<endl;
        else
        {
             for(k=1;k<=m/2;k++)
             {
                 di=k*k;
                 n=Hash(tphonenum,di);
                 if(a[n].sign==0) {cout << "找不到该用户"<<endl;break;}
                 else
                 {
                     if(strcmp(a[n].data.phonenum,tphonenum)==0)
                     {cout << "序号:"<<a[n].num+1 <<" \t电话:"<<a[n].data.phonenum<<"   用户名:"<<a[n].data.username<<"   地址:"<<a[n].data.address<<endl;break;}
                 }
                 di=-k*k;
                 n=Hash(tphonenum,di);
                 if(a[n].sign==0) {cout << "找不到该用户"<<endl;break;}
                else
                {
                    if(strcmp(a[n].data.phonenum,tphonenum)==0)
                     {cout << "序号:"<<a[n].num+1 <<" \t电话:"<<a[n].data.phonenum<<"   用户名:"<<a[n].data.username<<"   地址:"<<a[n].data.address<<endl;break;}
                     else continue;
                }
             }
             if(k==m/2+1)
                cout << "找不到该用户"<<endl;
        }
    }
}
void Create_txt()
{
    file *fc;
    int i;
    fc=fopen("D:\\data.txt","w");
    if(fc==NULL) {cout << "未提供权限打开文件"<<endl; return ;}
    for(i=0;i<m;i++)
    {
        if(a[i].sign==0)
            continue;
        else
        {
            fputs(a[i].data.phonenum,fc);
            fputs("     ",fc);
            fputs(a[i].data.username,fc);
            fputs("     ",fc);
            fputs(a[i].data.address,fc);
            fputc('\n',fc);
        }
    }
    cout << "data.txt文件生成成功"<<endl;
    fclose(fc);
}
int main()
{
    int n;
    cout << "-------------------------欢迎来到员工通讯录管理系统-------------------------"<<endl;
    cout<<"---------------------------------1.创建记录---------------------------------"<<endl;
    cout<<"---------------------------------2.查找记录---------------------------------"<<endl;
    cout<<"---------------------------------3.保存到本地-------------------------------"<<endl;
    cout<<"---------------------------------4.离开系统---------------------------------"<<endl;
    Initialization();
    cout <<"请输入序号："<<endl;
    cin >> n;
    while(n!=4)
     {
         switch(n)
        {
            case 1:create();break;
            case 2:Find();break;
            case 3:Create_txt();break;
            case 4:break;
            default :cout <<"输入序号有误，请检查输入序号"<<endl<<endl;break;
        }
        cout <<"请输入序号："<<endl;
        cin >> n;
     }
    return 0;
}
