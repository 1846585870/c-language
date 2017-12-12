#include<stdio.h>
int main()
{
    int Sn=0,i=1,t=0,a,n;
    scanf("%d%d",&a,&n);
    for(;i<=n;i++)
    {
        t=t+a;
        Sn=Sn+t;
        a=a*10;
    }
    printf("%d\n",Sn);
    return 0;
}
