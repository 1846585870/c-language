#include<stdio.h>
int main(void)
{
    int x,n,i,j,t,k,b[20];
    while(scanf("%d %d",&x,&n)!=EOF)
    {
        for(i=0;;i++)
            if(x/(int)pow(10,i)==0)
                break;
        if(n>i)
            n=n%i;
        int a[i];
        for(j=i-1;j>=0;j--)
        {
            a[j]=x%10;
            x=x/10;
        }
        for(t=0;t<i;t++)
        {
            b[t]=a[i-n];
            n--;
            if(n==0)
                n=i;
        }
        for(k=0;k<i;k++)
            printf("%d",b[k]);
        printf("\n");
    }
    return 0;
}
