#include<stdio.h>
int main()
{
    int t,i,j,k,l;
    scanf("%d",&t);
    int a[t];
    for(i=0;i<t;i++)
        scanf("%d",&a[i]);
    for(i=0;i<t;i++)
    {
       if(a[i]<0)
        {
            printf("-1 ");
            a[i]/=-1;
            for(j=2;j<=a[i];j++)
            {
                for(k=2;k<j;k++)
                    if(k%j==0)break;
                if(k==j&&a[i]%k==0)//is a prime.
                {
                    a[i]/=k;
                    printf("%d ",k);
                    while(a[i]%k==0)
                      {
                          printf("%d ",k);
                          a[i]/=k;
                      }
                }
            }
            printf("\n");
        }
        else
        {
            for(j=2;j<=a[i];j++)
            {
                for(k=2;k<j;k++)
                    if(k%j==0)break;
                if(k==j&&a[i]%k==0)//is a prime.
                {
                    a[i]/=k;
                    printf("%d ",k);
                    while(a[i]%k==0)
                      {
                          printf("%d ",k);
                          a[i]/=k;
                      }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
