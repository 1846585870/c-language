#include<stdio.h>
#include<math.h>
int main()
{
    int x,p,n,y,i,j,c,d,e,f,t,s=0,k=10,a[50],b[50];
    scanf("%d %d %d %d",&x,&p,&n,&y);
    for(i=0;;i++)
        if(x/(int)pow(10,i)==0)
            break;
    for(j=i-1;j>=0;j--)
    {
        a[j]=x%10;
        x=x/10;
    }
    for(c=0;;c++)
        if(y/(int)pow(10,c)==0)
            break;
    for(d=0;d<c;d++)
    {
        b[d]=y%10;
        y=y/10;
    }
    for(e=p-1,f=0;e<=n;e++,f++)
    {
        a[e]=b[f];
    }
    for(t=i-2;t>=0;t--)
    {
        s=s+a[t]*k;
        k=10*k;
    }
    x=s+a[i-1];
    printf("%d\n",x);
    return 0;
}
