#include<iostream>
#include<stdio.h>
#include<string.h>

#define MaxInt 32767
#define MVNum 100

using namespace std;

typedef FILE file;
typedef struct
{
    char name[20];
}ElemType;
typedef struct
{
    ElemType vexs[MVNum];
    int arcs[MVNum][MVNum];
    char arcs1[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;
int solution[MVNum],visited[MVNum],sign;
int LocateVex(AMGraph &G,char name[])
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(strcmp(G.vexs[i].name,name)==0)
            return i;
    if(i==G.vexnum)
        return -1;//error find
}
int Read_txt(AMGraph &G)
{
    file *fp;
    int a,b,w,i,j;
    char c;
    fp=fopen("D:\\Data.txt","r+");
    if(fp==NULL) return 0;
    fscanf(fp,"%d %d",&G.vexnum,&G.arcnum);
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]=MaxInt;
            G.arcs1[i][j]=' ';
        }
    for(i=0;i<G.vexnum;i++)
        fscanf(fp,"%s",&G.vexs[i].name);
    for(i=0;i<G.arcnum;i++)
    {
        fscanf(fp,"%d %d %d %c",&a,&b,&w,&c);
        G.arcs[a][b]=w;
        G.arcs1[a][b]=c;
    }
    fclose(fp);
    return 1;
}
void Print(AMGraph &G,int k)
{
    sign=1;
    int sum=0,i,m,n;
    cout << G.vexs[solution[1]].name;
    for(i=2;i<=k;i++)
    {
        if(G.arcs1[solution[i-1]][solution[i]]=='w')
            cout << " --(����" << G.arcs[solution[i-1]][solution[i]] <<"km" <<")--> " << G.vexs[solution[i]].name;
        else if(G.arcs1[solution[i-1]][solution[i]]=='s')
            cout << " --(����" << G.arcs[solution[i-1]][solution[i]] <<"km" <<")--> " << G.vexs[solution[i]].name;
        sum+=G.arcs[solution[i-1]][solution[i]];
    }
    cout <<endl<< "�����:" << sum << "km" << endl<<endl;
}
void DFS_AM(AMGraph &G,int k,int v,int e)
{
    solution[k]=v;
    visited[v]=1;
    if(v==e) Print(G,k);
    for(int w=0;w<G.vexnum;w++)
        if((G.arcs[v][w]!=MaxInt)&&(!visited[w])) DFS_AM(G,k+1,w,e);
    visited[v]=0;
}
void Find_allPath(AMGraph &G)
{
    char name1[20],name2[20];
    int start,end;
    cout <<"�����������յ�ľ�����:"<<endl;
    cin >> name1 >> name2;
    start=LocateVex(G,name1);end=LocateVex(G,name2);
    if(start==-1||end==-1)
    {
        cout << "error:�Ҳ����þ��������ѷ�����һ��" <<endl;
        return;
    }
    memset(visited,0,sizeof(visited));
    sign=0;
    DFS_AM(G,1,start,end);
    if(!sign) cout<<"�޿���·��!"<<endl;
}
void ShortestPath_DIJ(AMGraph G,int v0,int e)
{
    int n,i,j,v,w,min,s[MVNum],D[MVNum],Path[MVNum],t[MVNum];
    n=G.vexnum;
    for(v=0;v<n;++v)
    {
        s[v]=false;
        D[v]=G.arcs[v0][v];
        if(D[v]<MaxInt) Path[v]=v0;
        else Path[v]=-1;
    }
    s[v0]=1;
    D[v0]=0;
    for(i=1;i<n;++i)
    {
        min=MaxInt;
        for(w=0;w<n;++w)
            if(!s[w]&&D[w]<min)
            {
                v=w;min=D[w];
            }
        s[v]=1;
        for(w=0;w<n;++w)
            if(!s[w]&&(D[v]+G.arcs[v][w]<D[w]))
            {
                D[w]=D[v]+G.arcs[v][w];
                Path[w]=v;
            }
    }
    for(i=1;e!=v0;i++)
    {
        t[i]=e;
        e=Path[e];
    }
    for(t[i]=v0,j=1;i>=1;i--,j++)
        solution[j]=t[i];
    Print(G,j-1);
}
void Find_shortestPath(AMGraph &G)
{
    char name1[20],name2[20];
    int start,end;
    cout <<"�����������յ�ľ�����:"<<endl;
    cin >> name1 >> name2;
    start=LocateVex(G,name1);end=LocateVex(G,name2);
    if(start==-1||end==-1)
    {
        cout << "error:�Ҳ����þ��������ѷ�����һ��" <<endl;
        return;
    }
    sign=0;
    ShortestPath_DIJ(G,start,end);
    if(!sign) cout<<"�޿���·��!"<<endl;
}
int main()
{
    AMGraph G;int n;
    cout << "��ӭ�������ξ�����ѯϵͳ" << endl;
    cout << "���ڶ����ļ�Data.txt�ļ������Ե�......" << endl;
    if(Read_txt(G))
        cout << "����ɹ������Ե�......" << endl;
    else cout << "error:����ʧ�ܣ������ļ�Ȩ��"<< endl;
    cout << "1.��ѯ������������м�·�� 2.��ѯ������������·�� 3.�뿪ϵͳ" << endl;
    cout << "���������:" << endl;
    cin >> n;
    while(n!=3)
    {
        switch(n)
        {
            case 1:Find_allPath(G);cout << "���������:" << endl;break;
            case 2:Find_shortestPath(G);cout << "���������:" << endl;break;
            default:cout <<"���������������������:" <<endl;break;
        }
        cin >> n;
    }
    return 0;
}
