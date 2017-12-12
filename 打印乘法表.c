#include <stdio.h>
int main()
{
    int i,j,r;
    for(i=9;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            r=i*j;
            printf("%d*%d=%d ",i,j,r);
            if(r<10)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
