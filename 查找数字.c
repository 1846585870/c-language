#include<stdio.h>
int main()
{
    int n,x,i;
    while(scanf("%d %d",&n,&x)!=EOF)
    {
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            {
                if(a[i]==x)
                    {
                        printf("%d\n",i+1);
                        break;
                    }
                else if(i==n-1)
                    printf("-1\n");
            }
    }
    return 0;
}
