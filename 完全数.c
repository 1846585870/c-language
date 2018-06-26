#include<stdio.h>
int main()
{
    int i,j,t,a[1000],n;
    for(i=2;i<=1000;i++)
    {
        t=0;n=0;
        for(j=1;j<i;j++)
            {
                if(i%j==0)
                {
                    t+=j;
                    a[n]=j;
                    n++;
                }
            }
        if(t==i)
        {
            printf("%d its factors are ",i);
            for(j=0;j<n;j++)
            {
                printf("%d",a[j]);
                if(j!=n-1)
                    printf(",");
                else printf("\n");
            }

        }

    }
}
