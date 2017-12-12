#include<stdio.h>
int GCD(int m,int n)
{
    int r,t;
    if(m<n)
    {
        t=m;
        m=n;
        n=t;
    }
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return(m);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
        printf("%d\n",GCD(a,b));
    return 0;
}
