#include<stdio.h>
int insert(int a[],int b,int c,int x)
{
    int i,p,d[10000];
    for(i=0;i<c;i++)
    {
        if(a[i]==b)
        {
            p=i;
            break;
        }
    }
    for(i=p;i<c;i++)
        d[i+1]=a[i];
    a[p]=x;
    for(i=p+1;i<c+1;i++)
        a[i]=d[i];
    return *a;
}
int outsert(int a[],int b,int x)
{
    int i,p,d[10000];
    for(i=0;i<x;i++)
    {
        if(a[i]==b)
        {
            p=i;
            break;
        }
    }
    for(i=p+1;i<x;i++)
        d[i-1]=a[i];
    for(i=p;i<x;i++)
        a[i]=d[i];
    return *a;
}
int main()
{
    int a[10000],i,len,m,n,l;
    int *p;
    char c;
    p=a;
    for(i=0;i<10000;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1)
        {
            len=i;
            break;
        }
    }
    c=getchar();
    while(c!='#')
    {
        switch(c)
        {
            case'C':
                {
                    printf("%d\n",len);
                    break;
                }
            case'A':
                {
                    scanf("%d %d",&m,&n);
                    for(i=0;i<len;i++)
                        if(a[i]==m)
                            break;
                    if(i!=len)
                        {
                            len++;
                            *a=insert(a,m,len,n);
                        }
                    else printf("Not in the queue\n");
                    break;
                }
            case'D':
                {
                    scanf("%d",&l);
                    for(i=0;i<len;i++)
                        if(a[i]==l)
                            break;
                    if(i!=len)
                        {
                            *a=outsert(a,l,len);
                            len--;
                        }
                        else printf("Not in the queue\n");
                        break;
                }
            default:break;
        }
        c=getchar();
    }
    printf("The last one is %d\n",a[len-1]);
    return 0;
}
