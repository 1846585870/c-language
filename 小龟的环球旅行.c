#include<stdio.h>
int main()
{
    int n,t;
    double i,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1,sum=0;;i++)
        {
            sum=sum+1/i;
            if((int)sum==n)
            {
                t=(int)i;
                printf("%d\n",t);
                break;
            }
        }
    }
    return 0;
}
