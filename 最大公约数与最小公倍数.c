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
    printf("���Լ����%d\n��С��������%d",b,m/b);
}
