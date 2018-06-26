#include<stdio.h>
#define MaxInt 32767
#define MvNum 100
#define ok 1
typedef struct
{
   char vexs[MvNum];
   int arcs[MvNum][MvNum];
   int vexnum,arcnum;
}AMGraph;
int LocateVex(AMGraph G,char vex)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(vex==G.vexs[i])
            return i;
    if(i==G.vexnum)
        return -1;//cannot find vex.
}
AMGraph CreateDG(AMGraph G,int vexnum,int arcnum,char *c)
{
    int i,j,k,w;
    char v1,v2;
    G.vexnum=vexnum;
    G.arcnum=arcnum;
    for(i=0;i<G.vexnum;i++,c++)
        G.vexs[i]=*c;
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            G.arcs[i][j]=MaxInt;
    for(k=0;k<G.arcnum;k++)
    {
        scanf("%c %c %d",&v1,&v2,&w);
        getchar();
        i=LocateVex(G,v1);j=LocateVex(G,v2);
        G.arcs[i][j]=w;
        G.arcs[j][i]=w;
    }
    return G;
}
void ShortestPath_DIJ(AMGraph G,int v0,int vk)
{
    int m,n,v,i,j,S[100],D[100],Path[100],w,min,Route[100],t;
    n=G.vexnum;
    for(v=0;v<n;v++)
    {
        S[v]=0;//false
        D[v]=G.arcs[v0][v];
        if(D[v]<MaxInt) Path[v]=v0;
        else Path[v]=-1;
    }
    S[v0]=1;//true
    D[v0]=0;
    /*--------------------------------------------------------------------------*/
    for(i=1;i<n;i++)
    {
        min=MaxInt;
        for(w=0;w<n;w++)
            if(!S[w]&&D[w]<min)
            {
                v=w;
                min=D[w];
            }
            S[v]=1;
            for(w=0;w<n;w++)
                if(!S[w]&&(D[v]+G.arcs[v][w]<D[w]))
                {
                    D[w]=D[v]+G.arcs[v][w];
                    Path[w]=v;
                }

    }
    min=0;
    for(i=0;vk!=v0;i++)
    {
        Route[i]=vk;
        vk=Path[vk];
        min+=G.arcs[vk][Route[i]];
    }
    Route[i]=v0;
    printf("%d\n",min);
    for(j=i;j>=0;j--)
    {
        t=Route[j];
        printf("%c ",G.vexs[t]);
    }
     printf("\n");
}
void FindShortestPath()
{
    int n,m,i;
    char city[100],*c,v0,v;
    AMGraph G;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        getchar();
        if(n==0&m==0) break;
        for(i=1;i<=n;i++)
        {
            scanf("%c",&city[i]);//inputting city names compete
            getchar();
        }
        c=&city[1];
        G=CreateDG(G,n,m,c);
        scanf("%c %c",&v0,&v);
        getchar();
        ShortestPath_DIJ(G,LocateVex(G,v0),LocateVex(G,v));

    }
}
int main()
{
    FindShortestPath();
    return 0;
}
