#include<stdio.h>
int main()
{
    int a,b,r,t,m;
    scanf("%d %d",&a,&b);
    m=a*b;
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    printf("最大公约数：%d\n最小公倍数：%d",b,m/b);
}
