#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define size 26
#define ok 1
typedef struct
{
    char c;//char
    int i;//cishu
}Count;
typedef struct
{
    Count *elem;
    int length;
}Sqlist;
typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **Huffmancode;
int Initlist(Sqlist *l)
{
    int i;
    l->elem=(Count*)malloc(sizeof(Count)*size);
    if(!l->elem) exit(0);
    l->length=0;
    for(i=0;i<size;i++)
    {
      l->elem[i].c='\0';
      l->elem[i].i=0;
    }
    return ok;
}
void Select(HTNode *HT,int m,int *a,int *b)
{
    int i,min1,min2,t;
    for(i=1;i<=m;i++)
    {
        if(HT[i].parent==0)
        {
            min1=HT[i].weight;
            *a=i;
        }
    }
    for(i=1;i<=m;i++)
        if(HT[i].parent==0&&HT[i].weight<min1)
        {
            min1=HT[i].weight;
            *a=i;
        }

    for(i=1;i<=m;i++)
    {
        if(HT[i].parent==0&&i!=*a)
        {
            min2=HT[i].weight;
            *b=i;
        }
    }
    for(i=1;i<=m;i++)
        if(HT[i].parent==0&&HT[i].weight<min2&&i!=*a)
        {
            min2=HT[i].weight;
            *b=i;
        }
}
HuffmanTree CreateHuffmantree(HuffmanTree HT,Sqlist *l,int n)
{
    int m,i,s1,s2;
    if(n<=1) return;
    m=2*n-1;
    HT=malloc((m+1)*sizeof(HTNode));
    for(i=1;i<=m;i++)
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(i=1;i<=n;i++)
        HT[i].weight=l->elem[i-1].i;
    /*-------------------------------------------------------------------------*/
    for(i=n+1;i<=m;i++)
    {
        Select(HT,i-1,&s1,&s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    return HT;
}
Huffmancode CreatHuffmancode(HuffmanTree HT,Huffmancode HC,int n)
{
    char *cd;
    int start,f,i=1,c;
    HC=(Huffmancode)malloc((n+1)*sizeof(char *));
    cd=(char*)malloc(sizeof(char)*n);
    cd[n-1]='\0';
    for(i=1;i<=n;i++)
    {
        start=n-1;
        c=i;f=HT[i].parent;
        while(f!=0)
        {
            --start;
            if(HT[f].lchild==c) cd[start]='0';
            else cd[start]='1';
            c=f;f=HT[f].parent;
        }
        HC[i]=(char*)malloc(sizeof(char)*(n-start));
        strcpy(HC[i],&cd[start]);
    }
    free(cd);
    cd=NULL;
    return HC;
}
void IfCreatelist(Sqlist *l,char ch)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(l->elem[i].c=='\0')
        {
            l->elem[i].c=ch;
            l->elem[i].i++;
            l->length++;
            break;
        }
        else if(l->elem[i].c==ch)
        {
            l->elem[i].i++;
            break;
        }
    }
}
void Outprint(Sqlist l)
{
    int i;
    for(i=0;i<size;i++)
        if(l.elem[i].c!='\0')
            printf("%c:%d ",l.elem[i].c,l.elem[i].i);
    printf("\n");
}
void OutputHftree(HuffmanTree HT,int n)
{
    int m,i;
    m=2*n-1;
    for(i=1;i<=m;i++)
        printf("%-2d  %-2d  %-2d  %-2d  %-2d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
}
void sort(Sqlist *l)
{
    int i,j,t;
    char ct;
    for(i=0;i<l->length-1;i++)
        for(j=i+1;j<l->length;j++)
            if(l->elem[i].c>l->elem[j].c)
            {
                ct=l->elem[i].c;
                t=l->elem[i].i;
                l->elem[i].c=l->elem[j].c;
                l->elem[i].i=l->elem[j].i;
                l->elem[j].c=ct;
                l->elem[j].i=t;
            }
}
void Data_compression()
{
    char str[1000];
    while(scanf("%s",str)!=EOF)
    {
        if(strcmp(str,"0")==0)break;
        int i=1;
        Sqlist l;
        HuffmanTree HT;
        Huffmancode HC;
        Initlist(&l);
        char *p;
        p=str;
        for(;*p!='\0';p++)
            IfCreatelist(&l,*p);
        sort(&l);
        Outprint(l);
        HT=CreateHuffmantree(HT,&l,l.length);
        OutputHftree(HT,l.length);
        HC=CreatHuffmancode(HT,HC,l.length);
        for(i=1;i<=l.length;i++)
        {
            printf("%c:",l.elem[i-1].c);
            printf("%s ",HC[i]);
        }
        printf("\n");
        for(p=str;*p!='\0';p++)
            for(i=0;i<l.length;i++)
            {
                if(*p==l.elem[i].c)
                    printf("%s",HC[i+1]);
            }
        printf("\n");
        printf("%s",str);
        printf("\n");
        free(p);
    }
}
int main()
{
    Data_compression();
    return 1;
}
