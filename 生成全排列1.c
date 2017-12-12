#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,a[10],p[10],other[10];
void dg(int l)//dg
{
    int i;
    if(l>n)
    {
        for(i=1;i<n;i++)
        {
            printf("%d ",p[i]);
        }
        printf("%d\n",p[n]);
    }
    for(i=1;i<=n;i++)
    {
        if(!other[a[i]])
        {
            p[l]=a[i];
            other[a[i]]=1;
            dg(l+1);
            other[a[i]]=0;
        }
    }
}
int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            a[i]=i;
        }
        memset(other,0,sizeof(other));
        dg(1);
    }
    return 0;
}
