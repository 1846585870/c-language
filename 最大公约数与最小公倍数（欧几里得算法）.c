#include<stdio.h>
int main()
{
    int p,r,n,m,temp;
    scanf("%d%d",&m,&n);
    if(n<m)
    {
        temp=n;
        n=m;
        m=temp;
    }
    p=n*m;
    while(m!=0)
    {
        r=n%m;
        n=m;
        m=r;
    }
    printf("���Լ��=%d\n��С������=%d\n",n,p/n);
    return 0;
}
