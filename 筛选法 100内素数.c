#include<stdio.h>
#define N 100
int main()
{
    int n=2,i,j;
    printf("the prime below 100 are:1 ");
    for(i=2;i<=N;i++)
    {
        for(j=2;j<=i;j++)
            if(i%j==0)
                break;
        if(j==i)
            printf("%d ",i);
    }
    return 0;
}
