#include<stdio.h>
int main()
{
    int m,n,x,y;
    scanf("%d%d",&m,&n);
    if(m>n)
        x=n;
    else
        x=m;
    for(;x>0;)
    {
        if(m%x==0&&n%x==0)
            break;
        x--;
    }
    if(m>n)
        y=m;
    else
        y=n;
    for(;y>0;)
    {
        if(y%m==0&&y%n==0)
            break;
        y++;
    }
    printf("最大公约数=%d\n最小公倍数=%d\n",x,y);
    return 0;

}
