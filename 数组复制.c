#include<stdio.h>
int main()
{
    int n,x,i,j,t;
    int a[1000];
    while(scanf("%d %d",&n,&x)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        //paixu
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
              {
                  t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
              }
        for(i=0;i<n;i++)
            {
                if(a[i]>=x)
                    printf("%d ",a[i]);
                if(i==n-1)
                    printf("\n");

        }
    }
    return 0;
}
