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
    char username[10];//һ������ռ2���ֽ�
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
    cout << "ע�⣺��������(�绰���� �û��� ��ַ)�������� 0 0 0 �Խ�������" <<endl;
    cin >> e.phonenum >> e.username >> e.address;
    while(MAXSIZE)
     {
         if(strcmp(e.phonenum,"0")==0&&strcmp(e.username,"0")==0&&strcmp(e.address,"0")==0) break;
        if(strlen(e.phonenum)<11||strlen(e.phonenum)>=12)
        {
            cout <<"�ֻ��Ÿ�ʽ��������������"<<endl;
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
            {cout << "��ϣ�������޷��洢" << endl;break;}
        }
        cin >> e.phonenum >> e.username >> e.address;
     }
    for(i=0;i<m;i++)
    {
        if(a[i].sign==0)
            cout << "���:" <<a[i].num+1 << "δ��������"<<endl;
        else
            cout << "���:"<<a[i].num+1 <<" \t�绰:"<<a[i].data.phonenum<<"   �û���:"<<a[i].data.username<<"   ��ַ:"<<a[i].data.address<<endl;
    }
}
void Find()
{
    int n,k,di;
    char tphonenum[13];
    cout << "����������ҵ��û��绰���룺"<<endl;
    cin >> tphonenum;
    n=Hash(tphonenum,0);
    if(a[n].sign==0) cout << "�Ҳ������û�"<<endl;
    else
    {
        if(strcmp(a[n].data.phonenum,tphonenum)==0)
            cout << "���:"<<a[n].num+1 <<" \t�绰:"<<a[n].data.phonenum<<"   �û���:"<<a[n].data.username<<"   ��ַ:"<<a[n].data.address<<endl;
        else
        {
             for(k=1;k<=m/2;k++)
             {
                 di=k*k;
                 n=Hash(tphonenum,di);
                 if(a[n].sign==0) {cout << "�Ҳ������û�"<<endl;break;}
                 else
                 {
                     if(strcmp(a[n].data.phonenum,tphonenum)==0)
                     {cout << "���:"<<a[n].num+1 <<" \t�绰:"<<a[n].data.phonenum<<"   �û���:"<<a[n].data.username<<"   ��ַ:"<<a[n].data.address<<endl;break;}
                 }
                 di=-k*k;
                 n=Hash(tphonenum,di);
                 if(a[n].sign==0) {cout << "�Ҳ������û�"<<endl;break;}
                else
                {
                    if(strcmp(a[n].data.phonenum,tphonenum)==0)
                     {cout << "���:"<<a[n].num+1 <<" \t�绰:"<<a[n].data.phonenum<<"   �û���:"<<a[n].data.username<<"   ��ַ:"<<a[n].data.address<<endl;break;}
                     else continue;
                }
             }
             if(k==m/2+1)
                cout << "�Ҳ������û�"<<endl;
        }
    }
}
void Create_txt()
{
    file *fc;
    int i;
    fc=fopen("D:\\data.txt","w");
    if(fc==NULL) {cout << "δ�ṩȨ�޴��ļ�"<<endl; return ;}
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
    cout << "data.txt�ļ����ɳɹ�"<<endl;
    fclose(fc);
}
int main()
{
    int n;
    cout << "-------------------------��ӭ����Ա��ͨѶ¼����ϵͳ-------------------------"<<endl;
    cout<<"---------------------------------1.������¼---------------------------------"<<endl;
    cout<<"---------------------------------2.���Ҽ�¼---------------------------------"<<endl;
    cout<<"---------------------------------3.���浽����-------------------------------"<<endl;
    cout<<"---------------------------------4.�뿪ϵͳ---------------------------------"<<endl;
    Initialization();
    cout <<"��������ţ�"<<endl;
    cin >> n;
    while(n!=4)
     {
         switch(n)
        {
            case 1:create();break;
            case 2:Find();break;
            case 3:Create_txt();break;
            case 4:break;
            default :cout <<"����������������������"<<endl<<endl;break;
        }
        cout <<"��������ţ�"<<endl;
        cin >> n;
     }
    return 0;
}
