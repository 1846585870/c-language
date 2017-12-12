#include<stdio.h>
int f(int a)
{
    static int x=1;
    x*=a;
    return (x);
}
int main()
{
    int n,i,m;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        m=f(i);
    printf("%d",m);
    return 0;
}
