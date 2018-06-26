#include<stdio.h>
#include<malloc.h>
typedef struct lnode
{
    int num;
    struct lnode *next;
}lnode;
int createnode(lnode *l,int n)
{
    lnode *p,*q;
    p=l;
    for(;p->next!=NULL;p=p->next);
    q=(lnode*)malloc(sizeof(lnode));
    q->num=n;
    p->next=q;
    q->next=NULL;
}
int merge(lnode *la,lnode *lb,lnode *lc)//hebing
{
    lnode *pa,*pb,*pc,*q;
    lc=la;pc=la;
    pa=la->next;
    pb=lb->next;
    while(pa&&pb)
    {
        if(pa->num<pb->num)
        {   pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else if(pa->num>pb->num)
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
        else
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            q=pb->next;
            free(pb);
            pb=q;
        }

    }
    pc->next=pa?pa:pb;
    free(lb);
}
void listprint(lnode *l)
{
    lnode *p;
    for(p=l;p->next!=NULL;)
    {
        p=p->next;
        printf("%d ",p->num);
    }
    printf("\n");
}
void Input(lnode *l)
{
    int i,num,n;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        scanf("%d",&n);
        createnode(l,n);
    }
}
int main()
{
    lnode la,lb,lc;
    la.next=NULL;
    lb.next=NULL;
    Input(&la);
    Input(&lb);
    merge(&la,&lb,&lc);
    listprint(&lc);
}
