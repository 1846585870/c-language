#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int weight;
    int parent,lchild,rchild;
}htnode;
void select(htnode *ht,int n,int *s1,int *s2)
{
    int i,j,temp;
    for(i=1;i<=n;i++)
    {
        if(ht[i].parent==0)
        {
            *s1=i;
            break;
        }
    }
    for(j=i+1;j<=n;j++)
    {
        if(ht[j].parent==0)
        {
            *s2=j;
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(ht[i].parent==0)
        {
            if(ht[*s1].weight>ht[i].weight)
            {
                if((*s2)!=i)
                    *s1=i;
            }
        }
    }
    for(j=1;j<=n;j++)
    {
        if(ht[j].parent==0)
        {
            if(ht[*s2].weight>ht[j].weight)
            {
                if((*s1)!=j)
                    *s2=j;
            }
        }
    }
    if(s1>s2)
    {
        temp=*s1;
        *s1=*s2;
        *s2=temp;
    }
}
void create(htnode *ht,int n,int a[26])
{
    int m,i;
    int *s1,*s2;
    if(n<=1) return;
    m=2*n-1;
    //=(htnode *)malloc(sizeof(htnode)*(m+1));
    for(i=1;i<=m;i++)
    {
        ht[i].parent=0;
        ht[i].lchild=0;
        ht[i].rchild=0;
    }
    for(i=1;i<=n;i++)
    {
        ht[i].weight=a[i-1];
    }
    for(i=n+1;i<=m;i++)
    {
        ht[i].weight=0;
    }
    printf("1");
    for(i=n+1;i<=m;i++)
    {
        select(ht,i-1,s1,s2);
        ht[*s1].parent=i;
        ht[*s2].parent=i;
        ht[i].lchild=*s1;
        ht[i].rchild=*s2;
        ht[i].weight=ht[*s1].weight+ht[*s2].weight;
    }
    printf("2");
    for(i=1;i<=m;i++)
    {
        printf("%d %d %d %d %d\n",i,ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
    }
}
/*typedef char **huffmancode;
void createhuffmancode(htnode *ht,huffmancode *hc,int n)
{
    char *cd;
    int i,start,c,f;
    hc=malloc(sizeof(char)*n);
    cd=(char *)malloc(sizeof(char)*n);
    cd[n-1]='\0';
    for(i=0;i<n;i++)
    {
        start=n-1;
        c=i;
        f=ht[i].parent;
        while(f!=0)
        {
            --start;
            if(ht[f].lchild==c)
                cd[start]='0';
            else cd[start]='1';
            c=f;
            f=ht[f].parent;
        }
        hc[i]=malloc(sizeof(char)*(n-start));
        strcpy(*hc[i],&cd[start]);
    }
    free(cd);
}*/
/*void print(htnode *bn,int n)
{
    int i,m;
    m=2*n-1;
    if(bn!=NULL)
    {
        for(i=1;i<=m;i++)
        {
            printf("%d %d %d %d %d",i,bn[i].weight,bn[i].parent,bn[i].lchild,bn[i].rchild);
        }
    }
}*/
int main()
{
    int i,j,n=0;
    char ch;
    int a[26];
    char ah[100];
    for(i=0;i<=25;i++)
        a[i]=0;
    while((ch=getchar())!='0')
    {
        if(ch=='a') {a[0]=a[0]+1;ah[0]='a';}
        if(ch=='b') {a[1]=a[1]+1;ah[1]='b';}
        if(ch=='c') {a[2]=a[2]+1;ah[2]='c';}
        if(ch=='d') {a[3]=a[3]+1;ah[3]='d';}
        if(ch=='e') {a[4]=a[4]+1;ah[4]='e';}
        if(ch=='f') {a[5]=a[5]+1;ah[5]='f';}
        if(ch=='g') {a[6]=a[6]+1;ah[6]='g';}
        if(ch=='h') {a[7]=a[7]+1;ah[7]='h';}
        if(ch=='i') {a[8]=a[8]+1;ah[8]='i';}
        if(ch=='j') {a[9]=a[9]+1;ah[9]='j';}
        if(ch=='k') {a[10]=a[10]+1;ah[10]='k';}
        if(ch=='l') {a[11]=a[11]+1;ah[11]='l';}
        if(ch=='m') {a[12]=a[12]+1;ah[12]='m';}
        if(ch=='n') {a[13]=a[13]+1;ah[13]='n';}
        if(ch=='o') {a[14]=a[14]+1;ah[14]='o';}
        if(ch=='p') {a[15]=a[15]+1;ah[15]='p';}
        if(ch=='q') {a[16]=a[16]+1;ah[16]='q';}
        if(ch=='r') {a[17]=a[17]+1;ah[17]='r';}
        if(ch=='s') {a[18]=a[18]+1;ah[18]='s';}
        if(ch=='t') {a[19]=a[19]+1;ah[19]='t';}
        if(ch=='u') {a[20]=a[20]+1;ah[20]='u';}
        if(ch=='v') {a[21]=a[21]+1;ah[21]='v';}
        if(ch=='w') {a[22]=a[22]+1;ah[22]='w';}
        if(ch=='x') {a[23]=a[23]+1;ah[23]='x';}
        if(ch=='y') {a[24]=a[24]+1;ah[24]='y';}
        if(ch=='z') {a[25]=a[25]+1;ah[25]='z';}
    }
    for(i=0;i<=25;i++)
    {
        if(a[i]==0) continue;
        printf("%c:%d ",ah[i],a[i]);
        n++;
    }
    htnode an[n+1];
    printf("\n");
    create(an,n,a);
    return 0;
}
