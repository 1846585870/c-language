#include<stdio.h>
int main()
{
    int a,b,q,r,i,t;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a<b)
        {
            t=a;
            a=b;
            b=t;
        }
        for(i=0;b!=0;i++)
        {
            q=a/b;
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n",a);
    }
    return 0;
}
